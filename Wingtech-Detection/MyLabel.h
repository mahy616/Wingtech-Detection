#ifndef MYLABEL_H
#define MYLABEL_H

#include <QObject>
#include <QLabel>
#include <QMutex>

class MyLabel : public QLabel
{
	Q_OBJECT
public:
	explicit MyLabel(QWidget *parent = 0);
	void SetImage(QImage image);
	QImage GetImage();
protected:
	void paintEvent(QPaintEvent *event);                        //QPaint画图
	void wheelEvent(QWheelEvent *event) override;               //鼠标滚轮滚动
	void mousePressEvent(QMouseEvent *event) override;          //鼠标摁下
	void mouseDoubleClickEvent(QMouseEvent *event) override;    //双击，还原图像大小
	void mouseMoveEvent(QMouseEvent *event) override;           //鼠标松开
	void mouseReleaseEvent(QMouseEvent *event) override;        //鼠标发射事件

private:
	void OnZoomInImage();       //图片放大
	void OnZoomOutImage();      //图片缩小
	void OnPresetImage();       //图片还原

private:
	QMutex m_Mutex;
	QImage m_Image;           //显示的图片
	qreal ZoomValue = 1.0;  //鼠标缩放值
	int XPtInterval = 0;    //平移X轴的值
	int YPtInterval = 0;    //平移Y轴的值
	QPoint OldPos;          //旧的鼠标位置
	bool Pressed = false;   //鼠标是否被摁压
};

#endif // MYLABEL_H

