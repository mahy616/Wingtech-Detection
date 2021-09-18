#pragma once
#include <QThread>
#include "windows.h"
#include <QMutex>
#include "MvCamera.h"
#include "opencv2/opencv.hpp"
#include "qdebug.h"
#include "PLCManager.h"
using namespace std;
using namespace cv;

typedef enum
{
	CAMERA_FIRST,
	CAMERA_SECOND,
	CAMERA_THIRD,
	CAMERA_FOURTH
}e_CameraType;

typedef enum
{
	RUN_ONLINE,  //在线运行：跑算法，统计结果，PLC通讯
	CAMEREA_TEST, //相机测试：显示相机图像，不跑算法
	ONLINE_ALGO_TEST, //在线测试算法，相机采图并跑算法，显示结果
	OFFLINE_ALGO_TEST //加载离线图像，跑算法并显示结果
}s_SystemType;

class CImageCapture :public QThread
{
	Q_OBJECT
public:
	CImageCapture(QThread *parent = NULL);
	~CImageCapture();

	void SetCameraType(e_CameraType type);
	void SetSystemType(s_SystemType SystemType);
	void SetCameraStatus(bool bOpen);
	void StopThread();
    bool SetCameraHandle(CMvCamera &camera, e_CameraType type);
    void SetRunStatus(bool bStart);
	void InitConnections();


private:
	CMvCamera m_MvCamera;
	QMutex m_Mutex;
	bool m_bStop;
	bool m_bOpen;
	bool m_bStartRun;
	unsigned char*  m_pGrabBuf;
	unsigned int nDataSize;
	e_CameraType m_Type;
	s_SystemType m_SystemType;
	int GrabIndex ;

private:
	void run();
	Mat Convert2Mat(MV_FRAME_OUT_INFO_EX* pstImageInfo, unsigned char * pData);
signals:
	//void SendCameraImage(Mat image, int index);
	void SendCameraImage(Mat image, e_CameraType m_Type);
    void SendAlgoImage(Mat OriginalImage, e_CameraType RenderImage, int index, bool bok);
	void SendImageToAlgo(Mat OriginalImage, e_CameraType type, int index);
	void SendImageIndex(int index);
private slots:
    void ReceiveStartSign();
};