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
	//!��Ӱ�ť
	void AddNewBtn(QPoint pPos);

	virtual void InitAllButton() = 0;

signals:
	void SignalClkIndexBtn(const QPlayInfo* pStPlayDta);

protected:
	//!�ռ��С
	QRect m_WgtRect;
	QSize m_Wgtsize;
	//!����ͼ
	QPixmap* m_pBackGroundixmap;
	QString m_strBGSrc;

	//!��ťmap
	QMap<int, QHomeBtnItem*> m_VideoBtnMap;
	//!����label
	QLabel* m_pBGLabel;
	//!ҳ������
	EN_PageType m_ePageType;
	//!ҳ������
	QPlayData* m_pPlayData;
	//!��ʼ����־
	bool m_bInifFlag;
};

#endif // QBGBASELABEL_H
