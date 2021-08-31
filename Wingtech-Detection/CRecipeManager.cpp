#include "CRecipeManager.h"
#include "QDir"
#include "Config.h"
#include "QFileDialog"

CRecipeManager::CRecipeManager(QWidget *parent)
	: QDialog(parent)
{
	m_Ready = false;
	ui.setupUi(this);
	InitVariables();
	InitRecipeNames();
	InitConnections();
}

void CRecipeManager::RunAlgo(Mat Image, int ImageID)
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
				Algo->RunAlgo(ImageInfo);
			}
		}
	}
}

void CRecipeManager::SaveRecipeFromPLC(QString RecipeName,int ImageCount)
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
	if (Find==-1)
	{
		errMsg = QString::fromLocal8Bit("未找到配方:") + RecipeName;
		return false;
	}

	QString IniName = QCoreApplication::applicationDirPath() + "/RecipeFolder/" + RecipeName + ".ini";
	CConfig *cfg = new CConfig(IniName);
	int ImageCount = cfg->GetInt("Recipe_Parameters", "ImageCount");
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
				return false;
			}
			else
			{
				m_ModelAndAlgo.insert(ModelPath, Algo);
				Algo->start();
			}
		}
	}
	return true;
}

void CRecipeManager::InitConnections()
{
	qRegisterMetaType<e_CameraType>("e_CameraType");
	qRegisterMetaType<Mat>("Mat");
	connect(CPLCManager::GetInstance(), SIGNAL(SendChangePLCRecipe(QString,int)), this, SLOT(ReceiveChangePlcRecipe(QString.int)));
	connect(CPLCManager::GetInstance(), SIGNAL(SendSavePLCRecipe(QString, int)), this, SLOT(ReceiveSavePlcRecipe(QString.int)));


}

void CRecipeManager::SendPLCReadySign()
{
	CPLCManager::GetInstance()->WritePLCRead();
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
}

QStringList CRecipeManager::getFileNames(const QString &path)
{
	QDir dir(path);
	return dir.entryList(QStringList("*.ini"), QDir::Files | QDir::Readable, QDir::Name);
}

void CRecipeManager::InitRecipeNames()
{
	QString IniPath = QCoreApplication::applicationDirPath();
	IniPath += "/RecipeFolder";
	QStringList RecipeNames = getFileNames(IniPath);
	ui.comboBox->clear();
	for (int i = 0; i < RecipeNames.size(); ++i)
	{
		QFileInfo info(RecipeNames.at(i));
		QString Name = info.baseName();
		ui.comboBox->addItem(Name);
	}
	QString err;
	
	if (!InitRecipe(ui.comboBox->itemText(0), err))  //在没有接收PLC信号的基础上 测试用
	{
		cout << "初始化配方失败" << endl;
	}
	else
	{
		m_Ready = true;
	}
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

void CRecipeManager::ReceiveSavePlcRecipe(QString msg, int number)
{
	SaveRecipeFromPLC(msg,number);
}

void CRecipeManager::ReceiveChangePlcRecipe(QString msg,int number)
{
	emit SendInitImageNumber(number);
	m_Number = number;
	QString err;
	InitRecipe(msg, err);
}

void CRecipeManager::ReceivaOriginalImage(Mat Image,int ImageID)
{

	RunAlgo(Image, ImageID);
}

void CRecipeManager::ReceivaAlgoImage(Mat image, Mat RenderImage, int index, bool bOK, e_CameraType type)
{

	emit SendAlgoImage(image, RenderImage , index,bOK, type);
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
			//提示保存失败
		}
		cfg->Write("Recipe_Parameters", QString::number(i + 1), ModelPath);
	}

}
 