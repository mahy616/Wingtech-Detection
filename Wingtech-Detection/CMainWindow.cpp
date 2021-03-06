#include "CMainWindow.h"
#include "QDockWidget"
#include "ResultDetails.h"
#include "qdebug.h"
#include <QDateTime>
#include <QMouseEvent>
#include <QMutex>
#include <QTextStream>
#include <qdir.h>
#include "QMessageBox"
int GetImageCount(e_CameraType)
{
    return 0;
}

const QString m_red_SheetStyle = "min-width: 16px; min-height: 16px;max-width:16px; max-height: 16px;border-radius: "
                                 "8px;  border:1px solid black;background:red";
const QString m_green_SheetStyle = "min-width: 16px; min-height: 16px;max-width:16px; max-height: 16px;border-radius: "
                                   "8px;  border:1px solid black;background:green";
const QString m_grey_SheetStyle = "min-width: 16px; min-height: 16px;max-width:16px; max-height: 16px;border-radius: "
                                  "8px;  border:1px solid black;background:grey";
const QString m_yellow_SheetStyle = "min-width: 16px; min-height: 16px;max-width:16px; max-height: 16px;border-radius: "
                                    "8px;  border:1px solid black;background:yellow";

CMainWindow::~CMainWindow()
{
    delete m_Parameter;
    m_Parameter = NULL;
	delete m_RecipeManager;
	m_RecipeManager = nullptr;
	delete m_admin;
	m_admin = nullptr;
}


void outputMessage(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    static QMutex mutex;
    mutex.lock();

    QString text;
    switch (type)
    {
        case QtDebugMsg:
            text = QString("Debug:");
            break;

        case QtWarningMsg:
            text = QString("Warning:");
            break;

        case QtCriticalMsg:
            text = QString("Critical:");
            break;

        case QtFatalMsg:
            text = QString("Fatal:");
    }

    QString context_info = QString("File:(%1) Line:(%2)").arg(QString::fromLocal8Bit(context.file)).arg(context.line);
    QString current_date_time = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss ddd");
    QString current_date = QString("(%1)").arg(current_date_time);
    QString message = QString("%1          %2 %3 %4").arg(current_date).arg(text).arg(context_info).arg(msg);
    QString LogPath = QCoreApplication::applicationDirPath();
    LogPath.append("/log");
    QDir dir(LogPath);
    if (!dir.exists(LogPath))
    {
        dir.mkdir(LogPath);
    }
    QString logFile = LogPath + "/" + QDateTime::currentDateTime().toString("yyyy-MM-dd");
    logFile.append(".txt");
    QFile file(logFile);
    file.open(QIODevice::WriteOnly | QIODevice::Append);
    QTextStream text_stream(&file);
    text_stream << message << "\r\n";
    file.flush();
    file.close();

    mutex.unlock();
}

CMainWindow::CMainWindow(QWidget *parent) : QMainWindow(parent)
{
	qDebug() << "CMainWindow::CMainWindow(QWidget *parent) Init !";
    ui.setupUi(this);
    qInstallMessageHandler(outputMessage);
    InitVariables();
	m_Index = 0;      //??????????????????????
    InitResultDetails(m_ImageCounts);
    InitStatusBar();
    InitConnections();
}

