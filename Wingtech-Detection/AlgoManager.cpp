#include <windows.h>
#include "AlgoManager.h"

CAlgoManager *CAlgoManager::m_Algo = NULL;
CAlgoManager::CAlgoManager(QThread *parent)
	:QThread(parent)
{
	m_bStop = false;
	m_Algo = this;
	m_Index = 0;
}

CAlgoManager::~CAlgoManager()
{

}


bool CAlgoManager::InitAlgo(QString ModelPath)
{
	if (module.Init("H:/WXWork/1688850861907945/Cache/File/2021-08/model/wentai_1st_emtpy.smartmore", false, 0) != smartmore::ResultCode::Success)
	{
		std::cout << "Init module failed!" << std::endl;
		return 1;
	}
	return true;
}

void CAlgoManager::RunAlgo(s_ImageInfo ImageInfo)
{
	m_mutex.lock();
	m_ImageInfos.push_back(ImageInfo);
	m_mutex.unlock();
}

void CAlgoManager::StopAlgo()
{
	m_mutex.lock();
	m_bStop = true;
	m_mutex.unlock();
}

void CAlgoManager::InitConnections()
{

}

CAlgoManager * CAlgoManager::GetAlgoManager()
{
	return m_Algo;
}

void CAlgoManager::SetAlgoThreshold(QVector<double> AlgoThreshold)
{
	m_mutex.lock();
	m_AlgoThreshold = AlgoThreshold;
	m_mutex.unlock();
}

void CAlgoManager::run()
{
	while (!m_bStop)
	{
		if (m_ImageInfos.size() == 0)
		{
			Sleep(10);
			continue;
		}
		m_mutex.lock();
		s_ImageInfo ImageInfo = m_ImageInfos.dequeue();
		m_mutex.unlock();
	
		smartmore::DetectionRequest req;
		smartmore::DetectionResponse rsp;
		Mat RenderImage;
		vector<double> Threshold;
		req.thresholds = { 0.8f };
		//req.image = cv::imread(input_image);
		req.image = ImageInfo.Image;
		std::cout << "Init success" << std::endl;
		qDebug() << "Init success";
		smartmore::ResultCode res1=module.Run(req, rsp);
		std::cout << "Run success" << std::endl;
		qDebug() << "Run success";
		if (res1 != smartmore::ResultCode::Success)
		{
			qDebug() << "Position1 Normal run Failure.";
			std::cout << "Position1 Normal run Failure." << std::endl;
		}
		else
		{
			module.Visualize(req, rsp, RenderImage, Threshold);
			qDebug() << "smartmore::ResultCode::Success";
		};
		Mat Render;/////////////////////////////////////////////////////////////////////////////////////////////???????
		bool bok = true;//这里bok是但凡处理完图像就true，还是先这样写，这里的如果不通过是不是得标记一个false
		emit SendPorcessResult(ImageInfo.Image, Render, ImageInfo.ImageID-1,bok, ImageInfo.Type);
	}
}


