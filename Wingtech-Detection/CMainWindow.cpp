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
    ui.setupUi(this);
    qInstallMessageHandler(outputMessage);
    InitVariables();

	m_ImageCounts = 5;//测试用，实际会由PLC发送数据得到
	m_Index = 0;      //发往窗口的图片数据统计

    InitResultDetails(m_ImageCounts);
    InitStatusBar();
    InitConnections();
	
}

void CMainWindow::InitVariables()
{
    //处理结果 OK/NG
    QFont LabelFont("微软雅黑", 142);
    m_TotalResult = new QLabel("OK");
    // m_ResultLabel->setFont(LabelFont);
    m_TotalResult->setStyleSheet(
        "color: rgb(0, 170, 0);background-color: rgb(255, 255, 150);font: 142pt \"微软雅黑\";");
    m_TotalResult->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

    //检测最终结果
    QDockWidget *DockResult = new QDockWidget(QString::fromLocal8Bit("检测结果"));
    DockResult->setFeatures(QDockWidget::DockWidgetMovable | QDockWidget::DockWidgetFloatable);
    addDockWidget(Qt::RightDockWidgetArea, DockResult);
    DockResult->setWidget(m_TotalResult);

    //数据统计
    m_Statistics = new StatisticsWidget();
    QDockWidget *DockStatistics = new QDockWidget(QString::fromLocal8Bit("数据统计"));
    DockStatistics->setFeatures(QDockWidget::DockWidgetMovable | QDockWidget::DockWidgetFloatable);
    addDockWidget(Qt::RightDockWidgetArea, DockStatistics);
    DockStatistics->setWidget(m_Statistics);

    //日志
    m_ListView = new QListView();
    m_LogModel = new QStandardItemModel();
    QFont font("微软雅黑", 12);
    m_ListView->setFont(font);
    m_LogModel = new QStandardItemModel();
    m_ListView->setModel(m_LogModel);
    QDockWidget *LogDock = new QDockWidget(QString::fromLocal8Bit("日志"));
    LogDock->setFeatures(QDockWidget::DockWidgetMovable | QDockWidget::DockWidgetFloatable);
    addDockWidget(Qt::RightDockWidgetArea, LogDock);
    LogDock->setWidget(m_ListView);

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
}

//收到PLC切换配方指令，根据配方中图像数量初始化结果细节
//每行10个图像状态
void CMainWindow::InitResultDetails(int ImageCounts)
{
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

//收到PLC开始信号后，刷新状态
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
    label = new QLabel(QString::fromLocal8Bit("相机1:"));
    ui.statusBar->addWidget(label);

    m_Camera2.setStyleSheet(m_yellow_SheetStyle);
    ui.statusBar->addWidget(&m_Camera2);
    label = new QLabel(QString::fromLocal8Bit("相机2:"));
    ui.statusBar->addWidget(label);

    m_Camera3.setStyleSheet(m_yellow_SheetStyle);
    ui.statusBar->addWidget(&m_Camera3);
    label = new QLabel(QString::fromLocal8Bit("相机3:"));
    ui.statusBar->addWidget(label);

    m_Camera4.setStyleSheet(m_yellow_SheetStyle);
    ui.statusBar->addWidget(&m_Camera4);
    label = new QLabel(QString::fromLocal8Bit("相机4:"));
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
    connect(m_Parameter, SIGNAL(SendOriginalImage(Mat, int, e_CameraType)), m_RecipeManager, SLOT(ReceivaOriginalImage(Mat, int, e_CameraType)));
	connect(m_RecipeManager, SIGNAL(SendInitImageNumber(int)), this, SLOT(ReceiveInitImageNumber(int)));
	connect(m_RecipeManager, SIGNAL(SendAlgoImage(Mat, Mat, int , bool , e_CameraType )), this, SLOT(ReceiveAlgoImage(Mat, Mat, int, bool, e_CameraType)));
	connect(m_RecipeManager, SIGNAL(SendStartSign()), this, SLOT(ReceiveStartSign()));



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
	m_RecipeManager->SendPLCReadySign();
	ui.action_Start->setEnabled(false);
	ui.action_Stop->setEnabled(true);
	ui.action_Setting->setEnabled(false);
    m_Parameter->StartDetecion(true);
    m_bStart = true;
    // TODO 检查程序状态，PLC，相机连接状态
}

void CMainWindow::StopDection() 
{
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
	m_admin->exec();
	int adminctrl = m_admin->adminctrl;
	if (adminctrl == 1)
	{
		setActionEnable(true);
	}
	else if(adminctrl == 2)
	{
		ui.action_Start->setEnabled(true);
		ui.action_Setting->setEnabled(false);
		ui.action_Recipe->setEnabled(false);
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
            if (m_Camera1Images.size() > 5)
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

			if (m_Index == m_ImageCounts-1)
			{
				m_Index = 0;
				m_DetecionResult.insert(CAMERA_FIRST, m_Camera1Result);
				if (m_DetecionResult.size() == 4)
				{
					ProcessDetectionResult();
				}
			}
			SaveInfo.FirstStation = StationInfo;	
			m_Index++;
            break;
        }
        case CAMERA_SECOND:
        {
            m_Camera2Images.push_back(QImg);
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
            if (m_Index == m_ImageCounts-1)
            {
				m_Index = 0;
                m_DetecionResult.insert(CAMERA_SECOND, m_Camera2Result);
                if (m_DetecionResult.size() == 4)
                {
                    ProcessDetectionResult();
                }
            }
			SaveInfo.SecondStation = StationInfo;
			m_Index++;
            break;
        }
        case CAMERA_THIRD:
        {
            m_Camera3Images.push_back(QImg);
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

            if (m_Index == m_ImageCounts-1)
            {
				m_Index = 0;
                m_DetecionResult.insert(CAMERA_THIRD, m_Camera3Result);
                if (m_DetecionResult.size() == 4)
                {
                    ProcessDetectionResult();
                }
            }
			SaveInfo.ThirdStation = StationInfo;
			m_Index++;
            break;
        }
        case CAMERA_FOURTH:
        {
            m_Camera4Images.push_back(QImg);
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

            if (m_Index == m_ImageCounts-1)
            {
				m_Index = 0;
                m_DetecionResult.insert(CAMERA_FOURTH, m_Camera4Result);
                if (m_DetecionResult.size() == 4)
                {
                    ProcessDetectionResult();
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
	RefreshResultDetails();
}



void CMainWindow::ProcessDetectionResult()
{
    QString Msg;
    bool bok = true;
    QMap<e_CameraType, bool>::iterator it = m_DetecionResult.begin(), itEnd = m_DetecionResult.end();
    for (; it != itEnd; ++it)
    {
        bok &= it.value();
		if (bok == true)
		{
			Msg = Msg+"01";
		}
		else
		{
			Msg = Msg + "10";
		}
    }
    bool rv = true;
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
    // TODO PLC发送信号
    if (!rv)
    {
        AddLog(QString::fromLocal8Bit("发送结果失败:") + Msg);
    }
    else
    {
        AddLog(QString::fromLocal8Bit("发送结果:") + QString::number(bok));
    }
}

