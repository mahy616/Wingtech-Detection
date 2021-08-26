#include "mylabel.h"
#include <QPainter>
#include <QDebug>
#include <QWheelEvent>
#include <QMenu>
#include <QFileDialog>

MyLabel::MyLabel(QWidget *parent) :QLabel(parent)
{

}

//QPainter画图
void MyLabel::paintEvent(QPaintEvent *event)
{
	QPainter painter(this);
	painter.setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
	// 根据窗口计算应该显示的图片的大小
	m_Mutex.lock();
	int width = qMin(m_Image.width(), this->width());
	int height = width * 1.0 / (m_Image.width() * 1.0 / m_Image.height());
	height = qMin(height, this->height());
	width = height * 1.0 * (m_Image.width() * 1.0 / m_Image.height());

	// 平移
	painter.translate(this->width() / 2 + XPtInterval, this->height() / 2 + YPtInterval);

	// 缩放
	painter.scale(ZoomValue, ZoomValue);
	
	// 绘制图像
	QRect picRect(-width / 2, -height / 2, width, height);
	painter.drawImage(picRect, m_Image);
	m_Mutex.unlock();
}

//鼠标滚轮滚动
void MyLabel::wheelEvent(QWheelEvent *event)
{
	int value = event->delta();
	if (value > 0)  //放大
		OnZoomInImage();
	else            //缩小
		OnZoomOutImage();

	update();
}

//鼠标摁下
void MyLabel::mousePressEvent(QMouseEvent *event)
{
	OldPos = event->pos();
	Pressed = true;
}

void MyLabel::mouseDoubleClickEvent(QMouseEvent *event)
{
	if (event->button() == Qt::LeftButton)
	{
		ZoomValue = 1.0;
		XPtInterval = 0;
		YPtInterval = 0;
		update();
	}
}
//鼠标松开
void MyLabel::mouseMoveEvent(QMouseEvent *event)
{
	if (!Pressed)
		return QWidget::mouseMoveEvent(event);

	this->setCursor(Qt::SizeAllCursor);
	QPoint pos = event->pos();
	int xPtInterval = pos.x() - OldPos.x();
	int yPtInterval = pos.y() - OldPos.y();

	XPtInterval += xPtInterval;
	YPtInterval += yPtInterval;

	OldPos = pos;
	update();
}
//鼠标发射事件
void MyLabel::mouseReleaseEvent(QMouseEvent *event)
{
	Pressed = false;
	setCursor(Qt::ArrowCursor);
}

//图片放大
void MyLabel::OnZoomInImage()
{
	ZoomValue += 1;
	if (ZoomValue > 55)
	{
		ZoomValue = 55;
	}
	update();
}

//图片缩小
void MyLabel::OnZoomOutImage()
{
	ZoomValue -= 1;
	if (ZoomValue <= 0)
	{
		ZoomValue = 0.5;
		return;
	}

	update();
}

//图片还原
void MyLabel::OnPresetImage()
{
	ZoomValue = 1.0;
	XPtInterval = 0;
	YPtInterval = 0;
	update();
}

void MyLabel::SetImage(QImage image)
{
	m_Mutex.lock();
	m_Image = image.copy(0,0,image.width(),image.height());
	m_Mutex.unlock();
	update();
}

QImage MyLabel::GetImage()
{
	return m_Image;
}