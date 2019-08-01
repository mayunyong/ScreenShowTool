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
	//!���ò�������
	void setPlayData(QPlayData* pPlayData);

private:
	Ui::QvideoListTree ui;

private slots:
	//�����������Ƶ
	void SlotClkVideo(const QModelIndex &index);

private:
	//��������
	QPlayer* m_pPlayer;
	//����������
	QPlayData* m_pPlayData;
	//��model
	QtreeDefModel* m_pPlayerModel;
};

#endif // QVIDEOLISTTREE_H
