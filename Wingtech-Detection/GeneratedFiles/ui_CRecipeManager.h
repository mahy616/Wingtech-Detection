/********************************************************************************
** Form generated from reading UI file 'CRecipeManager.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CRECIPEMANAGER_H
#define UI_CRECIPEMANAGER_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_CRecipeManagerClass
{
public:
    QGridLayout *gridLayout;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer;
    QComboBox *comboBox;
    QLabel *label;
    QTableWidget *tableWidget;
    QPushButton *pushButton_deleteRecipe;

    void setupUi(QDialog *CRecipeManagerClass)
    {
        if (CRecipeManagerClass->objectName().isEmpty())
            CRecipeManagerClass->setObjectName(QString::fromUtf8("CRecipeManagerClass"));
        CRecipeManagerClass->resize(856, 638);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/CRecipeManager/Resources/recipe.png"), QSize(), QIcon::Normal, QIcon::Off);
        CRecipeManagerClass->setWindowIcon(icon);
        CRecipeManagerClass->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        gridLayout = new QGridLayout(CRecipeManagerClass);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        pushButton = new QPushButton(CRecipeManagerClass);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout->addWidget(pushButton, 1, 4, 1, 1);

        horizontalSpacer = new QSpacerItem(378, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 2, 1, 1);

        comboBox = new QComboBox(CRecipeManagerClass);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setMinimumSize(QSize(300, 0));

        gridLayout->addWidget(comboBox, 1, 1, 1, 1);

        label = new QLabel(CRecipeManagerClass);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 1, 0, 1, 1);

        tableWidget = new QTableWidget(CRecipeManagerClass);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));

        gridLayout->addWidget(tableWidget, 2, 0, 1, 5);

        pushButton_deleteRecipe = new QPushButton(CRecipeManagerClass);
        pushButton_deleteRecipe->setObjectName(QString::fromUtf8("pushButton_deleteRecipe"));

        gridLayout->addWidget(pushButton_deleteRecipe, 1, 3, 1, 1);


        retranslateUi(CRecipeManagerClass);
        QObject::connect(comboBox, SIGNAL(activated(QString)), CRecipeManagerClass, SLOT(SwitchRecipe(QString)));
        QObject::connect(pushButton, SIGNAL(clicked()), CRecipeManagerClass, SLOT(SaveRecipe()));

        QMetaObject::connectSlotsByName(CRecipeManagerClass);
    } // setupUi

    void retranslateUi(QDialog *CRecipeManagerClass)
    {
        CRecipeManagerClass->setWindowTitle(QCoreApplication::translate("CRecipeManagerClass", "\351\205\215\346\226\271\347\256\241\347\220\206", nullptr));
        pushButton->setText(QCoreApplication::translate("CRecipeManagerClass", "\344\277\235\345\255\230\351\205\215\346\226\271", nullptr));
        label->setText(QCoreApplication::translate("CRecipeManagerClass", "\351\205\215\346\226\271\345\210\207\346\215\242", nullptr));
        pushButton_deleteRecipe->setText(QCoreApplication::translate("CRecipeManagerClass", "\345\210\240\351\231\244\351\205\215\346\226\271", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CRecipeManagerClass: public Ui_CRecipeManagerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CRECIPEMANAGER_H
