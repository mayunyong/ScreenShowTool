#ifndef QHOMEBTNITEM_H
#define QHOMEBTNITEM_H

#include <QListWidgetItem>
#include "ui_qhomebtnitem.h"
#include "QListWidget"
#include "PlayData.h"
#include "UserDef.h"
#include "QPushButton"

class QHomeBtnItem : public QPushButton
{
	Q_OBJECT

public:
	QHomeBtnItem(QWidget *parent = 0, QSize btnSize = QSize(1920,1080));
	~QHomeBtnItem();

	void setPlayData(int iBtnIndex,  const QPlayData& ePlayDta);

	void setUIInfo(EN_PageType m_ePageType, int iNum);
signals:
	void SignalClkIndexBtn(int iBtnIndex);

private:
	Ui::QHomeBtnItem ui;
	int m_iBtnIndex;
	QPlayData m_playData;

private slots: 
	void SlotClickBtn();

	
};

#endif // QHOMEBTNITEM_H
