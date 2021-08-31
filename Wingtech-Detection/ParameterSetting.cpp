#include "ParameterSetting.h"
#include "QMessageBox"
CParameterSetting::CParameterSetting(QDialog *parent /*= NULL*/)
	:QDialog(parent)
{
	ui.setupUi(this);
	InitVariables();
	InitConnections();
	InitCamera();
	LoadConfig();
	LoadModelConfig();
}

CParameterSetting::~CParameterSetting()
{
	qDebug() << "~CParameterSetting";
	m_FirstCameraInfo.ImageCapture->StopThread();
	m_FirstCameraInfo.ImageCapture->wait(1000);
	if (m_FirstCameraInfo.bOpenCamera)
	{
		CloseDevice(1);
	}

	m_SecondCameraInfo.ImageCapture->StopThread();
	m_SecondCameraInfo.ImageCapture->wait(1000);
	if (m_SecondCameraInfo.bOpenCamera)
	{
		CloseDevice(2);
	}

	m_ThirdCameraInfo.ImageCapture->StopThread();
	m_ThirdCameraInfo.ImageCapture->wait(1000);
	if (m_ThirdCameraInfo.bOpenCamera)
	{
		CloseDevice(3);
	}

	m_FourCameraInfo.ImageCapture->StopThread();
	m_FourCameraInfo.ImageCapture->wait(1000);
	if (m_FourCameraInfo.bOpenCamera)
	{
		CloseDevice(4);
	}
	m_SaveImage.StopThread();
	m_SaveImage.wait(1000);


	qDebug() << "~CParameterSetting";
}

void CParameterSetting::InitVariables()
{
	//初始化
	m_FirstCameraInfo.Init();
	m_SecondCameraInfo.Init();
	m_ThirdCameraInfo.Init();
	m_FourCameraInfo.Init();

	//开启线程
	m_FirstCameraInfo.ImageCapture->start();
	m_SecondCameraInfo.ImageCapture->start();
	m_ThirdCameraInfo.ImageCapture->start();
	m_FourCameraInfo.ImageCapture->start();

	//m_FirstAlgo.Init();
	//m_FirstAlgo.Algo->start();

	InitFirstGroup();
	InitSecondGroup();
	InitThirdtGroup();
	InitFourthGroup();


	QString errMsg;
	//m_bFirstAlgoSuccess = CAlgoFirstStation::GetInstance()->InitAlgo(errMsg); //初始化模型
	QRegExp reg("\\b(?:(?:25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\.){3}(?:25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\b");
	ui.comboBox_SystemType->addItem(QString::fromLocal8Bit("在线运行"));
	ui.comboBox_SystemType->addItem(QString::fromLocal8Bit("相机调试"));
	ui.comboBox_SystemType->addItem(QString::fromLocal8Bit("在线Debug算法"));
	ui.comboBox_SystemType->addItem(QString::fromLocal8Bit("离线Debug算法"));
	
	m_FirstCameraInfo.ImageCapture->SetSystemType(RUN_ONLINE);
	m_SecondCameraInfo.ImageCapture->SetSystemType(RUN_ONLINE);
	m_ThirdCameraInfo.ImageCapture->SetSystemType(RUN_ONLINE);
	m_FourCameraInfo.ImageCapture->SetSystemType(RUN_ONLINE);

	m_FirstCameraInfo.ImageCapture->SetCameraType(CAMERA_FIRST);
	m_SecondCameraInfo.ImageCapture->SetCameraType(CAMERA_SECOND);
	m_ThirdCameraInfo.ImageCapture->SetCameraType(CAMERA_THIRD);
	m_FourCameraInfo.ImageCapture->SetCameraType(CAMERA_FOURTH);
	ui.lineEdit_IP->setValidator(new QRegExpValidator(reg));

	//开启存图线程
	m_SaveImage.start();
}
void CParameterSetting::InitTableWidget()
{
	QFont font("微软雅黑", 12);
	m_ModelChoice.setSelectionBehavior(QAbstractItemView::SelectRows);                                                   //设置选择行为时每次选择一行
	m_ModelChoice.setEditTriggers(QAbstractItemView::CurrentChanged);                                                    //设置不可编辑
	m_ModelChoice.horizontalHeader()->setDefaultAlignment(Qt::AlignHCenter);
	m_ModelChoice.horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
	m_ModelChoice.horizontalHeader()->setFont(font);                                                                     //设置字体
	m_ModelChoice.horizontalHeader()->setHighlightSections(false);                                                       //获取焦点
	m_ModelChoice.verticalHeader()->setHidden(true);
	m_ModelChoice.horizontalHeader()->setStyleSheet("QHeaderView::section{color:rgb(255,255,255);background:rgb(41,136,41);}"); //设置选中背景色
	m_ModelChoice.setColumnCount(3);
	m_ModelChoice.setRowCount(vtModelName.size());
	// 	m_BoxTab.horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);
	// 	m_BoxTab.horizontalHeader()->setSectionResizeMode(1, QHeaderView::ResizeToContents);
	QStringList Firstheader;
	Firstheader << QString::fromLocal8Bit("  图片ID  ") << QString::fromLocal8Bit("  模型  ") << QString::fromLocal8Bit("  选择  ");
	m_ModelChoice.setHorizontalHeaderLabels(Firstheader);                                                                     //设置表头内容

	//QDockWidget *FirstResult = new QDockWidget(QString::fromLocal8Bit("工位一"));
	//FirstResult->setMinimumWidth(200);
	//FirstResult->setFeatures(QDockWidget::DockWidgetMovable | QDockWidget::DockWidgetFloatable);
	//addDockWidget(Qt::RightDockWidgetArea, FirstResult);
	//FirstResult->setWidget(&m_ModelChoice);

	for (int n = 0; n < vtModelName.size(); n++)
	{
		pBtn = new QPushButton(QString::fromLocal8Bit("选择模型"), this);
		btnPushlist.append(pBtn);
		connect(btnPushlist.at(n), SIGNAL(clicked()), this, SLOT(OnBtnClicked()));
		m_ModelChoice.setCellWidget(n, 2, btnPushlist[n]);
		m_ModelChoice.setItem(n, 0, new QTableWidgetItem(QString::number(n+1)));
		m_ModelChoice.setItem(n, 1, new QTableWidgetItem(vtModelName[0]));
	
	}
	m_ModelChoice.show();
}
//初始化触发模式
void CParameterSetting::InitFirstGroup()
{
	m_FirstGroup = new QButtonGroup();
	m_FirstGroup->addButton(ui.radioButton_FreeFirst, 1);
	m_FirstGroup->addButton(ui.radioButton_ExternalFirst, 2);
	m_FirstGroup->addButton(ui.radioButton_SoftFirst, 3);
	SetButtonGroupEnabled(false, 1);

}

void CParameterSetting::InitSecondGroup()
{
	m_SecondGroup = new QButtonGroup();
	m_SecondGroup->addButton(ui.radioButton_FreeSecond, 1);
	m_SecondGroup->addButton(ui.radioButton_ExternalSecond, 2);
	m_SecondGroup->addButton(ui.radioButton_SoftSecond, 3);
	SetButtonGroupEnabled(false, 2);

}

void CParameterSetting::InitThirdtGroup()
{
	m_ThirdGroup = new QButtonGroup();
	m_ThirdGroup->addButton(ui.radioButton_FreeThird, 1);
	m_ThirdGroup->addButton(ui.radioButton_ExternalThird, 2);
	m_ThirdGroup->addButton(ui.radioButton_SoftThird, 3);
	SetButtonGroupEnabled(false, 3);

}

void CParameterSetting::InitFourthGroup()
{
	m_FourthGroup = new QButtonGroup();
	m_FourthGroup->addButton(ui.radioButton_FreeFourth, 1);
	m_FourthGroup->addButton(ui.radioButton_ExternalFourth, 2);
	m_FourthGroup->addButton(ui.radioButton_SoftFourth, 3);
	SetButtonGroupEnabled(false, 4);

}

//保存图片
void CParameterSetting::SaveImage(s_SaveImageInfo ImageInfo)
{
	QString CurTime = QDateTime::currentDateTime().toString("yyyy-MM-dd_hh-mm-ss-zzz");
	auto image_info = [&](s_StationInfo ImageInfo, const QString &curTime, const QString &path, bool bok,int index)
	{
		if (path.isEmpty())
		{
			qDebug() << "path is empty" << path;
			return;
		}
		QString CurPath = path + "/" + curTime;
		QDir dir;
		if (!dir.exists(CurPath))
		{
			dir.mkpath(CurPath);
		}
		if (!bok)
		{
			QString OriginalImageName = CurPath + "/" + QString::number(index) + "_O.jpg";
			QString RenderImageName = CurPath + "/" + QString::number(index) + "/_R.jpg";
			m_SaveImage.SaveImage(OriginalImageName, ImageInfo.OriginalImage);
			m_SaveImage.SaveImage(RenderImageName, ImageInfo.RenderImage);
		}
	};

	image_info(ImageInfo.FirstStation, CurTime, ui.lineEdit_NGPath_First->text(), ImageInfo.FirstStation.bok,1);
	image_info(ImageInfo.FirstStation, CurTime, ui.lineEdit_OKPath_First->text(), ImageInfo.FirstStation.bok,1);

	image_info(ImageInfo.SecondStation, CurTime, ui.lineEdit_NGPath_Second->text(), ImageInfo.SecondStation.bok,2);
	image_info(ImageInfo.SecondStation, CurTime, ui.lineEdit_NGPath_Second->text(), ImageInfo.SecondStation.bok,2);

	image_info(ImageInfo.ThirdStation, CurTime, ui.lineEdit_NGPath_Third->text(), ImageInfo.ThirdStation.bok,3);
	image_info(ImageInfo.ThirdStation, CurTime, ui.lineEdit_OKPath_Third->text(), ImageInfo.ThirdStation.bok,3);

	image_info(ImageInfo.FourStation, CurTime, ui.lineEdit_NGPath_Fourth->text(), ImageInfo.FourStation.bok,4);
	image_info(ImageInfo.FourStation, CurTime, ui.lineEdit_NGPath_Fourth->text(), ImageInfo.FourStation.bok,4);

	//if (ui.checkBox_SaveNG_First->isChecked())
	//{
	//	QString NGPath = ui.lineEdit_NGPath_First->text();
	//	if (NGPath.isEmpty())
	//	{
	//		qDebug() << "NG path is empty";
	//		return;
	//	}
	//	QString CurPath = NGPath + "/" + CurTime;
	//	QDir dir;
	//	if (!dir.exists(CurPath))
	//	{
	//		dir.mkpath(CurPath);
	//	}
	//	if (!ImageInfo.FirstStation.bok)
	//	{
	//		QString OriginalImageName = CurPath + "/1_O.jpg";
	//		QString RenderImageName = CurPath + "/1_R.jpg";
	//		m_SaveImage.SaveImage(OriginalImageName, ImageInfo.FirstStation.OriginalImage);
	//		m_SaveImage.SaveImage(RenderImageName, ImageInfo.FirstStation.RenderImage);
	//	}

	//	//if (!ImageInfo.SecondStation.bok)
	//	//{
	//	//	QString OriginalImageName = CurPath + "/2_O.jpg";
	//	//	QString RenderImageName = CurPath + "/2_R.jpg";
	//	//	m_SaveImage.SaveImage(OriginalImageName, ImageInfo.SecondStation.OriginalImage);
	//	//	m_SaveImage.SaveImage(RenderImageName, ImageInfo.SecondStation.RenderImage);
	//	//}
	//}

	//if (ui.checkBox_SaveOK_First->isChecked())
	//{
	//	QString OKPath = ui.lineEdit_OKPath_First->text();
	//	if (OKPath.isEmpty())
	//	{
	//		qDebug() << "OK path is empty";
	//		return;
	//	}
	//	QString CurPath = OKPath + "/" + CurTime;
	//	QDir dir;
	//	if (!dir.exists(CurPath))
	//	{
	//		dir.mkpath(CurPath);
	//	}
	//	if (ImageInfo.FirstStation.bok)
	//	{
	//		QString ImageName = CurPath + "/1_O.jpg";
	//		m_SaveImage.SaveImage(ImageName, ImageInfo.FirstStation.OriginalImage);
	//	}
	//	//if (ImageInfo.SecondStation.bok)
	//	//{
	//	//	QString ImageName = CurPath + "/2_O.jpg";
	//	//	m_SaveImage.SaveImage(ImageName, ImageInfo.SecondStation.OriginalImage);
	//	//}
	//}
}

