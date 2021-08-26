/********************************************************************************
** Form generated from reading UI file 'statisticswidget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STATISTICSWIDGET_H
#define UI_STATISTICSWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StatisticsWidget
{
public:
    QVBoxLayout *verticalLayout_2;
    QWidget *statistics_widget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *title_layout;
    QLabel *title_name_lab;
    QSpacerItem *horizontalSpacer;
    QPushButton *reset_btn;
    QWidget *total_counts_widget;
    QVBoxLayout *verticalLayout_10;
    QLabel *total_counts_lab;
    QLabel *total_lab;
    QHBoxLayout *pass_and_fail_layout;
    QWidget *pass_widget;
    QVBoxLayout *verticalLayout_11;
    QLabel *pass_counts_lab;
    QLabel *pass_lab;
    QWidget *fail_widget;
    QVBoxLayout *verticalLayout_12;
    QLabel *fail_counts_lab;
    QLabel *fail_lab;
    QWidget *pass_percent_widget;
    QVBoxLayout *verticalLayout_13;
    QLabel *percent_lab;
    QLabel *pass_percent_lab;

    void setupUi(QWidget *StatisticsWidget)
    {
        if (StatisticsWidget->objectName().isEmpty())
            StatisticsWidget->setObjectName(QString::fromUtf8("StatisticsWidget"));
        StatisticsWidget->resize(320, 214);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(StatisticsWidget->sizePolicy().hasHeightForWidth());
        StatisticsWidget->setSizePolicy(sizePolicy);
        StatisticsWidget->setMinimumSize(QSize(320, 214));
        verticalLayout_2 = new QVBoxLayout(StatisticsWidget);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        statistics_widget = new QWidget(StatisticsWidget);
        statistics_widget->setObjectName(QString::fromUtf8("statistics_widget"));
        statistics_widget->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"background-color: rgb(226, 240, 255);"));
        verticalLayout = new QVBoxLayout(statistics_widget);
        verticalLayout->setSpacing(4);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(10, 10, 10, 10);
        title_layout = new QHBoxLayout();
        title_layout->setObjectName(QString::fromUtf8("title_layout"));
        title_layout->setContentsMargins(-1, -1, -1, 6);
        title_name_lab = new QLabel(statistics_widget);
        title_name_lab->setObjectName(QString::fromUtf8("title_name_lab"));
        title_name_lab->setEnabled(true);
        title_name_lab->setAlignment(Qt::AlignCenter);
        title_name_lab->setMargin(0);

        title_layout->addWidget(title_name_lab);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        title_layout->addItem(horizontalSpacer);

        reset_btn = new QPushButton(statistics_widget);
        reset_btn->setObjectName(QString::fromUtf8("reset_btn"));
        reset_btn->setMinimumSize(QSize(50, 25));
        reset_btn->setMaximumSize(QSize(50, 20));
        reset_btn->setCursor(QCursor(Qt::PointingHandCursor));

        title_layout->addWidget(reset_btn);


        verticalLayout->addLayout(title_layout);

        total_counts_widget = new QWidget(statistics_widget);
        total_counts_widget->setObjectName(QString::fromUtf8("total_counts_widget"));
        verticalLayout_10 = new QVBoxLayout(total_counts_widget);
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        verticalLayout_10->setContentsMargins(0, -1, 0, -1);
        total_counts_lab = new QLabel(total_counts_widget);
        total_counts_lab->setObjectName(QString::fromUtf8("total_counts_lab"));
#if QT_CONFIG(tooltip)
        total_counts_lab->setToolTip(QString::fromUtf8(""));
#endif // QT_CONFIG(tooltip)
        total_counts_lab->setStyleSheet(QString::fromUtf8("font: 75 20pt \"Arial\";"));
        total_counts_lab->setText(QString::fromUtf8("0"));
        total_counts_lab->setAlignment(Qt::AlignCenter);

        verticalLayout_10->addWidget(total_counts_lab);

        total_lab = new QLabel(total_counts_widget);
        total_lab->setObjectName(QString::fromUtf8("total_lab"));
        total_lab->setAlignment(Qt::AlignCenter);

        verticalLayout_10->addWidget(total_lab);


        verticalLayout->addWidget(total_counts_widget);

        pass_and_fail_layout = new QHBoxLayout();
        pass_and_fail_layout->setObjectName(QString::fromUtf8("pass_and_fail_layout"));
        pass_and_fail_layout->setContentsMargins(0, -1, 0, -1);
        pass_widget = new QWidget(statistics_widget);
        pass_widget->setObjectName(QString::fromUtf8("pass_widget"));
        verticalLayout_11 = new QVBoxLayout(pass_widget);
        verticalLayout_11->setObjectName(QString::fromUtf8("verticalLayout_11"));
        verticalLayout_11->setContentsMargins(0, 9, 0, -1);
        pass_counts_lab = new QLabel(pass_widget);
        pass_counts_lab->setObjectName(QString::fromUtf8("pass_counts_lab"));
#if QT_CONFIG(tooltip)
        pass_counts_lab->setToolTip(QString::fromUtf8(""));
#endif // QT_CONFIG(tooltip)
        pass_counts_lab->setStyleSheet(QString::fromUtf8("font: 75 16pt \"Arial\";"));
        pass_counts_lab->setText(QString::fromUtf8("0"));
        pass_counts_lab->setAlignment(Qt::AlignCenter);

        verticalLayout_11->addWidget(pass_counts_lab);

        pass_lab = new QLabel(pass_widget);
        pass_lab->setObjectName(QString::fromUtf8("pass_lab"));
        pass_lab->setAlignment(Qt::AlignCenter);

        verticalLayout_11->addWidget(pass_lab);


        pass_and_fail_layout->addWidget(pass_widget);

        fail_widget = new QWidget(statistics_widget);
        fail_widget->setObjectName(QString::fromUtf8("fail_widget"));
        verticalLayout_12 = new QVBoxLayout(fail_widget);
        verticalLayout_12->setObjectName(QString::fromUtf8("verticalLayout_12"));
        verticalLayout_12->setContentsMargins(0, -1, 0, -1);
        fail_counts_lab = new QLabel(fail_widget);
        fail_counts_lab->setObjectName(QString::fromUtf8("fail_counts_lab"));
#if QT_CONFIG(tooltip)
        fail_counts_lab->setToolTip(QString::fromUtf8(""));
#endif // QT_CONFIG(tooltip)
        fail_counts_lab->setStyleSheet(QString::fromUtf8("font: 75 16pt \"Arial\";"));
        fail_counts_lab->setText(QString::fromUtf8("0"));
        fail_counts_lab->setAlignment(Qt::AlignCenter);

        verticalLayout_12->addWidget(fail_counts_lab);

        fail_lab = new QLabel(fail_widget);
        fail_lab->setObjectName(QString::fromUtf8("fail_lab"));
        fail_lab->setAlignment(Qt::AlignCenter);

        verticalLayout_12->addWidget(fail_lab);


        pass_and_fail_layout->addWidget(fail_widget);

        pass_percent_widget = new QWidget(statistics_widget);
        pass_percent_widget->setObjectName(QString::fromUtf8("pass_percent_widget"));
        verticalLayout_13 = new QVBoxLayout(pass_percent_widget);
        verticalLayout_13->setObjectName(QString::fromUtf8("verticalLayout_13"));
        verticalLayout_13->setContentsMargins(0, -1, 0, -1);
        percent_lab = new QLabel(pass_percent_widget);
        percent_lab->setObjectName(QString::fromUtf8("percent_lab"));
#if QT_CONFIG(tooltip)
        percent_lab->setToolTip(QString::fromUtf8(""));
#endif // QT_CONFIG(tooltip)
        percent_lab->setStyleSheet(QString::fromUtf8("font: 75 16pt \"Arial\";"));
        percent_lab->setText(QString::fromUtf8("0%"));
        percent_lab->setAlignment(Qt::AlignCenter);

        verticalLayout_13->addWidget(percent_lab);

        pass_percent_lab = new QLabel(pass_percent_widget);
        pass_percent_lab->setObjectName(QString::fromUtf8("pass_percent_lab"));
        pass_percent_lab->setAlignment(Qt::AlignCenter);

        verticalLayout_13->addWidget(pass_percent_lab);


        pass_and_fail_layout->addWidget(pass_percent_widget);


        verticalLayout->addLayout(pass_and_fail_layout);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 4);
        verticalLayout->setStretch(2, 4);

        verticalLayout_2->addWidget(statistics_widget);


        retranslateUi(StatisticsWidget);

        QMetaObject::connectSlotsByName(StatisticsWidget);
    } // setupUi

    void retranslateUi(QWidget *StatisticsWidget)
    {
        StatisticsWidget->setWindowTitle(QCoreApplication::translate("StatisticsWidget", "Form", nullptr));
        title_name_lab->setText(QCoreApplication::translate("StatisticsWidget", "\346\225\260\346\215\256\347\273\237\350\256\241", nullptr));
        reset_btn->setText(QCoreApplication::translate("StatisticsWidget", "\351\207\215\347\275\256", nullptr));
        total_lab->setText(QCoreApplication::translate("StatisticsWidget", "\346\243\200\346\265\213\346\200\273\346\225\260", nullptr));
        pass_lab->setText(QCoreApplication::translate("StatisticsWidget", "\350\211\257\345\223\201\346\225\260\351\207\217", nullptr));
        fail_lab->setText(QCoreApplication::translate("StatisticsWidget", "\344\270\215\350\211\257\346\225\260\351\207\217", nullptr));
        pass_percent_lab->setText(QCoreApplication::translate("StatisticsWidget", "\350\211\257\345\223\201\347\216\207", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StatisticsWidget: public Ui_StatisticsWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STATISTICSWIDGET_H
