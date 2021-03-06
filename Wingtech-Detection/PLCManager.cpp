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

bool CPLCManager::WritePLCData(QString strResult,bool bok)
{
	qDebug() << "WritePLCData:" << bok << strResult;
	if (m_bConnected)
	{
		if (m_StartIndex==1)
		{
			if (!WritePLC(strResult, "D200"))
				return false;
		}
		else if (m_StartIndex == 2)
		{
			if (!WritePLC(strResult, "D210"))
				return false;
		}
	}
	else
	{
		return true;
	}
}


bool CPLCManager::WritePLC(QString strResult,const char* Station)
{
	//bool ret = false;
	//const char sz_write[] = "01010101";//?????ã?ʵ??sz_write=strResult
	//int length = sizeof(sz_write) / sizeof(sz_write[0]);
	//ret = mc_write_string(m_fd, Station, length, sz_write);
	if (!mc_write_short(m_fd, Station, 85))
		return false;
}



void CPLCManager::WritePLCHeartbeat()
{
	//if(!mc_write_short(m_fd, "D221", 1))
	//qDebug() << "WritePLCHeartbeat error";

}

bool CPLCManager::WritePLCStartSign()
{
	if (m_StartIndex == 1)
	{
		return mc_write_short(m_fd, "D220", 1);
	}
	else if (m_StartIndex == 2)
	{
		return mc_write_short(m_fd, "D221", 1);
	}
}

bool CPLCManager::WritePLCReady()
{
     return mc_write_short(m_fd, "D222", 1);
}


bool CPLCManager::ReadCurrentRecipe()
{
	CurrentRecipe.Init();
	short Number=0;
	char* str_val = NULL;
	short ImageCounts = 0;
	if (!mc_read_string(m_fd, "D342", 30, &str_val))//??ǰ?䷽????
		return false;
	if (!mc_read_short(m_fd, "D341", &Number))//??ǰ?䷽????
		return false;
	if (!mc_read_short(m_fd, "D340", &ImageCounts))//??ǰ?䷽???մ???
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
	if (mc_read_short(m_fd, "D320", &s_val))//?䷽????
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
	if (mc_read_short(m_fd, "D330", &s_val))//?䷽?л?
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
	if (mc_read_short(m_fd, "D310", &s_val))//2#??ʼ????
	{
		if (s_val)
		{
			m_StartIndex = 2;
			emit SendStartSign();
			mc_write_short(m_fd, "D310", 0);
			//emit SendRefreshIndex();
		}

	}
	if (mc_read_short(m_fd, "D300", &s_val))//1#??ʼ????
	{
		if (s_val)
		{
			m_StartIndex = 1;
			emit SendStartSign();
			mc_write_short(m_fd, "D300", 0);
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
			//????
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