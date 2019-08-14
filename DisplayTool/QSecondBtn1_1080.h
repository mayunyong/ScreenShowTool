#ifndef QSECONDBTN1_1080_H
#define QSECONDBTN1_1080_H

#include <QPushButton>
#include "QSecondBaseBtn.h"

#ifdef SCRENN_1280_800
#include "ui_QSecondBtn1_800.h"
#else
#include "ui_QSecondBtn1_1080.h"
#endif


class QSecondBtn1_1080 : public QSecondBaseBtn
{
	Q_OBJECT

public:
	QSecondBtn1_1080(QWidget *parent = 0);
	~QSecondBtn1_1080();

private:

#ifdef SCRENN_1280_800
	Ui::QSecondBtn1_800 ui;
#else
	Ui::QSecondBtn1_1080 ui;
#endif
};

#endif // QSECONDBTN1_1080_H