//关闭设备
bool CParameterSetting::CloseDevice(int index)
{
	if (1 == index)
	{
		m_FirstCameraInfo.ImageCapture->SetCameraStatus(false);
		int nRet = m_FirstCameraInfo.CameraHandle.StopGrabbing();
		if (nRet != MV_OK)
		{
			QMessageBox::information(this, QString::fromLocal8Bit("错误"), "Frist Camera StopGrabbing failed:" + QString::number(nRet));
			return false;
		}
		nRet = m_FirstCameraInfo.CameraHandle.Close();
		if (nRet == MV_OK)
		{
			m_FirstCameraInfo.bOpenCamera = false;
			return true;
		}
		else
		{
			QMessageBox::information(this, QString::fromLocal8Bit("错误"), "close first device failed:" + QString::number(nRet));
			return false;
		}
	}
	else if (2 == index)
	{
		m_SecondCameraInfo.ImageCapture->SetCameraStatus(false);
		int nRet = m_SecondCameraInfo.CameraHandle.StopGrabbing();
		if (nRet != MV_OK)
		{
			QMessageBox::information(this, QString::fromLocal8Bit("错误"), "Frist Camera StopGrabbing failed:" + QString::number(nRet));
			return false;
		}
		nRet = m_SecondCameraInfo.CameraHandle.Close();
		if (nRet == MV_OK)
		{
			m_SecondCameraInfo.bOpenCamera = false;
			return true;
		}
		else
		{
			QMessageBox::information(this, QString::fromLocal8Bit("错误"), "close first device failed:" + QString::number(nRet));
			return false;
		}
	}
	else if (3 == index)
	{
		m_ThirdCameraInfo.ImageCapture->SetCameraStatus(false);
		int nRet = m_ThirdCameraInfo.CameraHandle.StopGrabbing();
		if (nRet != MV_OK)
		{
			QMessageBox::information(this, QString::fromLocal8Bit("错误"), "Frist Camera StopGrabbing failed:" + QString::number(nRet));
			return false;
		}
		nRet = m_ThirdCameraInfo.CameraHandle.Close();
		if (nRet == MV_OK)
		{
			m_ThirdCameraInfo.bOpenCamera = false;
			return true;
		}
		else
		{
			QMessageBox::information(this, QString::fromLocal8Bit("错误"), "close first device failed:" + QString::number(nRet));
			return false;
		}
	}
	else if (4 == index)
	{
		m_FourCameraInfo.ImageCapture->SetCameraStatus(false);
		int nRet = m_FourCameraInfo.CameraHandle.StopGrabbing();
		if (nRet != MV_OK)
		{
			QMessageBox::information(this, QString::fromLocal8Bit("错误"), "Frist Camera StopGrabbing failed:" + QString::number(nRet));
			return false;
		}
		nRet = m_FourCameraInfo.CameraHandle.Close();
		if (nRet == MV_OK)
		{
			m_FourCameraInfo.bOpenCamera = false;
			return true;
		}
		else
		{
			QMessageBox::information(this, QString::fromLocal8Bit("错误"), "close first device failed:" + QString::number(nRet));
			return false;
		}
	}

}

void CParameterSetting::InitConnections()
{
	qRegisterMetaType<Mat>("Mat");
	qRegisterMetaType<e_CameraType>("e_CameraType");
	//connect(m_FirstCameraInfo.ImageCapture, SIGNAL(SendAlgoImage(Mat, e_CameraType,int,bool)), this, SLOT(ReceivaAlgoImage( Mat, e_CameraType,int,bool)));
	connect(m_FirstGroup, SIGNAL(buttonToggled(int, bool)), this, SLOT(SwitchFirstCameraStatus(int, bool)));
	//connect(m_SecondCameraInfo.ImageCapture, SIGNAL(SendAlgoImage(Mat, e_CameraType, int, bool)), this, SLOT(ReceivaAlgoImage(Mat, e_CameraType, int, bool)));
	connect(m_SecondGroup, SIGNAL(buttonToggled(int, bool)), this, SLOT(SwitchSecondCameraStatus(int, bool)));
    //connect(m_FirstCameraInfo.ImageCapture, SIGNAL(SendImageToAlgo(Mat, e_CameraType, int, bool)), m_FirstAlgo.Algo, SLOT(ReceivaReImage(Mat, e_CameraType, int, bool)));
	//connect(m_FirstAlgo.Algo, SIGNAL(SendAlgoImageToParam(Mat, e_CameraType, int, bool)), this, SLOT(ReceivaAlgoImage(Mat, e_CameraType, int, bool)));
	//connect(m_FirstAlgo.Algo, SIGNAL(SendImageToAlgo(Mat, e_CameraType, int, bool)), m_FirstAlgo.Algo, SLOT(ReceivaAlgoImage(Mat, e_CameraType, int, bool)));

	connect(m_ThirdGroup, SIGNAL(buttonToggled(int, bool)), this, SLOT(SwitchThirdCameraStatus(int, bool)));
	connect(m_FourthGroup, SIGNAL(buttonToggled(int, bool)), this, SLOT(SwitchFourthCameraStatus(int, bool)));

	connect(m_FirstCameraInfo.ImageCapture, SIGNAL(SendCameraImage(Mat, int)), this, SLOT(ReceiveCameraImage(Mat, int)));
	connect(m_SecondCameraInfo.ImageCapture, SIGNAL(SendCameraImage(Mat, int)), this, SLOT(ReceiveCameraImage(Mat, int)));
	connect(m_ThirdCameraInfo.ImageCapture, SIGNAL(SendCameraImage(Mat, int)), this, SLOT(ReceiveCameraImage(Mat, int)));
	connect(m_FourCameraInfo.ImageCapture, SIGNAL(SendCameraImage(Mat, int)), this, SLOT(ReceiveCameraImage(Mat, int)));

	connect(m_FirstCameraInfo.ImageCapture, SIGNAL(SendImageToAlgo(Mat, e_CameraType, int)), this, SLOT(ReceivaOriginalImage(Mat, e_CameraType, int)));

	connect(CPLCManager::GetInstance(), SIGNAL(SendConnectStatus(bool)), this, SLOT(ReceiveConnectStatus(bool)));
}

void CParameterSetting::InitCamera()
{
	qDebug() << "InitCameraInfos";
	printf("InitCameraInfos\n");
	memset(&m_stDevList, 0, sizeof(MV_CC_DEVICE_INFO_LIST));
	int nRet = CMvCamera::EnumDevices(MV_GIGE_DEVICE, &m_stDevList);
	if (MV_OK != nRet)
	{
		qDebug() << QString::fromLocal8Bit("枚举相机失败:") << nRet;
		printf("枚举相机失败\n");
		return;
	}
	ui.pushButton_OpenFirst->setEnabled(m_stDevList.nDeviceNum > 0);
	ui.pushButton_OpenSecond->setEnabled(m_stDevList.nDeviceNum > 0);
	ui.pushButton_OpenThird->setEnabled(m_stDevList.nDeviceNum > 0);
	ui.pushButton_OpenFourth->setEnabled(m_stDevList.nDeviceNum > 0);
	for (int i = 0; i < m_stDevList.nDeviceNum; ++i)
	{
		MV_CC_DEVICE_INFO* pDeviceInfo = m_stDevList.pDeviceInfo[i];
		char strUserName[256] = { 0 };
		sprintf_s(strUserName, "%s-%s_%s", pDeviceInfo->SpecialInfo.stGigEInfo.chUserDefinedName, pDeviceInfo->SpecialInfo.stGigEInfo.chModelName,
				  pDeviceInfo->SpecialInfo.stGigEInfo.chSerialNumber);
		QString UserName = QString::fromLocal8Bit(strUserName);
		ui.comboBox_First->addItem(UserName);
		ui.comboBox_Second->addItem(UserName);
		ui.comboBox_Third->addItem(UserName);
		ui.comboBox_Four->addItem(UserName);
		qDebug() << "CameraName;" << strUserName;
		printf("Find Camera:%s\n", strUserName);
	}
}

void CParameterSetting::LoadFirstImage() 
{
	//if (m_bFirstAlgoSuccess)
	if (1)
	{
		QString imagePath = QFileDialog::getOpenFileName(this, QString::fromLocal8Bit("图像文件"), "", "*.bmp;*.jpg;*.png;;All Files(*)");
		if (imagePath.isEmpty())
		{
			return;
		}
		qDebug() << "load first image:" << imagePath;
		QByteArray ba = imagePath.toLocal8Bit();
		char *file = ba.data();
		m_FirstOriginalImage = imread(file);
		vector<int>Threshold;
		m_FirstRenderImage.create(m_FirstOriginalImage.rows, m_FirstOriginalImage.cols, m_FirstOriginalImage.type());
		QImage qImage;
		if (ui.checkBox_RenderFirst->isChecked())
		{
			qImage = MattoQImage(m_FirstRenderImage);
		}
		else
		{
			qImage = MattoQImage(m_FirstOriginalImage);
		}
		QString style;
		//if (AlgoRunData.bOK)
		//{
		//	style = "image: url(:/CMainWindow/Resources/OK.svg);";
		//}
		//else
		//{
		//	style = "image: url(:/CMainWindow/Resources/NG.svg);";
		//}
		ui.label_FirstTime->setText(QString::fromLocal8Bit("耗时:") + QString::number(1) + "ms");
		ui.label_FirstResult->setStyleSheet(style);
		ui.label_FirstImage->SetImage(qImage);
	}
	else
	{
		QMessageBox::information(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("工位1算法模型未初始化成功"));
	}
}

