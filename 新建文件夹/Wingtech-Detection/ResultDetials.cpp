#include "ResultDetails.h"

CResultDetials *CResultDetials::m_Instance = NULL;

CResultDetials::CResultDetials(QDialog *parent)
	:QDialog(parent)
{
	ui.setupUi(this);
	Qt::WindowFlags flags = Qt::Dialog;
	flags |= Qt::WindowMinimizeButtonHint;
	flags |= Qt::WindowMaximizeButtonHint;
	flags |= Qt::WindowCloseButtonHint;
	setWindowFlags(flags);
}

CResultDetials *CResultDetials::GetInstance()
{
	if (m_Instance == NULL)
	{
		m_Instance = new CResultDetials();
	}
	return m_Instance;
}

void CResultDetials::SetImage(QImage img)
{
	ui.label->SetImage(img);
}
