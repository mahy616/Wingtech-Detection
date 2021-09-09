#include "PLCManager.h"
#include "windows.h"


CPLCManager *CPLCManager::m_Instace = NULL;

CPLCManager::CPLCManager(QObject *parent)
	:QObject(parent)
{
	m_IP = "";
	m_Port = 0;
	m_bConnected = false;
	m_HeartBeat = 3;	
	//connect(m_TcpClient, SIGNAL(readyRead()), this, SLOT(ReadPLCData()));
	connect(&m_Timer, SIGNAL(timeout()), this, SLOT(SlotTimeOuter()));
	ReadCurrentRecipe();
	m_ImageCounts = 5;  //测试用，正常应该PLC发送图片个数后，赋值给m_ImageCounts
}

CPLCManager::~CPLCManager()
{
	if (m_Timer.isActive())
	{
		m_Timer.stop();
	}
}

CPLCManager *CPLCManager::GetInstance()
{
	if (m_Instace == NULL)
	{
		m_Instace = new CPLCManager();
	}
	return m_Instace;
}

void CPLCManager::TcpConnect(QString ip, quint16 port, int HeartBeat)
{
	qDebug() << "TcpConnect ip:" << ip << ",port:" << port << ",heart beat:" << HeartBeat;
	QByteArray ba = ip.toLocal8Bit();
	char *strIp = ba.data();
	fd = mc_connect(strIp, port, 0, 0);
	m_Mutex.lock();
	m_bConnected = fd > 0;
	m_Mutex.unlock();
	if (m_bConnected)
	{
		m_Timer.start(500);
	}
	emit SendConnectStatus(m_bConnected);
}



void CPLCManager::WritePLCData(QString strResult,bool bok)
{
	qDebug() << "WritePLCData:" << bok;
	if (m_bConnected)
	{
		if (bok)
		{
			WritePLCOK(strResult);
		}
		else
		{
			WritePLCNG(strResult);
		}
	}
	else
	{
		qDebug() << "PLC did not initialize successfully";
	}
}


void CPLCManager::WritePLCOK(QString strResult)
{
	bool ret = false;
	const char sz_write[] = "01010101";//测试用，实际sz_write=strResult
	int length = sizeof(sz_write) / sizeof(sz_write[0]);
	ret = mc_write_string(fd, "D200", length, sz_write);
	qDebug() << "WritePLCOK";
}

void CPLCManager::WritePLCNG(QString strResult)
{
	bool ret = false;
	const char sz_write[] = "10101010";//测试用，实际sz_write=strResult
	int length = sizeof(sz_write) / sizeof(sz_write[0]);
	ret = mc_write_string(fd, "D210", length, sz_write);
	qDebug() << "WritePLCNG";
}

void CPLCManager::WritePLCHeartbeat()
{
	m_Mutex.lock();
	bool ret = false;
	ret = mc_write_short(fd, "D221", 1);
	qDebug() << "WritePLCHeartbeat";
	m_Mutex.unlock();
}

void CPLCManager::WritePLCReady()
{
	bool ret = false;
	ret = mc_write_short(fd, "D222", 1);
	qDebug() << "WritePLCRead";
}


void CPLCManager::WritePLCChangeVar()
{
	bool ret = false;
	ret = mc_write_short(fd, "D220", 1);
	qDebug() << "WritePLCRead";
}

void CPLCManager::ReadCurrentRecipe()
{
	CurrentRecipe.Init();
	QString msg;
	int number;
	bool ret;
	char* str_val = NULL;
	short s_val = 0;
	int length = 30;
	if (ret = mc_read_string(fd, "D342", length, &str_val))//当前配方名称
	{
		msg = QString(str_val);
	}
	if (ret = mc_read_short(fd, "D341", &s_val))//当前配方编号
	{
		number = s_val;
	}
	if (ret = mc_read_short(fd, "D340", &s_val))//当前运行机种编号
	{
	}
	if (  number == 0 || msg == "")
	{
		cout << "初始化配方失败" << endl;
	}
	emit SendChangePLCRecipe(msg, number);
}

void CPLCManager::GetChangeRecipeName(char * str)
{
	QString msg;
	int number;
	//分割字符串 解析设备编号和名称
	emit SendChangePLCRecipe(msg, number);
}

void CPLCManager::GetSaveRecipeName(char * str)
{
	QString msg;
	int number;
	//分割字符串 解析设备编号和名称
	emit SendSavePLCRecipe(msg, number);
}



void CPLCManager::ReadPLCData()
{
	bool ret = false;
	short s_val = 0;
	char* str_val = NULL;
	int length =30;
	if(ret = mc_read_string(fd, "D320", length, &str_val))//配方保存
	{
		if (str_val == "1")
		GetSaveRecipeName(str_val);
	}
	if (ret = mc_read_string(fd, "D330", length, &str_val))//切换配方
	{
	   if(str_val=="1")
		GetChangeRecipeName(str_val);
	}
	if (1 == (ret = mc_read_short(fd, "D310", &s_val)))
	{
		if (s_val == 1)
		{
			m_StartIndex = 2;
			emit SendStartSign();
		}
			
	}
	if (1 == (ret = mc_read_short(fd, "D300", &s_val)))
	{
		if (s_val == 1)
		{
			m_StartIndex = 1;
			emit SendStartSign();
		}
	}
}

void CPLCManager::SlotTimeOuter()
{
	if (!m_bConnected)
	{
		if (!m_IP.isEmpty())
		{
			//重连
			qDebug() << "reconnect ip:" << m_IP << ",port:" << m_Port;
			QByteArray ba = m_IP.toLocal8Bit();
			char *strIp = ba.data();
			fd = mc_connect(strIp, m_Port, 0, 0);
			m_Mutex.lock();

		}
	}
 	else
 	{
		WritePLCHeartbeat();
		ReadPLCData();
 	}
}