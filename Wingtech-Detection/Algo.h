#pragma once
#include "QThread"
#include "ImageCapture.h"
#include "QQueue"
class CAlgo :public QThread
{
	Q_OBJECT
public:
	CAlgo(QThread *parent = NULL);
	~CAlgo();
private:
	void run();
	void InitConnections();
private:
	QQueue<Mat> m_FirstStation;
	QMutex m_Mutex;
signals:
	void SendAlgoImageToParam(Mat OriginalImage, e_CameraType type, int index, bool bok);
private slots:
	void ReceivaReImage(Mat OriginalImage, e_CameraType type, int Time, bool bok);
};