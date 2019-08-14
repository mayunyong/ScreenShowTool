#ifndef QSECONDBTN6_1080_H
#define QSECONDBTN6_1080_H

#include <QPushButton>
#include "QSecondBaseBtn.h"

#ifdef SCRENN_1280_800
#include "ui_QSecondBtn6_800.h"
#else
#include "ui_QSecondBtn6_1080.h"
#endif


class QSecondBtn6_1080 : public QSecondBaseBtn
{
	Q_OBJECT

public:
	QSecondBtn6_1080(QWidget *parent = 0);
	~QSecondBtn6_1080();

private:
#ifdef SCRENN_1280_800
	Ui::QSecondBtn6_800 ui;
#else
	Ui::QSecondBtn6_1080 ui;
#endif
};

#endif // QSECONDBTN6_1080_H
