/********************************************************************************
** Form generated from reading UI file 'CMainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CMAINWINDOW_H
#define UI_CMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CMainWindowClass
{
public:
    QAction *action_Start;
    QAction *action_Stop;
    QAction *action_Setting;
    QAction *action_Recipe;
    QAction *action_admin;
    QWidget *centralWidget;
    QGridLayout *gridLayout_6;
    QGroupBox *groupBox_Cam1;
    QGridLayout *gridLayout;
    QLabel *label_Image1;
    QGroupBox *groupBox_Cam2;
    QGridLayout *gridLayout_2;
    QLabel *label_Image2;
    QGroupBox *groupBox_Cam3;
    QGridLayout *gridLayout_3;
    QLabel *label_Image3;
    QGroupBox *groupBox_Cam4;
    QGridLayout *gridLayout_4;
    QLabel *label_Image4;
    QGroupBox *groupBox_5;
    QGridLayout *gridLayout_5;
    QGroupBox *groupBox_1;
    QGroupBox *groupBox_2;
    QGroupBox *groupBox_3;
    QGroupBox *groupBox_4;
    QStatusBar *statusBar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *CMainWindowClass)
    {
        if (CMainWindowClass->objectName().isEmpty())
            CMainWindowClass->setObjectName(QString::fromUtf8("CMainWindowClass"));
        CMainWindowClass->resize(1545, 855);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/CMainWindow/Resources/app.ico"), QSize(), QIcon::Normal, QIcon::Off);
        CMainWindowClass->setWindowIcon(icon);
        CMainWindowClass->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        action_Start = new QAction(CMainWindowClass);
        action_Start->setObjectName(QString::fromUtf8("action_Start"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/CMainWindow/Resources/start.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Start->setIcon(icon1);
        action_Stop = new QAction(CMainWindowClass);
        action_Stop->setObjectName(QString::fromUtf8("action_Stop"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/CMainWindow/Resources/stop.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Stop->setIcon(icon2);
        action_Setting = new QAction(CMainWindowClass);
        action_Setting->setObjectName(QString::fromUtf8("action_Setting"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/CMainWindow/Resources/settings.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Setting->setIcon(icon3);
        action_Recipe = new QAction(CMainWindowClass);
        action_Recipe->setObjectName(QString::fromUtf8("action_Recipe"));
        action_Recipe->setIcon(icon3);
        action_admin = new QAction(CMainWindowClass);
        action_admin->setObjectName(QString::fromUtf8("action_admin"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/CMainWindow/Resources/admin.ico"), QSize(), QIcon::Normal, QIcon::Off);
        action_admin->setIcon(icon4);
        centralWidget = new QWidget(CMainWindowClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout_6 = new QGridLayout(centralWidget);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        groupBox_Cam1 = new QGroupBox(centralWidget);
        groupBox_Cam1->setObjectName(QString::fromUtf8("groupBox_Cam1"));
        gridLayout = new QGridLayout(groupBox_Cam1);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_Image1 = new QLabel(groupBox_Cam1);
        label_Image1->setObjectName(QString::fromUtf8("label_Image1"));
        label_Image1->setStyleSheet(QString::fromUtf8("background-image: url(:/CMainWindow/Resources/background.png);"));

        gridLayout->addWidget(label_Image1, 0, 0, 1, 1);


        gridLayout_6->addWidget(groupBox_Cam1, 0, 0, 1, 1);

        groupBox_Cam2 = new QGroupBox(centralWidget);
        groupBox_Cam2->setObjectName(QString::fromUtf8("groupBox_Cam2"));
        gridLayout_2 = new QGridLayout(groupBox_Cam2);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_Image2 = new QLabel(groupBox_Cam2);
        label_Image2->setObjectName(QString::fromUtf8("label_Image2"));
        label_Image2->setStyleSheet(QString::fromUtf8("background-image: url(:/CMainWindow/Resources/background.png);"));

        gridLayout_2->addWidget(label_Image2, 0, 0, 1, 1);


        gridLayout_6->addWidget(groupBox_Cam2, 0, 1, 1, 1);

        groupBox_Cam3 = new QGroupBox(centralWidget);
        groupBox_Cam3->setObjectName(QString::fromUtf8("groupBox_Cam3"));
        gridLayout_3 = new QGridLayout(groupBox_Cam3);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label_Image3 = new QLabel(groupBox_Cam3);
        label_Image3->setObjectName(QString::fromUtf8("label_Image3"));
        label_Image3->setStyleSheet(QString::fromUtf8("background-image: url(:/CMainWindow/Resources/background.png);"));

        gridLayout_3->addWidget(label_Image3, 0, 0, 1, 1);


        gridLayout_6->addWidget(groupBox_Cam3, 0, 2, 1, 1);

        groupBox_Cam4 = new QGroupBox(centralWidget);
        groupBox_Cam4->setObjectName(QString::fromUtf8("groupBox_Cam4"));
        gridLayout_4 = new QGridLayout(groupBox_Cam4);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        label_Image4 = new QLabel(groupBox_Cam4);
        label_Image4->setObjectName(QString::fromUtf8("label_Image4"));
        label_Image4->setStyleSheet(QString::fromUtf8("background-image: url(:/CMainWindow/Resources/background.png);"));

        gridLayout_4->addWidget(label_Image4, 0, 0, 1, 1);


        gridLayout_6->addWidget(groupBox_Cam4, 0, 3, 1, 1);

        groupBox_5 = new QGroupBox(centralWidget);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        gridLayout_5 = new QGridLayout(groupBox_5);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        groupBox_1 = new QGroupBox(groupBox_5);
        groupBox_1->setObjectName(QString::fromUtf8("groupBox_1"));
        groupBox_1->setMouseTracking(true);

        gridLayout_5->addWidget(groupBox_1, 0, 0, 1, 1);

        groupBox_2 = new QGroupBox(groupBox_5);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setMouseTracking(true);

        gridLayout_5->addWidget(groupBox_2, 0, 1, 1, 1);

        groupBox_3 = new QGroupBox(groupBox_5);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setMouseTracking(true);

        gridLayout_5->addWidget(groupBox_3, 0, 2, 1, 1);

        groupBox_4 = new QGroupBox(groupBox_5);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setMouseTracking(true);

        gridLayout_5->addWidget(groupBox_4, 0, 3, 1, 1);


        gridLayout_6->addWidget(groupBox_5, 1, 0, 1, 4);

        CMainWindowClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(CMainWindowClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        CMainWindowClass->setStatusBar(statusBar);
        toolBar = new QToolBar(CMainWindowClass);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        toolBar->setIconSize(QSize(50, 50));
        toolBar->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        CMainWindowClass->addToolBar(Qt::TopToolBarArea, toolBar);

        toolBar->addAction(action_Start);
        toolBar->addAction(action_Stop);
        toolBar->addAction(action_Setting);
        toolBar->addAction(action_Recipe);
        toolBar->addAction(action_admin);

        retranslateUi(CMainWindowClass);

        QMetaObject::connectSlotsByName(CMainWindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *CMainWindowClass)
    {
        CMainWindowClass->setWindowTitle(QCoreApplication::translate("CMainWindowClass", "\351\227\273\346\263\260\344\270\255\346\241\206\346\243\200\346\265\213\350\275\257\344\273\266_V1.0,0", nullptr));
        action_Start->setText(QCoreApplication::translate("CMainWindowClass", "\345\274\200\345\247\213\346\243\200\346\265\213", nullptr));
        action_Stop->setText(QCoreApplication::translate("CMainWindowClass", "\345\201\234\346\255\242\346\243\200\346\265\213", nullptr));
        action_Setting->setText(QCoreApplication::translate("CMainWindowClass", "\345\217\202\346\225\260\350\256\276\347\275\256", nullptr));
        action_Recipe->setText(QCoreApplication::translate("CMainWindowClass", "\351\205\215\346\226\271\350\256\276\347\275\256", nullptr));
        action_admin->setText(QCoreApplication::translate("CMainWindowClass", "\347\224\250\346\210\267\347\231\273\345\275\225", nullptr));
#if QT_CONFIG(tooltip)
        action_admin->setToolTip(QCoreApplication::translate("CMainWindowClass", "\347\224\250\346\210\267\347\231\273\345\275\225", nullptr));
#endif // QT_CONFIG(tooltip)
        groupBox_Cam1->setTitle(QCoreApplication::translate("CMainWindowClass", "\345\267\245\344\275\215\344\270\200", nullptr));
        label_Image1->setText(QString());
        groupBox_Cam2->setTitle(QCoreApplication::translate("CMainWindowClass", "\345\267\245\344\275\215\344\272\214", nullptr));
        label_Image2->setText(QString());
        groupBox_Cam3->setTitle(QCoreApplication::translate("CMainWindowClass", "\345\267\245\344\275\215\344\270\211", nullptr));
        label_Image3->setText(QString());
        groupBox_Cam4->setTitle(QCoreApplication::translate("CMainWindowClass", "\345\267\245\344\275\215\345\233\233", nullptr));
        label_Image4->setText(QString());
        groupBox_5->setTitle(QCoreApplication::translate("CMainWindowClass", "\346\230\216\347\273\206", nullptr));
        groupBox_1->setTitle(QCoreApplication::translate("CMainWindowClass", "\345\267\245\344\275\215\344\270\200", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("CMainWindowClass", "\345\267\245\344\275\215\344\272\214", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("CMainWindowClass", "\345\267\245\344\275\215\344\270\211", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("CMainWindowClass", "\345\267\245\344\275\215\345\233\233", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("CMainWindowClass", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CMainWindowClass: public Ui_CMainWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CMAINWINDOW_H
