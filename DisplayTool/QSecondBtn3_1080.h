#ifndef QSECONDBTN3_1080_H
#define QSECONDBTN3_1080_H

#include <QPushButton>
#include "QSecondBaseBtn.h"

#ifdef SCRENN_1280_800
#include "ui_QSecondBtn3_800.h"
#else
#include "ui_QSecondBtn3_1080.h"
#endif


class QSecondBtn3_1080 : public QSecondBaseBtn
{
	Q_OBJECT

public:
	QSecondBtn3_1080(QWidget *parent = 0);
	~QSecondBtn3_1080();

private:
#ifdef SCRENN_1280_800
	Ui::QSecondBtn3_800 ui;
#else
	Ui::QSecondBtn3_1080 ui;
#endif
};

#endif // QSECONDBTN3_1080_H
