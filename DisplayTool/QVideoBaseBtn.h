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

private slots: 
	void SlotClickBtn();

protected:
	virtual void ShowPlayData();

protected:
	int m_iBtnIndex;
	const QPlayInfo* m_pPlayData;
	QString m_strSrcPath;
	bool m_bAdjustSize;
	bool m_bNeedSetText;
};

#endif // QVIDEOBASEBTN_H
