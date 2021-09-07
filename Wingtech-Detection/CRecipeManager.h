#pragma once
#include <QtWidgets/QDialog>
#include "ui_CRecipeManager.h"
#include "QMap"
#include "AlgoManager.h"
#include "PLCManager.h"
//#include "ImageCapture.h"
class CRecipeManager : public QDialog
{
	Q_OBJECT
public:
	CRecipeManager(QWidget *parent = Q_NULLPTR);
	//读取本地配方，并加载到下拉列表中
	void InitRecipeNames();
	//运行算法,TODO相机类型参数
	void RunAlgo(Mat Image, int ImageID, e_CameraType type);
	//PLC获取的配方名称，本地会生成一个该名称的ini文件
	void SaveRecipeFromPLC(QString RecipeName, int ImageCount);
	//初始化配方，初始化成功返回true，通知PLC Ready信号，否则返回false，界面log提示具体错误信息
	bool InitRecipe(QString RecipeName,QString &errMsg);
	void InitConnections();
	void SendPLCReadySign();
	
public:

private:
	void InitVariables();
	QStringList getFileNames(const QString &path);

private:
	Ui::CRecipeManagerClass ui;
	//图像ID对应模型表
	QMap<int, QString> m_ImageAndModel;
	QMap<QString, CAlgoManager*> m_ModelAndAlgo;
	CAlgoManager* m_Algo;
	bool m_Ready;
	int m_ImageID;  //图像ID
	int m_Number=5;   //配方个图像个数
	s_ImageInfo ImageInfo;
	QVector<double>m_AlgoThreshold;
	
signals:
	void SendAlgoImage(Mat image, Mat RenderImage, int index, bool bOK, e_CameraType type);
	void SendInitImageNumber(int number);
	void SendStartSign();
private slots:
	//切换配方，读取本地文件，Tabwidget显示具体内容
	void SwitchRecipe(QString Name);
	//保存配方，如果有图像ID没有选择模型，不能保存
	void SaveRecipe();
	//浏览模型
	void BrowseModelPath();
	//PLC触发保存配方
	void ReceiveSavePlcRecipe(QString msg, int number);     
	//PLC触发切换配方
	void ReceiveChangePlcRecipe(QString msg, int number);
	//接收源图
	void ReceivaOriginalImage(Mat Image, int ImageID, e_CameraType Type);
	//接收算法渲染图
	void ReceivaAlgoImage(Mat image, Mat RenderImage, int index, bool bOK, e_CameraType type);
	//接受开始拍照信号
	void ReceiveStartSign();
	//接收阈值设置完成信号
	void ReceiveAlgoThreshold(QVector<double>AlgoThreshold);
};