void CMainWindow::InitVariables()
{
	qDebug() << "CMainWindow::InitVariables()";
    //???????? OK/NG
    QFont LabelFont("????????", 142);
 //   m_TotalResult = new QLabel("OK");
 //   // m_ResultLabel->setFont(LabelFont);
 //   m_TotalResult->setStyleSheet(
 //       "color: rgb(0, 170, 0);background-color: rgb(255, 255, 150);font: 142pt \"????????\";");
 //   m_TotalResult->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
	//qDebug() << "Init OK label widget";
 //   //????????????
 //   QDockWidget *DockResult = new QDockWidget(QString::fromLocal8Bit("????????"));
 //   DockResult->setFeatures(QDockWidget::DockWidgetMovable | QDockWidget::DockWidgetFloatable);
 //   addDockWidget(Qt::RightDockWidgetArea, DockResult);
 //   DockResult->setWidget(m_TotalResult);
	//qDebug() << "Init DockResult widget";

	m_FirstResult = new QLabel("OK1");
	m_FirstResult->setStyleSheet(
		"color: rgb(0, 170, 0);background-color: rgb(255, 255, 150);font: 35pt \"????????\";");
	m_FirstResult->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);	

	m_SecondResult = new QLabel("OK2");
	m_SecondResult->setStyleSheet(
		"color: rgb(0, 170, 0);background-color: rgb(255, 255, 150);font: 35pt \"????????\";");
	m_SecondResult->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

	m_ThirdResult = new QLabel("OK3");
	m_ThirdResult->setStyleSheet(
		"color: rgb(0, 170, 0);background-color: rgb(255, 255, 150);font: 35pt \"????????\";");
	m_ThirdResult->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

	m_FourthResult = new QLabel("OK4");
	m_FourthResult->setFont(LabelFont);
	m_FourthResult->setStyleSheet(
		"color: rgb(0, 170, 0);background-color: rgb(255, 255, 150);font: 35pt \"????????\";");
	m_FourthResult->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
	   //????????????
	QDockWidget *DockResult = new QDockWidget(QString::fromLocal8Bit("????????"));
	DockResult->setFeatures(QDockWidget::DockWidgetMovable | QDockWidget::DockWidgetFloatable);
	addDockWidget(Qt::RightDockWidgetArea, DockResult);
	//DockResult->setWidget(m_TotalResult);

	QGridLayout *Layout = new QGridLayout();
	Layout->addWidget(m_FirstResult, 0, 0, 1, 1);
	Layout->addWidget(m_SecondResult, 0, 1, 1, 1);
	Layout->addWidget(m_ThirdResult, 1, 0, 1, 1);
	Layout->addWidget(m_FourthResult, 1, 1, 1, 1);

	QWidget *laywidget = new QWidget();
	laywidget->setLayout(Layout);
	DockResult->setWidget(laywidget);

    //????????
    m_Statistics = new StatisticsWidget();
    QDockWidget *DockStatistics = new QDockWidget(QString::fromLocal8Bit("????????"));
    DockStatistics->setFeatures(QDockWidget::DockWidgetMovable | QDockWidget::DockWidgetFloatable);
    addDockWidget(Qt::RightDockWidgetArea, DockStatistics);
    DockStatistics->setWidget(m_Statistics);
	qDebug() << "Init DockStatistics widget";
    //????
	//m_ListViewClear = new QPushButton();
	//QGridLayout *LogLayout = new QGridLayout();
	//LogLayout->addWidget(m_ListViewClear);
	//QWidget *Loglaywidget = new QWidget();
	//Loglaywidget->setLayout(LogLayout);


    m_ListView = new QListView();
    m_LogModel = new QStandardItemModel();
    QFont font("????????", 12);
    m_ListView->setFont(font);
    m_LogModel = new QStandardItemModel();
    m_ListView->setModel(m_LogModel);
    QDockWidget *LogDock = new QDockWidget(QString::fromLocal8Bit("????"));
    LogDock->setFeatures(QDockWidget::DockWidgetMovable | QDockWidget::DockWidgetFloatable);
    addDockWidget(Qt::RightDockWidgetArea, LogDock);
    LogDock->setWidget(m_ListView);
	
	qDebug() << "Init Log widget";
    m_Camera1Results.clear();
    m_Camera1Images.clear();
    m_Camera1Result = true;

    m_Camera2Results.clear();
    m_Camera2Images.clear();
    m_Camera2Result = true;

    m_Camera3Results.clear();
    m_Camera3Images.clear();
    m_Camera3Result = true;

    m_Camera4Results.clear();
    m_Camera4Images.clear();
    m_Camera4Result = true;

    m_Parameter = new CParameterSetting;
	m_RecipeManager = new CRecipeManager;
	m_admin = new adminLoginDialog;

	setActionEnable(false);
	m_bStart = false;
}

