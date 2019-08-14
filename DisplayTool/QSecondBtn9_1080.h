#ifndef QSECONDBTN9_1080_H
#define QSECONDBTN9_1080_H

#include "QSecondBaseBtn.h"
#include <QPushButton>
#ifdef SCRENN_1280_800
#include "ui_QSecondBtn9_800.h"
#else
#include "ui_QSecondBtn9_1080.h"
#endif


class QSecondBtn9_1080 : public QSecondBaseBtn
{
	Q_OBJECT

public:
	QSecondBtn9_1080(QWidget *parent = 0);
	~QSecondBtn9_1080();

private:
#ifdef SCRENN_1280_800
	Ui::QSecondBtn9_800 ui;
#else
	Ui::QSecondBtn9_1080 ui;
#endif
};

#endif // QSECONDBTN9_1080_H
