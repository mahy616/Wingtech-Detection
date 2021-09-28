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

bool CPLCManager::TcpConnect(QString ip, quint16 port, int HeartBeat)
{
	if (m_bConnected)
		return true;
	qDebug() << "TcpConnect ip:" << ip << ",port:" << port << ",heart beat:" << HeartBeat;
	QByteArray ba = ip.toLocal8Bit();
	char *strIp = ba.data();
	m_fd = mc_connect(strIp, port, 0, 0);
	if (m_fd > 0)
	{
		m_bConnected = true;
		m_Timer.start(500);
		emit SendConnectStatus(m_bConnected);
	}
	else
	{
		return false;
	}
}

void CPLCManager::WritePLCData(QString strResult,bool bok)
{
	qDebug() << "WritePLCData:" << bok << strResult;
	if (m_bConnected)
	{
		if (m_StartIndex==1)
		{
			WritePLC(strResult,"D200");
		}
		else if (m_StartIndex == 2)
		{
			WritePLC(strResult,"D210");
		}
	}
	else
	{
		qDebug() << "PLC did not initialize successfully";
	}
}


void CPLCManager::WritePLC(QString strResult,const char* Station)
{
	bool ret = false;
	const char sz_write[] = "01010101";//测试用，实际sz_write=strResult
	int length = sizeof(sz_write) / sizeof(sz_write[0]);
	ret = mc_write_string(m_fd, Station, length, sz_write);
	qDebug() << "WritePLCOK";
}



void CPLCManager::WritePLCHeartbeat()
{
	if(!mc_write_short(m_fd, "D221", 1))
	qDebug() << "WritePLCHeartbeat error";

}

bool CPLCManager::WritePLCReady()
{
     return mc_write_short(m_fd, "D222", 1);
}


void CPLCManager::WritePLCChangeVar()
{

}

bool CPLCManager::ReadCurrentRecipe()
{
	CurrentRecipe.Init();
	short Number=0;
	char* str_val = NULL;
	short ImageCounts = 0;
	if (!mc_read_string(m_fd, "D342", 30, &str_val))//当前配方名称
		return false;
	if (!mc_read_short(m_fd, "D341", &Number))//当前配方编号
		return false;
	if (!mc_read_short(m_fd, "D340", &ImageCounts))//当前配方拍照次数
		return false;
	QString RecipeName = QString(str_val);
	qDebug() << "ReadCurrentRecipe: " << "RecipeName = " << RecipeName << "," << "number = " << "," << Number << "ImageCounts" << ImageCounts;
	emit SendChangePLCRecipe(RecipeName, Number,ImageCounts);
}



void CPLCManager::ReadPLCData()
{
	bool ret = false;
	short s_val = 0;
	short counts = 0;
	char* str_val = NULL;
	int length = 30;
	QString RecipeName;
	int number;
	if (mc_read_short(m_fd, "D320", &s_val))//配方保存
	{
		if (str_val == "1")
		{
			if (!mc_read_string(m_fd, "D", length, &str_val))
				qDebug() << "GetRecipeName error";


			if (!mc_read_short(m_fd, "D", &s_val))
				qDebug() << "GetRecipeNumber error";

			if (!mc_read_short(m_fd, "D", &counts))
				qDebug() << "GetRecipeCounts error";
			qDebug() << "ReadPLCData SendSavePLCRecipe: " << "RecipeName = " << RecipeName << "," << "number = " << "," << number << "counts" << counts;
			emit SendSavePLCRecipe(RecipeName, number,counts);
		}
	}
	if (mc_read_short(m_fd, "D330", &s_val))//配方切换
	{
		if (str_val == "1")
		{
			if (!mc_read_string(m_fd, "D", length, &str_val))
				qDebug() << "GetRecipeName error";

			if (!mc_read_short(m_fd, "D", &s_val))
				qDebug() << "GetRecipeNumber error";

			if (!mc_read_short(m_fd, "D", &counts))
				qDebug() << "GetRecipeCounts error";
			qDebug() << "ReadPLCData SendChangePLCRecipe: " << "RecipeName = " << RecipeName << "," << "number = " << "," << number << "counts" << counts;
			emit SendChangePLCRecipe(RecipeName, number, counts);
		}
	}
	if (mc_read_short(m_fd, "D310", &s_val))//2#开始拍照
	{
		if (s_val)
		{
			m_StartIndex = 2;
			//emit SendStartSign();
			//emit SendRefreshIndex();
		}

	}
	if (mc_read_short(m_fd, "D300", &s_val))//1#开始拍照
	{
		if (s_val)
		{
			m_StartIndex = 1;
			//emit SendStartSign();
			//emit SendRefreshIndex();
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
			m_fd = mc_connect(strIp, m_Port, 0, 0);
			m_Mutex.lock();

		}
	}
 	else
 	{
		WritePLCHeartbeat();
		ReadPLCData();
 	}
}