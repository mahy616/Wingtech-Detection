#pragma once

#include "ui_ResultDetails.h"
#include "MyLabel.h"

class CResultDetials :public QDialog
{
	Q_OBJECT
public:
	static CResultDetials *GetInstance();
	void SetImage(QImage img);
private:
	Ui::DialogDetials ui;
	CResultDetials(QDialog *parent = NULL);
	static CResultDetials *m_Instance;
};
