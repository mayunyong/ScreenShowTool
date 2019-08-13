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
	// ����
	QJsonObject descs;
	QMap<int, QString>::iterator iterDesc = descInfo.begin();
	for (; iterDesc != descInfo.end(); iterDesc++)
	{
		descs.insert(QString::number(iterDesc.key()), iterDesc.value());
	}
	page.insert("desc", descs);
	// ������Ϣ
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
// Method        : ��ȡϵͳ���ã���ȡ����·��
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
    //��ȡ����ǰ����Ŀ¼
    if (m_strFilePath.isEmpty())
    {
        //m_strFilePath = QCoreApplication::applicationDirPath();
        m_strFilePath = QDir::currentPath();
    }
    // ����ini�ļ�·���½�QSettings��
    QSettings iniFile(SYS_CONFIG, QSettings::IniFormat);
    QString strValue = iniFile.value(SYS_CONFIG_DIRPATH_KEY).toString();
    if (strValue.isEmpty())
    {
        iniFile.beginGroup(SYS_CONFIG_SYSTEM);                    // ���õ�ǰ�������������µĲ����������������
        iniFile.setValue(SYS_CONFIG_DIRPATH, m_strFilePath);      // ��Ϊ���������˽��ˣ����ﲻ����Ҫ�ѽ���д��ȥ
        iniFile.endGroup();                                       // ������ǰ�ڵĲ���
        iniFile.sync();
    }
    else
    {
        m_strFilePath = strValue;
    }
    return true;
}

//*********************************************************
// Method        : ��ȡ��������
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
    //��Ϊ��Ԥ�ȶ���õ�JSON���ݸ�ʽ�������������������ȡ
    if (!rootObj.contains("page"))
    {
        qDebug() << "json error!";
        return false;
    }
	QJsonObject page = rootObj.value("page").toObject();	// ��ҳ����
	// ��������
	QJsonObject desc = page.value("desc").toObject();		// ��ҳ˵��
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
// Method        :  ��ȡJSON����
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

	// ���ù���ҳ
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
			
    // �ļ��Ƿ����
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
        nameFilters.push_back(playInfo.name + ".mp4");  // �ļ����͹���
        nameFilters.push_back(playInfo.name + ".avi");  // �ļ����͹���
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
	// ���������ҳ��
	if (jsonObj.contains("page"))
	{
		// ��ҳ����
		QJsonObject page = jsonObj.value("page").toObject();	// ��ҳ����
		QPlayData *childPlayData = new QPlayData;
		playInfo.playData = childPlayData;
		// ��������
		QJsonObject desc = page.value("desc").toObject();		// ��ҳ˵��
		for (QJsonObject::Iterator iter = desc.begin(); iter != desc.end(); iter++)
		{
			childPlayData->descInfo[iter.key().toInt()] = iter.value().toString();
		}
		// ���ú���
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
// Method        : ��ʼ������
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

