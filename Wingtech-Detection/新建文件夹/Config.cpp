#include "Config.h"
#include "qtextcodec.h"

CConfig::CConfig(QString IniPath)
	:m_IniPath(IniPath)
{
	m_Settings = new QSettings(m_IniPath,QSettings::IniFormat);
	m_Settings->setIniCodec(QTextCodec::codecForName("GB2312"));
}

CConfig::~CConfig()
{

}

bool CConfig::SectionExists(QString section)
{
	QStringList Groups = m_Settings->childGroups();
	for(int i = 0; i < Groups.size(); ++i)
	{
		QString Group = Groups.at(i);
		if(Group == section)
		{
			return true;
		}
	}
	return false;
}

QStringList CConfig::GetChildKeys(QString Section)
{
	m_Settings->beginGroup(Section);
	QStringList ls = m_Settings->childKeys();
	QStringList ls1 = m_Settings->allKeys();
	QStringList ls2 = m_Settings->childGroups();
	m_Settings->endGroup();
	return ls;
}

int CConfig::GetInt(QString Section,QString Key)
{
	m_Settings->beginGroup(Section);
	int value = m_Settings->value(Key).toInt();
	m_Settings->endGroup();
	return value;
}

double CConfig::GetDouble(QString Section,QString Key)
{
	m_Settings->beginGroup(Section);
	double value = m_Settings->value(Key).toDouble();
	m_Settings->endGroup();
	return value;
}

QString CConfig::GetString(QString Section,QString Key)
{
	m_Settings->beginGroup(Section);
	QString value = m_Settings->value(Key).toString();
	m_Settings->endGroup();
	return value;
}

bool CConfig::GetBool(QString Section,QString Key)
{
	m_Settings->beginGroup(Section);
	bool value = m_Settings->value(Key).toBool();
	m_Settings->endGroup();
	return value;
}

void CConfig::Write(QString Section,QString Key,QVariant Value)
{
	QString strSection = Section + "/" + Key;
	m_Settings->setValue(strSection,Value);
}

void CConfig::RemoveKey(QString Section)
{
	m_Settings->beginGroup(Section);
	QStringList Keys = m_Settings->allKeys();
	for (int i = 0; i < Keys.size(); ++i)
	{
		QString key = Keys.at(i);
		m_Settings->remove(key);
	}
	m_Settings->endGroup();
}