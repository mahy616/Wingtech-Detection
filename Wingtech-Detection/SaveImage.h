#pragma once
#include "QThread"
#include "QQueue"
#include "QMutex"
#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

typedef struct
{
	QString FileName;
	Mat Image;
}s_SaveInfo;

class CSaveImage :public QThread
{
public:
	CSaveImage(QThread *parent = NULL);
	void SaveImage(QString FileName, Mat Image);
	void StopThread();
private:
	QMutex m_Mutex;
	QQueue<s_SaveInfo> m_ImageList;
	bool m_bStop;
	void run();
};
