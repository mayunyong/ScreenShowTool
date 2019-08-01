#ifndef QBTNLISTWDGT_H
#define QBTNLISTWDGT_H

#include <QWidget>
#include "ui_QBtnListWdgt.h"
#include "PlayData.h"
class QGridLayout;

class QBtnListWdgt : public QWidget
{
	Q_OBJECT

public:
	QBtnListWdgt(QWidget *parent = 0);
	~QBtnListWdgt();
	
private:
	Ui::QBtnListWdgt ui;
	//!初始化界面
	void InitUIByData(QPlayData* m_pPlayData);

public:
	//!初始化数据
	void InitPlayerData(QPlayData* pPlayData);
	//!设置层级
	void SetLevel(int iIndex){m_iLevel = iIndex; }

private slots:
	void SlotClkBtnIndex(int iBtnIndex);

signals:
	void SignShowPlayData(QPlayData* playData, int iLevel);

private:
	//!播放信息
	QPlayData* m_pPlayData;
	//！布局
	QGridLayout *m_gridHomeBtnLay;
	//!层级
	int m_iLevel;
	//!桌面大小
	QRect m_DeskTopRect;
};

#endif // QBTNLISTWDGT_H
