#include "QGlobalSystemConfig.h"
#include <QtWidgets\QApplication>
#include <QDir>

#include "QTextCodec"
#include "QUuid"

//! �����ļ���ַ
#define SYSTEM_INI_PATH					 ("./sysConf")


//! Ĭ����������
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

	//! ����Qsetting����
	m_pConfigSettings = new QSettings(SYSTEM_INI_PATH, QSettings::IniFormat, this);
	//m_pConfigSettings->setIniCodec("UTF-8");

	//! ��ȡ�����ļ���Ϣ
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
*	\brief	ͨ�������ļ���ʼ�����ñ�����Ϣ
*	
*	\param_in	void
*
*	\retval	void
*/
void QGlobalSystemConfig::ReadVarValueByIniFile()
{
	//��ʼ��GLOBALConfig�ε���������
	InitHomeUiConfigSec();

	//! ��ʼ��GLDTCSConfig�ε���������
	InitSECUIConfigSec();
}


void QGlobalSystemConfig::InitHomeUiConfigSec()
{
	if(!m_pConfigSettings)
	{
		return;
	}

	m_pConfigSettings->beginGroup(INI_SEC_HOMEUI_CONFIG);
	
	//! ��ȡ��������ַ

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
*	\brief	��ʼ��GLDTCSConfig�ε���������
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

	//! ��ȡ��������ַ

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