//????PLC??????????????????????????????????????????????
//????10??????????
void CMainWindow::InitResultDetails(int ImageCounts)
{
	ImageCounts = m_RecipeManager->GetImageCounts();
	m_ImageCounts = ImageCounts;
    qDebug() << "InitResultDetials";
    QGridLayout *Camera1Layout = new QGridLayout();

    int row = 0;
    int col = 0;
    for (int i = 0; i < ImageCounts; ++i)
    {
        if (col > 9)
        {
            row++;
            col = 0;
        }
        QLabel *label = new QLabel();
        label->installEventFilter(this);
        label->setStyleSheet(m_grey_SheetStyle);
        Camera1Layout->addWidget(label, row, col);
        m_Camera1Results.push_back(label);
        col++;
    }
    ui.groupBox_1->setLayout(Camera1Layout);

    QGridLayout *Camera2Layout = new QGridLayout();
    row = 0;
    col = 0;
    for (int i = 0; i < ImageCounts; ++i)
    {
        if (col > 9)
        {
            row++;
            col = 0;
        }
        QLabel *label = new QLabel();
        label->installEventFilter(this);
        label->setStyleSheet(m_grey_SheetStyle);
        Camera2Layout->addWidget(label, row, col);
        m_Camera2Results.push_back(label);
        col++;
    }
    ui.groupBox_2->setLayout(Camera2Layout);

    QGridLayout *Camera3Layout = new QGridLayout();
    row = 0;
    col = 0;
    for (int i = 0; i < ImageCounts; ++i)
    {
        if (col > 9)
        {
            row++;
            col = 0;
        }
        QLabel *label = new QLabel();
        label->installEventFilter(this);
        label->setStyleSheet(m_grey_SheetStyle);
        Camera3Layout->addWidget(label, row, col);
        m_Camera3Results.push_back(label);
        col++;
    }
    ui.groupBox_3->setLayout(Camera3Layout);

    QGridLayout *Camera4Layout = new QGridLayout();
    row = 0;
    col = 0;
    for (int i = 0; i < ImageCounts; ++i)
    {
        if (col > 9)
        {
            row++;
            col = 0;
        }
        QLabel *label = new QLabel();
        label->installEventFilter(this);
        label->setStyleSheet(m_grey_SheetStyle);
        Camera4Layout->addWidget(label, row, col);
        m_Camera4Results.push_back(label);
        col++;
    }
    ui.groupBox_4->setLayout(Camera4Layout);
}

//????PLC????????????????????
void CMainWindow::RefreshResultDetails()
{
    for (int i = 0; i < m_Camera1Results.size(); ++i)
    {
        m_Camera1Results.at(i)->setStyleSheet(m_grey_SheetStyle);
    }
    m_Camera1Images.clear();
    m_Camera1Result = true;

    for (int i = 0; i < m_Camera2Results.size(); ++i)
    {
        m_Camera2Results.at(i)->setStyleSheet(m_grey_SheetStyle);
    }
    m_Camera2Images.clear();
    m_Camera2Result = true;

    for (int i = 0; i < m_Camera3Results.size(); ++i)
    {
        m_Camera3Results.at(i)->setStyleSheet(m_grey_SheetStyle);
    }
    m_Camera3Images.clear();
    m_Camera3Result = true;

    for (int i = 0; i < m_Camera4Results.size(); ++i)
    {
        m_Camera4Results.at(i)->setStyleSheet(m_grey_SheetStyle);
    }
    m_Camera4Images.clear();
    m_Camera4Result = true;
}



