#ifndef QBGBASELABEL_H
#define QBGBASELABEL_H

#include <QLabel>
#include "qhomebtnitem.h"
#include "QWidget"
#include "UserDef.h"

class QResizeEvent;
class QPixmap;

class QBGBaseWgt : public QWidget
{
	Q_OBJECT

public:
	QBGBaseWgt(QWidget *parent = 0);
	~QBGBaseWgt();

public:
	void InitUIInfo(const QRect& deskRect);

protected:
	void resizeEvent(QResizeEvent * event);
	void paintEvent(QPaintEvent *event);
	//!添加按钮
	void AddNewBtn(QPoint pPos);

	virtual void InitHomeButton() = 0;

protected:
	QRect m_WgtRect;
	QSize m_Wgtsize;
	QPixmap* m_pBackGroundixmap;
	QMap<int, QHomeBtnItem*> m_VideoBtnMap;
	//!背景label
	QLabel* m_pBGLabel;
	//!页面类型
	EN_PageType m_ePageType;
	
};

#endif // QBGBASELABEL_H
