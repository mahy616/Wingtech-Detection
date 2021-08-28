#pragma once
#include "QObject"
#include "QThread"
#include "qmutex.h"
#include "QQueue"
#include "opencv2/opencv.hpp"
#include "VimoDetectionModule.h"

using namespace std;
using namespace cv;
using namespace smartmore;
typedef struct
{
	int ImageID;
	Mat Image;
}s_ImageInfo;

class CAlgoManager :public QThread
{
	Q_OBJECT
public:
	CAlgoManager(QThread *parent = NULL);
	~CAlgoManager();
	bool InitAlgo(QString ModelPath);
	void RunAlgo(s_ImageInfo ImageInfo);
	void StopAlgo();
	void InitConnections();
private:
	QQueue<s_ImageInfo> m_ImageInfos;
	bool m_bStop;
	QMutex m_mutex;
	smartmore::VimoDetectionModule module;
private:
	void run();
signals:
	void SendPorcessResult(Mat OriginalImage, Mat RenderImage, int ImageID);
private slots:
	//void  RunAlgo(s_ImageInfo ImageInfo);
};