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
	//��ȡ�����䷽�������ص������б���
	void InitRecipeNames();
	//�����㷨,TODO������Ͳ���
	void RunAlgo(Mat Image, int ImageID);
	//PLC��ȡ���䷽���ƣ����ػ�����һ�������Ƶ�ini�ļ�
	void SaveRecipeFromPLC(QString RecipeName, int ImageCount);
	//��ʼ���䷽����ʼ���ɹ�����true��֪ͨPLC Ready�źţ����򷵻�false������log��ʾ���������Ϣ
	bool InitRecipe(QString RecipeName,QString &errMsg);
	void InitConnections();
	s_ImageInfo ImageInfo;
private:
	void InitVariables();
	QStringList getFileNames(const QString &path);
private:
	Ui::CRecipeManagerClass ui;
	//ͼ��ID��Ӧģ�ͱ�
	QMap<int, QString> m_ImageAndModel;
	QMap<QString, CAlgoManager*> m_ModelAndAlgo;

signals:
	void SendOriginalImage(s_ImageInfo ImageInfo);
private slots:
	//�л��䷽����ȡ�����ļ���Tabwidget��ʾ��������
	void SwitchRecipe(QString Name);
	//�����䷽�������ͼ��IDû��ѡ��ģ�ͣ����ܱ���
	void SaveRecipe();
	//���ģ��
	void BrowseModelPath();


	void ReceivaOriginalImage(Mat Image, int ImageID);
};
