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
		}
		m_mutex.lock();
		s_ImageInfo ImageInfo = m_ImageInfos.dequeue();
		m_mutex.unlock();
		Mat Render;/////////////////////////////////////////////////////////////////////////////////////////////???????
		emit SendPorcessResult(ImageInfo.Image, Render, ImageInfo.ImageID);
	}
}


