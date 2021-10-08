#include "adminLoginDialog.h"
#include <QMessageBox>

adminLoginDialog::adminLoginDialog(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	this->setWindowTitle(QString::fromLocal8Bit("登录"));
	
	ui.info_comboBox->addItem(QString::fromLocal8Bit("管理员"));
	ui.info_comboBox->addItem(QString::fromLocal8Bit("操作员"));

}

adminLoginDialog::~adminLoginDialog()
{

}

void adminLoginDialog::pushButtonAdminLogin()
{
	QString linePassword = ui.passwordLineEdit->text();
	if (ui.info_comboBox->currentIndex() == 0)
	{
		m_index = 0;
		m_admin.ID = ui.info_comboBox->currentText();
		m_admin.Pswd = ChangePswd::GetInstall()->GetAdminPswd();
		if (m_admin.Pswd == linePassword)
		{
			accept();
		}
		else
		{
			QMessageBox::information(this, tr("error"), tr("password error"));
		}
	}
	else if (ui.info_comboBox->currentIndex() == 1)
	{
		m_index = 1;
		m_operator.ID = ui.info_comboBox->currentText();
		m_operator.Pswd = ChangePswd::GetInstall()->GetOperatorPswd();
		if (m_operator.Pswd == linePassword)
		{
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
	this->hide();
	ChangePswd::GetInstall()->show();
}

