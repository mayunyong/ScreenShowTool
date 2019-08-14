#ifndef QSECONDBTN2_1080_H
#define QSECONDBTN2_1080_H

#include <QPushButton>
#include "QSecondBaseBtn.h"

#ifdef SCRENN_1280_800
#include "ui_QSecondBtn2_800.h"
#else
#include "ui_QSecondBtn2_1080.h"
#endif


class QSecondBtn2_1080 : public QSecondBaseBtn
{
	Q_OBJECT

public:
	QSecondBtn2_1080(QWidget *parent = 0);
	~QSecondBtn2_1080();

private:
#ifdef SCRENN_1280_800
	Ui::QSecondBtn2_800 ui;
#else
	Ui::QSecondBtn2_1080 ui;
#endif
};

#endif // QSECONDBTN2_1080_H
