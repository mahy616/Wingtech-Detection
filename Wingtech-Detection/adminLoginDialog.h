#pragma once

#include <QDialog>
#include "ui_adminLoginDialog.h"

class adminLoginDialog : public QDialog
{
	Q_OBJECT

public:
	adminLoginDialog(QWidget *parent = Q_NULLPTR);
	~adminLoginDialog();

	int adminctrl{ 0 };
private slots:
	void pushButtonAdminLogin();

	void pushButtonCancelLogin();

	void pushButtonChangePassword();;

private:
	Ui::adminLoginDialog ui;


};