bool CMainWindow::eventFilter(QObject *obj, QEvent *event)
{
    if (event->type() == QEvent::MouseButtonPress)
    {
        QMouseEvent *mouseevent = static_cast<QMouseEvent *>(event);
        if (mouseevent->buttons() == Qt::LeftButton)
        {
            for (int i = 0; i < m_Camera1Results.size(); ++i)
            {
                if (obj == m_Camera1Results.at(i))
                {
                    qDebug() << "click at camera1 details index = " << i + 1;
                    if (m_Camera1Images.size() > i)
                    {
                        const QImage image = m_Camera1Images.at(i);
                        CResultDetials::GetInstance()->SetImage(image);
                        CResultDetials::GetInstance()->exec();
                    }
                    break;
                }
            }

            for (int i = 0; i < m_Camera2Results.size(); ++i)
            {
                if (obj == m_Camera2Results.at(i))
                {
                    qDebug() << "click at camera2 details index = " << i + 1;
                    if (m_Camera2Images.size() > i)
                    {
                        const QImage image = m_Camera2Images.at(i);
                        CResultDetials::GetInstance()->SetImage(image);
                        CResultDetials::GetInstance()->exec();
                    }
                    break;
                }
            }

            for (int i = 0; i < m_Camera3Results.size(); ++i)
            {
                if (obj == m_Camera3Results.at(i))
                {
                    qDebug() << "click at camera3 details index = " << i + 1;
                    if (m_Camera3Images.size() > i)
                    {
                        const QImage image = m_Camera3Images.at(i);
                        CResultDetials::GetInstance()->SetImage(image);
                        CResultDetials::GetInstance()->exec();
                    }
                    break;
                }
            }
            for (int i = 0; i < m_Camera4Results.size(); ++i)
            {
                if (obj == m_Camera4Results.at(i))
                {
                    qDebug() << "click at camera4 details index = " << i + 1;
                    if (m_Camera4Images.size() > i)
                    {
                        const QImage image = m_Camera4Images.at(i);
                        CResultDetials::GetInstance()->SetImage(image);
                        CResultDetials::GetInstance()->exec();
                    }
                    break;
                }
            }
        }
    }
    return QMainWindow::eventFilter(obj, event);
}

void CMainWindow::InitStatusBar()
{
    qDebug() << "InitStatusBar";
    ui.statusBar->setStyleSheet("QStatusBar::item{ border: 0px }");
    m_PLC.setStyleSheet(m_yellow_SheetStyle);
    ui.statusBar->addWidget(&m_PLC);
    QLabel *label = new QLabel(QString::fromLocal8Bit("PLC:"));
    ui.statusBar->addWidget(label);

    m_Camera1.setStyleSheet(m_yellow_SheetStyle);
    ui.statusBar->addWidget(&m_Camera1);
    label = new QLabel(QString::fromLocal8Bit("????1:"));
    ui.statusBar->addWidget(label);

    m_Camera2.setStyleSheet(m_yellow_SheetStyle);
    ui.statusBar->addWidget(&m_Camera2);
    label = new QLabel(QString::fromLocal8Bit("????2:"));
    ui.statusBar->addWidget(label);

    m_Camera3.setStyleSheet(m_yellow_SheetStyle);
    ui.statusBar->addWidget(&m_Camera3);
    label = new QLabel(QString::fromLocal8Bit("????3:"));
    ui.statusBar->addWidget(label);

    m_Camera4.setStyleSheet(m_yellow_SheetStyle);
    ui.statusBar->addWidget(&m_Camera4);
    label = new QLabel(QString::fromLocal8Bit("????4:"));
    ui.statusBar->addWidget(label);

	ui.action_Stop->setEnabled(false);
}

