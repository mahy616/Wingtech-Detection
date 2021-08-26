#include "windows.h"
#include "SaveImage.h"
#include "QDebug"

CSaveImage::CSaveImage(QThread *parent /* = NULL */)
	:QThread(parent)
{
	m_ImageList.clear();
	m_bStop = false;
}

void CSaveImage::SaveImage(QString FileName, Mat Image)
{
	m_Mutex.lock();
	s_SaveInfo SaveInfo;
	SaveInfo.FileName = FileName;
	SaveInfo.Image = Image;// .clone();
	m_ImageList.push_back(SaveInfo);
	m_Mutex.unlock();
}

void CSaveImage::StopThread()
{
	m_Mutex.lock();
	m_bStop = true;
	m_Mutex.unlock();
}

void CSaveImage::run()
{
	while (1)
	{
		m_Mutex.lock();
		bool bStop = m_bStop;
		m_Mutex.unlock();
		if (bStop)
		{
			break;
		}
		if (m_ImageList.size() > 0)
		{
			m_Mutex.lock();
			s_SaveInfo SaveInfo = m_ImageList.dequeue();
			m_Mutex.unlock();
			QByteArray ba = SaveInfo.FileName.toLocal8Bit();
			char *file = ba.data();
			try 
			{
				bool rv = imwrite(file, SaveInfo.Image);
				if (rv)
				{
					qDebug() << "save image success:" << file;
				}
			}
			catch (cv::Exception& e)
			{
				const char* err_msg = e.what();
				qDebug() << "save image failed:" << file;
			}
		}
		else
		{
			Sleep(10);
		}
	}
	m_ImageList.clear();
}