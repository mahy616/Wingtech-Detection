/********************************************************************************
** Form generated from reading UI file 'adminLoginDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINLOGINDIALOG_H
#define UI_ADMINLOGINDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_adminLoginDialog
{
public:

    void setupUi(QDialog *adminLoginDialog)
    {
        if (adminLoginDialog->objectName().isEmpty())
            adminLoginDialog->setObjectName(QString::fromUtf8("adminLoginDialog"));
        adminLoginDialog->resize(400, 300);

        retranslateUi(adminLoginDialog);

        QMetaObject::connectSlotsByName(adminLoginDialog);
    } // setupUi

    void retranslateUi(QDialog *adminLoginDialog)
    {
        adminLoginDialog->setWindowTitle(QCoreApplication::translate("adminLoginDialog", "adminLoginDialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class adminLoginDialog: public Ui_adminLoginDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINLOGINDIALOG_H
