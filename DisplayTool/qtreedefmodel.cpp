#include "qtreedefmodel.h"
#include "QString"
#include "PlayData.h"
#include "QStyle"
#include "QWidget"

QtreeDefModel::QtreeDefModel(QObject *parent)
	: QAbstractItemModel(parent)
	,m_pPlayData(NULL)
{

}

QtreeDefModel::~QtreeDefModel()
{

}

//！重载index
QModelIndex QtreeDefModel::index(int row, int column, const QModelIndex &parent /*= QModelIndex()*/) const 
{
	//！一级节点
	if( parent.column() == -1 && parent.row() == -1 
		&& m_pPlayData
		&& row < m_pPlayData->children.size())
	{
		return createIndex(row, column, &m_pPlayData->children[row]);
	}
	else 
	{
		QPlayData* pPlayData = (QPlayData*)parent.internalPointer();
		if(pPlayData && row < pPlayData->children.size())
		{
			QModelIndex index = createIndex(row, column, &pPlayData->children[row]);
			pPlayData->children[row].m_PParentIndex = parent;
			return  index;
		}
	}

	return createIndex(row, column);
}

//!重载parent
QModelIndex QtreeDefModel::parent(const QModelIndex &child) const 
{

	if(child.isValid())
	{
		QPlayData* pPlayerData = (QPlayData*)child.internalPointer();
		if(pPlayerData && pPlayerData->m_PParentIndex.isValid())
		{
			return pPlayerData->m_PParentIndex;
		}
	}

	return QModelIndex();
}

//!重载rowCount
int QtreeDefModel::rowCount(const QModelIndex &parent /*= QModelIndex()*/) const 
{
	if(!parent.isValid() && m_pPlayData)
	{
		return m_pPlayData->children.size();
	}
	else 
	{
		QPlayData* pPlayData = (QPlayData*)parent.internalPointer();
		if(pPlayData)
		{
			return pPlayData->children.size();
		}
	}

	return 0;
}

//!列数
int QtreeDefModel::columnCount(const QModelIndex &parent /*= QModelIndex()*/) const 
{
	return 1;
}

//！数据
QVariant QtreeDefModel::data(const QModelIndex &index, int role /*= Qt::DisplayRole*/) const 
{
	if(index.isValid())
	{
		QPlayData* pPlayData = (QPlayData*)index.internalPointer();

		if(role == Qt::DisplayRole && index.column() == 0 && pPlayData) 
		{
			return pPlayData->displayName;
		}
		else if(role == Qt::DecorationRole && index.column() == 0)
		{
			QWidget wdgt;
			if(rowCount(index) > 0)
			{
				return wdgt.style()->standardIcon(QStyle::SP_DirHomeIcon);
			}
			else
			{
				return wdgt.style()->standardIcon(QStyle::SP_FileIcon);
			}
		}
	}

	return QVariant();
}

//!标志
Qt::ItemFlags QtreeDefModel::flags(const QModelIndex &index)
{
	return Qt::ItemIsEditable|Qt::ItemIsEnabled|Qt::ItemIsSelectable;
}

//！设置播放数据
void QtreeDefModel::setPlayerData(QPlayData* pPlayData)
{
	m_pPlayData = pPlayData;
}
