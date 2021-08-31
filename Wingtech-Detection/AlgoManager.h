#pragma once
#include "QObject"
#include "QThread"
#include "qmutex.h"
#include "QQueue"
#include "opencv2/opencv.hpp"
#include "VimoDetectionModule.h"
#include "ImageCapture.h"
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
	static CAlgoManager* GetAlgoManager();
private:
	QQueue<s_ImageInfo> m_ImageInfos;
	bool m_bStop;
	QMutex m_mutex;
	static CAlgoManager* m_Algo;
	smartmore::VimoDetectionModule module;
	int m_Index;
private:
	void run();
signals:
	void SendPorcessResult(Mat image, Mat RenderImage, int index, bool bOK, e_CameraType type);
private slots:
	//void  RunAlgo(s_ImageInfo ImageInfo);
};