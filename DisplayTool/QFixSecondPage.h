#ifndef QFIXSECONDPAGE_H
#define QFIXSECONDPAGE_H

#include "QBGBaseWgt.h"
#include "ui_QFixSecondPage.h"

class QFixSecondPage : public QBGBaseWgt
{
	Q_OBJECT

public:
	QFixSecondPage(QWidget *parent = 0);
	~QFixSecondPage();

private:
	void InitAllButton();


	private slots:
	void SlotClkBack();
		void SlotClkNext();

private:
	Ui::QFixSecondPage ui;
	
};

#endif // QFIXSECONDPAGE_H