void CParameterSetting::SwitchFirstCameraStatus(int index, bool checked)
{
	qDebug() << "SwitchFirstCameraStatus:" << index;

	if (checked)
	{
		ui.pushButton_TriggerFirst->setEnabled(false);
		switch (index)
		{
		case 1:
			m_FirstCameraInfo.CameraHandle.SetEnumValue("TriggerMode", MV_TRIGGER_MODE_OFF);
			break;
		case 2:
			m_FirstCameraInfo.CameraHandle.SetEnumValue("TriggerMode", MV_TRIGGER_MODE_ON);
			m_FirstCameraInfo.CameraHandle.SetEnumValue("TriggerSource", MV_TRIGGER_SOURCE_LINE0);
			break;
		case 3:
			m_FirstCameraInfo.CameraHandle.SetEnumValue("TriggerMode", MV_TRIGGER_MODE_ON);
			m_FirstCameraInfo.CameraHandle.SetEnumValue("TriggerSource", MV_TRIGGER_SOURCE_SOFTWARE);
			ui.pushButton_TriggerFirst->setEnabled(true);
			break;
		}
	}
}

void CParameterSetting::SwitchSecondCameraStatus(int index, bool checked)
{
	qDebug() << "SwitchSecondCameraStatus:" << index;

	if (checked)
	{
		ui.pushButton_TriggerSecond->setEnabled(false);
		switch (index)
		{
		case 1:
			m_SecondCameraInfo.CameraHandle.SetEnumValue("TriggerMode", MV_TRIGGER_MODE_OFF);
			break;
		case 2:
			m_SecondCameraInfo.CameraHandle.SetEnumValue("TriggerMode", MV_TRIGGER_MODE_ON);
			m_SecondCameraInfo.CameraHandle.SetEnumValue("TriggerSource", MV_TRIGGER_SOURCE_LINE0);
			break;
		case 3:
			m_SecondCameraInfo.CameraHandle.SetEnumValue("TriggerMode", MV_TRIGGER_MODE_ON);
			m_SecondCameraInfo.CameraHandle.SetEnumValue("TriggerSource", MV_TRIGGER_SOURCE_SOFTWARE);
			ui.pushButton_TriggerSecond->setEnabled(true);
			break;
		}
	}
}

void CParameterSetting::SaveCameraParams2()
{
	qDebug() << "参数设置buttonParamsSet2";
	update();
	bool bIsSetSucceed = true;
	int nRet = SetExposureTime(m_SecondCameraInfo.CameraHandle,2);
	if (nRet != MV_OK)
	{
		bIsSetSucceed = false;
		qDebug() << "Set Exposure Time Fail";
		ShowErrorMsg(("Set Exposure Time Fail"), nRet);
	}
	nRet = SetGain(m_SecondCameraInfo.CameraHandle,2);
	if (nRet != MV_OK)
	{
		bIsSetSucceed = false;
		qDebug() << "Set Gain Fail";
		ShowErrorMsg(("Set Gain Fail"), nRet);
	}

	if (true == bIsSetSucceed)
	{
		qDebug() << "Set Parameter Succeed";
		ShowErrorMsg(("Set Parameter Succeed"), nRet);
	}

	return;
}
void CParameterSetting::SwitchThirdCameraStatus(int index, bool checked)
{
	qDebug() << "SwitchThirdCameraStatus:" << index;
	printf("SwitchThirdCameraStatus:%d\n", index);
	if (checked)
	{
		ui.pushButton_TriggerThird->setEnabled(false);
		switch (index)
		{
		case 1:
			m_ThirdCameraInfo.CameraHandle.SetEnumValue("TriggerMode", MV_TRIGGER_MODE_OFF);
			break;
		case 2:
			m_ThirdCameraInfo.CameraHandle.SetEnumValue("TriggerMode", MV_TRIGGER_MODE_ON);
			m_ThirdCameraInfo.CameraHandle.SetEnumValue("TriggerSource", MV_TRIGGER_SOURCE_LINE0);
			break;
		case 3:
			m_ThirdCameraInfo.CameraHandle.SetEnumValue("TriggerMode", MV_TRIGGER_MODE_ON);
			m_ThirdCameraInfo.CameraHandle.SetEnumValue("TriggerSource", MV_TRIGGER_SOURCE_SOFTWARE);
			ui.pushButton_TriggerThird->setEnabled(true);
			break;
		}
	}
}

void CParameterSetting::SaveCameraParams3()
{
	qDebug() << "参数设置buttonParamsSet2";
	update();
	bool bIsSetSucceed = true;
	int nRet = SetExposureTime(m_ThirdCameraInfo.CameraHandle, 3);
	if (nRet != MV_OK)
	{
		bIsSetSucceed = false;
		qDebug() << "Set Exposure Time Fail";
		ShowErrorMsg(("Set Exposure Time Fail"), nRet);
	}
	nRet = SetGain(m_ThirdCameraInfo.CameraHandle, 3);
	if (nRet != MV_OK)
	{
		bIsSetSucceed = false;
		qDebug() << "Set Gain Fail";
		ShowErrorMsg(("Set Gain Fail"), nRet);
	}

	if (true == bIsSetSucceed)
	{
		qDebug() << "Set Parameter Succeed";
		ShowErrorMsg(("Set Parameter Succeed"), nRet);
	}

	return;
}

void CParameterSetting::SwitchFourthCameraStatus(int index, bool checked)
{
	qDebug() << "SwitchFourthCameraStatus:" << index;
	printf("SwitchFourthCameraStatus:%d\n", index);
	if (checked)
	{
		ui.pushButton_TriggerFourth->setEnabled(false);
		switch (index)
		{
		case 1:
			m_FourCameraInfo.CameraHandle.SetEnumValue("TriggerMode", MV_TRIGGER_MODE_OFF);
			break;
		case 2:
			m_FourCameraInfo.CameraHandle.SetEnumValue("TriggerMode", MV_TRIGGER_MODE_ON);
			m_FourCameraInfo.CameraHandle.SetEnumValue("TriggerSource", MV_TRIGGER_SOURCE_LINE0);
			break;
		case 3:
			m_FourCameraInfo.CameraHandle.SetEnumValue("TriggerMode", MV_TRIGGER_MODE_ON);
			m_FourCameraInfo.CameraHandle.SetEnumValue("TriggerSource", MV_TRIGGER_SOURCE_SOFTWARE);
			ui.pushButton_TriggerFourth->setEnabled(true);
			break;
		}
	}
}
void CParameterSetting::ReceiveConnectStatus(bool bConnected)
{
	QString style;
	if (bConnected)
	{
		style = "background-color: rgb(0, 170, 0);";
	}
	else
	{
		style = "background-color: rgb(170, 0, 0);";
	}
	ui.pushButton_SendOK->setEnabled(bConnected);
	ui.pushButton_SendNG->setEnabled(bConnected);
	ui.label_Status->setStyleSheet(style);
}
void CParameterSetting::ConnectToPLC()
{
	QString ip = ui.lineEdit_IP->text();
	QString port = ui.lineEdit_Port->text();
	int Heart = ui.spinBox_Heartbeat->value();
	if (ip.isEmpty())
	{
		QMessageBox::information(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("PLC地址不能为空"));
		return;
	}
	if (port.isEmpty())
	{
		QMessageBox::information(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("PLC端口不能为空"));
		return;
	}
	CPLCManager::GetInstance()->TcpConnect(ip, port.toUShort(), Heart);
}
void CParameterSetting::SendOKToPLC()
{
	CPLCManager::GetInstance()->WritePLCData(true);
}
void CParameterSetting::SendNGToPLC()
{
	CPLCManager::GetInstance()->WritePLCData(false);
}
void CParameterSetting::SetSystemType(int index)
{
	ui.pushButton_LoadFirstImage->setEnabled(false);
	ui.pushButton_LoadSecondImage->setEnabled(false);
	s_SystemType type;
	if (index == 0)
	{
		type = RUN_ONLINE;
	}
	else if (index == 1)
	{
		type = CAMEREA_TEST;
	}
	else if (index == 2)
	{
		type = ONLINE_ALGO_TEST;
	}
	else if (index == 3)
	{
		type = OFFLINE_ALGO_TEST;
		ui.pushButton_LoadFirstImage->setEnabled(true);
		ui.pushButton_LoadSecondImage->setEnabled(true);
		ui.pushButton_LoadThirdImage->setEnabled(true);
		ui.pushButton_LoadFourthImage->setEnabled(true);
	}
	m_FirstCameraInfo.ImageCapture->SetSystemType(type);
	m_SecondCameraInfo.ImageCapture->SetSystemType(type);
	m_ThirdCameraInfo.ImageCapture->SetSystemType(type);
	m_FourCameraInfo.ImageCapture->SetSystemType(type);
}
void CParameterSetting::GetFormula()
{
	QString ModelPath= QCoreApplication::applicationDirPath()+"/Model/"+ui.comboBox_Formula->currentText();
	QFileInfo info;
	if (info.exists(ModelPath))
	{
		CConfig *CfgFormula = new CConfig(ModelPath);
		int n = 0;
		while (1)
		{
			QString strIndex= "Index" + QString::number(n);
			QString ModelName = CfgFormula->GetString(MODEL, strIndex);
			if (ModelName.size() != 0)
			{
				vtModelName.push_back(ModelName);
				n++;
			}
			else
			{
				break;
			}
			
		}



		InitTableWidget();

	}
}

