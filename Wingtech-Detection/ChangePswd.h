#pragma once

#include <QWidget>
#include "ui_ChangePswd.h"

class ChangePswd : public QWidget
{
	Q_OBJECT

public:
	static ChangePswd *GetInstall();
	void setAdminID(const QString &id);
	void setAdminPswd(const QString &m_pswd);
	const QString &GetAdminID() const;
	const QString &GetAdminPswd() const;

	void setOperatorID(const QString &id);
	void setOperatorPswd(const QString &m_pswd);
	const QString &GetOperatorID() const;
	const QString &GetOperatorPswd() const;
	
private:
	ChangePswd(QWidget *parent = Q_NULLPTR);
	~ChangePswd();

private slots:
	void confirmChangePswd();
signals:
	void signalFromChangePswd(int index, QString ID, QString Pswd);
//signals:
//	void signalFromChangeAdminPswd(QString, QString);
//signals:
//	void signalFromChangeOperatorPswd(QString, QString);
private:
	Ui::ChangePswd ui;
	static ChangePswd *m_Instance;
	QString m_adminID{"管理员" };
	QString m_adminPswd{ "123456" };

	QString m_operatorID{ "操作员" };
	QString m_operatorPswd{ "123456" };
};
