#ifndef QVIDEOLISTTREE_H
#define QVIDEOLISTTREE_H

#include <QWidget>
#include "ui_QvideoListTree.h"
#include "PlayData.h"
class QPlayer;
class QtreeDefModel;

class QvideoListTree : public QWidget
{
	Q_OBJECT

public:
	QvideoListTree(QWidget *parent = 0);
	~QvideoListTree();

public:
	//!设置播放数据
	void setPlayData(QPlayData* pPlayData);

private:
	Ui::QvideoListTree ui;

private slots:
	//！点击播放视频
	void SlotClkVideo(const QModelIndex &index);

private:
	//！播放器
	QPlayer* m_pPlayer;
	//！播放数据
	QPlayData* m_pPlayData;
	//！model
	QtreeDefModel* m_pPlayerModel;
};

#endif // QVIDEOLISTTREE_H