void CMainWindow::InitConnections()
{
    connect(ui.action_Start, SIGNAL(triggered()), this, SLOT(StartDection()));
    connect(ui.action_Stop, SIGNAL(triggered()), this, SLOT(StopDection()));
    connect(ui.action_Setting, SIGNAL(triggered()), this, SLOT(OpenSetting()));
	connect(ui.action_Recipe, SIGNAL(triggered()), this, SLOT(RecipeSetting()));
	connect(ui.action_admin, SIGNAL(triggered()), this, SLOT(AdminDection()));
    qRegisterMetaType<Mat>("Mat");
    qRegisterMetaType<e_CameraType>("e_CameraType");
	qRegisterMetaType<s_ImageInfo>("s_ImageInfo");
	qRegisterMetaType<QVector<double>>("QVector<double>");
    connect(m_Parameter, SIGNAL(SendOriginalImage(Mat, int, e_CameraType)), m_RecipeManager, SLOT(ReceivaOriginalImage(Mat, int, e_CameraType)));
	connect(m_Parameter, SIGNAL(SendThreshold(QVector<double>)), m_RecipeManager, SLOT(ReceiveAlgoThreshold(QVector<double>)));
	connect(m_RecipeManager, SIGNAL(SendAlgoImage(Mat, Mat, int , bool , e_CameraType )), this, SLOT(ReceiveAlgoImage(Mat, Mat, int, bool, e_CameraType)));
	connect(m_RecipeManager, SIGNAL(SendStartSign()), this, SLOT(ReceiveStartSign()));



}

void CMainWindow::SendPLCResult(QString strResult,bool bok)
{
	qDebug() << "CParameterSetting:" << strResult;
	if (CPLCManager::GetInstance()->GetConnectStatus())
	{
		if (!CPLCManager::GetInstance()->WritePLCData(strResult, bok))
		{
			QString Msg = "Write PLC Result Falied ";
			AddLog(Msg);
		}
	}

}



void CMainWindow::AddLog(QString log)
{
    int rows = m_LogModel->rowCount();
    if (rows > 1000)
    {
        m_LogModel->removeRows(0, rows);
    }
    m_LogModel->appendRow(new QStandardItem(log));
    m_ListView->scrollToBottom();
}

void CMainWindow::StartDection()
{
	qDebug() << "CMainWindow::StartDection()";
	if (!m_RecipeManager->SendPLCReadySign())
	{
		QMessageBox::information(this, QString::fromLocal8Bit("????"), QString::fromLocal8Bit("??????????????") );
		return;
	}
	ui.action_Start->setEnabled(false);
	ui.action_Stop->setEnabled(true);
	ui.action_Setting->setEnabled(false);
    m_Parameter->StartDetecion(true);
    m_bStart = true;
    // TODO ??????????????PLC??????????????
}

void CMainWindow::StopDection() 
{
	qDebug() << "CMainWindow::StopDection()";
	ui.action_Start->setEnabled(true);
	ui.action_Stop->setEnabled(false);
	ui.action_Setting->setEnabled(true);
	m_Parameter->StartDetecion(false);
	m_bStart = false;
}

void CMainWindow::OpenSetting()
{
    m_Parameter->exec();
}

void CMainWindow::RecipeSetting()
{
	m_RecipeManager->exec();
}

void CMainWindow::AdminDection()
{
	m_Parameter->setIDandPswd();
	m_admin->exec();
	QString ID = ChangePswd::GetInstall()->GetAdminID();
	QString pswd = ChangePswd::GetInstall()->GetAdminPswd();
	
	if (m_admin->m_index == 0)
	{
		if (m_admin->m_admin.Pswd == pswd)
		{
			setActionEnable(true);
			ui.action_admin->setEnabled(false);
		}
	}
	else if(m_admin->m_index == 1)
	{
		if (m_admin->m_operator.Pswd == pswd)
		{
			ui.action_Start->setEnabled(true);
			ui.action_Setting->setEnabled(false);
			ui.action_Recipe->setEnabled(false);
			ui.action_admin->setEnabled(false);
		}
		
	}
	else
	{
		ui.action_Start->setEnabled(true);
		ui.action_Setting->setEnabled(false);
		ui.action_Recipe->setEnabled(false);
		ui.action_admin->setEnabled(true);
	}


}

