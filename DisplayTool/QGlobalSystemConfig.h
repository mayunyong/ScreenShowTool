#ifndef GLOBALSYSTEMCONFIG_H
#define GLOBALSYSTEMCONFIG_H

#include <QObject>
#include "QSettings"
#include "QMap"
#include "QPoint"


class  QGlobalSystemConfig : public QObject
{
	Q_OBJECT
	

private:
	QGlobalSystemConfig(QObject *parent = NULL);
	virtual ~QGlobalSystemConfig();

public:
	static QGlobalSystemConfig* Instance();


private:
	static QGlobalSystemConfig* m_spInstance;

private:
 	void ReadVarValueByIniFile();
	//! 初始化globalconfig段得变量值
	void InitHomeUiConfigSec();
	//! 初始化GLDTCSconfig段得变量值
	void InitSECUIConfigSec();
	

public:
	QMap<int, QPoint> GetHomeBtnPosMap(){ return m_HomeBtnPosMap; }
	QMap<int, QPoint> GetSecondBtnPosMap(){ return m_SecondBtnPosMap; }
	QMap<int, QPoint> GetSecondLabelPosMap(){ return m_SecondLabelPosMap; }

protected:
	QMap<int, QPoint> m_HomeBtnPosMap;
	QMap<int, QPoint> m_SecondBtnPosMap;
	QMap<int, QPoint> m_SecondLabelPosMap;

	//! 配置属性
	QSettings* m_pConfigSettings;
};

#endif // GLOBALSYSTEMCONFIG_H
