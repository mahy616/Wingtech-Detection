#include "CRecipeManager.h"
#include "QDir"
#include "Config.h"
#include "QFileDialog"
#include <qmessagebox.h>

CRecipeManager::CRecipeManager(QWidget *parent)
	: QDialog(parent)
{
	m_Ready = false;
	ui.setupUi(this);
	m_ImageCounts = 0;
	m_InitRecipe = true;
	InitVariables();
	InitRecipeNames();
	InitConnections();
	CPLCManager::GetInstance()->ReadCurrentRecipe();
}

void CRecipeManager::RunAlgo(Mat Image, int ImageID, e_CameraType type)
{
	QMap<int, QString>::iterator it = m_ImageAndModel.find(ImageID);
	if (it != m_ImageAndModel.end())
	{
		QString ModelPath = it.value();

		QMap<QString, CAlgoManager*>::iterator bt = m_ModelAndAlgo.find(ModelPath);
		if (bt != m_ModelAndAlgo.end())
		{
			CAlgoManager *Algo = bt.value();
			if (Algo != NULL)
			{
				s_ImageInfo ImageInfo;
				ImageInfo.Image = Image;
				ImageInfo.ImageID = ImageID;
				ImageInfo.Type = type;
				Algo->RunAlgo(ImageInfo);
			}
		}
	}
}
//保存从PLC接收的配方名称
void CRecipeManager::SaveRecipeFromPLC(QString RecipeName, int RecipeNumber, int ImageCount)
{
	QString IniName = QCoreApplication::applicationDirPath() + "/RecipeFolder/" + RecipeName + ".ini";
	bool bFind = ui.comboBox->findText(RecipeName);
	if (!bFind)
	{
		ui.comboBox->addItem(RecipeName);
	}
	else
	{
		//删除文件
		QFile::remove(IniName);
	}
	//保存文件
	CConfig *cfg = new CConfig(IniName);
	cfg->Write("Recipe_Parameters", "ImageCount", ImageCount);
}

bool CRecipeManager::InitRecipe(QString RecipeName, QString &errMsg)
{
	int Find = ui.comboBox->findText(RecipeName);
	if (Find == -1)
	{
		m_InitRecipe = false;
		errMsg = QString::fromLocal8Bit("初始化配方失败:") + RecipeName;
		//SaveRecipeFromPLC(RecipeName,m_Number,m_ImageCounts);
		QMessageBox::information(this, QString::fromLocal8Bit("错误"), QString::fromLocal8Bit("初始化配方失败"));
		return false;
	}
	QString IniName = QCoreApplication::applicationDirPath() + "/RecipeFolder/" + RecipeName + ".ini";
	CConfig *cfg = new CConfig(IniName);
	int ImageCount = cfg->GetInt("Recipe_Parameters", "ImageCount");
	if (ImageCount != m_ImageCounts)
	{
		ImageCount = m_ImageCounts;
		errMsg = QString::fromLocal8Bit("配方参数异常");
		cfg->Write("Recipe_Parameters", "ImageCount", ImageCount);
		return false;
	}
	if (ImageCount > 0)
	{
		m_ImageAndModel.clear();
		QMap<QString, CAlgoManager*>::iterator it = m_ModelAndAlgo.begin(), itEnd = m_ModelAndAlgo.end();
		for (; it != itEnd; ++it)
		{
			//停止线程
			it.value()->StopAlgo();
			it.value()->wait(100);
		}
		m_ModelAndAlgo.clear();
	}
	for (int i = 0; i < ImageCount; ++i)
	{
		QString ModelPath = cfg->GetString("Recipe_Parameters", QString::number(i + 1));
		if (!QFileInfo::exists(ModelPath))
		{
			errMsg = QString::fromLocal8Bit("模型不存在:") + ModelPath;
			QMessageBox::information(this, QString::fromLocal8Bit("错误"), QString::fromLocal8Bit("配方模型异常"));
			return false;
		}
		m_ImageAndModel.insert(i + 1, ModelPath);
		QMap<QString, CAlgoManager*>::iterator it = m_ModelAndAlgo.find(ModelPath);
		if (it == m_ModelAndAlgo.end())
		{
			CAlgoManager *Algo = new CAlgoManager();
			connect(CAlgoManager::GetAlgoManager(), SIGNAL(SendPorcessResult(Mat, Mat, int, bool, e_CameraType)), this, SLOT(ReceivaAlgoImage(Mat, Mat, int, bool, e_CameraType)));
			bool rv = Algo->InitAlgo(ModelPath);
			if (!rv)
			{
				errMsg = QString::fromLocal8Bit("模型初始化失败:") + ModelPath;
				QMessageBox::information(this, QString::fromLocal8Bit("错误"), QString::fromLocal8Bit("初始化配方失败"));
				return false;
			}
			else
			{
				m_ModelAndAlgo.insert(ModelPath, Algo);
				Algo->start();
			}
		}
	}
	m_Ready = true;
	return true;
}

