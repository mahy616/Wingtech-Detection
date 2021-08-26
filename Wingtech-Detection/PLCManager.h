#pragma once
#include <QObject>
#include <QTcpSocket>
#include <QHostAddress>
#include <QTimer>
#include <QDebug>
#include <QMutex>
#include "melsec_mc_bin.h"

class CPLCManager :public QObject
{
	Q_OBJECT
public:
	static CPLCManager *GetInstance();
	void TcpConnect(QString ip, quint16 port,int HeartBeat);
		//断开连接
	//	void TcpDisconnect();
	bool GetConnectStatus() { return m_bConnected; }
	bool GetPLCInitStatus() { return m_bInitPLCSuccess; }
	void WritePLCData(bool bok);
private:
	//PLC写操作
	void WriteInitCommand();
	void WritePLCOK();
	void WritePLCNG();
	void WritePLCHeartbeat();
	void WritePLCRead();
	void WritePLCChangeVar();
private:
	CPLCManager(QObject *parent = NULL);
	~CPLCManager();
	static CPLCManager *m_Instace;
	QTcpSocket *m_TcpClient;
	QString m_IP;
	quint16 m_Port;
	//网络连接标志
	bool m_bConnected;
	//PLC初始化成功标志
	bool m_bInitPLCSuccess;
	QTimer m_Timer;
	int m_HeartBeat;
	QMutex m_Mutex;
	QString m_HexLastHost; //PC端IP最后部分的16进制
	QString m_HexLastServer; //PLC端IP最后部分的16进制
	int fd;
private slots:
	void TcpConnected();
	void TcpDisConnected();
	void SlotTimeOuter();
	void ReadPLCData();
signals:
	void SendConnectStatus(bool status);
	void SendPLCMessage(QString msg);
};