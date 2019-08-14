#ifndef QSECONDBTN7_1080_H
#define QSECONDBTN7_1080_H

#include <QPushButton>
#include "QSecondBaseBtn.h"

#ifdef SCRENN_1280_800
#include "ui_QSecondBtn7_800.h"
#else
#include "ui_QSecondBtn7_1080.h"
#endif


class QSecondBtn7_1080 : public QSecondBaseBtn
{
	Q_OBJECT

public:
	QSecondBtn7_1080(QWidget *parent = 0);
	~QSecondBtn7_1080();

private:
#ifdef SCRENN_1280_800
	Ui::QSecondBtn7_800 ui;
#else
	Ui::QSecondBtn7_1080 ui;
#endif
};

#endif // QSECONDBTN7_1080_H
