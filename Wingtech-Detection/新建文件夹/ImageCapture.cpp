#include "ImageCapture.h"
#include <QDebug>


CImageCapture::CImageCapture(QThread *parent /*= NULL*/)
	:QThread(parent)
{
	m_bStop = false;
	m_bOpen = false;
	m_pGrabBuf = NULL;
	m_Index = 0;
	m_bStartRun = false;
}

CImageCapture::~CImageCapture()
{
}

void CImageCapture::SetCameraType(e_CameraType type)
{
	m_Mutex.lock();
	m_Type = type;
	m_Mutex.unlock();
}

void CImageCapture::SetSystemType(s_SystemType SystemType)
{
	m_Mutex.lock();
	m_SystemType = SystemType;
	m_Mutex.unlock();
}

void CImageCapture::SetCameraStatus(bool bOpen)
{
	m_Mutex.lock();
	m_bOpen = bOpen;
	m_Mutex.unlock();
}

void CImageCapture::StopThread()
{
	m_Mutex.lock();
	m_bStop = true;
	m_Mutex.unlock();
}

bool CImageCapture::SetCameraHandle(CMvCamera & camera, int index)
{
	m_Mutex.lock();
	m_MvCamera = camera;
	m_Index = index;
	m_Mutex.unlock();
	MVCC_INTVALUE_EX stIntValue = { 0 };
	int nRet = m_MvCamera.GetIntValue("PayloadSize", &stIntValue);
	if (nRet != MV_OK)
	{
		qDebug() << "failed in get PayloadSize:" << nRet;
		printf("failed in get PayloadSize:%d\n", nRet);
		return false;
	}
	nDataSize = (unsigned int)stIntValue.nCurValue;
	if (m_pGrabBuf != NULL)
	{
		delete m_pGrabBuf;
		m_pGrabBuf = NULL;
	}
	m_pGrabBuf = (unsigned char *)malloc(sizeof(unsigned char) * nDataSize);
	if (m_pGrabBuf == NULL)
	{
		qDebug() << "malloc grab buffer failed";
		printf("malloc grab buffer failed\n");
		return false;
	}
	return true;
}

void CImageCapture::SetRunStatus(bool bStart)
{
	m_Mutex.lock();
	m_bStartRun = bStart;
	m_Mutex.unlock();
}

void CImageCapture::run()
{
	int nRet = MV_OK;
	MV_FRAME_OUT_INFO_EX stImageInfo = { 0 };
	MV_DISPLAY_FRAME_INFO stDisplayInfo = { 0 };
	int GrabIndex = 0;
	while (1)
	{
		m_Mutex.lock();
		bool bStop = m_bStop;
		bool bOpen = m_bOpen;
		bool bStart = m_bStartRun;
		m_Mutex.unlock();
		if (bStop)
		{
			break;
		}
		if (bOpen)
		{
			int nRet = m_MvCamera.GetOneFrameTimeout(m_pGrabBuf, nDataSize, &stImageInfo, 1000);
			if (nRet == MV_OK)
			{
				Mat img = Convert2Mat(&stImageInfo, m_pGrabBuf);
				if (img.data == NULL)
				{
					continue;
				}
				Mat curImage = img;// .clone();
				if (m_SystemType == CAMEREA_TEST)
				{
					emit SendCameraImage(curImage, m_Index);
				}
				if (bStart)
				{
					if (m_Type == CAMERA_FIRST)
					{
						bool bok = 0;
						//emit SendAlgoImage(curImage, m_Type, GrabIndex, bok);
						emit SendImageToAlgo(curImage, m_Type, GrabIndex, bok);
						GrabIndex++;
						Sleep(2000);

					}

					if (m_Type == CAMERA_SECOND)
					{
						bool bok = 0;
						emit SendAlgoImage(curImage, m_Type, GrabIndex, bok);
						GrabIndex++;
						Sleep(200);
					}

					if (m_Type == CAMERA_THIRD)
					{
						bool bok = 0;
						emit SendAlgoImage(curImage, m_Type, GrabIndex, bok);
						GrabIndex++;
						Sleep(200);
					}

					if (m_Type == CAMERA_FOURTH)
					{
						bool bok = 0;
						emit SendAlgoImage(curImage, m_Type, GrabIndex, bok);
						GrabIndex++;
						Sleep(200);
					}
				}
			}
		}
	}
}
	







int RGB2BGR(unsigned char* pRgbData, unsigned int nWidth, unsigned int nHeight)
{
	if (NULL == pRgbData)
	{
		return MV_E_PARAMETER;
	}

	for (unsigned int j = 0; j < nHeight; j++)
	{
		for (unsigned int i = 0; i < nWidth; i++)
		{
			unsigned char red = pRgbData[j * (nWidth * 3) + i * 3];
			pRgbData[j * (nWidth * 3) + i * 3] = pRgbData[j * (nWidth * 3) + i * 3 + 2];
			pRgbData[j * (nWidth * 3) + i * 3 + 2] = red;
		}
	}

	return MV_OK;
}

Mat CImageCapture::Convert2Mat(MV_FRAME_OUT_INFO_EX * pstImageInfo, unsigned char * pData)
{
	Mat srcImage;
	if (pstImageInfo->enPixelType == PixelType_Gvsp_RGB8_Packed)
	{
		RGB2BGR(pData, pstImageInfo->nWidth, pstImageInfo->nHeight);
		return Mat(pstImageInfo->nHeight, pstImageInfo->nWidth, CV_8UC3, pData);
	}
	else if (pstImageInfo->enPixelType == PixelType_Gvsp_Mono8)
	{
		return Mat(pstImageInfo->nHeight, pstImageInfo->nWidth, CV_8UC1, pData);
	}
	else
	{
		//将相机图像格式转换为RGB8_Packed
		unsigned char *pDataForRGB = (unsigned char*)malloc(pstImageInfo->nWidth * pstImageInfo->nHeight * 3);
		unsigned int nDataSizeForRGB = pstImageInfo->nWidth * pstImageInfo->nHeight * 3;
		MV_CC_PIXEL_CONVERT_PARAM pstCvtParam = { 0 };
		memset(&pstCvtParam, 0, sizeof(MV_CC_PIXEL_CONVERT_PARAM));
		pstCvtParam.enSrcPixelType = pstImageInfo->enPixelType;
		pstCvtParam.nWidth = pstImageInfo->nWidth;
		pstCvtParam.nHeight = pstImageInfo->nHeight;
		pstCvtParam.pSrcData = pData;
		pstCvtParam.nSrcDataLen = pstImageInfo->nFrameLen;
		pstCvtParam.enDstPixelType = PixelType_Gvsp_RGB8_Packed;
		pstCvtParam.pDstBuffer = pDataForRGB;
		pstCvtParam.nDstBufferSize = nDataSizeForRGB;
		int nRet = m_MvCamera.ConvertPixelType(&pstCvtParam);
		if (nRet != MV_OK)
		{
			qDebug() << "Hik ConvertImageType failed :" << nRet;
			return srcImage;
		}

		RGB2BGR(pDataForRGB, pstImageInfo->nWidth, pstImageInfo->nHeight);
		srcImage = Mat(pstImageInfo->nHeight, pstImageInfo->nWidth, CV_8UC3, pDataForRGB).clone();
		delete pDataForRGB;
		pDataForRGB = NULL;
		return srcImage;
	}
}

