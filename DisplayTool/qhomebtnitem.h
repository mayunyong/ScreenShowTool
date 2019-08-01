#ifndef QHOMEBTNITEM_H
#define QHOMEBTNITEM_H

#include <QListWidgetItem>
#include "ui_qhomebtnitem.h"
#include "QListWidget"
#include "PlayData.h"

class QHomeBtnItem : public QWidget
{
	Q_OBJECT

public:
	QHomeBtnItem(QWidget *parent = 0, int iWidth = 200, int iHieght = 200);
	~QHomeBtnItem();

	void setPlayData(int iBtnIndex,  const QPlayData& ePlayDta);

signals:
	void SignalClkIndexBtn(int iBtnIndex);

private:
	Ui::QHomeBtnItem ui;
	int m_iBtnIndex;

private slots: 
	void SlotClickBtn();
};

#endif // QHOMEBTNITEM_H
