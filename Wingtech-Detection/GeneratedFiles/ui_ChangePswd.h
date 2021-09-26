/********************************************************************************
** Form generated from reading UI file 'ChangePswd.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHANGEPSWD_H
#define UI_CHANGEPSWD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChangePswd
{
public:
    QLabel *passwordLabel;
    QLineEdit *OriginalPasswordLineEdit;
    QLabel *passwordLabel_2;
    QLineEdit *NewPasswordLineEdit;
    QLabel *passwordLabel_3;
    QLineEdit *ConfirmPasswordLineEdit;
    QPushButton *ConfirmChangePushButton;
    QComboBox *info_comboBox;
    QLabel *passwordLabel_4;

    void setupUi(QWidget *ChangePswd)
    {
        if (ChangePswd->objectName().isEmpty())
            ChangePswd->setObjectName(QString::fromUtf8("ChangePswd"));
        ChangePswd->resize(316, 249);
        passwordLabel = new QLabel(ChangePswd);
        passwordLabel->setObjectName(QString::fromUtf8("passwordLabel"));
        passwordLabel->setGeometry(QRect(10, 80, 61, 20));
        OriginalPasswordLineEdit = new QLineEdit(ChangePswd);
        OriginalPasswordLineEdit->setObjectName(QString::fromUtf8("OriginalPasswordLineEdit"));
        OriginalPasswordLineEdit->setGeometry(QRect(97, 70, 211, 30));
        OriginalPasswordLineEdit->setMinimumSize(QSize(200, 30));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        OriginalPasswordLineEdit->setFont(font);
        OriginalPasswordLineEdit->setStyleSheet(QString::fromUtf8("background: #f7f9fa;\n"
"border-radius: 4px;\n"
"padding-left: 2px;\n"
"font-size: 14px;\n"
"color: rgba(0,0,0,0.3);"));
        OriginalPasswordLineEdit->setEchoMode(QLineEdit::Password);
        passwordLabel_2 = new QLabel(ChangePswd);
        passwordLabel_2->setObjectName(QString::fromUtf8("passwordLabel_2"));
        passwordLabel_2->setGeometry(QRect(10, 130, 61, 20));
        NewPasswordLineEdit = new QLineEdit(ChangePswd);
        NewPasswordLineEdit->setObjectName(QString::fromUtf8("NewPasswordLineEdit"));
        NewPasswordLineEdit->setGeometry(QRect(97, 120, 211, 30));
        NewPasswordLineEdit->setMinimumSize(QSize(200, 30));
        NewPasswordLineEdit->setFont(font);
        NewPasswordLineEdit->setStyleSheet(QString::fromUtf8("background: #f7f9fa;\n"
"border-radius: 4px;\n"
"padding-left: 2px;\n"
"font-size: 14px;\n"
"color: rgba(0,0,0,0.3);"));
        NewPasswordLineEdit->setEchoMode(QLineEdit::Password);
        passwordLabel_3 = new QLabel(ChangePswd);
        passwordLabel_3->setObjectName(QString::fromUtf8("passwordLabel_3"));
        passwordLabel_3->setGeometry(QRect(10, 170, 61, 20));
        ConfirmPasswordLineEdit = new QLineEdit(ChangePswd);
        ConfirmPasswordLineEdit->setObjectName(QString::fromUtf8("ConfirmPasswordLineEdit"));
        ConfirmPasswordLineEdit->setGeometry(QRect(97, 160, 211, 30));
        ConfirmPasswordLineEdit->setMinimumSize(QSize(200, 30));
        ConfirmPasswordLineEdit->setFont(font);
        ConfirmPasswordLineEdit->setStyleSheet(QString::fromUtf8("background: #f7f9fa;\n"
"border-radius: 4px;\n"
"padding-left: 2px;\n"
"font-size: 14px;\n"
"color: rgba(0,0,0,0.3);"));
        ConfirmPasswordLineEdit->setEchoMode(QLineEdit::Password);
        ConfirmChangePushButton = new QPushButton(ChangePswd);
        ConfirmChangePushButton->setObjectName(QString::fromUtf8("ConfirmChangePushButton"));
        ConfirmChangePushButton->setGeometry(QRect(230, 200, 81, 41));
        ConfirmChangePushButton->setStyleSheet(QString::fromUtf8("background: white;\n"
"border: 1px solid rgba(0,0,0,0.3);\n"
"border-radius: 4px;\n"
"color: rgba(0,0,0,0.5);\n"
"font-size: 14px;"));
        ConfirmChangePushButton->setIconSize(QSize(25, 16));
        info_comboBox = new QComboBox(ChangePswd);
        info_comboBox->setObjectName(QString::fromUtf8("info_comboBox"));
        info_comboBox->setGeometry(QRect(100, 20, 211, 30));
        info_comboBox->setMinimumSize(QSize(110, 30));
        info_comboBox->setStyleSheet(QString::fromUtf8("background: #e9eef2;\n"
"border-radius: 4px;\n"
"padding-left: 3px;\n"
"font-size: 14px;\n"
"color: rgba(0,0,0,0.8);\n"
"border: 0px;"));
        passwordLabel_4 = new QLabel(ChangePswd);
        passwordLabel_4->setObjectName(QString::fromUtf8("passwordLabel_4"));
        passwordLabel_4->setGeometry(QRect(10, 30, 71, 20));

        retranslateUi(ChangePswd);
        QObject::connect(ConfirmChangePushButton, SIGNAL(clicked()), ChangePswd, SLOT(confirmChangePswd()));

        QMetaObject::connectSlotsByName(ChangePswd);
    } // setupUi

    void retranslateUi(QWidget *ChangePswd)
    {
        ChangePswd->setWindowTitle(QCoreApplication::translate("ChangePswd", "ChangePswd", nullptr));
        passwordLabel->setText(QCoreApplication::translate("ChangePswd", "\345\216\237\345\257\206\347\240\201\357\274\232", nullptr));
        passwordLabel_2->setText(QCoreApplication::translate("ChangePswd", "\346\226\260\345\257\206\347\240\201\357\274\232", nullptr));
        passwordLabel_3->setText(QCoreApplication::translate("ChangePswd", "\347\241\256\350\256\244\345\257\206\347\240\201\357\274\232", nullptr));
        ConfirmChangePushButton->setText(QCoreApplication::translate("ChangePswd", "\347\241\256\350\256\244\344\277\256\346\224\271", nullptr));
        passwordLabel_4->setText(QCoreApplication::translate("ChangePswd", "\351\200\211\346\213\251\350\272\253\344\273\275\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChangePswd: public Ui_ChangePswd {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHANGEPSWD_H
