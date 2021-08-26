#pragma once
#include <QtWidgets/QDialog>
#include "ui_CRecipeManager.h"
#include "QMap"
#include "AlgoManager.h"
//#include "ImageCapture.h"
class CRecipeManager : public QDialog
{
	Q_OBJECT
public:
	CRecipeManager(QWidget *parent = Q_NULLPTR);
	//读取本地配方，并加载到下拉列表中
	void InitRecipeNames();
	//运行算法,TODO相机类型参数
	void RunAlgo(Mat Image, int ImageID);
	//PLC获取的配方名称，本地会生成一个该名称的ini文件
	void SaveRecipeFromPLC(QString RecipeName, int ImageCount);
	//初始化配方，初始化成功返回true，通知PLC Ready信号，否则返回false，界面log提示具体错误信息
	bool InitRecipe(QString RecipeName,QString &errMsg);
	void InitConnections();
	s_ImageInfo ImageInfo;
private:
	void InitVariables();
	QStringList getFileNames(const QString &path);
private:
	Ui::CRecipeManagerClass ui;
	//图像ID对应模型表
	QMap<int, QString> m_ImageAndModel;
	QMap<QString, CAlgoManager*> m_ModelAndAlgo;

signals:
	void SendOriginalImage(s_ImageInfo ImageInfo);
private slots:
	//切换配方，读取本地文件，Tabwidget显示具体内容
	void SwitchRecipe(QString Name);
	//保存配方，如果有图像ID没有选择模型，不能保存
	void SaveRecipe();
	//浏览模型
	void BrowseModelPath();


	void ReceivaOriginalImage(Mat Image, int ImageID);
};
