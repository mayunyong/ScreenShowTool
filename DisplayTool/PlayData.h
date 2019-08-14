#pragma once
#include <QString>
#include <QVector>
#include <QJsonObject>
#include <QMap>
#include "QMetaType"
//*********************************************************
// Class : QPlayData
// Brief : ����ģ��
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
    QString displayName;                                // ��ʾ����
    QString displayNum;                                 // ��ʾ���
    QString name;                                       // ʵ������
    QString parentName;                                 // ��һ�����Ŀ¼
    QString filePath;                                   // �ļ�·��
    int     dispalyID;                                  // Ҫ��ʾ�Ŀؼ�ID
    int     pageRoll;                                   // ��һ����Ԫ�ؽ϶�ʱ��Ҫ����ʱ��ҳ�棬Ĭ��Ϊ1
    bool    isExist;                                    // �Ƿ����
    enum _fileType { folder, file } fileType;           // �ļ������ļ���
    QPlayData *playData;                                // ���ӿ�������ҳ��
	QPlayInfo* pParentInfo;

    bool HavePage() const { return NULL != playData; }        // �Ƿ�����ҳ��
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
    QMap<int, QString> descInfo;                    // ������Ϣ��ҳ�������ı���ID��+��Ӧ������
    QMap<int, QVector<QPlayInfo*>> children;        // ����,key��pageRoll
    // �Ƿ��к���
    bool HaveChild() { return 0 < children.size(); }
    // ��Ҫ��������ҳ��
    int GetRollPage() { return children.size(); }
};
//*********************************************************
// Class : CPlayData
// Brief : ����������
// Created By MengYaohui on 2019/7/20 17:49:01
//*********************************************************
class CPlayData
{
public:
    CPlayData();
    ~CPlayData();
public:
    bool InitiaData(QString strPath = "");              // ��ʼ������
    //bool SetFilePath(const QString &strPath);           // �����ļ�����·��
	QString GetFilePath(){ return m_strFilePath; };                              // ��ȡ�ļ�����·��
    QPlayData * GetData() { return &m_PlayData; }
	//QPlayData * GetRootData() { return &m_PlayData; }
private:
    bool ReadSysData(const QString &strFilePath);       // ��ȡϵͳ���ã���ȡ����·��
    bool ReadRuleData();                                // ��ȡ��������
    void GetJsonData(QPlayInfo &playInfo, QJsonObject &jsonObj, QString strParentName);        // ��ȡJSON����
private:
    QString m_strFilePath;                      // ��һ������·��
    QPlayData m_PlayData;                       // ��ȡ������
    bool m_bInitData;                           // �Ƿ��ʼ��
};

