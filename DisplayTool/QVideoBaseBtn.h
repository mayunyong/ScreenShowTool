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
	//!设置视频数据
	virtual void setPlayData(int iBtnIndex,  const QPlayInfo* pStPlayDta);
	//!设置界面信息
	//void setUIInfo(EN_PageType m_ePageType, int iNum, bool bVideoFlag = false);

signals:
	void SignalClkIndexBtn(const QPlayInfo* pStPlayDta);

private slots: 
	void SlotClickBtn();

protected:
	//!显示数据
	virtual void ShowPlayData();

protected:
	int m_iBtnIndex;
	const QPlayInfo* m_pPlayData;
	QString m_strSrcPath;
	bool m_bAdjustSize;
	bool m_bNeedSetText;
};

#endif // QVIDEOBASEBTN_H
