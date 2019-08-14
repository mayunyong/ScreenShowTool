#pragma once
#include <QString>
#include <QVector>
#include <QJsonObject>
#include <QMap>
#include "QMetaType"
//*********************************************************
// Class : QPlayData
// Brief : 数据模型
// Created By MengYaohui on 2019/7/20 17:48:36
//*********************************************************
struct QPlayData;
struct QPlayInfo
{
    QPlayInfo();
    QPlayInfo(const QPlayInfo &r);
    ~QPlayInfo();
    QPlayInfo & operator = (const QPlayInfo &r);
    QJsonObject ToJson();
    QString ToString();
    QString displayName;                                // 显示名称
    QString displayNum;                                 // 显示编号
    QString name;                                       // 实际名称
    QString parentName;                                 // 上一级相对目录
    QString filePath;                                   // 文件路径
    int     dispalyID;                                  // 要显示的控件ID
    int     pageRoll;                                   // 当一个子元素较多时需要滚动时的页面，默认为1
    bool    isExist;                                    // 是否存在
    enum _fileType { folder, file } fileType;           // 文件或者文件夹
    QPlayData *playData;                                // 孩子可以有子页面
	QPlayInfo* pParentInfo;

    bool HavePage() const { return NULL != playData; }        // 是否有子页面
};
Q_DECLARE_METATYPE(const QPlayInfo*);

struct QPlayData
{
    QPlayData();
    QPlayData(const QPlayData &r);
    ~QPlayData();
    QPlayData & operator = (const QPlayData &r);
    QString ToString();
    void ToJson(QJsonObject &Obj);
    QMap<int, QString> descInfo;                    // 描述信息，页面可配的文本，ID号+对应的内容
    QMap<int, QVector<QPlayInfo*>> children;        // 孩子,key是pageRoll
    // 是否有孩子
    bool HaveChild() { return 0 < children.size(); }
    // 需要几个滚动页面
    int GetRollPage() { return children.size(); }
};
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
    //bool SetFilePath(const QString &strPath);           // 设置文件绝对路径
	QString GetFilePath(){ return m_strFilePath; };                              // 获取文件绝对路径
    QPlayData * GetData() { return &m_PlayData; }
	//QPlayData * GetRootData() { return &m_PlayData; }
private:
    bool ReadSysData(const QString &strFilePath);       // 读取系统配置，获取顶级路径
    bool ReadRuleData();                                // 读取规则配置
    void GetJsonData(QPlayInfo &playInfo, QJsonObject &jsonObj, QString strParentName);        // 获取JSON数据
private:
    QString m_strFilePath;                      // 上一级绝对路径
    QPlayData m_PlayData;                       // 读取的数据
    bool m_bInitData;                           // 是否初始化
};

