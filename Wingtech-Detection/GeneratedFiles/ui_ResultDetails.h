/********************************************************************************
** Form generated from reading UI file 'ResultDetails.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RESULTDETAILS_H
#define UI_RESULTDETAILS_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <mylabel.h>

QT_BEGIN_NAMESPACE

class Ui_DialogDetials
{
public:
    QGridLayout *gridLayout;
    MyLabel *label;

    void setupUi(QDialog *DialogDetials)
    {
        if (DialogDetials->objectName().isEmpty())
            DialogDetials->setObjectName(QString::fromUtf8("DialogDetials"));
        DialogDetials->resize(1203, 800);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/CMainWindow/Resources/Details.png"), QSize(), QIcon::Normal, QIcon::Off);
        DialogDetials->setWindowIcon(icon);
        gridLayout = new QGridLayout(DialogDetials);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new MyLabel(DialogDetials);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8("background-image: url(:/CMainWindow/Resources/background.png);"));

        gridLayout->addWidget(label, 0, 0, 1, 1);


        retranslateUi(DialogDetials);

        QMetaObject::connectSlotsByName(DialogDetials);
    } // setupUi

    void retranslateUi(QDialog *DialogDetials)
    {
        DialogDetials->setWindowTitle(QCoreApplication::translate("DialogDetials", "\346\243\200\346\265\213\350\257\246\347\273\206\344\277\241\346\201\257", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class DialogDetials: public Ui_DialogDetials {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RESULTDETAILS_H
