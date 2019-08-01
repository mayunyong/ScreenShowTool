#pragma once
#include <QString>
#include <QVector>
#include <QJsonObject>
#include "QAbstractItemModel"
//*********************************************************
// Class : QPlayData
// Brief : 数据模型
// Created By MengYaohui on 2019/7/20 17:48:36
//*********************************************************
typedef struct _QPlayData
{
    QString displayName;                                // 显示名称
    QString name;                                       // 实际名称
    QString parentName;                                 // 上一级相对目录
    QString filePath;                                   // 文件路径
    bool isExist;                                       // 是否存在
	QModelIndex m_PParentIndex;
    enum _fileType{ folder, file } fileType;            // 文件或者文件夹
    QVector<_QPlayData> children;                       // 孩子
    bool HaveChild(){ return 0 < children.size(); }
} QPlayData;


Q_DECLARE_METATYPE(QPlayData*);
//*********************************************************
// Class : CPlayData
// Brief : 播放数据类
// Created By MengYaohui on 2019/7/20 17:49:01
//*********************************************************
class CPlayData
{
public:
    CPlayData();
    ~CPlayData();
public:
    bool InitiaData(QString strPath = "");              // 初始化数据
    bool SetFilePath(const QString &strPath);           // 设置文件绝对路径
    QString GetFilePath();                              // 获取文件绝对路径
     QPlayData * GetData()  { return &m_PlayData; }

private:
    bool ReadSysData(const QString &strFilePath);       // 读取系统配置，获取顶级路径
    bool ReadRuleData();                                // 读取规则配置
    void GetJsonData(QPlayData &playData, QJsonObject &jsonObj, QString strParentName);        // 获取JSON数据

private:
    QString m_strFilePath;                      // 上一级绝对路径
    QPlayData m_PlayData;                       // 读取的数据
    bool m_bInitData;                           // 是否初始化
};

