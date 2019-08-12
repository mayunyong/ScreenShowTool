#include "playData.h"
#include "qcoreapplication.h"
#include "QSettings.h"
#include "qfile.h"
#include <QJsonDocument>
#include <QJsonParseError>
#include <QFile>
#include <QDebug>
#include <QJsonArray>
#include <QDir>

#define RLUE_CONFIG         "./ruleConf"
#define SYS_CONFIG          "./sysConf"
#define SYS_CONFIG_SYSTEM   "system"
#define SYS_CONFIG_DIRPATH  "dirpath"
#define SYS_CONFIG_DIRPATH_KEY  SYS_CONFIG_SYSTEM"/"SYS_CONFIG_DIRPATH

//*********************************************************
QPlayInfo::QPlayInfo() :playData(NULL)
{
}

QPlayInfo::QPlayInfo(const QPlayInfo &r)
{
	displayName = r.displayName;
	name        = r.name;
	parentName  = r.parentName;
	filePath    = r.filePath;
	dispalyID   = r.dispalyID;
	pageRoll    = r.pageRoll;
	isExist     = r.isExist;
	fileType    = r.fileType;

	if (r.playData)
	{
		playData = new QPlayData;
		*playData = *r.playData;
	}
};

QPlayInfo::~QPlayInfo()
{
	if (NULL != playData)
	{
		delete playData;
		playData = NULL;
	}
}

QPlayInfo & QPlayInfo::operator = (const QPlayInfo &r)
{
	displayName = r.displayName;
	name        = r.name;
	parentName  = r.parentName;
	filePath    = r.filePath;
	dispalyID   = r.dispalyID;
	pageRoll    = r.pageRoll;
	isExist     = r.isExist;
	fileType    = r.fileType;

	if (r.playData)
	{
		playData = new QPlayData;
		*playData = *r.playData;
	}
	return *this;
}

QJsonObject QPlayInfo::ToJson()
{
	QJsonObject Obj;
	Obj.insert("displayName", displayName);
	Obj.insert("name", name);
	Obj.insert("parentName", parentName);
	Obj.insert("filePath", filePath);
	Obj.insert("dispalyID", dispalyID);
	Obj.insert("pageRoll", pageRoll);
	Obj.insert("isExist", isExist);
	Obj.insert("fileType", fileType);

	if (playData)
	{
		QJsonObject chidPage;
		playData->ToJson(chidPage);
		Obj.insert("page", chidPage);
	}

	return Obj;
}

QString QPlayInfo::ToString()
{
	QJsonDocument json_doc;
	json_doc.setObject(ToJson());
	return json_doc.toJson(QJsonDocument::Compact);
}
//*********************************************************
QPlayData::QPlayData()
{
}

QPlayData::QPlayData(const QPlayData &r)
{
	descInfo = r.descInfo;
	children = r.children;
}
QPlayData::~QPlayData()
{
	QMap<int, QVector<QPlayInfo*>>::iterator iter = children.begin();
	for (; iter != children.end(); iter++)
	{
		QVector<QPlayInfo*> inofs = iter.value();
		for (int i = 0; i < inofs.size(); i++)
		{
			if (NULL != inofs[i])
			{
				delete inofs[i];
				inofs[i] = NULL;
			}
		}
	}
};
QPlayData & QPlayData::operator = (const QPlayData &r)
{
	descInfo = r.descInfo;
	children = r.children;
	return *this;
};

void QPlayData::ToJson(QJsonObject &Obj)
{
	QJsonObject page;
	// 描述
	QJsonObject descs;
	QMap<int, QString>::iterator iterDesc = descInfo.begin();
	for (; iterDesc != descInfo.end(); iterDesc++)
	{
		descs.insert(QString::number(iterDesc.key()), iterDesc.value());
	}
	page.insert("desc", descs);
	// 孩子信息
	QJsonObject group;
	QMap<int, QVector<QPlayInfo*>>::iterator iterInfo = children.begin();
	for (; iterInfo != children.end(); iterInfo++)
	{
		QVector<QPlayInfo*> inofs = iterInfo.value();
		QJsonArray chidrenInfo;
		for (int i = 0; i < inofs.size(); i++)
		{
			if (NULL != inofs[i])
			{
				chidrenInfo.append(inofs[i]->ToJson());
			}
		}
		group.insert(QString::number(iterInfo.key()), chidrenInfo);
	}
	page.insert("child", group);
	Obj.insert("page", page);
}
QString QPlayData::ToString()
{
	QJsonObject Obj;
	ToJson(Obj);

	QJsonDocument json_doc;
	json_doc.setObject(Obj);
	return json_doc.toJson(QJsonDocument::Compact);
}
//*********************************************************
CPlayData::CPlayData() :m_bInitData(false)
{
}


CPlayData::~CPlayData()
{
}

//*********************************************************
// Method        : 读取系统配置，获取顶级路径
// Parameter[in] : 
// Parameter[out]: 
// Return        : 
// Created By MengYaohui on 2019/7/20 17:52:31
//*********************************************************
bool CPlayData::ReadSysData(const QString &strFilePath)
{
    if (!strFilePath.isEmpty() && m_strFilePath == strFilePath)
    {
        return true;
    }
    //获取程序当前运行目录
    if (m_strFilePath.isEmpty())
    {
        //m_strFilePath = QCoreApplication::applicationDirPath();
        m_strFilePath = QDir::currentPath();
    }
    // 根据ini文件路径新建QSettings类
    QSettings iniFile(SYS_CONFIG, QSettings::IniFormat);
    QString strValue = iniFile.value(SYS_CONFIG_DIRPATH_KEY).toString();
    if (strValue.isEmpty())
    {
        iniFile.beginGroup(SYS_CONFIG_SYSTEM);                    // 设置当前节名，代表以下的操作都是在这个节中
        iniFile.setValue(SYS_CONFIG_DIRPATH, m_strFilePath);      // 因为上面设置了节了，这里不在需要把节名写上去
        iniFile.endGroup();                                       // 结束当前节的操作
        iniFile.sync();
    }
    else
    {
        m_strFilePath = strValue;
    }
    return true;
}