void CMainWindow::setActionEnable(bool bok)
{
	ui.action_Start->setEnabled(bok);
	ui.action_Setting->setEnabled(bok);
	ui.action_Recipe->setEnabled(bok);
}

void CMainWindow::ReceiveCameraStatus(e_CameraType type, bool bOpen)
{
    switch (type)
    {
        case CAMERA_FIRST:
            m_Camera1.setStyleSheet(bOpen ? m_green_SheetStyle : m_red_SheetStyle);
            break;
        case CAMERA_SECOND:
            m_Camera2.setStyleSheet(bOpen ? m_green_SheetStyle : m_red_SheetStyle);
            break;
        case CAMERA_THIRD:
            m_Camera3.setStyleSheet(bOpen ? m_green_SheetStyle : m_red_SheetStyle);
            break;
        case CAMERA_FOURTH:
            m_Camera4.setStyleSheet(bOpen ? m_green_SheetStyle : m_red_SheetStyle);
            break;
    }
}

void CMainWindow::ReceivePLCStatus(bool bConnected)
{
    m_PLC.setStyleSheet(bConnected ? m_green_SheetStyle : m_red_SheetStyle);
}

QImage CMainWindow::MattoQImage(Mat image)
{
    switch (image.type())
    {
        case CV_8UC1:
        {
            QImage img((const unsigned char *)(image.data), image.cols, image.rows, image.cols,
                       QImage::Format_Grayscale8);
            return img;
        }
        break;
        case CV_8UC3:
        {
            QImage img((const unsigned char *)(image.data), image.cols, image.rows, image.cols * 3,
                       QImage::Format_RGB888);
            return img.rgbSwapped();
        }
        break;
        default:
        {
            QImage img;
            return img;
        }
        break;
    }
}

