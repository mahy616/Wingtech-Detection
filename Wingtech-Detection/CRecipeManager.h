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
	//��ȡ�����䷽�������ص������б���
	void InitRecipeNames();
	//�����㷨,TODO������Ͳ���
	void RunAlgo(Mat Image, int ImageID);
	//PLC��ȡ���䷽���ƣ����ػ�����һ�������Ƶ�ini�ļ�
	void SaveRecipeFromPLC(QString RecipeName, int ImageCount);
	//��ʼ���䷽����ʼ���ɹ�����true��֪ͨPLC Ready�źţ����򷵻�false������log��ʾ���������Ϣ
	bool InitRecipe(QString RecipeName,QString &errMsg);
	void InitConnections();
	void SendPLCReadySign();
	s_ImageInfo ImageInfo;
public:

private:
	void InitVariables();
	QStringList getFileNames(const QString &path);

private:
	Ui::CRecipeManagerClass ui;
	//ͼ��ID��Ӧģ�ͱ�
	QMap<int, QString> m_ImageAndModel;
	QMap<QString, CAlgoManager*> m_ModelAndAlgo;
	CAlgoManager* m_Algo;
	bool m_Ready;
	int m_ImageID;  //ͼ��ID
	int m_Number=5;   //�䷽��ͼ�����
signals:
	void SendAlgoImage(Mat image, Mat RenderImage, int index, bool bOK, e_CameraType type);
private slots:
	//�л��䷽����ȡ�����ļ���Tabwidget��ʾ��������
	void SwitchRecipe(QString Name);
	//�����䷽�������ͼ��IDû��ѡ��ģ�ͣ����ܱ���
	void SaveRecipe();
	//���ģ��
	void BrowseModelPath();

	void ReceiveSavePlcRecipe(QString msg, int number);
	void ReceiveChangePlcRecipe(QString msg, int number);

	void ReceivaOriginalImage(Mat Image, int ImageID);
	void ReceivaAlgoImage(Mat image, Mat RenderImage, int index, bool bOK, e_CameraType type);
};
