#include "Algo.h"

CAlgo::CAlgo(QThread *parent /* = NULL */)
	:QThread(parent)
{
	InitConnections();
}

CAlgo::~CAlgo()
{
}

void CAlgo::run()
{
	while (1)
	{
		if (m_FirstStation.size() != 0)
		{
			Mat AlgoImage;
			e_CameraType type;
			int Time;
			bool bok;
			emit SendAlgoImageToParam(AlgoImage, type,  Time,  bok);
			//m_FirstStation.dequeue();
		}
	}
}

void CAlgo::InitConnections()
{
	
}

void CAlgo::ReceivaReImage(Mat OriginalImage, e_CameraType type, int Time, bool bok)
{
	m_Mutex.lock();
	m_FirstStation.push_back(OriginalImage);
	m_Mutex.unlock();

}