void CParameterSetting::ReceiveCameraImage(Mat image, int index)
{
	QImage qimage = MattoQImage(image);
	if (index == 1)
	{
		ui.label_FirstImage->SetImage(qimage);
	}
	else if (index == 2)
	{
		ui.label_SecondImage->SetImage(qimage);
	}
	else if (index == 3)
	{
		ui.label_ThirdImage->SetImage(qimage);
	}
	else if (index == 4)
	{
		ui.label_FourthImage->SetImage(qimage);
	}
}
void CParameterSetting::OnBtnClicked()
{
	QPushButton *btn = qobject_cast<QPushButton*>(sender());
	//获取按钮显示文本
	QString text = btn->text();
	//获取按钮对象名称
	QString name = sender()->objectName();
	//do something在这里进行其他事项处理
	qDebug() << text;
	qDebug() << name;


}
void CParameterSetting::ReceivaOriginalImage(Mat OriginalImage, e_CameraType type, int Time)
{
	//emit SendAlgoImageToMainWindow(AlgolImage, type, Time, bok);//??
	emit SendOriginalImage(OriginalImage, Time);

}
void CParameterSetting::SaveCameraParams4()
{
	qDebug() << "参数设置buttonParamsSet2";
	update();
	bool bIsSetSucceed = true;
	int nRet = SetExposureTime(m_FourCameraInfo.CameraHandle, 4);
	if (nRet != MV_OK)
	{
		bIsSetSucceed = false;
		qDebug() << "Set Exposure Time Fail";
		ShowErrorMsg(("Set Exposure Time Fail"), nRet);
	}
	nRet = SetGain(m_FourCameraInfo.CameraHandle, 4);
	if (nRet != MV_OK)
	{
		bIsSetSucceed = false;
		qDebug() << "Set Gain Fail";
		ShowErrorMsg(("Set Gain Fail"), nRet);
	}

	if (true == bIsSetSucceed)
	{
		qDebug() << "Set Parameter Succeed";
		ShowErrorMsg(("Set Parameter Succeed"), nRet);
	}

	return;
}

void CParameterSetting::ChooseFirstOkPath()
{
	QString filePath =   QFileDialog::getExistingDirectory(this, "Open OK Path", QCoreApplication::applicationDirPath());
	if (false == filePath.isEmpty())
	{
		ui.lineEdit_OKPath_First->setText(filePath);
	}
	else
	{
		QMessageBox::information(this, QString::fromLocal8Bit("错误"),QString::fromLocal8Bit("未设置路径信息"));
	}
}

void CParameterSetting::ChooseFirstNgPath()
{
	QString filePath = QFileDialog::getExistingDirectory(this, "Open NG Path", QCoreApplication::applicationDirPath());
	if (false == filePath.isEmpty())
	{
		ui.lineEdit_NGPath_First->setText(filePath);
	}
	else
	{
		QMessageBox::information(this, QString::fromLocal8Bit("错误"), QString::fromLocal8Bit("未设置路径信息"));
	}

}

void CParameterSetting::ChooseSecondOkPath()
{
	QString filePath =   QFileDialog::getExistingDirectory(this, "Open OK Path", QCoreApplication::applicationDirPath());
	if (false == filePath.isEmpty())
	{
		ui.lineEdit_OKPath_Second->setText(filePath);
	}
	else
	{
		QMessageBox::information(this, QString::fromLocal8Bit("错误"),QString::fromLocal8Bit("未设置路径信息"));
	}
}

void CParameterSetting::ChooseSecondNgPath()
{
	QString filePath = QFileDialog::getExistingDirectory(this, "Open NG Path", QCoreApplication::applicationDirPath());
	if (false == filePath.isEmpty())
	{
		ui.lineEdit_NGPath_Second->setText(filePath);
	}
	else
	{
		QMessageBox::information(this, QString::fromLocal8Bit("错误"), QString::fromLocal8Bit("未设置路径信息"));
	}
}

void CParameterSetting::ChooseThirdOkPath()
{
	QString filePath =   QFileDialog::getExistingDirectory(this, "Open OK Path", QCoreApplication::applicationDirPath());
	if (false == filePath.isEmpty())
	{
		ui.lineEdit_OKPath_Third->setText(filePath);
	}
	else
	{
		QMessageBox::information(this, QString::fromLocal8Bit("错误"),QString::fromLocal8Bit("未设置路径信息"));
	}
}

void CParameterSetting::ChooseThirdNgPath()
{
	QString filePath = QFileDialog::getExistingDirectory(this, "Open NG Path", QCoreApplication::applicationDirPath());
	if (false == filePath.isEmpty())
	{
		ui.lineEdit_NGPath_Third->setText(filePath);
	}
	else
	{
		QMessageBox::information(this, QString::fromLocal8Bit("错误"), QString::fromLocal8Bit("未设置路径信息"));
	}
}

void CParameterSetting::ChooseFourthOkPath()
{
	QString filePath =   QFileDialog::getExistingDirectory(this, "Open OK Path", QCoreApplication::applicationDirPath());
	if (false == filePath.isEmpty())
	{
		ui.lineEdit_OKPath_Fourth->setText(filePath);
	}
	else
	{
		QMessageBox::information(this, QString::fromLocal8Bit("错误"),QString::fromLocal8Bit("未设置路径信息"));
	}
}

void CParameterSetting::ChooseFourthNgPath()
{
	QString filePath = QFileDialog::getExistingDirectory(this, "Open NG Path", QCoreApplication::applicationDirPath());
	if (false == filePath.isEmpty())
	{
		ui.lineEdit_NGPath_Fourth->setText(filePath);
	}
	else
	{
		QMessageBox::information(this, QString::fromLocal8Bit("错误"), QString::fromLocal8Bit("未设置路径信息"));
	}
}

void CParameterSetting::SaveConfig()
{
	QString IniPath = QCoreApplication::applicationDirPath() + "/parameter_cfg.ini";
	CConfig *cfg = new CConfig(IniPath);
	if (m_FirstCameraInfo.bOpenCamera)
	{
		cfg->Write(CAMERA_SECTION, FIRST_CAMERA_NAME, m_FirstCameraInfo.CameraName);
	}
	if (m_SecondCameraInfo.bOpenCamera)
	{
		cfg->Write(CAMERA_SECTION, SECOND_CAMERA_NAME, m_SecondCameraInfo.CameraName);
	}
	if (m_ThirdCameraInfo.bOpenCamera)
	{
		cfg->Write(CAMERA_SECTION, THIRD_CAMERA_NAME, m_ThirdCameraInfo.CameraName);
	}
	if (m_FourCameraInfo.bOpenCamera)
	{
		cfg->Write(CAMERA_SECTION, FOURTH_CAMERA_NAME, m_FourCameraInfo.CameraName);
	}
	//相机1的OK/NG保存路径
	bool bchecked = ui.checkBox_SaveNG_First->isChecked();
	cfg->Write(DATA_SECTION, SAVE_NG, bchecked);
	QString NGPath = ui.lineEdit_NGPath_First->text();
	if (bchecked && !NGPath.isEmpty())
	{
		//cfg->Write(DATA_SECTION, NG_PATH, NGPath);
		cfg->Write(PATHLINE_SECTOIN, CAMERA_FIRST_LINE_NG, NGPath);
	}
	bchecked = ui.checkBox_SaveOK_First->isChecked();
	cfg->Write(DATA_SECTION, SAVE_OK, bchecked);
	QString OKPath = ui.lineEdit_OKPath_First->text();
	if (bchecked && !OKPath.isEmpty())
	{
		//cfg->Write(DATA_SECTION, OK_PATH, OKPath);
		cfg->Write(PATHLINE_SECTOIN, CAMERA_FIRST_LINE_OK, OKPath);
	}	
	//相机2的OK/NG保存路径
	bool bchecked2 = ui.checkBox_SaveNG_Second->isChecked();
	cfg->Write(DATA_SECTION, SAVE_NG, bchecked2);
	QString NGPath2 = ui.lineEdit_NGPath_Second->text();
	if (bchecked2 && !NGPath2.isEmpty())
	{
		cfg->Write(PATHLINE_SECTOIN, CAMERA_SECOND_LINE_NG, NGPath2);
		//cfg->Write(DATA_SECTION, NG_PATH, NGPath2);
	}
	bchecked2 = ui.checkBox_SaveOK_Second->isChecked();
	cfg->Write(DATA_SECTION, SAVE_OK, bchecked2);
	QString OKPath2 = ui.lineEdit_OKPath_Second->text();
	if (bchecked2 && !OKPath.isEmpty())
	{
		cfg->Write(PATHLINE_SECTOIN, CAMERA_SECOND_LINE_OK, OKPath2);
		//cfg->Write(DATA_SECTION, OK_PATH, OKPath2);
	}
	//相机3的OK/NG保存路径
	bool bchecked3 = ui.checkBox_SaveNG_Third->isChecked();
	cfg->Write(DATA_SECTION, SAVE_NG, bchecked3);
	QString NGPath3 = ui.lineEdit_NGPath_Third->text();
	if (bchecked3 && !NGPath.isEmpty())
	{
		cfg->Write(PATHLINE_SECTOIN, CAMERA_THIRD_LINE_NG, NGPath3);
		//cfg->Write(DATA_SECTION, NG_PATH, NGPath3);
	}
	bchecked3 = ui.checkBox_SaveOK_Third->isChecked();
	cfg->Write(DATA_SECTION, SAVE_OK, bchecked3);
	QString OKPath3 = ui.lineEdit_OKPath_Third->text();
	if (bchecked3 && !OKPath.isEmpty())
	{
		cfg->Write(PATHLINE_SECTOIN, CAMERA_THIRD_LINE_OK, OKPath3);
		//cfg->Write(DATA_SECTION, OK_PATH, OKPath3);
	}
	//相机4的OK/NG保存路径
	bool bchecked4 = ui.checkBox_SaveNG_Fourth->isChecked();
	cfg->Write(DATA_SECTION, SAVE_NG, bchecked4);
	QString NGPath4 = ui.lineEdit_NGPath_Fourth->text();
	if (bchecked4 && !NGPath.isEmpty())
	{
		cfg->Write(PATHLINE_SECTOIN, CAMERA_FOURTH_LINE_NG, NGPath4);
		//cfg->Write(DATA_SECTION, NG_PATH, NGPath4);
	}
	bchecked4 = ui.checkBox_SaveOK_Fourth->isChecked();
	cfg->Write(DATA_SECTION, SAVE_OK, bchecked4);
	QString OKPath4 = ui.lineEdit_OKPath_Fourth->text();
	if (bchecked4 && !OKPath.isEmpty())
	{
		cfg->Write(PATHLINE_SECTOIN, CAMERA_FOURTH_LINE_OK, OKPath4);
		//cfg->Write(DATA_SECTION, OK_PATH, OKPath4);
	}

	bool bconnected = CPLCManager::GetInstance()->GetConnectStatus();
	cfg->Write(COMMUNICATION_SECTOIN, COM_STATUS, bconnected);
	if (bconnected)
	{
		QString Ip = ui.lineEdit_IP->text();
		int heartbeat = ui.spinBox_Heartbeat->value();
		cfg->Write(COMMUNICATION_SECTOIN, IP, Ip);
		cfg->Write(COMMUNICATION_SECTOIN, HEARTBEAT, heartbeat);
	}

	delete cfg;
	cfg = NULL;
}
void CParameterSetting::SetButtonGroupEnabled(bool enabled, int index)
{
	if (index == 1)
	{
		ui.radioButton_FreeFirst->setEnabled(enabled);
		ui.radioButton_ExternalFirst->setEnabled(enabled);
		ui.radioButton_SoftFirst->setEnabled(enabled);
		setFirstEnable(enabled);
	}
	else if (index == 2)
	{
		
        ui.radioButton_FreeSecond->setEnabled(enabled);
        ui.radioButton_ExternalSecond->setEnabled(enabled);
        ui.radioButton_SoftSecond->setEnabled(enabled);
		setSecondEnable(enabled);
	}
    else if (index == 3)
    {
        ui.radioButton_FreeThird->setEnabled(enabled);
        ui.radioButton_ExternalThird->setEnabled(enabled);
        ui.radioButton_SoftThird->setEnabled(enabled);
		setThirdEnable(enabled);
    }
    else if (index == 4)
    {
        ui.radioButton_FreeFourth->setEnabled(enabled);
        ui.radioButton_ExternalFourth->setEnabled(enabled);
        ui.radioButton_SoftFourth->setEnabled(enabled);
		setFourthEnable(enabled);
    }

}