void CRecipeManager::InitConnections()
{
	qRegisterMetaType<e_CameraType>("e_CameraType");
	qRegisterMetaType<Mat>("Mat");
	connect(CPLCManager::GetInstance(), SIGNAL(SendChangePLCRecipe(QString,int,int)), this, SLOT(ReceiveChangePlcRecipe(QString,int,int)));
	connect(CPLCManager::GetInstance(), SIGNAL(SendSavePLCRecipe(QString, int,int)), this, SLOT(ReceiveSavePlcRecipe(QString,int,int)));
	connect(CPLCManager::GetInstance(), SIGNAL(SendStartSign()), this, SLOT(ReceiveStartSign()));

}

bool CRecipeManager::SendPLCReadySign()
{
	if (m_Ready&&m_InitRecipe)
	{
		CPLCManager::GetInstance()->WritePLCReady();
		return true;
	}
	else
	{
		return false;
	}
}

int CRecipeManager::GetImageCounts()
{
	return m_ImageCounts;
}

void CRecipeManager::InitVariables()
{
	QFont font("微软雅黑", 12);
	ui.tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
	ui.tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
	ui.tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
	ui.tableWidget->horizontalHeader()->setFont(font);
	ui.tableWidget->horizontalHeader()->setHighlightSections(false);
	ui.tableWidget->horizontalHeader()->setStyleSheet("QHeaderView::section{color:rgb(255,255,255);background:rgb(41,136,41);}");
	ui.tableWidget->setColumnCount(3);
	ui.tableWidget->horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeToContents);
	ui.tableWidget->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
	ui.tableWidget->horizontalHeader()->setSectionResizeMode(2, QHeaderView::ResizeToContents);
	ui.tableWidget->verticalHeader()->setHidden(true);
	QStringList header;
	header << QString::fromLocal8Bit("图像ID") << QString::fromLocal8Bit("模型路径") << QString::fromLocal8Bit("选择模型");
	ui.tableWidget->setHorizontalHeaderLabels(header);

	ui.tableWidget_Camear->setSelectionBehavior(QAbstractItemView::SelectRows);
	ui.tableWidget_Camear->setEditTriggers(QAbstractItemView::NoEditTriggers);
	ui.tableWidget_Camear->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
	ui.tableWidget_Camear->horizontalHeader()->setFont(font);
	ui.tableWidget_Camear->horizontalHeader()->setHighlightSections(false);
	ui.tableWidget_Camear->horizontalHeader()->setStyleSheet("QHeaderView::section{color:rgb(255,255,255);background:rgb(41,136,41);}");
	ui.tableWidget_Camear->setColumnCount(3);
	ui.tableWidget_Camear->setRowCount(4);
	ui.tableWidget_Camear->horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeToContents);
	ui.tableWidget_Camear->horizontalHeader()->setSectionResizeMode(1, QHeaderView::ResizeToContents);
	ui.tableWidget_Camear->horizontalHeader()->setSectionResizeMode(2, QHeaderView::ResizeToContents);
	ui.tableWidget_Camear->verticalHeader()->setHidden(true);

	ui.tableWidget_Camear->setItem(0, 0, new QTableWidgetItem(QString::fromLocal8Bit("相机一")));
	ui.tableWidget_Camear->setItem(1, 0, new QTableWidgetItem(QString::fromLocal8Bit("相机二")));
	ui.tableWidget_Camear->setItem(2, 0, new QTableWidgetItem(QString::fromLocal8Bit("相机三")));
	ui.tableWidget_Camear->setItem(3, 0, new QTableWidgetItem(QString::fromLocal8Bit("相机四")));

	QStringList headerCamer;
	headerCamer << QString::fromLocal8Bit("相机") << QString::fromLocal8Bit("曝光值") << QString::fromLocal8Bit("增益值");
	ui.tableWidget_Camear->setHorizontalHeaderLabels(headerCamer);
}

QStringList CRecipeManager::getFileNames(const QString &path)
{
	QDir dir(path);
	return dir.entryList(QStringList("*.ini"), QDir::Files | QDir::Readable, QDir::Name);
}

void CRecipeManager::InitRecipeNames()
{
	QString IniPath = QCoreApplication::applicationDirPath() + "/RecipeFolder";
	//IniPath += "/RecipeFolder";
	QStringList RecipeNames = getFileNames(IniPath);
	ui.comboBox->clear();
	for (int i = 0; i < RecipeNames.size(); ++i)
	{
		QFileInfo info(RecipeNames.at(i));
		QString Name = info.baseName();
		ui.comboBox->addItem(Name);
	}
	QString err;
	
	//if (!InitRecipe(ui.comboBox->itemText(0), err))  //在没有接收PLC信号的基础上 测试用
	//{
	//	cout << "初始化配方失败" << endl;
	//}
	//else
	//{
	//	m_Ready = true;
	//}
}

