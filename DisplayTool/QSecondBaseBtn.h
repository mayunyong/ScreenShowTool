#ifndef QSECONDBASEBTN_H
#define QSECONDBASEBTN_H

#include "QVideoBaseBtn.h"
#include "QLabel"

class QSecondBaseBtn : public QVideoBaseBtn
{
	Q_OBJECT

public:
	QSecondBaseBtn(QWidget *parent);
	~QSecondBaseBtn();

protected:
	//!显示视频信息
	void ShowPlayData();

protected:
	QLabel* m_pNOLabel;
	QLabel* m_pNameLabel;
};

#endif // QSECONDBASEBTN_H
