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
	//!��ʼ������
	void InitUIByData(QPlayData* m_pPlayData);

public:
	//!��ʼ������
	void InitPlayerData(QPlayData* pPlayData);
	//!���ò㼶
	void SetLevel(int iIndex){m_iLevel = iIndex; }

private slots:
	void SlotClkBtnIndex(int iBtnIndex);

signals:
	void SignShowPlayData(QPlayData* playData, int iLevel);

private:
	//!������Ϣ
	QPlayData* m_pPlayData;
	//������
	QGridLayout *m_gridHomeBtnLay;
	//!�㼶
	int m_iLevel;
	//!�����С
	QRect m_DeskTopRect;
};

#endif // QBTNLISTWDGT_H