bool CParameterSetting::OpenCamera(MV_CC_DEVICE_INFO device_info, int index)
{
	qDebug() << "OpenCamera:" << index;
	printf("open camere:%d\n", index);
	if (index == 1)
	{
		int nRet = m_FirstCameraInfo.CameraHandle.Open(&device_info);
		if (nRet != MV_OK)
		{
			QMessageBox::information(this, QString::fromLocal8Bit("错误"), QString::fromLocal8Bit("打开一工位相机失败:") + QString::number(nRet));
			return false;
		}
		else
		{
			GetExposureTime(m_FirstCameraInfo.CameraHandle, 1);
			GetGain(m_FirstCameraInfo.CameraHandle,1); 
			unsigned int PackSize = 0;
			int nRet = m_FirstCameraInfo.CameraHandle.GetOptimalPacketSize(&PackSize);
			if (nRet == MV_OK)
			{
				m_FirstCameraInfo.CameraHandle.SetIntValue("GevSCPSPacketSize", PackSize);
			}
			else
			{
				QMessageBox::information(this, QString::fromLocal8Bit("错误"), "First Camera GevSCPSPacketSize Error:" + QString::number(nRet));
				return false;
			}
			nRet = m_FirstCameraInfo.CameraHandle.StartGrabbing();
			if (nRet != MV_OK)
			{
				QMessageBox::information(this, QString::fromLocal8Bit("错误"), "First Camera Start grabbing Error:" + QString::number(nRet));
				return false;
			}
			m_FirstCameraInfo.CameraHandle.SetEnumValue("TriggerMode", MV_TRIGGER_MODE_ON);
			m_FirstCameraInfo.CameraHandle.SetEnumValue("TriggerSource", MV_TRIGGER_SOURCE_LINE0);
		}
	}
	else if (index == 2)
	{
		int nRet = m_SecondCameraInfo.CameraHandle.Open(&device_info);
		if (nRet != MV_OK)
		{
			QMessageBox::information(this, QString::fromLocal8Bit("错误"), QString::fromLocal8Bit("打开二工位相机失败:") + QString::number(nRet));
			return false;
		}
		else
		{
			GetGain(m_SecondCameraInfo.CameraHandle, 2);
			GetExposureTime(m_SecondCameraInfo.CameraHandle, 2);
			unsigned int PackSize = 0;
			int nRet = m_SecondCameraInfo.CameraHandle.GetOptimalPacketSize(&PackSize);
			if (nRet == MV_OK)
			{
				m_SecondCameraInfo.CameraHandle.SetIntValue("GevSCPSPacketSize", PackSize);
			}
			else
			{
				QMessageBox::information(this, QString::fromLocal8Bit("错误"), "Second Camera GevSCPSPacketSize Error:" + QString::number(nRet));
				return false;
			}
			nRet = m_SecondCameraInfo.CameraHandle.StartGrabbing();
			if (nRet != MV_OK)
			{
				QMessageBox::information(this, QString::fromLocal8Bit("错误"), "Second Camera Start grabbing Error:" + QString::number(nRet));
				return false;
			}
			m_SecondCameraInfo.CameraHandle.SetEnumValue("TriggerMode", MV_TRIGGER_MODE_ON);
			m_SecondCameraInfo.CameraHandle.SetEnumValue("TriggerSource", MV_TRIGGER_SOURCE_LINE0);
		}
    }
	else if (index == 3)
	{
        int nRet = m_ThirdCameraInfo.CameraHandle.Open(&device_info);
        if (nRet != MV_OK)
        {
            QMessageBox::information(this, QString::fromLocal8Bit("错误"),
                                     QString::fromLocal8Bit("打开三工位相机失败:") + QString::number(nRet));
            return false;
        }
        else
        {
			GetGain(m_ThirdCameraInfo.CameraHandle, 3);
			GetExposureTime(m_ThirdCameraInfo.CameraHandle, 3);
            unsigned int PackSize = 0;
            int nRet = m_ThirdCameraInfo.CameraHandle.GetOptimalPacketSize(&PackSize);
            if (nRet == MV_OK)
            {
                m_ThirdCameraInfo.CameraHandle.SetIntValue("GevSCPSPacketSize", PackSize);
            }
            else
            {
                QMessageBox::information(this, QString::fromLocal8Bit("错误"),
                                         "Third Camera GevSCPSPacketSize Error:" + QString::number(nRet));
                return false;
            }
            nRet = m_ThirdCameraInfo.CameraHandle.StartGrabbing();
            if (nRet != MV_OK)
            {
                QMessageBox::information(this, QString::fromLocal8Bit("错误"),
                                         "Third Camera Start grabbing Error:" + QString::number(nRet));
                return false;
            }
            m_ThirdCameraInfo.CameraHandle.SetEnumValue("TriggerMode", MV_TRIGGER_MODE_ON);
            m_ThirdCameraInfo.CameraHandle.SetEnumValue("TriggerSource", MV_TRIGGER_SOURCE_LINE0);
        }
	}
	else if (index == 4)
	{
        int nRet = m_FourCameraInfo.CameraHandle.Open(&device_info);
        if (nRet != MV_OK)
        {
            QMessageBox::information(this, QString::fromLocal8Bit("错误"),
                                     QString::fromLocal8Bit("打开四工位相机失败:") + QString::number(nRet));
            return false;
        }
        else
        {
			GetGain(m_FourCameraInfo.CameraHandle, 4);
			GetExposureTime(m_FourCameraInfo.CameraHandle, 4);
            unsigned int PackSize = 0;
            int nRet = m_FourCameraInfo.CameraHandle.GetOptimalPacketSize(&PackSize);
            if (nRet == MV_OK)
            {
                m_FourCameraInfo.CameraHandle.SetIntValue("GevSCPSPacketSize", PackSize);
            }
            else
            {
                QMessageBox::information(this, QString::fromLocal8Bit("错误"),
                                         "Fourth Camera GevSCPSPacketSize Error:" + QString::number(nRet));
                return false;
            }
            nRet = m_FourCameraInfo.CameraHandle.StartGrabbing();
            if (nRet != MV_OK)
            {
                QMessageBox::information(this, QString::fromLocal8Bit("错误"),
                                         "Fourth Camera Start grabbing Error:" + QString::number(nRet));
                return false;
            }
            m_FourCameraInfo.CameraHandle.SetEnumValue("TriggerMode", MV_TRIGGER_MODE_ON);
            m_FourCameraInfo.CameraHandle.SetEnumValue("TriggerSource", MV_TRIGGER_SOURCE_LINE0);
        }
	}
	return true;
}

