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
	//!��Ӱ�ť
	void AddNewBtn(QPoint pPos);

	virtual void InitAllButton() = 0;
	void ShowPage(int iPage = 1);

signals:
	void SignalClkIndexBtn(const QPlayInfo* pStPlayDta);
	void SignalMin();
protected:
	//!�ռ��С
	QRect m_WgtRect;
	QSize m_Wgtsize;
	//!����ͼ
	QPixmap* m_pBackGroundixmap;
	QString m_strBGSrc;

	//!��ťmap
	QMap<int, QVideoBaseBtn*> m_VideoBtnMap;
	//!����label
	QLabel* m_pBGLabel;
	//!ҳ������
	EN_PageType m_ePageType;
	//!ҳ������
	const QPlayInfo* m_pPlayInfo;
	//!��ʼ����־
	bool m_bInifFlag;
	int m_iCurPage;
	int m_iAllPageSize;
};

#endif // QBGBASELABEL_H
