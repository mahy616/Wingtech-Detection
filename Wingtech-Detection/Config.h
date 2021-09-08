#pragma  once
#include "qsettings.h"



const QString MODEL = "Model";
const QString INDEX = "Index";
//相机相关
const QString CAMERA_SECTION = "Camera";
const QString FIRST_CAMERA_NAME = "First_CameraName";
const QString SECOND_CAMERA_NAME = "Second_CameraName";
const QString THIRD_CAMERA_NAME = "Third_CameraName";
const QString FOURTH_CAMERA_NAME = "Fourth_CameraName";


//通讯相关
const QString COMMUNICATION_SECTOIN = "Communication";
const QString COM_STATUS = "Com_Status";
const QString IP = "Ip";
const QString HEARTBEAT = "Heartbeat";
const QString PORT = "Port";

//数据相关
const QString DATA_SECTION = "Data_Section";

const QString SAVE_NG_FIRST = "Save_NG_FIRST";
const QString SAVE_OK_FIRST = "Save_OK_FIRST";
const QString NG_PATH_FIRST = "NG_Path_FIRST";
const QString OK_PATH_FIRST = "OK_Path_FIRST";

const QString SAVE_NG_SECOND = "Save_NG_SECOND";
const QString SAVE_OK_SECOND = "Save_OK_SECOND";
const QString NG_PATH_SECOND = "NG_Path_SECOND";
const QString OK_PATH_SECOND = "OK_Path_SECOND";

const QString SAVE_NG_THIRD = "Save_NG_THIRD";
const QString SAVE_OK_THIRD = "Save_OK_THIRD";
const QString NG_PATH_THIRD = "NG_Path_THIRD";
const QString OK_PATH_THIRD = "OK_Path_THIRD";

const QString SAVE_NG_FOURTH = "Save_NG_FOURTH";
const QString SAVE_OK_FOURTH = "Save_OK_FOURTH";
const QString NG_PATH_FOURTH = "NG_Path_FOURTH";
const QString OK_PATH_FOURTH = "OK_Path_FOURTH";

//阈值
const QString FIRST_THRESHOLD = "Threshold";

const QString FIRST_AREA_THRESHOLD1 = "Area_Threshold1";
const QString FIRST_AREA_THRESHOLD2 = "Area_Threshold2";
const QString FIRST_AREA_THRESHOLD3 = "Area_Threshold3";
const QString FIRST_AREA_THRESHOLD4 = "Area_Threshold4";
const QString FIRST_AREA_THRESHOLD5 = "Area_Threshold5";
const QString FIRST_WH_THRESHOLD6 = "Wh_Threshold6";
const QString FIRST_WH_THRESHOLD7 = "Wh_Threshold7";
const QString FIRST_WH_THRESHOLD8 = "Wh_Threshold8";
const QString FIRST_WH_THRESHOLD9 = "Wh_Threshold9";
const QString FIRST_WH_THRESHOLD10 = "Wh_Threshold10";



class CConfig
{
public:
	CConfig(QString IniPath);
	~CConfig();
	bool SectionExists(QString section);
	QStringList GetChildKeys(QString Section);
	int GetInt(QString Section,QString Key);
	double GetDouble(QString Section,QString Key);
	QString GetString(QString Section,QString Key);
	bool GetBool(QString Section,QString Key);
	void Write(QString Section,QString Key,QVariant Value);
	void RemoveKey(QString Section);
private:
	QString m_IniPath;
	QSettings *m_Settings;
};