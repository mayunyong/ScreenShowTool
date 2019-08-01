#ifndef QTREEDEFMODEL_H
#define QTREEDEFMODEL_H

#include <QObject>
#include "QAbstractItemModel"
#include "QVector"
#include "PlayData.h"


class QtreeDefModel : public QAbstractItemModel
{
	Q_OBJECT

public:
	QtreeDefModel(QObject *parent);
	~QtreeDefModel();

	// ���츸�ڵ����ӽڵ������
	virtual QModelIndex index(int row, int column, const QModelIndex &parent = QModelIndex()) const override;
	// ͨ���ӽڵ�������ȡ���ڵ�����
	virtual QModelIndex parent(const QModelIndex &child) const override;
	// ��ȡ���ڵ����ӽڵ������
	virtual int rowCount(const QModelIndex &parent = QModelIndex()) const override;
	// ��ȡ���ڵ����ӽڵ�����
	virtual int columnCount(const QModelIndex &parent = QModelIndex()) const override;
	// ��ȡ�ڵ����ݣ�����DisplayRole|TextAlignmentRole��
	virtual QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
	//!��ʶ
	virtual Qt::ItemFlags flags(const QModelIndex &index);

public:
	//�����ò�������
	void setPlayerData(QPlayData* pPlayData);

private:
	//����������
	QPlayData* m_pPlayData;
};

#endif // QTREEDEFMODEL_H
