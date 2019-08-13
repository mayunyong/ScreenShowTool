#ifndef QBGBASELABEL_H
#define QBGBASELABEL_H

#include <QLabel>
#include "qhomebtnitem.h"
#include "QWidget"
#include "UserDef.h"
#include "PlayData.h"

class QResizeEvent;
class QPixmap;

class QBGBaseWgt : public QWidget
{
	Q_OBJECT

public:
	QBGBaseWgt(QWidget *parent = 0);
	~QBGBaseWgt();

public:
	void InitUIInfo(const QRect& deskRect, QPlayData* pPlayData);

protected:
	void resizeEvent(QResizeEvent * event);
	void paintEvent(QPaintEvent *event);
	//!添加按钮
	void AddNewBtn(QPoint pPos);

	virtual void InitAllButton() = 0;

signals:
	void SignalClkIndexBtn(const QPlayInfo* pStPlayDta);

protected:
	//!空间大小
	QRect m_WgtRect;
	QSize m_Wgtsize;
	//!背景图
	QPixmap* m_pBackGroundixmap;
	QString m_strBGSrc;

	//!按钮map
	QMap<int, QHomeBtnItem*> m_VideoBtnMap;
	//!背景label
	QLabel* m_pBGLabel;
	//!页面类型
	EN_PageType m_ePageType;
	//!页面数据
	QPlayData* m_pPlayData;
	//!初始化标志
	bool m_bInifFlag;
};

#endif // QBGBASELABEL_H
