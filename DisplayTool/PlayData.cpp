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
    QString strValue = iniFile.value(SYS_CONFIG_SYSTEM"/"SYS_CONFIG_DIRPATH).toString();
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

    QStringList keys = rootObj.keys();
    for (int i = 0; i < keys.size(); i++)
    {
        qDebug() << "key" << i << " is:" << keys.at(i);
    }

    //��Ϊ��Ԥ�ȶ���õ�JSON���ݸ�ʽ�������������������ȡ
    if (!rootObj.contains("module"))
    {
        qDebug() << "json error!";
        return false;
    }
    QJsonArray modules = rootObj.value("module").toArray();
    for (int i = 0; i < modules.count(); i++)
    {
        QJsonObject subObj = modules.at(i).toObject();
        QPlayData subData;
        GetJsonData(subData, subObj, "");
        m_PlayData.children.push_back(subData);
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
void CPlayData::GetJsonData(QPlayData &playData, QJsonObject &jsonObj, QString strParentName)
{
    playData.name        = jsonObj.value("fileName").toString();
    playData.displayName = jsonObj.value("name").toString();
    playData.fileType = "1" == jsonObj.value("isFolder").toString() ? QPlayData::folder : QPlayData::file;
    playData.parentName  = strParentName;
    playData.filePath    = m_strFilePath + strParentName + "/" + playData.name;

    //
    if (QPlayData::folder == playData.fileType)
    {
        QFileInfo file(playData.filePath);
        playData.isExist = file.isDir() && file.exists();
    }
    else if (QPlayData::file == playData.fileType && !playData.parentName.isEmpty())
    {
        playData.isExist = false;
        QDir dir(m_strFilePath + playData.parentName);
        QStringList nameFilters;
        nameFilters.push_back(playData.name + ".mp4");  // �ļ����͹���
        nameFilters.push_back(playData.name + ".avi");  // �ļ����͹���
        QFileInfoList files = dir.entryInfoList(nameFilters, QDir::Files | QDir::Readable|QDir::NoDotAndDotDot, QDir::Name);
      //  files = dir.entryInfoList();
        for (int i = 0; i < files.size(); i++)
        {
            QFileInfo fileInfo = files.at(i);
            playData.filePath = fileInfo.filePath();
            playData.isExist = true;
            break;
        }
    }

    QJsonArray children  = jsonObj.value("child").toArray();
    for (int i = 0; i < children.count(); i++)
    {
        QJsonObject child = children.at(i).toObject();
        QPlayData childData;
        GetJsonData(childData, child, strParentName + "/" + playData.name);
        playData.children.push_back(childData);
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