//*********************************************************
// Method        : 读取规则配置
// Parameter[in] : 
// Parameter[out]: 
// Return        : 
// Created By MengYaohui on 2019/7/20 18:11:59
//*********************************************************
bool CPlayData::ReadRuleData()
{
    if (m_bInitData)
    {
        return true;
    }
    QFile loadFile(RLUE_CONFIG);

    if (!loadFile.open(QIODevice::ReadOnly))
    {
        qDebug() << "could't open projects json";
        return false;
    }

    QByteArray allData = loadFile.readAll();
    loadFile.close();

    QJsonParseError json_error;
    QJsonDocument jsonDoc(QJsonDocument::fromJson(allData, &json_error));

    if (json_error.error != QJsonParseError::NoError)
    {
        qDebug() << "json error!";
        return false;
    }

    QJsonObject rootObj = jsonDoc.object();
    //因为是预先定义好的JSON数据格式，所以这里可以这样读取
    if (!rootObj.contains("page"))
    {
        qDebug() << "json error!";
        return false;
    }
	QJsonObject page = rootObj.value("page").toObject();	// 首页数据
	// 设置描述
	QJsonObject desc = page.value("desc").toObject();		// 首页说明
	for (QJsonObject::Iterator iter = desc.begin(); iter != desc.end(); iter++)
	{
		m_PlayData.descInfo[iter.key().toInt()] = iter.value().toString();
	}

    QJsonArray modules = page.value("child").toArray();
    for (int i = 0; i < modules.count(); i++)
    {
        QJsonObject subObj = modules.at(i).toObject();
		QPlayInfo *subInfo = new QPlayInfo;
        GetJsonData(*subInfo, subObj, "");
        m_PlayData.children[subInfo->pageRoll].push_back(subInfo);
    }
    m_bInitData = true;
    return true;
}
//*********************************************************
// Method        :  获取JSON数据
// Parameter[in] : 
// Parameter[out]: 
// Return        : 
// Created By MengYaohui on 2019/7/20 18:37:09
//*********************************************************
void CPlayData::GetJsonData(QPlayInfo &playInfo, QJsonObject &jsonObj, QString strParentName)
{
    playInfo.name        = jsonObj.value("fileName").toString();
    playInfo.displayName = jsonObj.value("name").toString();
    playInfo.fileType    = "1" == jsonObj.value("isFolder").toString() ? QPlayInfo::folder : QPlayInfo::file;
    playInfo.parentName  = strParentName;
    playInfo.filePath    = m_strFilePath + strParentName + "/" + playInfo.name;

	// 设置滚动页
	QString strDisplay   = jsonObj.value("display").toString();
	QStringList listPlay = strDisplay.split('_');
	if (2 == listPlay.size())
	{
		playInfo.pageRoll  = listPlay.at(0).toInt();
		playInfo.dispalyID = listPlay.at(1).toInt();
	}
	else
	{
		playInfo.pageRoll  = 1;
		playInfo.dispalyID = jsonObj.value("display").toString().toInt();
	}
			
    // 文件是否存在
    if (QPlayInfo::folder == playInfo.fileType)
    {
        QFileInfo file(playInfo.filePath);
        playInfo.isExist = file.isDir() && file.exists();
    }
    else if (QPlayInfo::file == playInfo.fileType && !playInfo.parentName.isEmpty())
    {
        playInfo.isExist = false;
        QDir dir(m_strFilePath + playInfo.parentName);
        QStringList nameFilters;
        nameFilters.push_back(playInfo.name + ".mp4");  // 文件类型过滤
        nameFilters.push_back(playInfo.name + ".avi");  // 文件类型过滤
        QFileInfoList files = dir.entryInfoList(nameFilters, QDir::Files | QDir::Readable, QDir::Name);
        files = dir.entryInfoList();
        for (int i = 0; i < files.size(); i++)
        {
            QFileInfo fileInfo = files.at(i);
            playInfo.filePath = fileInfo.filePath();
            playInfo.isExist = true;
            break;
        }
    }
	// 如果包含子页面
	if (jsonObj.contains("page"))
	{
		// 子页设置
		QJsonObject page = jsonObj.value("page").toObject();	// 子页数据
		QPlayData *childPlayData = new QPlayData;
		playInfo.playData = childPlayData;
		// 设置描述
		QJsonObject desc = page.value("desc").toObject();		// 子页说明
		for (QJsonObject::Iterator iter = desc.begin(); iter != desc.end(); iter++)
		{
			childPlayData->descInfo[iter.key().toInt()] = iter.value().toString();
		}
		// 设置孩子
		QJsonArray children = page.value("child").toArray();
		for (int i = 0; i < children.count(); i++)
		{
			QJsonObject child = children.at(i).toObject();
			QPlayInfo *childInfo = new QPlayInfo;
			GetJsonData(*childInfo, child, strParentName + "/" + playInfo.name);
			childPlayData->children[childInfo->pageRoll].push_back(childInfo);
		}
	}
}

//*********************************************************
// Method        : 初始化数据
// Parameter[in] : 
// Parameter[out]: 
// Return        : 
// Created By MengYaohui on 2019/7/20 18:56:37
//*********************************************************
bool CPlayData::InitiaData(QString strPath)
{
    ReadSysData(strPath);
    return ReadRuleData();
}

