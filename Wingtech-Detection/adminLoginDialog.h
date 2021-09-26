#pragma once

#include <QDialog>
#include "ui_adminLoginDialog.h"
#include "ChangePswd.h"
#include "ChangePswd.h"


typedef struct
{
	QString ID;
	QString Pswd;
	void Init()
	{
		ID = "";
		Pswd = "";
	}
}Account;


class adminLoginDialog : public QDialog
{
	Q_OBJECT

public:
	adminLoginDialog(QWidget *parent = Q_NULLPTR);
	~adminLoginDialog();

	int m_index{ 2 };
	QString m_ID;
	QString m_Pswd;
	Account m_operator;
	Account m_admin;
signals:
	void showChangePswdWidget();
private slots:
	void pushButtonAdminLogin();

	void pushButtonCancelLogin();

	void pushButtonChangePassword();;

private:
	Ui::adminLoginDialog ui;
	
};
