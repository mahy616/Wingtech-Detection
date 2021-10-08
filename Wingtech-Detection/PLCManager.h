#pragma once
#include <QObject>
#include <QTcpSocket>
#include <QHostAddress>
#include <QTimer>
#include <QDebug>
#include <QMutex>
#include "melsec_mc_bin.h"
#include <iostream >

//using namespace std;

typedef struct
{
	int CurrentMachineNumber;
	int CurrentRecipeNumber;
	QString CurrentRecipeName;
	void Init()
	{
		CurrentMachineNumber=0;
		CurrentRecipeNumber=0;
		CurrentRecipeName ="";
	}
}s_CurrentRecipe;


class CPLCManager :public QObject
{
	Q_OBJECT
public:
	static CPLCManager *GetInstance();
	bool TcpConnect(QString ip, quint16 port,int HeartBeat);
		//�Ͽ�����
	//	void TcpDisconnect();
	bool GetConnectStatus() { return m_bConnected; }
	//bool GetPLCInitStatus() { return m_bInitPLCSuccess; }
	bool WritePLCData(QString strResult, bool bok);
	bool WritePLCReady();
	bool ReadCurrentRecipe();
	bool WritePLCStartSign();
private:
	//PLCд����
	bool WritePLC(QString strResult, const char* Station);
	void WritePLCHeartbeat();
	
	


private:
	CPLCManager(QObject *parent = NULL);
	~CPLCManager();
	static CPLCManager *m_Instace;
	QString m_IP;
	quint16 m_Port;
	//�������ӱ�־
	bool m_bConnected;
	//PLC��ʼ���ɹ���־
	//bool m_bInitPLCSuccess;
	QTimer m_Timer;
	int m_HeartBeat;
	QMutex m_Mutex;
	QString m_HexLastHost; //PC��IP��󲿷ֵ�16����
	QString m_HexLastServer; //PLC��IP��󲿷ֵ�16����
	s_CurrentRecipe CurrentRecipe;
	int m_StartIndex;
	int m_fd;
	int m_c;
private slots:
	void SlotTimeOuter();
	void ReadPLCData();
signals:
	void SendConnectStatus(bool status);
	void SendPLCMessage(QString msg);
	void SendChangePLCRecipe(QString msg, int number,int ImageCounts);
	void SendSavePLCRecipe(QString msg, int number, int ImageCounts);
	void SendStartSign();
	void SendRefreshIndex();
};