void CMainWindow::ReceiveAlgoImage(Mat image, Mat RenderImage, int index, bool bOK, e_CameraType type)
{
    bOK = 1;
    qDebug() << "ReceiveImage type:" << type;
	QString Msg = "Receive algo image: type = " + QString::number(type) + ",result = "+QString::number(bOK) + "Index ="+QString::number(index);
	AddLog(Msg);
    QImage QImg = MattoQImage(image);
	s_SaveImageInfo SaveInfo;
	s_StationInfo StationInfo;
	StationInfo.OriginalImage = image;
	StationInfo.RenderImage = RenderImage;
	StationInfo.bok = bOK;
    switch (type)
    {
        case CAMERA_FIRST:
        {	
            m_Camera1Images.push_back(QImg);
            if (m_Camera1Images.size() > m_ImageCounts)
                return;
            ui.label_Image1->setPixmap(QPixmap::fromImage(
                QImg.scaled(ui.label_Image1->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation)));
            QLabel *Label = m_Camera1Results.at(index);
            if (Label == NULL)
            {
                qDebug() << "Camera1 Label is NULL,index = " << index;
                return;
            }
            if (bOK)
            {
                Label->setStyleSheet(m_green_SheetStyle);
            }
            else
            {
                Label->setStyleSheet("background-color: rgba(170, 0, 0, 255);");
                m_Camera1Result = false;
            }

			if (index == m_ImageCounts-1)
			{
				QString Msg = "Receive algo image: type = " + QString::number(type) + ",result = " + QString::number(index) ;
				AddLog(Msg);
				m_Index = 0;
				m_DetecionResult.insert(CAMERA_FIRST, m_Camera1Result);
				if (m_DetecionResult.size() == 4)
				{
					ProcessDetectionResult();
					m_DetecionResult.clear();
				}
			}
			SaveInfo.FirstStation = StationInfo;	
			m_Index++;
            break;
        }
        case CAMERA_SECOND:
        {
            m_Camera2Images.push_back(QImg);
			if (m_Camera2Images.size() > m_ImageCounts)
				return;
            ui.label_Image2->setPixmap(QPixmap::fromImage(
                QImg.scaled(ui.label_Image2->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation)));
            QLabel *Label = m_Camera2Results.at(index);
            if (Label == NULL)
            {
                qDebug() << "Camera1 Label is NULL,index = " << index;
                return;
            }
            if (bOK)
            {
                Label->setStyleSheet(m_green_SheetStyle);
            }
            else
            {
                Label->setStyleSheet("background-color: rgba(170, 0, 0, 255);");
                m_Camera2Result = false;
            }
            if (index == m_ImageCounts-1)
            {
				QString Msg = "Receive algo image: type = " + QString::number(type) + ",result = " + QString::number(index);
				AddLog(Msg);
				m_Index = 0;
                m_DetecionResult.insert(CAMERA_SECOND, m_Camera2Result);
                if (m_DetecionResult.size() == 4)
                {
                    ProcessDetectionResult();
					m_DetecionResult.clear();
                }
            }
			SaveInfo.SecondStation = StationInfo;
			m_Index++;
            break;
        }
        case CAMERA_THIRD:
        {
            m_Camera3Images.push_back(QImg);
			if (m_Camera3Images.size() > m_ImageCounts)
				return;
            ui.label_Image3->setPixmap(QPixmap::fromImage(
                QImg.scaled(ui.label_Image3->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation)));
            QLabel *Label = m_Camera3Results.at(index);
            if (Label == NULL)
            {
                qDebug() << "Camera3 Label is NULL,index = " << index;
                return;
            }
            if (bOK)
            {
                Label->setStyleSheet(m_green_SheetStyle);
            }
            else
            {
                Label->setStyleSheet("background-color: rgba(170, 0, 0, 255);");
            }

            if (index == m_ImageCounts-1)
            {
				QString Msg = "Receive algo image: type = " + QString::number(type) + ",result = " + QString::number(index);
				AddLog(Msg);
				m_Index = 0;
                m_DetecionResult.insert(CAMERA_THIRD, m_Camera3Result);
                if (m_DetecionResult.size() == 4)
                {
                    ProcessDetectionResult();
					m_DetecionResult.clear();
                }
            }
			SaveInfo.ThirdStation = StationInfo;
			m_Index++;
            break;
        }
        case CAMERA_FOURTH:
        {
            m_Camera4Images.push_back(QImg);
			if (m_Camera4Images.size() > m_ImageCounts)
				return;
            ui.label_Image4->setPixmap(QPixmap::fromImage(
                QImg.scaled(ui.label_Image4->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation)));
            QLabel *Label = m_Camera4Results.at(index);
            if (Label == NULL)
            {
                qDebug() << "Camera4 Label is NULL,index = " << index;
                return;
            }
            if (bOK)
            {
                Label->setStyleSheet(m_green_SheetStyle);
            }
            else
            {
                Label->setStyleSheet("background-color: rgba(170, 0, 0, 255);");
            }

            if (index == m_ImageCounts-1)
            {
				QString Msg = "Receive algo image: type = " + QString::number(type) + ",result = " + QString::number(index);
				AddLog(Msg);
				m_Index = 0;
                m_DetecionResult.insert(CAMERA_FOURTH, m_Camera4Result);
                if (m_DetecionResult.size() == 4)
                {
                    ProcessDetectionResult();
					m_DetecionResult.clear();
                }
            }
			SaveInfo.FourStation = StationInfo;
			m_Index++;
     	break;
        }
        break;
        default:;
    }
	m_Parameter->SaveImage(SaveInfo);
}

void CMainWindow::ReceiveInitImageNumber(int number)
{
	m_ImageCounts = number;
}

void CMainWindow::ReceiveStartSign()
{
	QString Msg = "Init Start ";
	AddLog(Msg);
	 Msg = "Init End ";
	AddLog(Msg);
	RefreshResultDetails();
	m_Parameter->GetCameraInfo();
	if (!CPLCManager::GetInstance()->WritePLCStartSign())
	{
		Msg = "Write PLC Start Sign Failed ";
		AddLog(Msg);
		return;
	}
	Msg = "Init Success ";
	AddLog(Msg);
}



