#include "PLCManager.h"
#include "windows.h"


CPLCManager *CPLCManager::m_Instace = NULL;

CPLCManager::CPLCManager(QObject *parent)
	:QObject(parent)
{
	m_TcpClient = new QTcpSocket(); 
	m_IP = "";
	m_Port = 0;
	m_bConnected = false;
	m_bInitPLCSuccess = false;
	m_HeartBeat = 3;
	connect(m_TcpClient, SIGNAL(connected()), this, SLOT(TcpConnected()));
	connect(m_TcpClient, SIGNAL(disconnected()), this, SLOT(TcpDisConnected()));
	connect(m_TcpClient, SIGNAL(readyRead()), this, SLOT(ReadPLCData()));
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
	printf("connect to server ip:%s,port:%d,heartbeat:%d\n",ip.toStdString().c_str(),port,HeartBeat);
	qDebug() << "TcpConnect ip:" << ip << ",port:" << port << ",heart beat:" << HeartBeat;
	m_Timer.stop();
	m_IP = ip;
	m_Port = port;
	QAbstractSocket::SocketState status = m_TcpClient->state();
	if (status == QAbstractSocket::ConnectedState)
	{
		m_TcpClient->abort();
		Sleep(100);
	}
	m_TcpClient->connectToHost(m_IP, m_Port);
	m_TcpClient->waitForConnected(500);
	m_IP = ip;
	m_Port = port;
	m_HeartBeat = HeartBeat;
	m_Timer.start(m_HeartBeat*1000);
}

#if 0
void CPLCManager::TcpDisconnect()
{
	qDebug() << "TcpDisconnect";
	QAbstractSocket::SocketState status = m_TcpClient->state();
	if (m_bConnected)
	{
		m_TcpClient->disconnectFromHost();
		m_bConnected = false;
		m_TcpClient->waitForDisconnected(1000);	
		m_IP.clear();
		m_Port = 0;
	}
}
#endif

void CPLCManager::WritePLCData(QString strResult,bool bok)
{
	qDebug() << "WritePLCData:" << bok;
	if (m_bInitPLCSuccess)
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
		printf("PLC did not initialize successfully\n");
		qDebug() << "PLC did not initialize successfully";
	}
}

void CPLCManager::WriteInitCommand()
{
	qDebug() << "WriteInitCommand";
	printf("WriteInitCommand\n");
	QByteArray ba = m_IP.toLatin1(); // must
	fd = mc_connect(ba.data(), m_Port, 0, 0);
}

void CPLCManager::WritePLCOK(QString strResult)
{
	bool ret = false;
	const char sz_write[] = "01010101";//测试用，实际sz_write=strResult
	int length = sizeof(sz_write) / sizeof(sz_write[0]);
	ret = mc_write_string(fd, "D200", length, sz_write);
	printf("Write\t D200 \tstring:\t %s, \tret: %d\n", sz_write, ret);
	qDebug() << "WritePLCOK";
	printf("WritePLCOK\n");
	//if (m_TcpClient->state() == QAbstractSocket::ConnectedState)
	//{
	//	QString WriteCommand = "46 49 4E 53"; //FINS
	//	WriteCommand += " 00 00 00 1C"; //写入1C:28*2个字节
	//	WriteCommand += " 00 00 00 02"; //功能码，发送命令
	//	WriteCommand += " 00 00 00 00"; //错误代码
	//	WriteCommand += " 80 00 02 00 ";  //80 表示 ICF;  00表示RSV 02表示GCT, 00表示PLC网络号
	//	WriteCommand += m_HexLastServer + " 00 00 " + m_HexLastHost; //PLC的ip最后部分，00--plc单元号 00--pc网络号 PC的IP最后部分
	//	WriteCommand += " 00 FF 01 02";  //00--pc单元号 FF--SID  01-- MRC命令 02--GCT命令(后面0102表示写)
	//	WriteCommand += " 80"; //CIO - 80，DM - 82，WR - B1
	//	WriteCommand += " 01 F4 00 00 01"; //01 F4 地址500,00 首地址，00 01 写入长度
	//	WriteCommand += " 00 01"; //写入1
	//	printf("write plc ok command:%s\n", WriteCommand.toStdString().c_str());
	//	QByteArray arrayHex = QByteArray::fromHex(WriteCommand.toLatin1());
	//	m_TcpClient->write(arrayHex);
	//	m_TcpClient->waitForBytesWritten(10);
	//	m_TcpClient->flush();
	//	m_TcpClient->waitForReadyRead(10);
	//}
	//else
	//{
	//	qDebug() << "write plc ok error:" << m_TcpClient->errorString();
	//	printf("write plc ok error :%s\n", m_TcpClient->errorString().toStdString().c_str());
	//}
}

