#include "adminLoginDialog.h"
#include <QMessageBox>

adminLoginDialog::adminLoginDialog(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	this->setWindowTitle(QString::fromLocal8Bit("��¼"));
	
	ui.info_comboBox->addItem(QString::fromLocal8Bit("����Ա"));
	ui.info_comboBox->addItem(QString::fromLocal8Bit("����Ա"));

}

adminLoginDialog::~adminLoginDialog()
{

}

void adminLoginDialog::pushButtonAdminLogin()
{
	QString adminPassword;
	QString linePassword = ui.passwordLineEdit->text();
	if (ui.info_comboBox->currentIndex() == 0)
	{
		adminPassword = "1";
		if (adminPassword == linePassword)
		{
			adminctrl = 1;
			accept();
		}
		else
		{
			QMessageBox::information(this, tr("error"), tr("password error"));
		}
	}
	else if (ui.info_comboBox->currentIndex() == 1)
	{
		adminPassword = "2";
		if (adminPassword == linePassword)
		{
			adminctrl = 2;
			accept();
		}
		else
		{
			QMessageBox::information(this, tr("error"), tr("password error"));
		}
	}
}

void adminLoginDialog::pushButtonCancelLogin()
{
	reject();
}

void adminLoginDialog::pushButtonChangePassword()
{

}
