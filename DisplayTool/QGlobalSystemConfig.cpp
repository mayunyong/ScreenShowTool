#include "QGlobalSystemConfig.h"
#include <QtWidgets\QApplication>
#include <QDir>

#include "QTextCodec"
#include "QUuid"

//! 配置文件地址
#define SYSTEM_INI_PATH					 ("./sysConf")


//! 默认配置属性
#define INI_SEC_HOMEUI_CONFIG		("HomePage")
#define INI_SEC_SEC_CONFIG			("SecondPage")								


#define INI_HOMEBTN_KEY		("HomeBtn%1")							
#define INI_SECBTN_KEY		("SecondBtn%1")							
#define INI_SECLABEL_KEY	("SecondLabel_%1")	


 QGlobalSystemConfig* QGlobalSystemConfig::m_spInstance = NULL;

QGlobalSystemConfig::QGlobalSystemConfig(QObject *parent)
	: QObject(parent)
	,m_pConfigSettings(NULL)
{
	QDir dir;  
	if(!dir.exists(SYSTEM_INI_PATH))
	{
		return;
	}

	//! 构造Qsetting对象
	m_pConfigSettings = new QSettings(SYSTEM_INI_PATH, QSettings::IniFormat, this);
	//m_pConfigSettings->setIniCodec("UTF-8");

	//! 获取配置文件信息
	ReadVarValueByIniFile();
}

QGlobalSystemConfig::~QGlobalSystemConfig()
{

}

QGlobalSystemConfig* QGlobalSystemConfig::Instance()
{
	if( m_spInstance == NULL ) 
	{
		m_spInstance = new QGlobalSystemConfig();
	}

	return m_spInstance;
}

/*!
*	\brief	通过配置文件初始化配置变量信息
*	
*	\param_in	void
*
*	\retval	void
*/
void QGlobalSystemConfig::ReadVarValueByIniFile()
{
	//初始化GLOBALConfig段的配置属性
	InitHomeUiConfigSec();

	//! 初始化GLDTCSConfig段的配置属性
	InitSECUIConfigSec();
}


void QGlobalSystemConfig::InitHomeUiConfigSec()
{
	if(!m_pConfigSettings)
	{
		return;
	}

	m_pConfigSettings->beginGroup(INI_SEC_HOMEUI_CONFIG);
	
	//! 获取服务器网址

		for(int index = 1; index < 6; index++)
		{
			QVariant qVal = m_pConfigSettings->value(QString(INI_HOMEBTN_KEY).arg(index));
			if(qVal.type() == QVariant::StringList)
			{
				QStringList strPosList = qVal.toStringList();
				if(2 == strPosList.size())
				{
					QPoint btnPos;
					btnPos.setX(strPosList[0].toInt());
					btnPos.setY(strPosList[1].toInt());

					m_HomeBtnPosMap[index] = btnPos;
				}
			}
		}

	m_pConfigSettings->endGroup();
}


/*!
*	\brief	初始化GLDTCSConfig段的配置属性
*	
*	\param_in	void
*
*	\retval	void
*/
void QGlobalSystemConfig::InitSECUIConfigSec()
{
	if(!m_pConfigSettings)
	{
		return;
	}

	m_pConfigSettings->beginGroup(INI_SEC_SEC_CONFIG);

	//! 获取服务器网址

	for(int index = 1; index < 10; index++)
	{
		QVariant qVal = m_pConfigSettings->value(QString(INI_SECBTN_KEY).arg(index));
		if(qVal.type() == QVariant::StringList)
		{
			QStringList strPosList = qVal.toStringList();
			if(2 == strPosList.size())
			{
				QPoint btnPos;
				btnPos.setX(strPosList[0].toInt());
				btnPos.setY(strPosList[1].toInt());

				m_SecondBtnPosMap[index] = btnPos;
			}
		}
	}

	for(int index = 1; index < 6; index++)
	{
		QVariant qVal = m_pConfigSettings->value(QString(INI_SECLABEL_KEY).arg(index));
		if(qVal.type() == QVariant::StringList)
		{
			QStringList strPosList = qVal.toStringList();
			if(2 == strPosList.size())
			{
				QPoint btnPos;
				btnPos.setX(strPosList[0].toInt());
				btnPos.setY(strPosList[1].toInt());

				m_SecondLabelPosMap[index] = btnPos;
			}
		}
	}


	m_pConfigSettings->endGroup();
}