void CRecipeManager::SwitchRecipe(QString Name)
{
	QString IniName = QCoreApplication::applicationDirPath() + "/RecipeFolder/" + Name + ".ini";
	CConfig *cfg = new CConfig(IniName);
	int ImageCount = cfg->GetInt("Recipe_Parameters", "ImageCount");
	ui.tableWidget->setRowCount(0);
	ui.tableWidget->clearContents();
	for (int i = 0; i < ImageCount; ++i)
	{
		ui.tableWidget->insertRow(ui.tableWidget->rowCount());
		QTableWidgetItem *item = new QTableWidgetItem(QString::number(i+1));
		ui.tableWidget->setItem(i, 0, item);
		QString ModelPath = cfg->GetString("Recipe_Parameters", QString::number(i + 1));
		ui.tableWidget->setItem(i, 1, new QTableWidgetItem(ModelPath));
		QPushButton *button = new QPushButton(QString::fromLocal8Bit("浏览..."));
		ui.tableWidget->setCellWidget(i, 2, button);
		connect(button, SIGNAL(clicked()), this, SLOT(BrowseModelPath()));
	}
}

void CRecipeManager::BrowseModelPath()
{
	QPushButton *senderObj = qobject_cast<QPushButton*>(sender());
	if (senderObj == nullptr)
	{
		return;
	}
	int row = ui.tableWidget->indexAt(QPoint(senderObj->frameGeometry().x(), senderObj->frameGeometry().y())).row();
	QString ModelPath = QFileDialog::getOpenFileName(this, QString::fromLocal8Bit("模型路径"), "./", "*.smartmore");
	if (!ModelPath.isEmpty())
	{
		ui.tableWidget->setItem(row, 1, new QTableWidgetItem(ModelPath));
	}
}

void CRecipeManager::ReceiveSavePlcRecipe(QString msg, int RecipeNumber,int ImageCounts)
{
	SaveRecipeFromPLC(msg, RecipeNumber,ImageCounts);
}

void CRecipeManager::ReceiveChangePlcRecipe(QString msg, int number, int ImageCounts)
{
	m_ImageCounts = ImageCounts;
	m_Number = number;
	QString err;
	InitRecipe(QString::number(number), err);
}

void CRecipeManager::ReceivaOriginalImage(Mat Image,int ImageID, e_CameraType Type)
{

	RunAlgo(Image, ImageID,Type);
}

void CRecipeManager::ReceivaAlgoImage(Mat image, Mat RenderImage, int index, bool bOK, e_CameraType type)
{

	emit SendAlgoImage(image, RenderImage , index,bOK, type);
}

void CRecipeManager::ReceiveStartSign()
{
	emit SendStartSign();
}

void CRecipeManager::ReceiveAlgoThreshold(QVector<double> AlgoThreshold)
{
	m_AlgoThreshold = AlgoThreshold;
	QMap<QString, CAlgoManager*>::iterator it; //遍历map  
	for (it = m_ModelAndAlgo.begin(); it != m_ModelAndAlgo.end(); ++it)
	{
		it.value()->SetAlgoThreshold(m_AlgoThreshold);
	}

}

void CRecipeManager::SaveRecipe()
{
	QString RecipeName = ui.comboBox->currentText();
	QString IniName = QCoreApplication::applicationDirPath() + "/RecipeFolder/" + RecipeName + ".ini";
	CConfig *cfg = new CConfig(IniName);
	int rows = ui.tableWidget->rowCount();
	cfg->Write("Recipe_Parameters", "ImageCount", rows);
	for (int i = 0; i < rows; ++i)
	{
		QString ModelPath = ui.tableWidget->item(i, 1)->text();
		if (!QFileInfo::exists(ModelPath))
		{
			QMessageBox::information(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("模型路径不存在"));
		}
		cfg->Write("Recipe_Parameters", QString::number(i + 1), ModelPath);
	}
	delete cfg;
	cfg = nullptr;
	QString errMsg;
	InitRecipe(RecipeName, errMsg);
}
 
void CRecipeManager::DeleteRecipe()
{

}

void CRecipeManager::updateTableInfos(void)
{
	ui.tableWidget->clear();
	QStringList header;
	header << QString::fromLocal8Bit("图像ID") << QString::fromLocal8Bit("模型路径") << QString::fromLocal8Bit("选择模型");
	ui.tableWidget->setHorizontalHeaderLabels(header);
	InitRecipeNames();
}

void CRecipeManager::tableWidget_click(const QModelIndex &index)
{
	index.row();

}