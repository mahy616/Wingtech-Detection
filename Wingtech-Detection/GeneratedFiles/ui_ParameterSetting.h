/********************************************************************************
** Form generated from reading UI file 'ParameterSetting.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PARAMETERSETTING_H
#define UI_PARAMETERSETTING_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>
#include <mylabel.h>

QT_BEGIN_NAMESPACE

class Ui_DialogSetting
{
public:
    QGridLayout *gridLayout_2;
    QGroupBox *groupBox_8;
    QGridLayout *gridLayout_9;
    QCheckBox *checkBox_RenderThird;
    QLabel *label_ThirdResult;
    MyLabel *label_ThirdImage;
    QLabel *label_ThirdTime;
    QGroupBox *groupBox_6;
    QGridLayout *gridLayout_6;
    QLabel *label_SecondResult;
    MyLabel *label_SecondImage;
    QLabel *label_SecondTime;
    QCheckBox *checkBox_RenderSecond;
    QGroupBox *groupBox_9;
    QGridLayout *gridLayout_10;
    QLabel *label_FourthResult;
    MyLabel *label_FourthImage;
    QLabel *label_FourthTime;
    QCheckBox *checkBox_RenderFourth;
    QGroupBox *groupBox_5;
    QGridLayout *gridLayout_5;
    QLabel *label_FirstResult;
    QLabel *label_FirstTime;
    MyLabel *label_FirstImage;
    QCheckBox *checkBox_RenderFirst;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGridLayout *gridLayout_7;
    QGroupBox *groupBox_Frist_4;
    QGridLayout *gridLayout_19;
    QLabel *label_17;
    QRadioButton *radioButton_ExternalThird;
    QCheckBox *checkBox_SaveOK_Third;
    QRadioButton *radioButton_SoftThird;
    QPushButton *pushButton_TriggerThird;
    QLabel *label_First_5;
    QComboBox *comboBox_Third;
    QPushButton *pushButton_OpenThird;
    QPushButton *pushButton_LoadOKPath_Third;
    QRadioButton *radioButton_FreeThird;
    QPushButton *pushButton_LoadNGPath_Third;
    QCheckBox *checkBox_SaveNG_Third;
    QLineEdit *lineEdit_OKPath_Third;
    QLineEdit *le_exposure_3;
    QLineEdit *lineEdit_NGPath_Third;
    QLabel *label_18;
    QPushButton *pushButton_SaveParams_Third;
    QLineEdit *le_gain_3;
    QGroupBox *groupBox_Frist_5;
    QGridLayout *gridLayout_25;
    QPushButton *pushButton_LoadOKPath_Fourth;
    QLabel *label_31;
    QLabel *label_First_6;
    QLineEdit *le_exposure_4;
    QPushButton *pushButton_SaveParams_Fourth;
    QLineEdit *lineEdit_OKPath_Fourth;
    QPushButton *pushButton_OpenFourth;
    QLineEdit *lineEdit_NGPath_Fourth;
    QLineEdit *le_gain_4;
    QRadioButton *radioButton_ExternalFourth;
    QRadioButton *radioButton_FreeFourth;
    QComboBox *comboBox_Four;
    QRadioButton *radioButton_SoftFourth;
    QCheckBox *checkBox_SaveNG_Fourth;
    QLabel *label_32;
    QCheckBox *checkBox_SaveOK_Fourth;
    QPushButton *pushButton_LoadNGPath_Fourth;
    QPushButton *pushButton_TriggerFourth;
    QGroupBox *groupBox_Frist_3;
    QGridLayout *gridLayout_18;
    QPushButton *pushButton_OpenSecond;
    QLineEdit *lineEdit_NGPath_Second;
    QLineEdit *le_exposure_2;
    QLineEdit *le_gain_2;
    QPushButton *pushButton_SaveParams_Second;
    QRadioButton *radioButton_ExternalSecond;
    QPushButton *pushButton_TriggerSecond;
    QCheckBox *checkBox_SaveNG_Second;
    QLineEdit *lineEdit_OKPath_Second;
    QLabel *label_16;
    QLabel *label_First_4;
    QPushButton *pushButton_LoadNGPath_Second;
    QCheckBox *checkBox_SaveOK_Second;
    QRadioButton *radioButton_FreeSecond;
    QPushButton *pushButton_LoadOKPath_Second;
    QRadioButton *radioButton_SoftSecond;
    QLabel *label_15;
    QComboBox *comboBox_Second;
    QGroupBox *groupBox_Frist;
    QGridLayout *gridLayout;
    QLabel *label;
    QRadioButton *radioButton_FreeFirst;
    QPushButton *pushButton_LoadNGPath_First;
    QCheckBox *checkBox_SaveOK_First;
    QPushButton *pushButton_LoadOKPath_First;
    QLabel *label_First;
    QComboBox *comboBox_First;
    QLabel *label_4;
    QLineEdit *lineEdit_NGPath_First;
    QPushButton *pushButton_OpenFirst;
    QPushButton *pushButton_SaveParams;
    QPushButton *pushButton_TriggerFirst;
    QLineEdit *lineEdit_OKPath_First;
    QLineEdit *le_gain_1;
    QRadioButton *radioButton_SoftFirst;
    QRadioButton *radioButton_ExternalFirst;
    QCheckBox *checkBox_SaveNG_First;
    QLineEdit *le_exposure_1;
    QPushButton *pushButton_SaveConfig;
    QWidget *tab_2;
    QGroupBox *groupBox_7;
    QGridLayout *gridLayout_8;
    QLabel *label_2;
    QLineEdit *lineEdit_MachineCode;
    QPushButton *pushButton_Copy;
    QLabel *label_3;
    QLineEdit *lineEdit_RegisterCode;
    QPushButton *pushButton_Register;
    QLabel *label_RegisterInfo;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout_3;
    QPushButton *pushButton_LoadFirstImage;
    QLabel *label_8;
    QPushButton *pushButton_LoadThirdImage;
    QPushButton *pushButton_LoadFourthImage;
    QPushButton *pushButton_LoadSecondImage;
    QComboBox *comboBox_SystemType;
    QGroupBox *groupBox_10;
    QGridLayout *gridLayout_4;
    QLabel *label_5;
    QLineEdit *lineEdit_IP;
    QLabel *label_6;
    QLineEdit *lineEdit_Port;
    QLabel *label_7;
    QSpinBox *spinBox_Heartbeat;
    QPushButton *pushButton_SendOK;
    QPushButton *pushButton_SendNG;
    QLabel *label_Status;
    QPushButton *pushButton_ConnectPLC;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_16;
    QLabel *label_22;
    QLabel *label_19;
    QLabel *label_20;
    QSpinBox *spinBox_Area_YaShang;
    QSpinBox *spinBox_Wh_YaShang;
    QLabel *label_23;
    QSpinBox *spinBox_Area_PengShang;
    QSpinBox *spinBox_Wh_PengShang;
    QLabel *label_21;
    QSpinBox *spinBox_Area_HuaShang;
    QSpinBox *spinBox_Wh_HuaShang;
    QLabel *label_24;
    QSpinBox *spinBox_Area_CaShang;
    QSpinBox *spinBox_Wh_CaShang;
    QLabel *label_41;
    QSpinBox *spinBox_Area_TieFen;
    QSpinBox *spinBox_Wh_TieFen;
    QWidget *tab_3;
    QComboBox *comboBox_Formula;
    QPushButton *pushButton_3;

    void setupUi(QDialog *DialogSetting)
    {
        if (DialogSetting->objectName().isEmpty())
            DialogSetting->setObjectName(QString::fromUtf8("DialogSetting"));
        DialogSetting->resize(1720, 1011);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/CMainWindow/Resources/settings.png"), QSize(), QIcon::Normal, QIcon::Off);
        DialogSetting->setWindowIcon(icon);
        DialogSetting->setStyleSheet(QString::fromUtf8("font: 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(0, 85, 0);"));
        gridLayout_2 = new QGridLayout(DialogSetting);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        groupBox_8 = new QGroupBox(DialogSetting);
        groupBox_8->setObjectName(QString::fromUtf8("groupBox_8"));
        gridLayout_9 = new QGridLayout(groupBox_8);
        gridLayout_9->setSpacing(0);
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        gridLayout_9->setContentsMargins(0, 0, 0, 0);
        checkBox_RenderThird = new QCheckBox(groupBox_8);
        checkBox_RenderThird->setObjectName(QString::fromUtf8("checkBox_RenderThird"));
        checkBox_RenderThird->setMaximumSize(QSize(16777215, 51));
        checkBox_RenderThird->setChecked(true);

        gridLayout_9->addWidget(checkBox_RenderThird, 0, 1, 1, 1);

        label_ThirdResult = new QLabel(groupBox_8);
        label_ThirdResult->setObjectName(QString::fromUtf8("label_ThirdResult"));
        label_ThirdResult->setMinimumSize(QSize(151, 0));
        label_ThirdResult->setMaximumSize(QSize(151, 51));
        label_ThirdResult->setStyleSheet(QString::fromUtf8("image: url(:/CMainWindow/Resources/OK.svg);"));

        gridLayout_9->addWidget(label_ThirdResult, 0, 2, 1, 1);

        label_ThirdImage = new MyLabel(groupBox_8);
        label_ThirdImage->setObjectName(QString::fromUtf8("label_ThirdImage"));
        label_ThirdImage->setStyleSheet(QString::fromUtf8("background-image: url(:/CMainWindow/Resources/background.png);"));

        gridLayout_9->addWidget(label_ThirdImage, 1, 0, 1, 3);

        label_ThirdTime = new QLabel(groupBox_8);
        label_ThirdTime->setObjectName(QString::fromUtf8("label_ThirdTime"));
        label_ThirdTime->setMinimumSize(QSize(241, 0));
        label_ThirdTime->setMaximumSize(QSize(241, 51));
        label_ThirdTime->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 255, 255);\n"
"color: rgb(85, 0, 255);"));

        gridLayout_9->addWidget(label_ThirdTime, 0, 0, 1, 1);


        gridLayout_2->addWidget(groupBox_8, 1, 1, 1, 1);

        groupBox_6 = new QGroupBox(DialogSetting);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        gridLayout_6 = new QGridLayout(groupBox_6);
        gridLayout_6->setSpacing(0);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        gridLayout_6->setContentsMargins(0, 0, 0, 0);
        label_SecondResult = new QLabel(groupBox_6);
        label_SecondResult->setObjectName(QString::fromUtf8("label_SecondResult"));
        label_SecondResult->setMinimumSize(QSize(151, 0));
        label_SecondResult->setMaximumSize(QSize(151, 51));
        label_SecondResult->setStyleSheet(QString::fromUtf8("image: url(:/CMainWindow/Resources/OK.svg);"));

        gridLayout_6->addWidget(label_SecondResult, 0, 2, 1, 1);

        label_SecondImage = new MyLabel(groupBox_6);
        label_SecondImage->setObjectName(QString::fromUtf8("label_SecondImage"));
        label_SecondImage->setStyleSheet(QString::fromUtf8("background-image: url(:/CMainWindow/Resources/background.png);"));

        gridLayout_6->addWidget(label_SecondImage, 1, 0, 1, 3);

        label_SecondTime = new QLabel(groupBox_6);
        label_SecondTime->setObjectName(QString::fromUtf8("label_SecondTime"));
        label_SecondTime->setMinimumSize(QSize(241, 0));
        label_SecondTime->setMaximumSize(QSize(241, 51));
        label_SecondTime->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 255, 255);\n"
"color: rgb(85, 0, 255);"));

        gridLayout_6->addWidget(label_SecondTime, 0, 0, 1, 1);

        checkBox_RenderSecond = new QCheckBox(groupBox_6);
        checkBox_RenderSecond->setObjectName(QString::fromUtf8("checkBox_RenderSecond"));
        checkBox_RenderSecond->setMaximumSize(QSize(16777215, 51));
        checkBox_RenderSecond->setChecked(true);

        gridLayout_6->addWidget(checkBox_RenderSecond, 0, 1, 1, 1);


        gridLayout_2->addWidget(groupBox_6, 0, 2, 1, 1);

        groupBox_9 = new QGroupBox(DialogSetting);
        groupBox_9->setObjectName(QString::fromUtf8("groupBox_9"));
        gridLayout_10 = new QGridLayout(groupBox_9);
        gridLayout_10->setSpacing(0);
        gridLayout_10->setObjectName(QString::fromUtf8("gridLayout_10"));
        gridLayout_10->setContentsMargins(0, 0, 0, 0);
        label_FourthResult = new QLabel(groupBox_9);
        label_FourthResult->setObjectName(QString::fromUtf8("label_FourthResult"));
        label_FourthResult->setMinimumSize(QSize(151, 0));
        label_FourthResult->setMaximumSize(QSize(151, 51));
        label_FourthResult->setStyleSheet(QString::fromUtf8("image: url(:/CMainWindow/Resources/OK.svg);"));

        gridLayout_10->addWidget(label_FourthResult, 0, 2, 1, 1);

        label_FourthImage = new MyLabel(groupBox_9);
        label_FourthImage->setObjectName(QString::fromUtf8("label_FourthImage"));
        label_FourthImage->setStyleSheet(QString::fromUtf8("background-image: url(:/CMainWindow/Resources/background.png);"));

        gridLayout_10->addWidget(label_FourthImage, 1, 0, 1, 3);

        label_FourthTime = new QLabel(groupBox_9);
        label_FourthTime->setObjectName(QString::fromUtf8("label_FourthTime"));
        label_FourthTime->setMinimumSize(QSize(241, 0));
        label_FourthTime->setMaximumSize(QSize(241, 51));
        label_FourthTime->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 255, 255);\n"
"color: rgb(85, 0, 255);"));

        gridLayout_10->addWidget(label_FourthTime, 0, 0, 1, 1);

        checkBox_RenderFourth = new QCheckBox(groupBox_9);
        checkBox_RenderFourth->setObjectName(QString::fromUtf8("checkBox_RenderFourth"));
        checkBox_RenderFourth->setMaximumSize(QSize(16777215, 51));
        checkBox_RenderFourth->setChecked(true);

        gridLayout_10->addWidget(checkBox_RenderFourth, 0, 1, 1, 1);


        gridLayout_2->addWidget(groupBox_9, 1, 2, 1, 1);

        groupBox_5 = new QGroupBox(DialogSetting);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        gridLayout_5 = new QGridLayout(groupBox_5);
        gridLayout_5->setSpacing(0);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_5->setContentsMargins(0, 0, 0, 0);
        label_FirstResult = new QLabel(groupBox_5);
        label_FirstResult->setObjectName(QString::fromUtf8("label_FirstResult"));
        label_FirstResult->setMinimumSize(QSize(151, 0));
        label_FirstResult->setMaximumSize(QSize(151, 51));
        label_FirstResult->setStyleSheet(QString::fromUtf8("image: url(:/CMainWindow/Resources/OK.svg);"));

        gridLayout_5->addWidget(label_FirstResult, 0, 2, 1, 1);

        label_FirstTime = new QLabel(groupBox_5);
        label_FirstTime->setObjectName(QString::fromUtf8("label_FirstTime"));
        label_FirstTime->setMinimumSize(QSize(241, 0));
        label_FirstTime->setMaximumSize(QSize(241, 51));
        label_FirstTime->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 255, 255);\n"
"color: rgb(85, 0, 255);"));

        gridLayout_5->addWidget(label_FirstTime, 0, 0, 1, 1);

        label_FirstImage = new MyLabel(groupBox_5);
        label_FirstImage->setObjectName(QString::fromUtf8("label_FirstImage"));
        label_FirstImage->setStyleSheet(QString::fromUtf8("background-image: url(:/CMainWindow/Resources/background.png);"));

        gridLayout_5->addWidget(label_FirstImage, 1, 0, 1, 3);

        checkBox_RenderFirst = new QCheckBox(groupBox_5);
        checkBox_RenderFirst->setObjectName(QString::fromUtf8("checkBox_RenderFirst"));
        checkBox_RenderFirst->setMaximumSize(QSize(16777215, 51));
        checkBox_RenderFirst->setChecked(true);

        gridLayout_5->addWidget(checkBox_RenderFirst, 0, 1, 1, 1);


        gridLayout_2->addWidget(groupBox_5, 0, 1, 1, 1);

        tabWidget = new QTabWidget(DialogSetting);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setEnabled(true);
        tabWidget->setMaximumSize(QSize(500, 16777215));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        gridLayout_7 = new QGridLayout(tab);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        groupBox_Frist_4 = new QGroupBox(tab);
        groupBox_Frist_4->setObjectName(QString::fromUtf8("groupBox_Frist_4"));
        groupBox_Frist_4->setMaximumSize(QSize(581, 16777215));
        gridLayout_19 = new QGridLayout(groupBox_Frist_4);
        gridLayout_19->setSpacing(0);
        gridLayout_19->setObjectName(QString::fromUtf8("gridLayout_19"));
        gridLayout_19->setContentsMargins(0, 0, 0, 0);
        label_17 = new QLabel(groupBox_Frist_4);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        gridLayout_19->addWidget(label_17, 5, 4, 1, 2);

        radioButton_ExternalThird = new QRadioButton(groupBox_Frist_4);
        radioButton_ExternalThird->setObjectName(QString::fromUtf8("radioButton_ExternalThird"));

        gridLayout_19->addWidget(radioButton_ExternalThird, 1, 3, 1, 2);

        checkBox_SaveOK_Third = new QCheckBox(groupBox_Frist_4);
        checkBox_SaveOK_Third->setObjectName(QString::fromUtf8("checkBox_SaveOK_Third"));

        gridLayout_19->addWidget(checkBox_SaveOK_Third, 3, 0, 1, 2);

        radioButton_SoftThird = new QRadioButton(groupBox_Frist_4);
        radioButton_SoftThird->setObjectName(QString::fromUtf8("radioButton_SoftThird"));

        gridLayout_19->addWidget(radioButton_SoftThird, 1, 5, 1, 2);

        pushButton_TriggerThird = new QPushButton(groupBox_Frist_4);
        pushButton_TriggerThird->setObjectName(QString::fromUtf8("pushButton_TriggerThird"));
        pushButton_TriggerThird->setMaximumSize(QSize(111, 16777215));

        gridLayout_19->addWidget(pushButton_TriggerThird, 1, 7, 1, 1);

        label_First_5 = new QLabel(groupBox_Frist_4);
        label_First_5->setObjectName(QString::fromUtf8("label_First_5"));
        label_First_5->setMaximumSize(QSize(101, 16777215));

        gridLayout_19->addWidget(label_First_5, 0, 0, 1, 1);

        comboBox_Third = new QComboBox(groupBox_Frist_4);
        comboBox_Third->setObjectName(QString::fromUtf8("comboBox_Third"));

        gridLayout_19->addWidget(comboBox_Third, 0, 2, 1, 5);

        pushButton_OpenThird = new QPushButton(groupBox_Frist_4);
        pushButton_OpenThird->setObjectName(QString::fromUtf8("pushButton_OpenThird"));
        pushButton_OpenThird->setMaximumSize(QSize(111, 16777215));

        gridLayout_19->addWidget(pushButton_OpenThird, 0, 7, 1, 1);

        pushButton_LoadOKPath_Third = new QPushButton(groupBox_Frist_4);
        pushButton_LoadOKPath_Third->setObjectName(QString::fromUtf8("pushButton_LoadOKPath_Third"));

        gridLayout_19->addWidget(pushButton_LoadOKPath_Third, 3, 7, 1, 1);

        radioButton_FreeThird = new QRadioButton(groupBox_Frist_4);
        radioButton_FreeThird->setObjectName(QString::fromUtf8("radioButton_FreeThird"));

        gridLayout_19->addWidget(radioButton_FreeThird, 1, 2, 1, 1);

        pushButton_LoadNGPath_Third = new QPushButton(groupBox_Frist_4);
        pushButton_LoadNGPath_Third->setObjectName(QString::fromUtf8("pushButton_LoadNGPath_Third"));
        pushButton_LoadNGPath_Third->setMaximumSize(QSize(120, 16777215));

        gridLayout_19->addWidget(pushButton_LoadNGPath_Third, 2, 7, 1, 1);

        checkBox_SaveNG_Third = new QCheckBox(groupBox_Frist_4);
        checkBox_SaveNG_Third->setObjectName(QString::fromUtf8("checkBox_SaveNG_Third"));

        gridLayout_19->addWidget(checkBox_SaveNG_Third, 2, 0, 1, 2);

        lineEdit_OKPath_Third = new QLineEdit(groupBox_Frist_4);
        lineEdit_OKPath_Third->setObjectName(QString::fromUtf8("lineEdit_OKPath_Third"));
        lineEdit_OKPath_Third->setReadOnly(true);

        gridLayout_19->addWidget(lineEdit_OKPath_Third, 3, 2, 1, 5);

        le_exposure_3 = new QLineEdit(groupBox_Frist_4);
        le_exposure_3->setObjectName(QString::fromUtf8("le_exposure_3"));
        le_exposure_3->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_19->addWidget(le_exposure_3, 5, 2, 1, 1);

        lineEdit_NGPath_Third = new QLineEdit(groupBox_Frist_4);
        lineEdit_NGPath_Third->setObjectName(QString::fromUtf8("lineEdit_NGPath_Third"));
        lineEdit_NGPath_Third->setReadOnly(true);

        gridLayout_19->addWidget(lineEdit_NGPath_Third, 2, 2, 1, 5);

        label_18 = new QLabel(groupBox_Frist_4);
        label_18->setObjectName(QString::fromUtf8("label_18"));

        gridLayout_19->addWidget(label_18, 5, 0, 1, 1);

        pushButton_SaveParams_Third = new QPushButton(groupBox_Frist_4);
        pushButton_SaveParams_Third->setObjectName(QString::fromUtf8("pushButton_SaveParams_Third"));

        gridLayout_19->addWidget(pushButton_SaveParams_Third, 5, 7, 1, 1);

        le_gain_3 = new QLineEdit(groupBox_Frist_4);
        le_gain_3->setObjectName(QString::fromUtf8("le_gain_3"));

        gridLayout_19->addWidget(le_gain_3, 5, 6, 1, 1);


        gridLayout_7->addWidget(groupBox_Frist_4, 2, 0, 1, 1);

        groupBox_Frist_5 = new QGroupBox(tab);
        groupBox_Frist_5->setObjectName(QString::fromUtf8("groupBox_Frist_5"));
        groupBox_Frist_5->setMaximumSize(QSize(581, 16777215));
        gridLayout_25 = new QGridLayout(groupBox_Frist_5);
        gridLayout_25->setSpacing(0);
        gridLayout_25->setObjectName(QString::fromUtf8("gridLayout_25"));
        gridLayout_25->setContentsMargins(0, 0, 0, 0);
        pushButton_LoadOKPath_Fourth = new QPushButton(groupBox_Frist_5);
        pushButton_LoadOKPath_Fourth->setObjectName(QString::fromUtf8("pushButton_LoadOKPath_Fourth"));

        gridLayout_25->addWidget(pushButton_LoadOKPath_Fourth, 3, 7, 1, 1);

        label_31 = new QLabel(groupBox_Frist_5);
        label_31->setObjectName(QString::fromUtf8("label_31"));

        gridLayout_25->addWidget(label_31, 4, 4, 1, 2);

        label_First_6 = new QLabel(groupBox_Frist_5);
        label_First_6->setObjectName(QString::fromUtf8("label_First_6"));
        label_First_6->setMaximumSize(QSize(101, 16777215));

        gridLayout_25->addWidget(label_First_6, 0, 0, 1, 1);

        le_exposure_4 = new QLineEdit(groupBox_Frist_5);
        le_exposure_4->setObjectName(QString::fromUtf8("le_exposure_4"));
        le_exposure_4->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_25->addWidget(le_exposure_4, 4, 2, 1, 1);

        pushButton_SaveParams_Fourth = new QPushButton(groupBox_Frist_5);
        pushButton_SaveParams_Fourth->setObjectName(QString::fromUtf8("pushButton_SaveParams_Fourth"));

        gridLayout_25->addWidget(pushButton_SaveParams_Fourth, 4, 7, 1, 1);

        lineEdit_OKPath_Fourth = new QLineEdit(groupBox_Frist_5);
        lineEdit_OKPath_Fourth->setObjectName(QString::fromUtf8("lineEdit_OKPath_Fourth"));
        lineEdit_OKPath_Fourth->setReadOnly(true);

        gridLayout_25->addWidget(lineEdit_OKPath_Fourth, 3, 2, 1, 5);

        pushButton_OpenFourth = new QPushButton(groupBox_Frist_5);
        pushButton_OpenFourth->setObjectName(QString::fromUtf8("pushButton_OpenFourth"));
        pushButton_OpenFourth->setMaximumSize(QSize(111, 16777215));

        gridLayout_25->addWidget(pushButton_OpenFourth, 0, 7, 1, 1);

        lineEdit_NGPath_Fourth = new QLineEdit(groupBox_Frist_5);
        lineEdit_NGPath_Fourth->setObjectName(QString::fromUtf8("lineEdit_NGPath_Fourth"));
        lineEdit_NGPath_Fourth->setReadOnly(true);

        gridLayout_25->addWidget(lineEdit_NGPath_Fourth, 2, 2, 1, 5);

        le_gain_4 = new QLineEdit(groupBox_Frist_5);
        le_gain_4->setObjectName(QString::fromUtf8("le_gain_4"));

        gridLayout_25->addWidget(le_gain_4, 4, 6, 1, 1);

        radioButton_ExternalFourth = new QRadioButton(groupBox_Frist_5);
        radioButton_ExternalFourth->setObjectName(QString::fromUtf8("radioButton_ExternalFourth"));

        gridLayout_25->addWidget(radioButton_ExternalFourth, 1, 3, 1, 2);

        radioButton_FreeFourth = new QRadioButton(groupBox_Frist_5);
        radioButton_FreeFourth->setObjectName(QString::fromUtf8("radioButton_FreeFourth"));

        gridLayout_25->addWidget(radioButton_FreeFourth, 1, 2, 1, 1);

        comboBox_Four = new QComboBox(groupBox_Frist_5);
        comboBox_Four->setObjectName(QString::fromUtf8("comboBox_Four"));

        gridLayout_25->addWidget(comboBox_Four, 0, 2, 1, 5);

        radioButton_SoftFourth = new QRadioButton(groupBox_Frist_5);
        radioButton_SoftFourth->setObjectName(QString::fromUtf8("radioButton_SoftFourth"));

        gridLayout_25->addWidget(radioButton_SoftFourth, 1, 5, 1, 2);

        checkBox_SaveNG_Fourth = new QCheckBox(groupBox_Frist_5);
        checkBox_SaveNG_Fourth->setObjectName(QString::fromUtf8("checkBox_SaveNG_Fourth"));

        gridLayout_25->addWidget(checkBox_SaveNG_Fourth, 2, 0, 1, 2);

        label_32 = new QLabel(groupBox_Frist_5);
        label_32->setObjectName(QString::fromUtf8("label_32"));

        gridLayout_25->addWidget(label_32, 4, 0, 1, 1);

        checkBox_SaveOK_Fourth = new QCheckBox(groupBox_Frist_5);
        checkBox_SaveOK_Fourth->setObjectName(QString::fromUtf8("checkBox_SaveOK_Fourth"));

        gridLayout_25->addWidget(checkBox_SaveOK_Fourth, 3, 0, 1, 2);

        pushButton_LoadNGPath_Fourth = new QPushButton(groupBox_Frist_5);
        pushButton_LoadNGPath_Fourth->setObjectName(QString::fromUtf8("pushButton_LoadNGPath_Fourth"));
        pushButton_LoadNGPath_Fourth->setMaximumSize(QSize(120, 16777215));

        gridLayout_25->addWidget(pushButton_LoadNGPath_Fourth, 2, 7, 1, 1);

        pushButton_TriggerFourth = new QPushButton(groupBox_Frist_5);
        pushButton_TriggerFourth->setObjectName(QString::fromUtf8("pushButton_TriggerFourth"));
        pushButton_TriggerFourth->setMaximumSize(QSize(111, 16777215));

        gridLayout_25->addWidget(pushButton_TriggerFourth, 1, 7, 1, 1);


        gridLayout_7->addWidget(groupBox_Frist_5, 3, 0, 1, 1);

        groupBox_Frist_3 = new QGroupBox(tab);
        groupBox_Frist_3->setObjectName(QString::fromUtf8("groupBox_Frist_3"));
        groupBox_Frist_3->setMaximumSize(QSize(581, 16777215));
        gridLayout_18 = new QGridLayout(groupBox_Frist_3);
        gridLayout_18->setSpacing(0);
        gridLayout_18->setObjectName(QString::fromUtf8("gridLayout_18"));
        gridLayout_18->setContentsMargins(0, 0, 0, 0);
        pushButton_OpenSecond = new QPushButton(groupBox_Frist_3);
        pushButton_OpenSecond->setObjectName(QString::fromUtf8("pushButton_OpenSecond"));
        pushButton_OpenSecond->setMaximumSize(QSize(111, 16777215));

        gridLayout_18->addWidget(pushButton_OpenSecond, 0, 7, 1, 1);

        lineEdit_NGPath_Second = new QLineEdit(groupBox_Frist_3);
        lineEdit_NGPath_Second->setObjectName(QString::fromUtf8("lineEdit_NGPath_Second"));
        lineEdit_NGPath_Second->setReadOnly(true);

        gridLayout_18->addWidget(lineEdit_NGPath_Second, 2, 2, 1, 5);

        le_exposure_2 = new QLineEdit(groupBox_Frist_3);
        le_exposure_2->setObjectName(QString::fromUtf8("le_exposure_2"));
        le_exposure_2->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_18->addWidget(le_exposure_2, 4, 2, 1, 1);

        le_gain_2 = new QLineEdit(groupBox_Frist_3);
        le_gain_2->setObjectName(QString::fromUtf8("le_gain_2"));

        gridLayout_18->addWidget(le_gain_2, 4, 6, 1, 1);

        pushButton_SaveParams_Second = new QPushButton(groupBox_Frist_3);
        pushButton_SaveParams_Second->setObjectName(QString::fromUtf8("pushButton_SaveParams_Second"));

        gridLayout_18->addWidget(pushButton_SaveParams_Second, 4, 7, 1, 1);

        radioButton_ExternalSecond = new QRadioButton(groupBox_Frist_3);
        radioButton_ExternalSecond->setObjectName(QString::fromUtf8("radioButton_ExternalSecond"));

        gridLayout_18->addWidget(radioButton_ExternalSecond, 1, 3, 1, 2);

        pushButton_TriggerSecond = new QPushButton(groupBox_Frist_3);
        pushButton_TriggerSecond->setObjectName(QString::fromUtf8("pushButton_TriggerSecond"));
        pushButton_TriggerSecond->setMaximumSize(QSize(111, 16777215));

        gridLayout_18->addWidget(pushButton_TriggerSecond, 1, 7, 1, 1);

        checkBox_SaveNG_Second = new QCheckBox(groupBox_Frist_3);
        checkBox_SaveNG_Second->setObjectName(QString::fromUtf8("checkBox_SaveNG_Second"));

        gridLayout_18->addWidget(checkBox_SaveNG_Second, 2, 0, 1, 2);

        lineEdit_OKPath_Second = new QLineEdit(groupBox_Frist_3);
        lineEdit_OKPath_Second->setObjectName(QString::fromUtf8("lineEdit_OKPath_Second"));
        lineEdit_OKPath_Second->setReadOnly(true);

        gridLayout_18->addWidget(lineEdit_OKPath_Second, 3, 2, 1, 5);

        label_16 = new QLabel(groupBox_Frist_3);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        gridLayout_18->addWidget(label_16, 4, 0, 1, 1);

        label_First_4 = new QLabel(groupBox_Frist_3);
        label_First_4->setObjectName(QString::fromUtf8("label_First_4"));
        label_First_4->setMaximumSize(QSize(101, 16777215));

        gridLayout_18->addWidget(label_First_4, 0, 0, 1, 1);

        pushButton_LoadNGPath_Second = new QPushButton(groupBox_Frist_3);
        pushButton_LoadNGPath_Second->setObjectName(QString::fromUtf8("pushButton_LoadNGPath_Second"));
        pushButton_LoadNGPath_Second->setMaximumSize(QSize(120, 16777215));

        gridLayout_18->addWidget(pushButton_LoadNGPath_Second, 2, 7, 1, 1);

        checkBox_SaveOK_Second = new QCheckBox(groupBox_Frist_3);
        checkBox_SaveOK_Second->setObjectName(QString::fromUtf8("checkBox_SaveOK_Second"));

        gridLayout_18->addWidget(checkBox_SaveOK_Second, 3, 0, 1, 2);

        radioButton_FreeSecond = new QRadioButton(groupBox_Frist_3);
        radioButton_FreeSecond->setObjectName(QString::fromUtf8("radioButton_FreeSecond"));

        gridLayout_18->addWidget(radioButton_FreeSecond, 1, 2, 1, 1);

        pushButton_LoadOKPath_Second = new QPushButton(groupBox_Frist_3);
        pushButton_LoadOKPath_Second->setObjectName(QString::fromUtf8("pushButton_LoadOKPath_Second"));

        gridLayout_18->addWidget(pushButton_LoadOKPath_Second, 3, 7, 1, 1);

        radioButton_SoftSecond = new QRadioButton(groupBox_Frist_3);
        radioButton_SoftSecond->setObjectName(QString::fromUtf8("radioButton_SoftSecond"));

        gridLayout_18->addWidget(radioButton_SoftSecond, 1, 5, 1, 2);

        label_15 = new QLabel(groupBox_Frist_3);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        gridLayout_18->addWidget(label_15, 4, 4, 1, 2);

        comboBox_Second = new QComboBox(groupBox_Frist_3);
        comboBox_Second->setObjectName(QString::fromUtf8("comboBox_Second"));

        gridLayout_18->addWidget(comboBox_Second, 0, 2, 1, 5);


        gridLayout_7->addWidget(groupBox_Frist_3, 1, 0, 1, 1);

        groupBox_Frist = new QGroupBox(tab);
        groupBox_Frist->setObjectName(QString::fromUtf8("groupBox_Frist"));
        groupBox_Frist->setMaximumSize(QSize(581, 16777215));
        gridLayout = new QGridLayout(groupBox_Frist);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(groupBox_Frist);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 4, 0, 1, 1);

        radioButton_FreeFirst = new QRadioButton(groupBox_Frist);
        radioButton_FreeFirst->setObjectName(QString::fromUtf8("radioButton_FreeFirst"));

        gridLayout->addWidget(radioButton_FreeFirst, 1, 2, 1, 1);

        pushButton_LoadNGPath_First = new QPushButton(groupBox_Frist);
        pushButton_LoadNGPath_First->setObjectName(QString::fromUtf8("pushButton_LoadNGPath_First"));
        pushButton_LoadNGPath_First->setMaximumSize(QSize(120, 16777215));

        gridLayout->addWidget(pushButton_LoadNGPath_First, 2, 7, 1, 1);

        checkBox_SaveOK_First = new QCheckBox(groupBox_Frist);
        checkBox_SaveOK_First->setObjectName(QString::fromUtf8("checkBox_SaveOK_First"));

        gridLayout->addWidget(checkBox_SaveOK_First, 3, 0, 1, 2);

        pushButton_LoadOKPath_First = new QPushButton(groupBox_Frist);
        pushButton_LoadOKPath_First->setObjectName(QString::fromUtf8("pushButton_LoadOKPath_First"));

        gridLayout->addWidget(pushButton_LoadOKPath_First, 3, 7, 1, 1);

        label_First = new QLabel(groupBox_Frist);
        label_First->setObjectName(QString::fromUtf8("label_First"));
        label_First->setMaximumSize(QSize(101, 16777215));

        gridLayout->addWidget(label_First, 0, 0, 1, 1);

        comboBox_First = new QComboBox(groupBox_Frist);
        comboBox_First->setObjectName(QString::fromUtf8("comboBox_First"));
        comboBox_First->setEnabled(true);

        gridLayout->addWidget(comboBox_First, 0, 2, 1, 5);

        label_4 = new QLabel(groupBox_Frist);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 4, 4, 1, 1);

        lineEdit_NGPath_First = new QLineEdit(groupBox_Frist);
        lineEdit_NGPath_First->setObjectName(QString::fromUtf8("lineEdit_NGPath_First"));
        lineEdit_NGPath_First->setReadOnly(true);

        gridLayout->addWidget(lineEdit_NGPath_First, 2, 2, 1, 5);

        pushButton_OpenFirst = new QPushButton(groupBox_Frist);
        pushButton_OpenFirst->setObjectName(QString::fromUtf8("pushButton_OpenFirst"));
        pushButton_OpenFirst->setMaximumSize(QSize(111, 16777215));

        gridLayout->addWidget(pushButton_OpenFirst, 0, 7, 1, 1);

        pushButton_SaveParams = new QPushButton(groupBox_Frist);
        pushButton_SaveParams->setObjectName(QString::fromUtf8("pushButton_SaveParams"));

        gridLayout->addWidget(pushButton_SaveParams, 4, 7, 1, 1);

        pushButton_TriggerFirst = new QPushButton(groupBox_Frist);
        pushButton_TriggerFirst->setObjectName(QString::fromUtf8("pushButton_TriggerFirst"));
        pushButton_TriggerFirst->setMaximumSize(QSize(111, 16777215));

        gridLayout->addWidget(pushButton_TriggerFirst, 1, 7, 1, 1);

        lineEdit_OKPath_First = new QLineEdit(groupBox_Frist);
        lineEdit_OKPath_First->setObjectName(QString::fromUtf8("lineEdit_OKPath_First"));
        lineEdit_OKPath_First->setReadOnly(true);

        gridLayout->addWidget(lineEdit_OKPath_First, 3, 2, 1, 5);

        le_gain_1 = new QLineEdit(groupBox_Frist);
        le_gain_1->setObjectName(QString::fromUtf8("le_gain_1"));
        le_gain_1->setMinimumSize(QSize(0, 0));
        le_gain_1->setMaximumSize(QSize(16777215, 16777215));

        gridLayout->addWidget(le_gain_1, 4, 5, 1, 1);

        radioButton_SoftFirst = new QRadioButton(groupBox_Frist);
        radioButton_SoftFirst->setObjectName(QString::fromUtf8("radioButton_SoftFirst"));

        gridLayout->addWidget(radioButton_SoftFirst, 1, 5, 1, 2);

        radioButton_ExternalFirst = new QRadioButton(groupBox_Frist);
        radioButton_ExternalFirst->setObjectName(QString::fromUtf8("radioButton_ExternalFirst"));

        gridLayout->addWidget(radioButton_ExternalFirst, 1, 3, 1, 2);

        checkBox_SaveNG_First = new QCheckBox(groupBox_Frist);
        checkBox_SaveNG_First->setObjectName(QString::fromUtf8("checkBox_SaveNG_First"));

        gridLayout->addWidget(checkBox_SaveNG_First, 2, 0, 1, 2);

        le_exposure_1 = new QLineEdit(groupBox_Frist);
        le_exposure_1->setObjectName(QString::fromUtf8("le_exposure_1"));
        le_exposure_1->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(le_exposure_1->sizePolicy().hasHeightForWidth());
        le_exposure_1->setSizePolicy(sizePolicy);
        le_exposure_1->setMaximumSize(QSize(16777215, 16777215));

        gridLayout->addWidget(le_exposure_1, 4, 2, 1, 1);


        gridLayout_7->addWidget(groupBox_Frist, 0, 0, 1, 1);

        pushButton_SaveConfig = new QPushButton(tab);
        pushButton_SaveConfig->setObjectName(QString::fromUtf8("pushButton_SaveConfig"));

        gridLayout_7->addWidget(pushButton_SaveConfig, 4, 0, 1, 1);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        groupBox_7 = new QGroupBox(tab_2);
        groupBox_7->setObjectName(QString::fromUtf8("groupBox_7"));
        groupBox_7->setGeometry(QRect(10, 620, 471, 151));
        gridLayout_8 = new QGridLayout(groupBox_7);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        label_2 = new QLabel(groupBox_7);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(0, 0));
        label_2->setMaximumSize(QSize(80, 16777215));

        gridLayout_8->addWidget(label_2, 0, 0, 1, 1);

        lineEdit_MachineCode = new QLineEdit(groupBox_7);
        lineEdit_MachineCode->setObjectName(QString::fromUtf8("lineEdit_MachineCode"));
        lineEdit_MachineCode->setReadOnly(true);

        gridLayout_8->addWidget(lineEdit_MachineCode, 0, 1, 1, 1);

        pushButton_Copy = new QPushButton(groupBox_7);
        pushButton_Copy->setObjectName(QString::fromUtf8("pushButton_Copy"));

        gridLayout_8->addWidget(pushButton_Copy, 0, 2, 1, 1);

        label_3 = new QLabel(groupBox_7);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMinimumSize(QSize(0, 0));
        label_3->setMaximumSize(QSize(80, 16777215));

        gridLayout_8->addWidget(label_3, 1, 0, 1, 1);

        lineEdit_RegisterCode = new QLineEdit(groupBox_7);
        lineEdit_RegisterCode->setObjectName(QString::fromUtf8("lineEdit_RegisterCode"));

        gridLayout_8->addWidget(lineEdit_RegisterCode, 1, 1, 1, 1);

        pushButton_Register = new QPushButton(groupBox_7);
        pushButton_Register->setObjectName(QString::fromUtf8("pushButton_Register"));

        gridLayout_8->addWidget(pushButton_Register, 1, 2, 1, 1);

        label_RegisterInfo = new QLabel(groupBox_7);
        label_RegisterInfo->setObjectName(QString::fromUtf8("label_RegisterInfo"));
        label_RegisterInfo->setLayoutDirection(Qt::LeftToRight);
        label_RegisterInfo->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 0);"));
        label_RegisterInfo->setAlignment(Qt::AlignCenter);

        gridLayout_8->addWidget(label_RegisterInfo, 2, 0, 1, 3);

        groupBox_4 = new QGroupBox(tab_2);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(20, 20, 461, 171));
        groupBox_4->setMaximumSize(QSize(581, 16777215));
        gridLayout_3 = new QGridLayout(groupBox_4);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        pushButton_LoadFirstImage = new QPushButton(groupBox_4);
        pushButton_LoadFirstImage->setObjectName(QString::fromUtf8("pushButton_LoadFirstImage"));

        gridLayout_3->addWidget(pushButton_LoadFirstImage, 2, 0, 1, 1);

        label_8 = new QLabel(groupBox_4);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setMaximumSize(QSize(90, 16777215));

        gridLayout_3->addWidget(label_8, 0, 0, 1, 1);

        pushButton_LoadThirdImage = new QPushButton(groupBox_4);
        pushButton_LoadThirdImage->setObjectName(QString::fromUtf8("pushButton_LoadThirdImage"));

        gridLayout_3->addWidget(pushButton_LoadThirdImage, 3, 0, 1, 1);

        pushButton_LoadFourthImage = new QPushButton(groupBox_4);
        pushButton_LoadFourthImage->setObjectName(QString::fromUtf8("pushButton_LoadFourthImage"));

        gridLayout_3->addWidget(pushButton_LoadFourthImage, 3, 3, 1, 1);

        pushButton_LoadSecondImage = new QPushButton(groupBox_4);
        pushButton_LoadSecondImage->setObjectName(QString::fromUtf8("pushButton_LoadSecondImage"));

        gridLayout_3->addWidget(pushButton_LoadSecondImage, 2, 3, 1, 1);

        comboBox_SystemType = new QComboBox(groupBox_4);
        comboBox_SystemType->setObjectName(QString::fromUtf8("comboBox_SystemType"));

        gridLayout_3->addWidget(comboBox_SystemType, 0, 1, 1, 3);

        groupBox_10 = new QGroupBox(tab_2);
        groupBox_10->setObjectName(QString::fromUtf8("groupBox_10"));
        groupBox_10->setGeometry(QRect(10, 200, 471, 117));
        groupBox_10->setMaximumSize(QSize(581, 16777215));
        gridLayout_4 = new QGridLayout(groupBox_10);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        label_5 = new QLabel(groupBox_10);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setMinimumSize(QSize(31, 0));
        label_5->setMaximumSize(QSize(31, 16777215));

        gridLayout_4->addWidget(label_5, 0, 0, 1, 1);

        lineEdit_IP = new QLineEdit(groupBox_10);
        lineEdit_IP->setObjectName(QString::fromUtf8("lineEdit_IP"));

        gridLayout_4->addWidget(lineEdit_IP, 0, 1, 1, 2);

        label_6 = new QLabel(groupBox_10);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setMinimumSize(QSize(50, 0));
        label_6->setMaximumSize(QSize(50, 16777215));

        gridLayout_4->addWidget(label_6, 0, 3, 1, 1);

        lineEdit_Port = new QLineEdit(groupBox_10);
        lineEdit_Port->setObjectName(QString::fromUtf8("lineEdit_Port"));
        lineEdit_Port->setMinimumSize(QSize(80, 0));
        lineEdit_Port->setMaximumSize(QSize(80, 16777215));

        gridLayout_4->addWidget(lineEdit_Port, 0, 4, 1, 1);

        label_7 = new QLabel(groupBox_10);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setMinimumSize(QSize(50, 0));
        label_7->setMaximumSize(QSize(50, 16777215));

        gridLayout_4->addWidget(label_7, 0, 5, 1, 1);

        spinBox_Heartbeat = new QSpinBox(groupBox_10);
        spinBox_Heartbeat->setObjectName(QString::fromUtf8("spinBox_Heartbeat"));
        spinBox_Heartbeat->setMinimumSize(QSize(80, 0));
        spinBox_Heartbeat->setMaximumSize(QSize(80, 16777215));
        spinBox_Heartbeat->setMinimum(1);

        gridLayout_4->addWidget(spinBox_Heartbeat, 0, 6, 1, 1);

        pushButton_SendOK = new QPushButton(groupBox_10);
        pushButton_SendOK->setObjectName(QString::fromUtf8("pushButton_SendOK"));

        gridLayout_4->addWidget(pushButton_SendOK, 1, 4, 1, 1);

        pushButton_SendNG = new QPushButton(groupBox_10);
        pushButton_SendNG->setObjectName(QString::fromUtf8("pushButton_SendNG"));
        pushButton_SendNG->setMinimumSize(QSize(80, 0));
        pushButton_SendNG->setMaximumSize(QSize(80, 16777215));

        gridLayout_4->addWidget(pushButton_SendNG, 1, 6, 1, 1);

        label_Status = new QLabel(groupBox_10);
        label_Status->setObjectName(QString::fromUtf8("label_Status"));
        label_Status->setMinimumSize(QSize(35, 35));
        label_Status->setMaximumSize(QSize(35, 35));
        label_Status->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 0);"));

        gridLayout_4->addWidget(label_Status, 1, 3, 1, 1);

        pushButton_ConnectPLC = new QPushButton(groupBox_10);
        pushButton_ConnectPLC->setObjectName(QString::fromUtf8("pushButton_ConnectPLC"));

        gridLayout_4->addWidget(pushButton_ConnectPLC, 1, 1, 1, 2);

        groupBox_3 = new QGroupBox(tab_2);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(10, 330, 471, 281));
        gridLayout_16 = new QGridLayout(groupBox_3);
        gridLayout_16->setObjectName(QString::fromUtf8("gridLayout_16"));
        label_22 = new QLabel(groupBox_3);
        label_22->setObjectName(QString::fromUtf8("label_22"));

        gridLayout_16->addWidget(label_22, 0, 1, 1, 1);

        label_19 = new QLabel(groupBox_3);
        label_19->setObjectName(QString::fromUtf8("label_19"));

        gridLayout_16->addWidget(label_19, 0, 2, 1, 1);

        label_20 = new QLabel(groupBox_3);
        label_20->setObjectName(QString::fromUtf8("label_20"));

        gridLayout_16->addWidget(label_20, 1, 0, 1, 1);

        spinBox_Area_YaShang = new QSpinBox(groupBox_3);
        spinBox_Area_YaShang->setObjectName(QString::fromUtf8("spinBox_Area_YaShang"));
        spinBox_Area_YaShang->setMinimum(0);
        spinBox_Area_YaShang->setMaximum(10000);
        spinBox_Area_YaShang->setValue(0);

        gridLayout_16->addWidget(spinBox_Area_YaShang, 1, 1, 1, 1);

        spinBox_Wh_YaShang = new QSpinBox(groupBox_3);
        spinBox_Wh_YaShang->setObjectName(QString::fromUtf8("spinBox_Wh_YaShang"));
        spinBox_Wh_YaShang->setMinimum(0);
        spinBox_Wh_YaShang->setMaximum(10000);
        spinBox_Wh_YaShang->setValue(0);

        gridLayout_16->addWidget(spinBox_Wh_YaShang, 1, 2, 1, 1);

        label_23 = new QLabel(groupBox_3);
        label_23->setObjectName(QString::fromUtf8("label_23"));

        gridLayout_16->addWidget(label_23, 2, 0, 1, 1);

        spinBox_Area_PengShang = new QSpinBox(groupBox_3);
        spinBox_Area_PengShang->setObjectName(QString::fromUtf8("spinBox_Area_PengShang"));
        spinBox_Area_PengShang->setMinimum(0);
        spinBox_Area_PengShang->setMaximum(10000);
        spinBox_Area_PengShang->setValue(0);

        gridLayout_16->addWidget(spinBox_Area_PengShang, 2, 1, 1, 1);

        spinBox_Wh_PengShang = new QSpinBox(groupBox_3);
        spinBox_Wh_PengShang->setObjectName(QString::fromUtf8("spinBox_Wh_PengShang"));
        spinBox_Wh_PengShang->setMinimum(0);
        spinBox_Wh_PengShang->setMaximum(10000);
        spinBox_Wh_PengShang->setValue(0);

        gridLayout_16->addWidget(spinBox_Wh_PengShang, 2, 2, 1, 1);

        label_21 = new QLabel(groupBox_3);
        label_21->setObjectName(QString::fromUtf8("label_21"));

        gridLayout_16->addWidget(label_21, 3, 0, 1, 1);

        spinBox_Area_HuaShang = new QSpinBox(groupBox_3);
        spinBox_Area_HuaShang->setObjectName(QString::fromUtf8("spinBox_Area_HuaShang"));
        spinBox_Area_HuaShang->setMinimum(0);
        spinBox_Area_HuaShang->setMaximum(10000);
        spinBox_Area_HuaShang->setValue(0);

        gridLayout_16->addWidget(spinBox_Area_HuaShang, 3, 1, 1, 1);

        spinBox_Wh_HuaShang = new QSpinBox(groupBox_3);
        spinBox_Wh_HuaShang->setObjectName(QString::fromUtf8("spinBox_Wh_HuaShang"));
        spinBox_Wh_HuaShang->setMinimum(0);
        spinBox_Wh_HuaShang->setMaximum(10000);
        spinBox_Wh_HuaShang->setValue(0);

        gridLayout_16->addWidget(spinBox_Wh_HuaShang, 3, 2, 1, 1);

        label_24 = new QLabel(groupBox_3);
        label_24->setObjectName(QString::fromUtf8("label_24"));

        gridLayout_16->addWidget(label_24, 4, 0, 1, 1);

        spinBox_Area_CaShang = new QSpinBox(groupBox_3);
        spinBox_Area_CaShang->setObjectName(QString::fromUtf8("spinBox_Area_CaShang"));
        spinBox_Area_CaShang->setMinimum(0);
        spinBox_Area_CaShang->setMaximum(10000);
        spinBox_Area_CaShang->setValue(0);

        gridLayout_16->addWidget(spinBox_Area_CaShang, 4, 1, 1, 1);

        spinBox_Wh_CaShang = new QSpinBox(groupBox_3);
        spinBox_Wh_CaShang->setObjectName(QString::fromUtf8("spinBox_Wh_CaShang"));
        spinBox_Wh_CaShang->setMinimum(0);
        spinBox_Wh_CaShang->setMaximum(10000);
        spinBox_Wh_CaShang->setValue(0);

        gridLayout_16->addWidget(spinBox_Wh_CaShang, 4, 2, 1, 1);

        label_41 = new QLabel(groupBox_3);
        label_41->setObjectName(QString::fromUtf8("label_41"));

        gridLayout_16->addWidget(label_41, 5, 0, 1, 1);

        spinBox_Area_TieFen = new QSpinBox(groupBox_3);
        spinBox_Area_TieFen->setObjectName(QString::fromUtf8("spinBox_Area_TieFen"));
        spinBox_Area_TieFen->setMinimum(0);
        spinBox_Area_TieFen->setMaximum(10000);
        spinBox_Area_TieFen->setValue(0);

        gridLayout_16->addWidget(spinBox_Area_TieFen, 5, 1, 1, 1);

        spinBox_Wh_TieFen = new QSpinBox(groupBox_3);
        spinBox_Wh_TieFen->setObjectName(QString::fromUtf8("spinBox_Wh_TieFen"));
        spinBox_Wh_TieFen->setMinimum(0);
        spinBox_Wh_TieFen->setMaximum(10000);
        spinBox_Wh_TieFen->setValue(0);

        gridLayout_16->addWidget(spinBox_Wh_TieFen, 5, 2, 1, 1);

        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        comboBox_Formula = new QComboBox(tab_3);
        comboBox_Formula->setObjectName(QString::fromUtf8("comboBox_Formula"));
        comboBox_Formula->setGeometry(QRect(10, 30, 301, 31));
        pushButton_3 = new QPushButton(tab_3);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(350, 30, 91, 31));
        tabWidget->addTab(tab_3, QString());

        gridLayout_2->addWidget(tabWidget, 0, 0, 2, 1);


        retranslateUi(DialogSetting);
        QObject::connect(checkBox_RenderFirst, SIGNAL(clicked(bool)), DialogSetting, SLOT(ShowFristRender(bool)));
        QObject::connect(checkBox_RenderSecond, SIGNAL(clicked(bool)), DialogSetting, SLOT(ShowSecondRender(bool)));
        QObject::connect(pushButton_Copy, SIGNAL(clicked()), DialogSetting, SLOT(CopyRegisterCode()));
        QObject::connect(pushButton_Register, SIGNAL(clicked()), DialogSetting, SLOT(SoftwareRegister()));
        QObject::connect(pushButton_LoadFirstImage, SIGNAL(clicked()), DialogSetting, SLOT(LoadFirstImage()));
        QObject::connect(comboBox_SystemType, SIGNAL(activated(int)), DialogSetting, SLOT(SetSystemType(int)));
        QObject::connect(pushButton_SaveParams, SIGNAL(clicked()), DialogSetting, SLOT(SaveCameraParams1()));
        QObject::connect(pushButton_OpenFirst, SIGNAL(clicked()), DialogSetting, SLOT(OpenFirstCamera()));
        QObject::connect(pushButton_OpenSecond, SIGNAL(clicked()), DialogSetting, SLOT(OpenSecondCamera()));
        QObject::connect(pushButton_OpenThird, SIGNAL(clicked()), DialogSetting, SLOT(OpenThirdCamera()));
        QObject::connect(pushButton_OpenFourth, SIGNAL(clicked()), DialogSetting, SLOT(OpenFourthCamera()));
        QObject::connect(pushButton_SaveParams_Second, SIGNAL(clicked()), DialogSetting, SLOT(SaveCameraParams2()));
        QObject::connect(pushButton_SaveParams_Third, SIGNAL(clicked()), DialogSetting, SLOT(SaveCameraParams3()));
        QObject::connect(pushButton_SaveParams_Fourth, SIGNAL(clicked()), DialogSetting, SLOT(SaveCameraParams4()));
        QObject::connect(pushButton_LoadNGPath_First, SIGNAL(clicked()), DialogSetting, SLOT(ChooseFirstNgPath()));
        QObject::connect(pushButton_LoadOKPath_First, SIGNAL(clicked()), DialogSetting, SLOT(ChooseFirstOkPath()));
        QObject::connect(pushButton_LoadSecondImage, SIGNAL(clicked()), DialogSetting, SLOT(LoadSecondImage()));
        QObject::connect(pushButton_LoadThirdImage, SIGNAL(clicked()), DialogSetting, SLOT(LoadThirdImage()));
        QObject::connect(pushButton_LoadFourthImage, SIGNAL(clicked()), DialogSetting, SLOT(LoadFourthImage()));
        QObject::connect(pushButton_LoadNGPath_Second, SIGNAL(clicked()), DialogSetting, SLOT(ChooseSecondNgPath()));
        QObject::connect(pushButton_LoadOKPath_Second, SIGNAL(clicked()), DialogSetting, SLOT(ChooseSecondOkPath()));
        QObject::connect(pushButton_LoadNGPath_Third, SIGNAL(clicked()), DialogSetting, SLOT(ChooseThirdNgPath()));
        QObject::connect(pushButton_LoadOKPath_Third, SIGNAL(clicked()), DialogSetting, SLOT(ChooseThirdOkPath()));
        QObject::connect(pushButton_LoadNGPath_Fourth, SIGNAL(clicked()), DialogSetting, SLOT(ChooseFourthNgPath()));
        QObject::connect(pushButton_LoadOKPath_Fourth, SIGNAL(clicked()), DialogSetting, SLOT(ChooseFourthOkPath()));
        QObject::connect(spinBox_Area_YaShang, SIGNAL(valueChanged(int)), DialogSetting, SLOT(SetThreshold()));
        QObject::connect(spinBox_Area_PengShang, SIGNAL(valueChanged(int)), DialogSetting, SLOT(SetThreshold()));
        QObject::connect(spinBox_Area_HuaShang, SIGNAL(valueChanged(int)), DialogSetting, SLOT(SetThreshold()));
        QObject::connect(spinBox_Area_CaShang, SIGNAL(valueChanged(int)), DialogSetting, SLOT(SetThreshold()));
        QObject::connect(spinBox_Area_TieFen, SIGNAL(valueChanged(int)), DialogSetting, SLOT(SetThreshold()));
        QObject::connect(spinBox_Wh_YaShang, SIGNAL(valueChanged(int)), DialogSetting, SLOT(SetThreshold()));
        QObject::connect(spinBox_Wh_PengShang, SIGNAL(valueChanged(int)), DialogSetting, SLOT(SetThreshold()));
        QObject::connect(spinBox_Wh_HuaShang, SIGNAL(valueChanged(int)), DialogSetting, SLOT(SetThreshold()));
        QObject::connect(spinBox_Wh_CaShang, SIGNAL(valueChanged(int)), DialogSetting, SLOT(SetThreshold()));
        QObject::connect(spinBox_Wh_TieFen, SIGNAL(valueChanged(int)), DialogSetting, SLOT(SetThreshold()));
        QObject::connect(pushButton_SaveConfig, SIGNAL(clicked()), DialogSetting, SLOT(SaveConfig()));

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(DialogSetting);
    } // setupUi

    void retranslateUi(QDialog *DialogSetting)
    {
        DialogSetting->setWindowTitle(QCoreApplication::translate("DialogSetting", "\345\217\202\346\225\260\350\256\276\347\275\256", nullptr));
        groupBox_8->setTitle(QCoreApplication::translate("DialogSetting", "\344\270\211\345\267\245\344\275\215", nullptr));
        checkBox_RenderThird->setText(QCoreApplication::translate("DialogSetting", "\346\270\262\346\237\223\345\233\276", nullptr));
        label_ThirdResult->setText(QString());
        label_ThirdImage->setText(QString());
        label_ThirdTime->setText(QCoreApplication::translate("DialogSetting", "\350\200\227\346\227\266\357\274\232", nullptr));
        groupBox_6->setTitle(QCoreApplication::translate("DialogSetting", "\344\272\214\345\267\245\344\275\215", nullptr));
        label_SecondResult->setText(QString());
        label_SecondImage->setText(QString());
        label_SecondTime->setText(QCoreApplication::translate("DialogSetting", "\350\200\227\346\227\266\357\274\232", nullptr));
        checkBox_RenderSecond->setText(QCoreApplication::translate("DialogSetting", "\346\270\262\346\237\223\345\233\276", nullptr));
        groupBox_9->setTitle(QCoreApplication::translate("DialogSetting", "\345\233\233\345\267\245\344\275\215", nullptr));
        label_FourthResult->setText(QString());
        label_FourthImage->setText(QString());
        label_FourthTime->setText(QCoreApplication::translate("DialogSetting", "\350\200\227\346\227\266\357\274\232", nullptr));
        checkBox_RenderFourth->setText(QCoreApplication::translate("DialogSetting", "\346\270\262\346\237\223\345\233\276", nullptr));
        groupBox_5->setTitle(QCoreApplication::translate("DialogSetting", "\344\270\200\345\267\245\344\275\215", nullptr));
        label_FirstResult->setText(QString());
        label_FirstTime->setText(QCoreApplication::translate("DialogSetting", "\350\200\227\346\227\266\357\274\232", nullptr));
        label_FirstImage->setText(QString());
        checkBox_RenderFirst->setText(QCoreApplication::translate("DialogSetting", "\346\270\262\346\237\223\345\233\276", nullptr));
        groupBox_Frist_4->setTitle(QCoreApplication::translate("DialogSetting", "\344\270\200\345\267\245\344\275\215-\347\233\270\346\234\272\345\217\202\346\225\260", nullptr));
        label_17->setText(QCoreApplication::translate("DialogSetting", "\345\242\236\347\233\212", nullptr));
        radioButton_ExternalThird->setText(QCoreApplication::translate("DialogSetting", "\347\241\254\350\247\246\345\217\221", nullptr));
        checkBox_SaveOK_Third->setText(QCoreApplication::translate("DialogSetting", "\344\277\235\345\255\230OK", nullptr));
        radioButton_SoftThird->setText(QCoreApplication::translate("DialogSetting", "\350\275\257\350\247\246\345\217\221", nullptr));
        pushButton_TriggerThird->setText(QCoreApplication::translate("DialogSetting", "\350\247\246\345\217\221\344\270\200\346\254\241", nullptr));
        label_First_5->setText(QCoreApplication::translate("DialogSetting", "\347\233\270\346\234\272\345\220\215\347\247\260", nullptr));
        pushButton_OpenThird->setText(QCoreApplication::translate("DialogSetting", "\346\211\223\345\274\200\347\233\270\346\234\272", nullptr));
        pushButton_LoadOKPath_Third->setText(QCoreApplication::translate("DialogSetting", "\346\211\223\345\274\200\350\267\257\345\276\204", nullptr));
        radioButton_FreeThird->setText(QCoreApplication::translate("DialogSetting", "\350\207\252\347\224\261\351\207\207\351\233\206", nullptr));
        pushButton_LoadNGPath_Third->setText(QCoreApplication::translate("DialogSetting", "\346\211\223\345\274\200\350\267\257\345\276\204", nullptr));
        checkBox_SaveNG_Third->setText(QCoreApplication::translate("DialogSetting", "\344\277\235\345\255\230NG", nullptr));
        lineEdit_OKPath_Third->setPlaceholderText(QCoreApplication::translate("DialogSetting", "OK\345\233\276\345\203\217\350\267\257\345\276\204", nullptr));
        lineEdit_NGPath_Third->setPlaceholderText(QCoreApplication::translate("DialogSetting", "NG\345\233\276\345\203\217\350\267\257\345\276\204", nullptr));
        label_18->setText(QCoreApplication::translate("DialogSetting", "\346\233\235\345\205\211", nullptr));
        pushButton_SaveParams_Third->setText(QCoreApplication::translate("DialogSetting", "\344\277\235\345\255\230\345\217\202\346\225\260", nullptr));
        groupBox_Frist_5->setTitle(QCoreApplication::translate("DialogSetting", "\344\270\200\345\267\245\344\275\215-\347\233\270\346\234\272\345\217\202\346\225\260", nullptr));
        pushButton_LoadOKPath_Fourth->setText(QCoreApplication::translate("DialogSetting", "\346\211\223\345\274\200\350\267\257\345\276\204", nullptr));
        label_31->setText(QCoreApplication::translate("DialogSetting", "\345\242\236\347\233\212", nullptr));
        label_First_6->setText(QCoreApplication::translate("DialogSetting", "\347\233\270\346\234\272\345\220\215\347\247\260", nullptr));
        pushButton_SaveParams_Fourth->setText(QCoreApplication::translate("DialogSetting", "\344\277\235\345\255\230\345\217\202\346\225\260", nullptr));
        lineEdit_OKPath_Fourth->setPlaceholderText(QCoreApplication::translate("DialogSetting", "OK\345\233\276\345\203\217\350\267\257\345\276\204", nullptr));
        pushButton_OpenFourth->setText(QCoreApplication::translate("DialogSetting", "\346\211\223\345\274\200\347\233\270\346\234\272", nullptr));
        lineEdit_NGPath_Fourth->setPlaceholderText(QCoreApplication::translate("DialogSetting", "NG\345\233\276\345\203\217\350\267\257\345\276\204", nullptr));
        radioButton_ExternalFourth->setText(QCoreApplication::translate("DialogSetting", "\347\241\254\350\247\246\345\217\221", nullptr));
        radioButton_FreeFourth->setText(QCoreApplication::translate("DialogSetting", "\350\207\252\347\224\261\351\207\207\351\233\206", nullptr));
        radioButton_SoftFourth->setText(QCoreApplication::translate("DialogSetting", "\350\275\257\350\247\246\345\217\221", nullptr));
        checkBox_SaveNG_Fourth->setText(QCoreApplication::translate("DialogSetting", "\344\277\235\345\255\230NG", nullptr));
        label_32->setText(QCoreApplication::translate("DialogSetting", "\346\233\235\345\205\211", nullptr));
        checkBox_SaveOK_Fourth->setText(QCoreApplication::translate("DialogSetting", "\344\277\235\345\255\230OK", nullptr));
        pushButton_LoadNGPath_Fourth->setText(QCoreApplication::translate("DialogSetting", "\346\211\223\345\274\200\350\267\257\345\276\204", nullptr));
        pushButton_TriggerFourth->setText(QCoreApplication::translate("DialogSetting", "\350\247\246\345\217\221\344\270\200\346\254\241", nullptr));
        groupBox_Frist_3->setTitle(QCoreApplication::translate("DialogSetting", "\344\270\200\345\267\245\344\275\215-\347\233\270\346\234\272\345\217\202\346\225\260", nullptr));
        pushButton_OpenSecond->setText(QCoreApplication::translate("DialogSetting", "\346\211\223\345\274\200\347\233\270\346\234\272", nullptr));
        lineEdit_NGPath_Second->setPlaceholderText(QCoreApplication::translate("DialogSetting", "NG\345\233\276\345\203\217\350\267\257\345\276\204", nullptr));
        pushButton_SaveParams_Second->setText(QCoreApplication::translate("DialogSetting", "\344\277\235\345\255\230\345\217\202\346\225\260", nullptr));
        radioButton_ExternalSecond->setText(QCoreApplication::translate("DialogSetting", "\347\241\254\350\247\246\345\217\221", nullptr));
        pushButton_TriggerSecond->setText(QCoreApplication::translate("DialogSetting", "\350\247\246\345\217\221\344\270\200\346\254\241", nullptr));
        checkBox_SaveNG_Second->setText(QCoreApplication::translate("DialogSetting", "\344\277\235\345\255\230NG", nullptr));
        lineEdit_OKPath_Second->setPlaceholderText(QCoreApplication::translate("DialogSetting", "OK\345\233\276\345\203\217\350\267\257\345\276\204", nullptr));
        label_16->setText(QCoreApplication::translate("DialogSetting", "\346\233\235\345\205\211", nullptr));
        label_First_4->setText(QCoreApplication::translate("DialogSetting", "\347\233\270\346\234\272\345\220\215\347\247\260", nullptr));
        pushButton_LoadNGPath_Second->setText(QCoreApplication::translate("DialogSetting", "\346\211\223\345\274\200\350\267\257\345\276\204", nullptr));
        checkBox_SaveOK_Second->setText(QCoreApplication::translate("DialogSetting", "\344\277\235\345\255\230OK", nullptr));
        radioButton_FreeSecond->setText(QCoreApplication::translate("DialogSetting", "\350\207\252\347\224\261\351\207\207\351\233\206", nullptr));
        pushButton_LoadOKPath_Second->setText(QCoreApplication::translate("DialogSetting", "\346\211\223\345\274\200\350\267\257\345\276\204", nullptr));
        radioButton_SoftSecond->setText(QCoreApplication::translate("DialogSetting", "\350\275\257\350\247\246\345\217\221", nullptr));
        label_15->setText(QCoreApplication::translate("DialogSetting", "\345\242\236\347\233\212", nullptr));
        groupBox_Frist->setTitle(QCoreApplication::translate("DialogSetting", "\344\270\200\345\267\245\344\275\215-\347\233\270\346\234\272\345\217\202\346\225\260", nullptr));
        label->setText(QCoreApplication::translate("DialogSetting", "\346\233\235\345\205\211", nullptr));
        radioButton_FreeFirst->setText(QCoreApplication::translate("DialogSetting", "\350\207\252\347\224\261\351\207\207\351\233\206", nullptr));
        pushButton_LoadNGPath_First->setText(QCoreApplication::translate("DialogSetting", "\346\211\223\345\274\200\350\267\257\345\276\204", nullptr));
        checkBox_SaveOK_First->setText(QCoreApplication::translate("DialogSetting", "\344\277\235\345\255\230OK", nullptr));
        pushButton_LoadOKPath_First->setText(QCoreApplication::translate("DialogSetting", "\346\211\223\345\274\200\350\267\257\345\276\204", nullptr));
        label_First->setText(QCoreApplication::translate("DialogSetting", "\347\233\270\346\234\272\345\220\215\347\247\260", nullptr));
        label_4->setText(QCoreApplication::translate("DialogSetting", "\345\242\236\347\233\212", nullptr));
        lineEdit_NGPath_First->setPlaceholderText(QCoreApplication::translate("DialogSetting", "NG\345\233\276\345\203\217\350\267\257\345\276\204", nullptr));
        pushButton_OpenFirst->setText(QCoreApplication::translate("DialogSetting", "\346\211\223\345\274\200\347\233\270\346\234\272", nullptr));
        pushButton_SaveParams->setText(QCoreApplication::translate("DialogSetting", "\344\277\235\345\255\230\345\217\202\346\225\260", nullptr));
        pushButton_TriggerFirst->setText(QCoreApplication::translate("DialogSetting", "\350\247\246\345\217\221\344\270\200\346\254\241", nullptr));
        lineEdit_OKPath_First->setPlaceholderText(QCoreApplication::translate("DialogSetting", "OK\345\233\276\345\203\217\350\267\257\345\276\204", nullptr));
        radioButton_SoftFirst->setText(QCoreApplication::translate("DialogSetting", "\350\275\257\350\247\246\345\217\221", nullptr));
        radioButton_ExternalFirst->setText(QCoreApplication::translate("DialogSetting", "\347\241\254\350\247\246\345\217\221", nullptr));
        checkBox_SaveNG_First->setText(QCoreApplication::translate("DialogSetting", "\344\277\235\345\255\230NG", nullptr));
        pushButton_SaveConfig->setText(QCoreApplication::translate("DialogSetting", "\344\277\235\345\255\230\350\256\276\347\275\256", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("DialogSetting", "\347\233\270\346\234\272\345\217\202\346\225\260", nullptr));
        groupBox_7->setTitle(QCoreApplication::translate("DialogSetting", "\350\275\257\344\273\266\346\263\250\345\206\214", nullptr));
        label_2->setText(QCoreApplication::translate("DialogSetting", "\346\234\272\345\231\250\347\240\201\357\274\232", nullptr));
        pushButton_Copy->setText(QCoreApplication::translate("DialogSetting", "\345\244\215\345\210\266\346\234\272\345\231\250\347\240\201", nullptr));
        label_3->setText(QCoreApplication::translate("DialogSetting", "\346\263\250\345\206\214\347\240\201\357\274\232", nullptr));
        pushButton_Register->setText(QCoreApplication::translate("DialogSetting", "\346\263\250\345\206\214", nullptr));
        label_RegisterInfo->setText(QCoreApplication::translate("DialogSetting", "\346\234\252\346\263\250\345\206\214", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("DialogSetting", "\347\263\273\347\273\237\345\217\202\346\225\260", nullptr));
        pushButton_LoadFirstImage->setText(QCoreApplication::translate("DialogSetting", "\345\212\240\350\275\275\344\270\200\345\267\245\344\275\215\345\233\276\345\203\217", nullptr));
        label_8->setText(QCoreApplication::translate("DialogSetting", "\350\277\220\350\241\214\346\250\241\345\274\217", nullptr));
        pushButton_LoadThirdImage->setText(QCoreApplication::translate("DialogSetting", "\345\212\240\350\275\275\344\270\211\345\267\245\344\275\215\345\233\276\345\203\217", nullptr));
        pushButton_LoadFourthImage->setText(QCoreApplication::translate("DialogSetting", "\345\212\240\350\275\275\345\233\233\345\267\245\344\275\215\345\233\276\345\203\217", nullptr));
        pushButton_LoadSecondImage->setText(QCoreApplication::translate("DialogSetting", "\345\212\240\350\275\275\344\272\214\345\267\245\344\275\215\345\233\276\345\203\217", nullptr));
        groupBox_10->setTitle(QCoreApplication::translate("DialogSetting", "\351\200\232\350\256\257", nullptr));
        label_5->setText(QCoreApplication::translate("DialogSetting", "IP", nullptr));
        label_6->setText(QCoreApplication::translate("DialogSetting", "\347\253\257\345\217\243", nullptr));
        label_7->setText(QCoreApplication::translate("DialogSetting", "\345\277\203\350\267\263", nullptr));
        spinBox_Heartbeat->setSuffix(QCoreApplication::translate("DialogSetting", "\347\247\222", nullptr));
        pushButton_SendOK->setText(QCoreApplication::translate("DialogSetting", "\345\217\221\351\200\201OK", nullptr));
        pushButton_SendNG->setText(QCoreApplication::translate("DialogSetting", "\345\217\221\351\200\201NG", nullptr));
        label_Status->setText(QString());
        pushButton_ConnectPLC->setText(QCoreApplication::translate("DialogSetting", "\350\277\236\346\216\245PLC", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("DialogSetting", "\347\274\272\351\231\267\351\230\210\345\200\274\350\256\276\347\275\256", nullptr));
        label_22->setText(QCoreApplication::translate("DialogSetting", "\351\235\242\347\247\257\351\230\210\345\200\274", nullptr));
        label_19->setText(QCoreApplication::translate("DialogSetting", "\351\225\277\345\272\246\351\230\210\345\200\274", nullptr));
        label_20->setText(QCoreApplication::translate("DialogSetting", "\345\216\213\344\274\244", nullptr));
        spinBox_Area_YaShang->setSuffix(QString());
        spinBox_Area_YaShang->setPrefix(QString());
        spinBox_Wh_YaShang->setSuffix(QString());
        spinBox_Wh_YaShang->setPrefix(QString());
        label_23->setText(QCoreApplication::translate("DialogSetting", "\347\242\260\344\274\244", nullptr));
        spinBox_Area_PengShang->setSuffix(QString());
        spinBox_Area_PengShang->setPrefix(QString());
        spinBox_Wh_PengShang->setSuffix(QString());
        spinBox_Wh_PengShang->setPrefix(QString());
        label_21->setText(QCoreApplication::translate("DialogSetting", "\345\210\222\344\274\244", nullptr));
        spinBox_Area_HuaShang->setSuffix(QString());
        spinBox_Area_HuaShang->setPrefix(QString());
        spinBox_Wh_HuaShang->setSuffix(QString());
        spinBox_Wh_HuaShang->setPrefix(QString());
        label_24->setText(QCoreApplication::translate("DialogSetting", "\346\223\246\344\274\244", nullptr));
        spinBox_Area_CaShang->setSuffix(QString());
        spinBox_Area_CaShang->setPrefix(QString());
        spinBox_Wh_CaShang->setSuffix(QString());
        spinBox_Wh_CaShang->setPrefix(QString());
        label_41->setText(QCoreApplication::translate("DialogSetting", "\351\223\201\347\262\211", nullptr));
        spinBox_Area_TieFen->setSuffix(QString());
        spinBox_Area_TieFen->setPrefix(QString());
        spinBox_Wh_TieFen->setSuffix(QString());
        spinBox_Wh_TieFen->setPrefix(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("DialogSetting", "\350\277\220\350\241\214\345\217\202\346\225\260", nullptr));
        pushButton_3->setText(QCoreApplication::translate("DialogSetting", "\351\200\211\346\213\251\351\205\215\346\226\271", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("DialogSetting", "\351\205\215\346\226\271\350\256\276\347\275\256", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogSetting: public Ui_DialogSetting {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PARAMETERSETTING_H