QImage CParameterSetting::MattoQImage(Mat image)
{
	switch (image.type())
	{
	case CV_8UC1:
	{
		QImage img((const unsigned char *)(image.data), image.cols, image.rows, image.cols, QImage::Format_Grayscale8);
		return img;
	}
	break;
	case CV_8UC3:
	{
		QImage img((const unsigned char *)(image.data), image.cols, image.rows, image.cols * 3, QImage::Format_RGB888);
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

void CParameterSetting::LoadConfig()
{

	QString IniPath = QCoreApplication::applicationDirPath() + "/parameter_cfg.ini";
	QFileInfo info;
	if (info.exists(IniPath))
	{
		CConfig *cfg = new CConfig(IniPath);
		QString FirstCameraName = cfg->GetString(CAMERA_SECTION, FIRST_CAMERA_NAME);
		qDebug() << "load config first camera name:" << FirstCameraName;
		printf("load config first camera name:%s\n", FirstCameraName.toStdString().c_str());
		if (!FirstCameraName.isEmpty())
		{
			int index = ui.comboBox_First->findText(FirstCameraName);
			qDebug() << "first camera comboBox index:" << index;
			printf("first camera comboBox index:%d\n", index);
			if (index != -1)
			{
				ui.comboBox_First->setCurrentIndex(index);
				OpenFirstCamera();
			}
		}

		QString SecondCameraName = cfg->GetString(CAMERA_SECTION, SECOND_CAMERA_NAME);
		qDebug() << "load config second camera name:" << SecondCameraName;
		printf("load config second camera name:%s\n", SecondCameraName.toStdString().c_str());
		if (!SecondCameraName.isEmpty())
		{
			int index = ui.comboBox_Second->findText(SecondCameraName);
			qDebug() << "second camera comboBox index:" << index;
			printf("second camera comboBox index:%d\n", index);
			if (index != -1)
			{
				ui.comboBox_Second->setCurrentIndex(index);
				OpenSecondCamera();
			}
		}


		QString ThirdCameraName = cfg->GetString(CAMERA_SECTION, THIRD_CAMERA_NAME);
		qDebug() << "load config third camera name:" << ThirdCameraName;
		printf("load config third camera name:%s\n", ThirdCameraName.toStdString().c_str());
		if (!ThirdCameraName.isEmpty())
		{
			int index = ui.comboBox_Third->findText(ThirdCameraName);
			qDebug() << "third camera comboBox index:" << index;
			printf("third camera comboBox index:%d\n", index);
			if (index != -1)
			{
				ui.comboBox_Third->setCurrentIndex(index);
				OpenThirdCamera();
			}
		}

		QString FourthCameraName = cfg->GetString(CAMERA_SECTION, FOURTH_CAMERA_NAME);
		qDebug() << "load config fourth camera name:" << FourthCameraName;
		printf("load config fourth camera name:%s\n", FourthCameraName.toStdString().c_str());
		if (!FourthCameraName.isEmpty())
		{
			int index = ui.comboBox_Four->findText(FourthCameraName);
			qDebug() << "fourth camera comboBox index:" << index;
			printf("fourth camera comboBox index:%d\n", index);
			if (index != -1)
			{
				ui.comboBox_Four->setCurrentIndex(index);
				OpenFourthCamera();
			}
		}

		bool rv = cfg->GetBool(COMMUNICATION_SECTOIN, COM_STATUS);
		qDebug() << "load config plc connected:" << rv;
		if (rv)
		{
			QString ip = cfg->GetString(COMMUNICATION_SECTOIN, IP);
			qDebug() << "load config plc ip:" << ip;
			printf("load config plc ip:%s\n", ip.toStdString().c_str());
			ui.lineEdit_IP->setText(ip);
			QString port = cfg->GetString(COMMUNICATION_SECTOIN, PORT);
			qDebug() << "load config plc port:" << port;
			printf("load config plc port:%s\n", port.toStdString().c_str());
			ui.lineEdit_Port->setText(port);
			int heartbeat = cfg->GetInt(COMMUNICATION_SECTOIN, HEARTBEAT);
			qDebug() << "load config heartbeat:" << heartbeat;
			printf("load config heartbeat:%d\n", heartbeat);
			ui.spinBox_Heartbeat->setValue(heartbeat);
			ConnectToPLC();
			  
		}

		bool bSaveNG = cfg->GetBool(DATA_SECTION, SAVE_NG);
		qDebug() << "load config save ng:" << bSaveNG;
		printf("load config save ng:%d\n", bSaveNG);
		ui.checkBox_SaveNG_First->setChecked(bSaveNG);
		ui.pushButton_LoadNGPath_First->setEnabled(bSaveNG);
		if (bSaveNG)
		{
			QString NGPath = cfg->GetString(DATA_SECTION, NG_PATH);
			qDebug() << "load config save ng path:" << NGPath;
			printf("load config save ng path:%s\n", NGPath.toStdString().c_str());
			if (!NGPath.isEmpty())
			{
				ui.lineEdit_NGPath_First->setText(NGPath);
			}
		}

		bool bSaveOK = cfg->GetBool(DATA_SECTION, SAVE_OK);
		qDebug() << "load config save ok:" << bSaveOK;
		printf("load config save ok:%d\n", bSaveOK);
		ui.checkBox_SaveOK_First->setChecked(bSaveOK);
		ui.pushButton_LoadOKPath_First->setEnabled(bSaveOK);
		if (bSaveOK)
		{
			QString OKPath = cfg->GetString(DATA_SECTION, OK_PATH);
			qDebug() << "load config save ok path:" << OKPath;
			printf("load config save ok path:%s\n", OKPath.toStdString().c_str());
			if (!OKPath.isEmpty())
			{
				ui.lineEdit_OKPath_First->setText(OKPath);
			}
		}


	}
	else
	{
		qDebug() << IniPath << ",is not exist";
		printf("%s,is not exist\n", IniPath.toStdString().c_str());
	}




}

void CParameterSetting::LoadModelConfig()
{
	QString Path= QString::fromLocal8Bit("/Model/");
	QString IniPath = QCoreApplication::applicationDirPath()+Path;
	QDir dir(IniPath);
	QStringList NameFilters;
	NameFilters << "*.ini";
	QStringList MyFiles = dir.entryList(NameFilters, QDir::Files | QDir::Readable, QDir::Name);
	QStringList::Iterator it = MyFiles.begin(), itend = MyFiles.end();
	int i = 0;
	for (; it != itend; it++, i++) 
	{
		ui.comboBox_Formula->addItem(*it);
	}	
}

void CParameterSetting::StartDetecion(bool bStart)
{
	if (bStart)
	{
		m_FirstCameraInfo.ImageCapture->SetSystemType(RUN_ONLINE);
		m_SecondCameraInfo.ImageCapture->SetSystemType(RUN_ONLINE);
		m_ThirdCameraInfo.ImageCapture->SetSystemType(RUN_ONLINE);
		m_FourCameraInfo.ImageCapture->SetSystemType(RUN_ONLINE);
	}
	else
	{
		SetSystemType(ui.comboBox_SystemType->currentIndex());
	}
	m_FirstCameraInfo.ImageCapture->SetRunStatus(bStart);
	m_SecondCameraInfo.ImageCapture->SetRunStatus(bStart);
	m_ThirdCameraInfo.ImageCapture->SetRunStatus(bStart);
	m_FourCameraInfo.ImageCapture->SetRunStatus(bStart);
	//CSerialManager::GetInstance()->OpenHeart(bStart);
}

void CParameterSetting::OpenFirstCamera()
{
	qDebug() << "open first camera";

	QString name = ui.comboBox_First->currentText();
	int index = ui.comboBox_First->currentIndex();
	if (m_FirstCameraInfo.bOpenCamera)
	{
		bool rv = CloseDevice(1);
		if (!rv)
		{
			return;
		}
		ui.pushButton_OpenFirst->setText(QString::fromLocal8Bit("打开相机"));
		SetButtonGroupEnabled(false, 1);
		//ui.pushButton_SaveConfig->setEnabled(false);
		ui.pushButton_TriggerFirst->setEnabled(false);
		m_FirstCameraInfo.bOpenCamera = false;
		m_FirstCameraInfo.CameraName.clear();

	}
	else
	{
	if (name == m_FirstCameraInfo.CameraName)
		{
			QMessageBox::information(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("相机已被占用"));
			return;
		}
		else if (index <= m_stDevList.nDeviceNum)
		{
			QString errMsg;
			m_FirstCameraInfo.bOpenCamera = OpenCamera(*m_stDevList.pDeviceInfo[index], 1);
			if (!m_FirstCameraInfo.bOpenCamera)
			{
				return;
			}
			m_FirstCameraInfo.ImageCapture->SetCameraHandle(m_FirstCameraInfo.CameraHandle, 1);
			m_FirstCameraInfo.ImageCapture->SetCameraStatus(true);
			m_FirstCameraInfo.CameraName = name;
			SetButtonGroupEnabled(true, 1);
			//ui.pushButton_SaveConfig->setEnabled(m_SecondCameraInfo.bOpenCamera);
			ui.radioButton_FreeFirst->setChecked(false);
			ui.radioButton_ExternalFirst->setChecked(true);
			ui.radioButton_SoftFirst->setChecked(false);
			ui.pushButton_TriggerFirst->setEnabled(false);
			ui.pushButton_OpenFirst->setText(QString::fromLocal8Bit("关闭相机"));

		}
	}
}


void CParameterSetting::LoadSecondImage()
{
	//if (m_bFirstAlgoSuccess)
	if (1)
	{
		QString imagePath = QFileDialog::getOpenFileName(this, QString::fromLocal8Bit("图像文件"), "", "*.bmp;*.jpg;*.png;;All Files(*)");
		if (imagePath.isEmpty())
		{
			return;
		}
		qDebug() << "load first image:" << imagePath;
		QByteArray ba = imagePath.toLocal8Bit();
		char *file = ba.data();
		m_SecondOriginalImage = imread(file);
		vector<int>Threshold;
		m_SecondRenderImage.create(m_SecondOriginalImage.rows, m_SecondOriginalImage.cols, m_SecondOriginalImage.type());
		QImage qImage;
		if (ui.checkBox_RenderSecond->isChecked())
		{
			qImage = MattoQImage(m_SecondRenderImage);
		}
		else
		{
			qImage = MattoQImage(m_SecondOriginalImage);
		}
		QString style;
		//if (AlgoRunData.bOK)
		//{
		//	style = "image: url(:/CMainWindow/Resources/OK.svg);";
		//}
		//else
		//{
		//	style = "image: url(:/CMainWindow/Resources/NG.svg);";
		//}
		ui.label_SecondTime->setText(QString::fromLocal8Bit("耗时:") + QString::number(1) + "ms");
		ui.label_SecondResult->setStyleSheet(style);
		ui.label_SecondImage->SetImage(qImage);
	}
	else
	{
		QMessageBox::information(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("工位2算法模型未初始化成功"));
	}
}
void CParameterSetting::OpenSecondCamera()
{
	qDebug() << "open second camera";

	QString name = ui.comboBox_Second->currentText();
	int index = ui.comboBox_Second->currentIndex();
	if (m_SecondCameraInfo.bOpenCamera)
	{
		bool rv = CloseDevice(2);
		if (!rv)
		{
			return;
		}
		ui.pushButton_OpenSecond->setText(QString::fromLocal8Bit("打开相机"));
		SetButtonGroupEnabled(false, 2);
		//ui.pushButton_SaveConfig->setEnabled(false);
		ui.pushButton_TriggerSecond->setEnabled(false);
		m_SecondCameraInfo.bOpenCamera = false;
		m_SecondCameraInfo.CameraName.clear();
	}
	else
	{
		if (name == m_SecondCameraInfo.CameraName)
		{
			QMessageBox::information(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("相机已被占用"));
			return;
		}
		else if (index <= m_stDevList.nDeviceNum)
		{
			QString errMsg;
			m_SecondCameraInfo.bOpenCamera = OpenCamera(*m_stDevList.pDeviceInfo[index], 2);
			if (!m_SecondCameraInfo.bOpenCamera)
			{
				return;
			}
			m_SecondCameraInfo.ImageCapture->SetCameraHandle(m_SecondCameraInfo.CameraHandle, 2);
			m_SecondCameraInfo.ImageCapture->SetCameraStatus(true);
			m_SecondCameraInfo.CameraName = name;
			SetButtonGroupEnabled(true, 2);
			//ui.pushButton_SaveConfig->setEnabled(m_SecondCameraInfo.bOpenCamera);
			ui.radioButton_FreeSecond->setChecked(false);
			ui.radioButton_ExternalSecond->setChecked(true);
			ui.radioButton_SoftSecond->setChecked(false);
			ui.pushButton_TriggerSecond->setEnabled(false);
			ui.pushButton_OpenSecond->setText(QString::fromLocal8Bit("关闭相机"));
		}
	}
}
void CParameterSetting::OpenThirdCamera()
{
	qDebug() << "open third camera";

	QString name = ui.comboBox_Third->currentText();
	int index = ui.comboBox_Third->currentIndex();
	if (m_ThirdCameraInfo.bOpenCamera)
	{
		bool rv = CloseDevice(3);
		if (!rv)
		{
			return;
		}
		ui.pushButton_OpenThird->setText(QString::fromLocal8Bit("打开相机"));
		SetButtonGroupEnabled(false, 3);
		//ui.pushButton_SaveConfig->setEnabled(false);
		ui.pushButton_TriggerThird->setEnabled(false);
		m_ThirdCameraInfo.bOpenCamera = false;
		m_ThirdCameraInfo.CameraName.clear();
	}
	else
	{
		if (name == m_ThirdCameraInfo.CameraName)
		{
			QMessageBox::information(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("相机已被占用"));
			return;
		}
		else if (index <= m_stDevList.nDeviceNum)
		{
			QString errMsg;
			m_ThirdCameraInfo.bOpenCamera = OpenCamera(*m_stDevList.pDeviceInfo[index], 3);
			if (!m_ThirdCameraInfo.bOpenCamera)
			{
				return;
			}
			m_ThirdCameraInfo.ImageCapture->SetCameraHandle(m_ThirdCameraInfo.CameraHandle, 3);
			m_ThirdCameraInfo.ImageCapture->SetCameraStatus(true);
			m_ThirdCameraInfo.CameraName = name;
			SetButtonGroupEnabled(true, 3);
			//ui.pushButton_SaveConfig->setEnabled(m_SecondCameraInfo.bOpenCamera);
			ui.radioButton_FreeThird->setChecked(false);
			ui.radioButton_ExternalThird->setChecked(true);
			ui.radioButton_SoftThird->setChecked(false);
			ui.pushButton_TriggerThird->setEnabled(false);
			ui.pushButton_OpenThird->setText(QString::fromLocal8Bit("关闭相机"));
		}
	}
}

void CParameterSetting::LoadThirdImage()
{
	//if (m_bFirstAlgoSuccess)
	if (1)
	{
		QString imagePath = QFileDialog::getOpenFileName(this, QString::fromLocal8Bit("图像文件"), "", "*.bmp;*.jpg;*.png;;All Files(*)");
		if (imagePath.isEmpty())
		{
			return;
		}
		qDebug() << "load first image:" << imagePath;
		QByteArray ba = imagePath.toLocal8Bit();
		char *file = ba.data();
		m_ThirdOriginalImage = imread(file);
		vector<int>Threshold;
		m_ThirdRenderImage.create(m_ThirdOriginalImage.rows, m_ThirdOriginalImage.cols, m_ThirdOriginalImage.type());
		QImage qImage;
		if (ui.checkBox_RenderThird->isChecked())
		{
			qImage = MattoQImage(m_ThirdRenderImage);
		}
		else
		{
			qImage = MattoQImage(m_ThirdOriginalImage);
		}
		QString style;
		//if (AlgoRunData.bOK)
		//{
		//	style = "image: url(:/CMainWindow/Resources/OK.svg);";
		//}
		//else
		//{
		//	style = "image: url(:/CMainWindow/Resources/NG.svg);";
		//}
		ui.label_ThirdTime->setText(QString::fromLocal8Bit("耗时:") + QString::number(1) + "ms");
		ui.label_ThirdResult->setStyleSheet(style);
		ui.label_ThirdImage->SetImage(qImage);
	}
	else
	{
		QMessageBox::information(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("工位3算法模型未初始化成功"));
	}
}

void CParameterSetting::OpenFourthCamera()
{
	qDebug() << "open fourth camera";

	QString name = ui.comboBox_Four->currentText();
	int index = ui.comboBox_Four->currentIndex();
	if (m_FourCameraInfo.bOpenCamera)
	{
		bool rv = CloseDevice(4);
		if (!rv)
		{
			return;
		}
		ui.pushButton_OpenFourth->setText(QString::fromLocal8Bit("打开相机"));
		SetButtonGroupEnabled(false, 4);
		//ui.pushButton_SaveConfig->setEnabled(false);
		ui.pushButton_TriggerFourth->setEnabled(false);
		m_FourCameraInfo.bOpenCamera = false;
		m_FourCameraInfo.CameraName.clear();
	}
	else
	{
		if (name == m_FourCameraInfo.CameraName)
		{
			QMessageBox::information(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("相机已被占用"));
			return;
		}
		else if (index <= m_stDevList.nDeviceNum)
		{
			QString errMsg;
			m_FourCameraInfo.bOpenCamera = OpenCamera(*m_stDevList.pDeviceInfo[index], 4);
			if (!m_FourCameraInfo.bOpenCamera)
			{
				return;
			}
			m_FourCameraInfo.ImageCapture->SetCameraHandle(m_FourCameraInfo.CameraHandle, 4);
			m_FourCameraInfo.ImageCapture->SetCameraStatus(true);
			m_FourCameraInfo.CameraName = name;
			SetButtonGroupEnabled(true, 4);
			//ui.pushButton_SaveConfig->setEnabled(m_SecondCameraInfo.bOpenCamera);
			ui.radioButton_FreeFourth->setChecked(false);
			ui.radioButton_ExternalFourth->setChecked(true);
			ui.radioButton_SoftFourth->setChecked(false);
			ui.pushButton_TriggerFourth->setEnabled(false);
			ui.pushButton_OpenFourth->setText(QString::fromLocal8Bit("关闭相机"));
		}
	}
}

void CParameterSetting::LoadFourthImage()
{
	//if (m_bFirstAlgoSuccess)
	if (1)
	{
		QString imagePath = QFileDialog::getOpenFileName(this, QString::fromLocal8Bit("图像文件"), "", "*.bmp;*.jpg;*.png;;All Files(*)");
		if (imagePath.isEmpty())
		{
			return;
		}
		qDebug() << "load first image:" << imagePath;
		QByteArray ba = imagePath.toLocal8Bit();
		char *file = ba.data();
		m_FourthOriginalImage = imread(file);
		vector<int>Threshold;
		m_FourthRenderImage.create(m_FourthOriginalImage.rows, m_FourthOriginalImage.cols, m_FourthOriginalImage.type());
		QImage qImage;
		if (ui.checkBox_RenderFourth->isChecked())
		{
			qImage = MattoQImage(m_FourthRenderImage);
		}
		else
		{
			qImage = MattoQImage(m_FourthOriginalImage);
		}
		QString style;
		//if (AlgoRunData.bOK)
		//{
		//	style = "image: url(:/CMainWindow/Resources/OK.svg);";
		//}
		//else
		//{
		//	style = "image: url(:/CMainWindow/Resources/NG.svg);";
		//}
		ui.label_FourthTime->setText(QString::fromLocal8Bit("耗时:") + QString::number(1) + "ms");
		ui.label_FourthResult->setStyleSheet(style);
		ui.label_FourthImage->SetImage(qImage);
	}
	else
	{
		QMessageBox::information(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("工位4算法模型未初始化成功"));
	}
}

void CParameterSetting::SaveCameraParams1()
{
    qDebug() << "参数设置buttonParamsSet";
    update();
    bool bIsSetSucceed = true;
    int nRet = SetExposureTime(m_FirstCameraInfo.CameraHandle,1);
    if (nRet != MV_OK)
    {
        SafeParamsSetting();
        bIsSetSucceed = false;
        qDebug() << "Set Exposure Time Fail";
        ShowErrorMsg(("Set Exposure Time Fail"), nRet);
    }
    nRet = SetGain(m_FirstCameraInfo.CameraHandle,1);
    if (nRet != MV_OK)
    {
      	SafeParamsSetting();
        bIsSetSucceed = false;
        qDebug() << "Set Gain Fail";
        ShowErrorMsg(("Set Gain Fail"), nRet);
    }

    if (true == bIsSetSucceed)
    {
        qDebug() << "Set Parameter Succeed";
        ShowErrorMsg(("Set Parameter Succeed"), nRet);
    }

    return;
}

// ch:设置曝光时间 | en:Set Exposure Time
int CParameterSetting::SetExposureTime(CMvCamera &CameraHandle, int index)
{
    // ch:调节这两个曝光模式，才能让曝光时间生效
    // en:Adjust these two exposure mode to allow exposure time effective
    int nRet = CameraHandle.SetEnumValue("ExposureMode", MV_EXPOSURE_MODE_TIMED);
    if (MV_OK != nRet)
    {
        return nRet;
    }


    nRet = CameraHandle.SetEnumValue("ExposureAuto", MV_EXPOSURE_AUTO_MODE_OFF);
	switch (index)
	{
		case 1:
			{
				m_dExposureEdit = ui.le_exposure_1->text().toFloat();
			}
			break;
		case 2:
			{
				m_dExposureEdit = ui.le_exposure_2->text().toFloat();
			}
			break;
		case 3:
			{
				m_dExposureEdit = ui.le_exposure_3->text().toFloat();
			}
			break;
		case 4:
			{
				m_dExposureEdit = ui.le_exposure_4->text().toFloat();
			}
			break;
	}
    nRet = CameraHandle.SetFloatValue("ExposureTime", (float)m_dExposureEdit);
    if (MV_OK != nRet)
    {
        return nRet;
    }

    return MV_OK;
}
// ch:获取曝光时间 | en:Get Exposure Time
int CParameterSetting::GetExposureTime(CMvCamera &CameraHandle, int index)
{
    MVCC_FLOATVALUE stFloatValue = {0};
    //m_FirstCameraInfo.CameraHandle = CameraHandle;
    int nRet = CameraHandle.GetFloatValue("ExposureTime", &stFloatValue);
    if (MV_OK != nRet)
    {
        return nRet;
    }

	switch (index)
	{
	case 1:
	{
		if (ui.le_exposure_1->text().isEmpty())
		{
			m_dExposureEdit = stFloatValue.fCurValue;
			ui.le_exposure_1->setText(QString::number(m_dExposureEdit));
		}
		else
		{
			m_dExposureEdit = ui.le_exposure_1->text().toFloat();
		}
		break;
	}
	case 2:
	{
		if (ui.le_exposure_2->text().isEmpty())
		{
			m_dExposureEdit = stFloatValue.fCurValue;
			ui.le_exposure_2->setText(QString::number(m_dExposureEdit));
		}
		else
		{
			m_dExposureEdit = ui.le_exposure_2->text().toFloat();
		}
		break;
	}
	case 3:
	{
		if (ui.le_exposure_3->text().isEmpty())
		{
			m_dExposureEdit = stFloatValue.fCurValue;
			ui.le_exposure_3->setText(QString::number(m_dExposureEdit));
		}
		else
		{
			m_dExposureEdit = ui.le_exposure_3->text().toFloat();
		}
		break;
	}
	case 4:
	{
		if (ui.le_exposure_4->text().isEmpty())
		{
			m_dExposureEdit = stFloatValue.fCurValue;
			ui.le_exposure_4->setText(QString::number(m_dExposureEdit));
		}
		else
		{
			m_dExposureEdit = ui.le_exposure_4->text().toFloat();
		}
		break;
	}
	default:;
	}



    return MV_OK;
}

// ch:获取增益 | en:Get Gain
int CParameterSetting::GetGain(CMvCamera &CameraHandle, int index)
{
    MVCC_FLOATVALUE stFloatValue = {0};

	int nRet = CameraHandle.GetFloatValue("Gain", &stFloatValue);
    if (MV_OK != nRet)
    {
        return nRet;
    }
	switch (index)
	{
		case 1 : 
		{
			if (ui.le_gain_1->text().isEmpty())
			{
				m_dGainEdit = (int)stFloatValue.fCurValue;
				ui.le_gain_1->setText(QString::number(m_dGainEdit));
			}
			else
			{
				m_dGainEdit = ui.le_gain_1->text().toDouble();
			}
			break;
		}
		case 2:
		{
			if (ui.le_gain_2->text().isEmpty())
			{
				m_dGainEdit = (int)stFloatValue.fCurValue;
				ui.le_gain_2->setText(QString::number(m_dGainEdit));
			}
			else
			{
				m_dGainEdit = ui.le_gain_2->text().toDouble();
			}
			break;
		}
		case 3:
		{
			if (ui.le_gain_3->text().isEmpty())
			{
				m_dGainEdit = (int)stFloatValue.fCurValue;
				ui.le_gain_3->setText(QString::number(m_dGainEdit));
			}
			else
			{
				m_dGainEdit = ui.le_gain_3->text().toDouble();
			}
			break;
		}
		case 4:
		{
			if (ui.le_gain_4->text().isEmpty())
			{
				m_dGainEdit = (int)stFloatValue.fCurValue;
				ui.le_gain_4->setText(QString::number(m_dGainEdit));
			}
			else
			{
				m_dGainEdit = ui.le_gain_4->text().toDouble();
			}
			break;
		}
		default:;
	}


    return MV_OK;
}


// ch:设置增益 | en:Set Gain
int CParameterSetting::SetGain(CMvCamera &CameraHandle, int index)
{
    // ch:设置增益前先把自动增益关闭，失败无需返回
    // en:Set Gain after Auto Gain is turned off, this failure does not need to return

    int nRet = CameraHandle.SetEnumValue("GainAuto", 0);
	switch (index)
	{
		case 1:
			{
				m_dGainEdit = ui.le_gain_1->text().toDouble();
			}
			break;
		case 2:
			{
				m_dGainEdit = ui.le_gain_2->text().toDouble();
			}
			break;
		case 3:
			{
				m_dGainEdit = ui.le_gain_3->text().toDouble();
			}
			break;
		case 4:
			{
				m_dGainEdit = ui.le_gain_4->text().toDouble();
			}
			break;
		default:;
	}
    
    return CameraHandle.SetFloatValue("Gain", (float)m_dGainEdit);
}

// ch:显示错误信息 | en:Show error message
void CParameterSetting::ShowErrorMsg(QString Message, int nErrorNum)
{
    QString errorMsg;
    if (nErrorNum == 0)
    {
        errorMsg = Message;
    }
    else
    {
        errorMsg = QString("%1: error = %2: ").arg(Message).arg(nErrorNum);
    }

    switch (nErrorNum)
    {
        case MV_E_HANDLE:
            errorMsg += "Error or invalid handle ";
            break;
        case MV_E_SUPPORT:
            errorMsg += "Not supported function ";
            break;
        case MV_E_BUFOVER:
            errorMsg += "Cache is full ";
            break;
        case MV_E_CALLORDER:
            errorMsg += "Function calling order error ";
            break;
        case MV_E_PARAMETER:
            errorMsg += "Incorrect parameter ";
            break;
        case MV_E_RESOURCE:
            errorMsg += "Applying resource failed ";
            break;
        case MV_E_NODATA:
            errorMsg += "No data ";
            break;
        case MV_E_PRECONDITION:
            errorMsg += "Precondition error, or running environment changed ";
            break;
        case MV_E_VERSION:
            errorMsg += "Version mismatches ";
            break;
        case MV_E_NOENOUGH_BUF:
            errorMsg += "Insufficient memory ";
            break;
        case MV_E_ABNORMAL_IMAGE:
            errorMsg += "Abnormal image, maybe incomplete image because of lost packet ";
            break;
        case MV_E_UNKNOW:
            errorMsg += "Unknown error ";
            break;
        case MV_E_GC_GENERIC:
            errorMsg += "General error ";
            break;
        case MV_E_GC_ACCESS:
            errorMsg += "Node accessing condition error ";
            break;
        case MV_E_ACCESS_DENIED:
            errorMsg += "No permission ";
            break;
        case MV_E_BUSY:
            errorMsg += "Device is busy, or network disconnected ";
            break;
        case MV_E_NETER:
            errorMsg += "Network error ";
            break;
    }
    QMessageBox::information(NULL, "PROMPT", errorMsg, QMessageBox::Yes || QMessageBox::No, QMessageBox::Yes);
}

void CParameterSetting::getCameraParams(int index)
{
    qDebug() << "获取参数buttonParamsGet";

    //int nRet = GetTriggerMode();
    //if (nRet != MV_OK)
    //{
    //    qDebug() << "Get Trigger Mode Fail";
    //    ShowErrorMsg(("Get Trigger Mode Fail"), nRet);
    //}
	switch (index)
	{
		case 1:
		{
			int nRet = GetExposureTime(m_FirstCameraInfo.CameraHandle,1);
			if (nRet != MV_OK)
			{
				qDebug() << "Get Exposure Time Fail";
				ShowErrorMsg(("Get Exposure Time Fail"), nRet);
			}

			nRet = GetGain(m_FirstCameraInfo.CameraHandle,1);
			if (nRet != MV_OK)
			{
				qDebug() << "Get Gain Fail";
				ShowErrorMsg(("Get Gain Fail"), nRet);
			}
		}	
		break;
		case 2:
		{
			int nRet = GetExposureTime(m_SecondCameraInfo.CameraHandle,2);
			if (nRet != MV_OK)
			{
				qDebug() << "Get Exposure Time Fail";
				ShowErrorMsg(("Get Exposure Time Fail"), nRet);
			}

			nRet = GetGain(m_SecondCameraInfo.CameraHandle,2);
			if (nRet != MV_OK)
			{
				qDebug() << "Get Gain Fail";
				ShowErrorMsg(("Get Gain Fail"), nRet);
			}
		}	
		break;
		case 3:
		{
			int nRet = GetExposureTime(m_ThirdCameraInfo.CameraHandle,3);
			if (nRet != MV_OK)
			{
				qDebug() << "Get Exposure Time Fail";
				ShowErrorMsg(("Get Exposure Time Fail"), nRet);
			}

			nRet = GetGain(m_ThirdCameraInfo.CameraHandle,3);
			if (nRet != MV_OK)
			{
				qDebug() << "Get Gain Fail";
				ShowErrorMsg(("Get Gain Fail"), nRet);
			}
		}	
		break;
		case 4:
		{
			int nRet = GetExposureTime(m_FourCameraInfo.CameraHandle,4);
			if (nRet != MV_OK)
			{
				qDebug() << "Get Exposure Time Fail";
				ShowErrorMsg(("Get Exposure Time Fail"), nRet);
			}

			nRet = GetGain(m_FourCameraInfo.CameraHandle,4);
			if (nRet != MV_OK)
			{
				qDebug() << "Get Gain Fail";
				ShowErrorMsg(("Get Gain Fail"), nRet);
			}
		}
		break;
		default:;
	}


    //nRet = GetTriggerSource();
    //if (nRet != MV_OK)
    //{
    //    qDebug() << "Get Trigger Source Fail";
    //    ShowErrorMsg(("Get Trigger Source Fail"), nRet);
    //}
    update();

    return;
}

void CParameterSetting::SafeParamsSetting()
{
	if ((m_dGainEdit <= 15.0061998 && m_dGainEdit > 1) && (m_dExposureEdit <= 9999571 && m_dExposureEdit > 59))
	{

	}
	else
	{
		ShowErrorMsg("ERROR:PLEASE SETTING RIGHT EXPOSURE PARAM ARANGE: 59-9999571, GAIN ARANGE: 1.00520003-15.0061998",0);
	}
	
}

void CParameterSetting::setFirstEnable(bool checked)
{
	ui.pushButton_LoadNGPath_First->setEnabled(checked);
	ui.pushButton_LoadOKPath_First->setEnabled(checked);
	ui.pushButton_SaveParams->setEnabled(checked);
	ui.checkBox_SaveOK_First->setEnabled(checked);
	ui.checkBox_SaveNG_First->setEnabled(checked);
	ui.lineEdit_NGPath_First->setEnabled(checked);
	ui.lineEdit_OKPath_First->setEnabled(checked);
	ui.le_exposure_1->setEnabled(checked);
	ui.le_gain_1->setEnabled(checked);
}

void CParameterSetting::setSecondEnable(bool checked)
{
	ui.pushButton_LoadNGPath_Second->setEnabled(checked);
	ui.pushButton_LoadOKPath_Second->setEnabled(checked);
	ui.pushButton_SaveParams_Second->setEnabled(checked);
	ui.checkBox_SaveOK_Second->setEnabled(checked);
	ui.checkBox_SaveNG_Second->setEnabled(checked);
	ui.lineEdit_NGPath_Second->setEnabled(checked);
	ui.lineEdit_OKPath_Second->setEnabled(checked);
	ui.le_exposure_2->setEnabled(checked);
	ui.le_gain_2->setEnabled(checked);
}

void CParameterSetting::setThirdEnable(bool checked)
{
	ui.pushButton_LoadNGPath_Third->setEnabled(checked);
	ui.pushButton_LoadOKPath_Third->setEnabled(checked);
	ui.pushButton_SaveParams_Third->setEnabled(checked);
	ui.checkBox_SaveOK_Third->setEnabled(checked);
	ui.checkBox_SaveNG_Third->setEnabled(checked);
	ui.lineEdit_NGPath_Third->setEnabled(checked);
	ui.lineEdit_OKPath_Third->setEnabled(checked);
	ui.le_exposure_3->setEnabled(checked);
	ui.le_gain_3->setEnabled(checked);
}

void CParameterSetting::setFourthEnable(bool checked)
{
	ui.pushButton_LoadNGPath_Fourth->setEnabled(checked);
	ui.pushButton_LoadOKPath_Fourth->setEnabled(checked);
	ui.pushButton_SaveParams_Fourth->setEnabled(checked);
	ui.checkBox_SaveOK_Fourth->setEnabled(checked);
	ui.checkBox_SaveNG_Fourth->setEnabled(checked);
	ui.lineEdit_NGPath_Fourth->setEnabled(checked);
	ui.lineEdit_OKPath_Fourth->setEnabled(checked);
	ui.le_exposure_4->setEnabled(checked);
	ui.le_gain_4->setEnabled(checked);
}
