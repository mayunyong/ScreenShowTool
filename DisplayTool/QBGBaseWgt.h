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
	void InitUIInfo(const QRect& deskRect, const QPlayInfo* pPlayInfo);

protected:
	void resizeEvent(QResizeEvent * event);
	void paintEvent(QPaintEvent *event);
	void AddNewBtn(QVideoBaseBtn* pBtn, QPoint pPos);
	//!添加按钮
	void AddNewBtn(QPoint pPos);

	virtual void InitAllButton() = 0;
	void ShowPage(int iPage = 1);

signals:
	void SignalClkIndexBtn(const QPlayInfo* pStPlayDta);
	void SignalMin();
protected:
	//!空间大小
	QRect m_WgtRect;
	QSize m_Wgtsize;
	//!背景图
	QPixmap* m_pBackGroundixmap;
	QString m_strBGSrc;

	//!按钮map
	QMap<int, QVideoBaseBtn*> m_VideoBtnMap;
	//!背景label
	QLabel* m_pBGLabel;
	//!页面类型
	EN_PageType m_ePageType;
	//!页面数据
	const QPlayInfo* m_pPlayInfo;
	//!初始化标志
	bool m_bInifFlag;
	int m_iCurPage;
	int m_iAllPageSize;
};

#endif // QBGBASELABEL_H
