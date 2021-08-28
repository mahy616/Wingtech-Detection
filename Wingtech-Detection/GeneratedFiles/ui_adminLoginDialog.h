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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_adminLoginDialog
{
public:
    QComboBox *info_comboBox;
    QPushButton *Buttonchange;
    QLabel *usrLabel;
    QPushButton *adminButton;
    QLabel *passwordLabel;
    QPushButton *cancelButton;
    QLineEdit *passwordLineEdit;

    void setupUi(QDialog *adminLoginDialog)
    {
        if (adminLoginDialog->objectName().isEmpty())
            adminLoginDialog->setObjectName(QString::fromUtf8("adminLoginDialog"));
        adminLoginDialog->resize(282, 163);
        info_comboBox = new QComboBox(adminLoginDialog);
        info_comboBox->setObjectName(QString::fromUtf8("info_comboBox"));
        info_comboBox->setGeometry(QRect(60, 10, 211, 30));
        info_comboBox->setMinimumSize(QSize(110, 30));
        info_comboBox->setStyleSheet(QString::fromUtf8("background: #e9eef2;\n"
"border-radius: 4px;\n"
"padding-left: 3px;\n"
"font-size: 14px;\n"
"color: rgba(0,0,0,0.8);\n"
"border: 0px;"));
        Buttonchange = new QPushButton(adminLoginDialog);
        Buttonchange->setObjectName(QString::fromUtf8("Buttonchange"));
        Buttonchange->setGeometry(QRect(190, 100, 81, 51));
        Buttonchange->setStyleSheet(QString::fromUtf8("background: white;\n"
"border: 1px solid rgba(0,0,0,0.3);\n"
"border-radius: 4px;\n"
"color: rgba(0,0,0,0.5);\n"
"font-size: 14px;"));
        Buttonchange->setIconSize(QSize(25, 16));
        usrLabel = new QLabel(adminLoginDialog);
        usrLabel->setObjectName(QString::fromUtf8("usrLabel"));
        usrLabel->setGeometry(QRect(10, 10, 41, 30));
        usrLabel->setMinimumSize(QSize(20, 20));
        adminButton = new QPushButton(adminLoginDialog);
        adminButton->setObjectName(QString::fromUtf8("adminButton"));
        adminButton->setGeometry(QRect(10, 100, 81, 51));
        adminButton->setStyleSheet(QString::fromUtf8("background: #006db2;\n"
"border-radius: 4px;\n"
"color: white;\n"
"font-size: 14px;"));
        adminButton->setIconSize(QSize(25, 16));
        passwordLabel = new QLabel(adminLoginDialog);
        passwordLabel->setObjectName(QString::fromUtf8("passwordLabel"));
        passwordLabel->setGeometry(QRect(10, 60, 24, 16));
        cancelButton = new QPushButton(adminLoginDialog);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));
        cancelButton->setGeometry(QRect(100, 100, 81, 51));
        cancelButton->setStyleSheet(QString::fromUtf8("background: white;\n"
"border: 1px solid rgba(0,0,0,0.3);\n"
"border-radius: 4px;\n"
"color: rgba(0,0,0,0.5);\n"
"font-size: 14px;"));
        cancelButton->setIconSize(QSize(25, 16));
        passwordLineEdit = new QLineEdit(adminLoginDialog);
        passwordLineEdit->setObjectName(QString::fromUtf8("passwordLineEdit"));
        passwordLineEdit->setGeometry(QRect(60, 50, 211, 30));
        passwordLineEdit->setMinimumSize(QSize(200, 30));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        passwordLineEdit->setFont(font);
        passwordLineEdit->setStyleSheet(QString::fromUtf8("background: #f7f9fa;\n"
"border-radius: 4px;\n"
"padding-left: 2px;\n"
"font-size: 14px;\n"
"color: rgba(0,0,0,0.3);"));
        passwordLineEdit->setEchoMode(QLineEdit::Password);

        retranslateUi(adminLoginDialog);
        QObject::connect(adminButton, SIGNAL(clicked()), adminLoginDialog, SLOT(pushButtonAdminLogin()));
        QObject::connect(cancelButton, SIGNAL(clicked()), adminLoginDialog, SLOT(pushButtonCancelLogin()));
        QObject::connect(Buttonchange, SIGNAL(clicked()), adminLoginDialog, SLOT(pushButtonChangePassword()));

        QMetaObject::connectSlotsByName(adminLoginDialog);
    } // setupUi

    void retranslateUi(QDialog *adminLoginDialog)
    {
        adminLoginDialog->setWindowTitle(QCoreApplication::translate("adminLoginDialog", "adminLoginDialog", nullptr));
        Buttonchange->setText(QCoreApplication::translate("adminLoginDialog", "\344\277\256\346\224\271\345\257\206\347\240\201", nullptr));
        usrLabel->setText(QCoreApplication::translate("adminLoginDialog", "\347\224\250\346\210\267\345\220\215", nullptr));
        adminButton->setText(QCoreApplication::translate("adminLoginDialog", "\347\231\273\345\275\225", nullptr));
        passwordLabel->setText(QCoreApplication::translate("adminLoginDialog", "\345\257\206\347\240\201", nullptr));
        cancelButton->setText(QCoreApplication::translate("adminLoginDialog", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class adminLoginDialog: public Ui_adminLoginDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINLOGINDIALOG_H
