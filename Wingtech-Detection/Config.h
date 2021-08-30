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

//路径相关
const QString PATHLINE_SECTOIN = "Path_LineEdite";
const QString CAMERA_FIRST_LINE_OK = "CAMERA_FIRST_LINE_OK";
const QString CAMERA_FIRST_LINE_NG = "CAMERA_FIRST_LINE_NG";
const QString CAMERA_SECOND_LINE_OK = "CAMERA_SECOND_LINE_OK";
const QString CAMERA_SECOND_LINE_NG = "CAMERA_SECOND_LINE_NG";
const QString CAMERA_THIRD_LINE_OK = "CAMERA_THIRD_LINE_OK";
const QString CAMERA_THIRD_LINE_NG = "CAMERA_THIRD_LINE_NG";
const QString CAMERA_FOURTH_LINE_OK = "CAMERA_FOURTH_LINE_OK";
const QString CAMERA_FOURTH_LINE_NG = "CAMERA_FOURTH_LINE_NG";


//通讯相关
const QString COMMUNICATION_SECTOIN = "Communication";
const QString COM_STATUS = "Com_Status";
const QString IP = "Ip";
const QString HEARTBEAT = "Heartbeat";
const QString PORT = "Port";

//数据相关
const QString DATA_SECTION = "Data_Section";
const QString SAVE_NG = "Save_NG";
const QString SAVE_OK = "Save_OK";
const QString NG_PATH = "NG_Path";
const QString OK_PATH = "OK_Path";

//工位一阈值
const QString FIRST_THRESHOLD = "First_Threshold";

const QString FIRST_AREA_THRESHOLD1 = "First_Area_Threshold1";
const QString FIRST_AREA_THRESHOLD2 = "First_Area_Threshold2";
const QString FIRST_AREA_THRESHOLD3 = "First_Area_Threshold3";
const QString FIRST_AREA_THRESHOLD4 = "First_Area_Threshold4";
const QString FIRST_WH_THRESHOLD6 = "First_Wh_Threshold6";
const QString FIRST_WH_THRESHOLD7 = "First_Wh_Threshold7";
const QString FIRST_WH_THRESHOLD8 = "First_Wh_Threshold8";
const QString FIRST_WH_THRESHOLD9 = "First_Wh_Threshold9";

//工位二阈值
const QString SECOND_THRESHOLD = "Second_Threshold";

const QString SECOND_AREA_THRESHOLD1 = "Second_Area_Threshold1";
const QString SECOND_AREA_THRESHOLD2 = "Second_Area_Threshold2";
const QString SECOND_AREA_THRESHOLD3 = "Second_Area_Threshold3";
const QString SECOND_AREA_THRESHOLD4 = "Second_Area_Threshold4";
const QString SECOND_AREA_THRESHOLD5 = "Second_Area_Threshold5";
const QString SECOND_AREA_THRESHOLD6 = "Second_Area_Threshold6";
const QString SECOND_AREA_THRESHOLD7 = "Second_Area_Threshold7";
const QString SECOND_AREA_THRESHOLD8 = "Second_Area_Threshold8";
const QString SECOND_AREA_THRESHOLD9 = "Second_Area_Threshold9";
const QString SECOND_WH_THRESHOLD11 = "Second_Wh_Threshold11";
const QString SECOND_WH_THRESHOLD12 = "Second_Wh_Threshold12";
const QString SECOND_WH_THRESHOLD13 = "Second_Wh_Threshold13";
const QString SECOND_WH_THRESHOLD14 = "Second_Wh_Threshold14";
const QString SECOND_WH_THRESHOLD15 = "Second_Wh_Threshold15";
const QString SECOND_WH_THRESHOLD16 = "Second_Wh_Threshold16";
const QString SECOND_WH_THRESHOLD17 = "Second_Wh_Threshold17";
const QString SECOND_WH_THRESHOLD18 = "Second_Wh_Threshold18";
const QString SECOND_WH_THRESHOLD19 = "Second_Wh_Threshold19";

//角度阈值
const QString DEGREE_THRESHOLD = "Degree_Threshold";
const QString DEGREE_Add = "Degree_Add";
const QString DEGREE_Sub= "Degree_Sub";


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