void CMainWindow::ProcessDetectionResult()
{
#if 1
	QString Msg;
	bool bok = true;
	//   QMap<e_CameraType, bool>::iterator it = m_DetecionResult.begin(), itEnd = m_DetecionResult.end();
	   //it = m_DetecionResult.find(CAMERA_FIRST);
	   //bok &= it.value();

	auto CameraLocalResult = [&](e_CameraType camera, QLabel* label, bool bok)
	{
		QMap<e_CameraType, bool>::iterator it = m_DetecionResult.find(camera);

		bok &= it.value();
		if (bok == true)
		{
			Msg = Msg + "01";
		}
		else
		{
			Msg = Msg + "10";
		}
		if (bok)
		{

			label->setStyleSheet("color: rgb(0, 170, 0);background-color: rgb(255, 255, 150);");
			label->setText("OK");
			m_Statistics->SetSuccess();
		}
		else
		{
			label->setStyleSheet("color: rgb(170, 0, 0);background-color: rgb(255, 255, 150);");
			label->setText("NG");
			m_Statistics->SetFailed();
		}
	};

	CameraLocalResult(CAMERA_FIRST, m_FirstResult, bok);
	CameraLocalResult(CAMERA_SECOND, m_SecondResult, bok);
	CameraLocalResult(CAMERA_THIRD, m_ThirdResult, bok);
	CameraLocalResult(CAMERA_FOURTH, m_FourthResult, bok);
#else
	QString Msg;
	bool bok = true;
	QMap<e_CameraType, bool>::iterator it = m_DetecionResult.begin(), itEnd = m_DetecionResult.end();
	it = m_DetecionResult.find(CAMERA_FIRST);
	bok &= it.value();
	for (; it != itEnd; ++it)
	{

		bok &= it.value();
		if (bok == true)
		{
			Msg = Msg + "01";
		}
		else
		{
			Msg = Msg + "10";
		}
	}

	if (bok)
	{
		m_TotalResult->setStyleSheet("color: rgb(0, 170, 0);background-color: rgb(255, 255, 150);");
		m_TotalResult->setText("OK");
		m_Statistics->SetSuccess();
	}
	else
	{
		m_TotalResult->setStyleSheet("color: rgb(170, 0, 0);background-color: rgb(255, 255, 150);");
		m_TotalResult->setText("NG");
		m_Statistics->SetFailed();
	}
#endif
	// TODO PLC????????

	//AddLog(QString::fromLocal8Bit("????????????:") + Msg);
	AddLog(QString::fromLocal8Bit("????????:") + QString::number(bok));


 //   QString Msg;
 //   bool bok = true;
 //   QMap<e_CameraType, bool>::iterator it = m_DetecionResult.begin(), itEnd = m_DetecionResult.end();
 //   for (; it != itEnd; ++it)
 //   {
 //       bok &= it.value();
	//	if (bok == true)
	//	{
	//		Msg = Msg+"01";
	//	}
	//	else
	//	{
	//		Msg = Msg + "10";
	//	}
 //   }
 //   if (bok)
 //   {
 //       m_TotalResult->setStyleSheet("color: rgb(0, 170, 0);background-color: rgb(255, 255, 150);");
 //       m_TotalResult->setText("OK");
 //       m_Statistics->SetSuccess();
 //   }
 //   else
 //   {
 //       m_TotalResult->setStyleSheet("color: rgb(170, 0, 0);background-color: rgb(255, 255, 150);");
 //       m_TotalResult->setText("NG");
 //       m_Statistics->SetFailed();
 //   }
 //   // TODO PLC????????
	//SendPLCResult(Msg, bok);
	//qDebug() << "CMainWindow::ProcessDetectionResult()" << "Msg = " << Msg << ", bok" << bok;
	////AddLog(QString::fromLocal8Bit("????????????:") + Msg);
	//AddLog(QString::fromLocal8Bit("????????:") + QString::number(bok));

}

