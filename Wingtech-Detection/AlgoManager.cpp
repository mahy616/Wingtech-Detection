#include <windows.h>
#include "AlgoManager.h"


CAlgoManager::CAlgoManager(QThread *parent)
	:QThread(parent)
{
	m_bStop = false;
}

CAlgoManager::~CAlgoManager()
{

}

bool CAlgoManager::InitAlgo(QString ModelPath)
{
	if (module.Init("H:/WXWork/1688850861907945/Cache/File/2021-08/model/andaotuo202106.smartmore", false, 0) != smartmore::ResultCode::Success)
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
	m_bStop = true;
}

void CAlgoManager::InitConnections()
{

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
		std::string input_image = "C:/Users/Mhy/Desktop/Image_20210726193600846.bmp";
		
		std::cout << module.Version() << std::endl;
		smartmore::DetectionRequest req;
		smartmore::DetectionResponse rsp;
		req.thresholds = { 0.8f };
		req.image = cv::imread(input_image);
		std::cout << "Init success" << std::endl;

		module.Run(req, rsp);
		std::cout << "Run success" << std::endl;
		Mat Render;/////////////////////////////////////////////////////////////////////////////////////////////???????
		emit SendPorcessResult(ImageInfo.Image, Render, ImageInfo.ImageID);
	}
}


