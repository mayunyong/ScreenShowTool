#pragma once
#include <QString>
#include <QVector>
#include <QJsonObject>
#include "QAbstractItemModel"
//*********************************************************
// Class : QPlayData
// Brief : ����ģ��
// Created By MengYaohui on 2019/7/20 17:48:36
//*********************************************************
typedef struct _QPlayData
{
    QString displayName;                                // ��ʾ����
    QString name;                                       // ʵ������
    QString parentName;                                 // ��һ�����Ŀ¼
    QString filePath;                                   // �ļ�·��
    bool isExist;                                       // �Ƿ����
	QModelIndex m_PParentIndex;
    enum _fileType{ folder, file } fileType;            // �ļ������ļ���
    QVector<_QPlayData> children;                       // ����
    bool HaveChild(){ return 0 < children.size(); }
} QPlayData;


Q_DECLARE_METATYPE(QPlayData*);
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
    bool SetFilePath(const QString &strPath);           // �����ļ�����·��
    QString GetFilePath();                              // ��ȡ�ļ�����·��
     QPlayData * GetData()  { return &m_PlayData; }

private:
    bool ReadSysData(const QString &strFilePath);       // ��ȡϵͳ���ã���ȡ����·��
    bool ReadRuleData();                                // ��ȡ��������
    void GetJsonData(QPlayData &playData, QJsonObject &jsonObj, QString strParentName);        // ��ȡJSON����

private:
    QString m_strFilePath;                      // ��һ������·��
    QPlayData m_PlayData;                       // ��ȡ������
    bool m_bInitData;                           // �Ƿ��ʼ��
};

