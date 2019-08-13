#ifndef QHOMEBTNITEM_H
#define QHOMEBTNITEM_H

#include <QListWidgetItem>
#include "ui_qhomebtnitem.h"
#include "QListWidget"
#include "PlayData.h"
#include "UserDef.h"
#include "QPushButton"
#include "QVideoBaseBtn.h"

class QHomeBtnItem : public QVideoBaseBtn
{
	Q_OBJECT

public:
	QHomeBtnItem(QWidget *parent = 0, QSize btnSize = QSize(1920,1080));
	~QHomeBtnItem();

	void setPlayData(int iBtnIndex,  const QPlayInfo* pStPlayDta);

	void setUIInfo(EN_PageType m_ePageType, int iNum, bool bVideoFlag = false);

signals:
	void SignalClkIndexBtn(const QPlayInfo* pStPlayDta);

private:
	Ui::QHomeBtnItem ui;
	int m_iBtnIndex;
	const QPlayInfo* m_pPlayData;

private slots: 
	void SlotClickBtn();

	
};

#endif // QHOMEBTNITEM_H
