/****************************************************************************
 *  @file     statisticswidget.h
 *  @brief    统计显示窗口类
 *  @author   junjie.zeng
 *  @email    junjie.zeng@smartmore.com
 *  @version
 *  @date     2020.12.21
 *  Copyright (c) 2020 SmartMore All rights reserved.
 ****************************************************************************/
#ifndef STATISTICSWIDGET_H
#define STATISTICSWIDGET_H
#include "ui_statisticswidget.h"

class StatisticsWidget : public QWidget
{
    Q_OBJECT

public:
    explicit StatisticsWidget(QWidget *parent = nullptr);
    ~StatisticsWidget();
	void SetSuccess();
	void SetFailed();
private slots:
    void on_reset_btn_clicked();

private:
    void updateStatisticsResult();

private:
    Ui::StatisticsWidget *ui;
    int m_total_counts;
    int m_ng_counts;
    int m_ok_counts;
    float m_pass_percent{0.0000f};
};
#endif  // STATISTICSWIDGET_H
