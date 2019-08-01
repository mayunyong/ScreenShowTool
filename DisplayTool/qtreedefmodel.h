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

	// 构造父节点下子节点的索引
	virtual QModelIndex index(int row, int column, const QModelIndex &parent = QModelIndex()) const override;
	// 通过子节点索引获取父节点索引
	virtual QModelIndex parent(const QModelIndex &child) const override;
	// 获取父节点下子节点的行数
	virtual int rowCount(const QModelIndex &parent = QModelIndex()) const override;
	// 获取父节点下子节点列数
	virtual int columnCount(const QModelIndex &parent = QModelIndex()) const override;
	// 获取节点数据：包括DisplayRole|TextAlignmentRole等
	virtual QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
	//!标识
	virtual Qt::ItemFlags flags(const QModelIndex &index);

public:
	//！设置播放数据
	void setPlayerData(QPlayData* pPlayData);

private:
	//！播放数据
	QPlayData* m_pPlayData;
};

#endif // QTREEDEFMODEL_H
