#ifndef QVIDEOBASEBTN_H
#define QVIDEOBASEBTN_H

#include <QPushButton>
#include "QSize"
#include "PlayData.h"
#include "UserDef.h"

class QVideoBaseBtn : public QPushButton
{
	Q_OBJECT

public:
	QVideoBaseBtn(QWidget *parent);
	~QVideoBaseBtn();

public:
	virtual void setPlayData(int iBtnIndex,  const QPlayInfo* pStPlayDta);
	void setUIInfo(EN_PageType m_ePageType, int iNum, bool bVideoFlag = false);

signals:
	void SignalClkIndexBtn(const QPlayInfo* pStPlayDta);

protected:
	int m_iBtnIndex;
	const QPlayInfo* m_pPlayData;
	QString m_strSrcPath;

private slots: 
	void SlotClickBtn();
};

#endif // QVIDEOBASEBTN_H
