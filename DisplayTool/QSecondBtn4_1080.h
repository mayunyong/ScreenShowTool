#ifndef QSECONDBTN4_1080_H
#define QSECONDBTN4_1080_H

#include <QPushButton>
#include "QSecondBaseBtn.h"

#ifdef SCRENN_1280_800
#include "ui_QSecondBtn4_800.h"
#else
#include "ui_QSecondBtn4_1080.h"
#endif
#include "QSecondBaseBtn.h"

class QSecondBtn4_1080 : public QSecondBaseBtn
{
	Q_OBJECT

public:
	QSecondBtn4_1080(QWidget *parent = 0);
	~QSecondBtn4_1080();

private:
#ifdef SCRENN_1280_800
	Ui::QSecondBtn4_800 ui;
#else
	Ui::QSecondBtn4_1080 ui;
#endif
};

#endif // QSECONDBTN4_1080_H