void CPLCManager::WritePLCNG(QString strResult)
{
	bool ret = false;
	const char sz_write[] = "10101010";//测试用，实际sz_write=strResult
	int length = sizeof(sz_write) / sizeof(sz_write[0]);
	ret = mc_write_string(fd, "D210", length, sz_write);
	printf("Write\t D210 \tstring:\t %s, \tret: %d\n", sz_write, ret);
	qDebug() << "WritePLCNG";
	printf("WritePLCNG\n");
}

void CPLCManager::WritePLCHeartbeat()
{
	bool ret = false;
	ret = mc_write_short(fd, "D221", 1);
	printf("Write\t D100 \tshort:\t %d, \tret: %d\n", 1, ret);
	qDebug() << "WritePLCHeartbeat";
	printf("WritePLCHeartbeat\n");
}

void CPLCManager::WritePLCRead()
{
	bool ret = false;
	ret = mc_write_short(fd, "D222", 1);
	printf("Write\t D222 \tshort:\t %d, \tret: %d\n", 1, ret);
	qDebug() << "WritePLCRead";
	printf("WritePLCRead\n");
}


void CPLCManager::WritePLCChangeVar()
{
	bool ret = false;
	ret = mc_write_short(fd, "D220", 1);
	printf("Write\t D220 \tshort:\t %d, \tret: %d\n", 1, ret);
	qDebug() << "WritePLCRead";
	printf("WritePLCRead\n");
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
	if (ret = mc_read_string(fd, "D342", length, &str_val))//切换配方
	{
		return;
	}
	if (ret = mc_read_short(fd, "D341", &s_val))
	{
		return;
	}
	if (ret = mc_read_short(fd, "D340", &s_val))
	{
		return;
	}
	if (CurrentRecipe.CurrentMachineNumber == 0 || CurrentRecipe.CurrentRecipeNumber == 0 || CurrentRecipe.CurrentRecipeName == "")
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



void CPLCManager::TcpConnected()
{
	qDebug() << "TcpConnected";
	m_Mutex.lock();
	m_bConnected = true;
	//获取PLC和PC端IP最后一部分的16进制
	QString HostAddress = m_TcpClient->localAddress().toString();
	int pos = HostAddress.lastIndexOf(".");
	QString LastHost = HostAddress.right(HostAddress.length() - pos - 1);
	pos = m_IP.lastIndexOf(".");
	QString LastServer = m_IP.right(m_IP.length() - pos - 1);
	m_HexLastHost = QString::number(LastHost.toInt(), 16).toUpper();
	m_HexLastServer = QString::number(LastServer.toInt(), 16).toUpper();
	WriteInitCommand();
	m_Mutex.unlock();
	emit SendConnectStatus(true);
}

void CPLCManager::TcpDisConnected()
{
	mc_disconnect(fd);
	qDebug() << "TcpDisConnected";
	m_Mutex.lock();
	m_bConnected = false;
	m_Mutex.unlock();
	emit SendConnectStatus(false);
}

void CPLCManager::ReadPLCData()
{
	bool ret = false;
	short s_val = 0;
	char* str_val = NULL;
	int length =30;
	if(ret = mc_read_string(fd, "D320", length, &str_val))//切换配方
	{
		if (str_val == "1")
		GetSaveRecipeName(str_val);
	}
	if (ret = mc_read_string(fd, "D330", length, &str_val))//保存配方
	{
	   if(str_val=="1")
		GetChangeRecipeName(str_val);
	}
	if (1 == (ret = mc_read_short(fd, "D310", &s_val)))
	{
		if (s_val == 1)
			emit SendStartSign();
	}
	if (1 == (ret = mc_read_short(fd, "D300", &s_val)))
	{
		if (s_val == 1)
			emit SendStartSign();
	}
	printf("Read\t \tshort:\t %d\n", s_val);


}

void CPLCManager::SlotTimeOuter()
{
	if (!m_bConnected)
	{
		if (!m_IP.isEmpty())
		{
			//重连
			qDebug() << "reconnect ip:" << m_IP << ",port:" << m_Port;
			m_TcpClient->connectToHost(m_IP, m_Port);
			m_bConnected = m_TcpClient->waitForConnected(50);
		}
	}
 	else
 	{
		WritePLCHeartbeat();
		ReadPLCData();
 	}
}