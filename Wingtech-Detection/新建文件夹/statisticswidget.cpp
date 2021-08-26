/****************************************************************************
 *  @file     statisticswidget.cpp
 *  @brief    统计显示窗口类
 *  @author   junjie.zeng
 *  @email    junjie.zeng@smartmore.com
 *  @version
 *  @date     2020.12.21
 *  Copyright (c) 2020 SmartMore All rights reserved.
 ****************************************************************************/
#include "statisticswidget.h"


StatisticsWidget::StatisticsWidget(QWidget *parent) : QWidget(parent), ui(new Ui::StatisticsWidget)
{
	ui->setupUi(this);
	m_total_counts = 0;
	m_ng_counts = 0;
	m_ok_counts = 0;
	updateStatisticsResult();
}

StatisticsWidget::~StatisticsWidget()
{
    delete ui;
}

void StatisticsWidget::SetSuccess()
{
	m_total_counts++;
	m_ok_counts++;
	updateStatisticsResult();
}

void StatisticsWidget::SetFailed()
{
	m_total_counts++;
	m_ng_counts++;
	updateStatisticsResult();
}

void StatisticsWidget::on_reset_btn_clicked()
{
    m_total_counts = 0;
    m_ng_counts = 0;
    m_ok_counts = 0;
    m_pass_percent = 0.0000f;
    updateStatisticsResult();
}

void StatisticsWidget::updateStatisticsResult()
{
    ui->total_counts_lab->setText(QString::number(m_total_counts));
    ui->pass_counts_lab->setText(QString::number(m_ok_counts));
    ui->fail_counts_lab->setText(QString::number(m_ng_counts));
    ui->percent_lab->setText(QString::number(m_pass_percent, 'f', 2) + "%");
}