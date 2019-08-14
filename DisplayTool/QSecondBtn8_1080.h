#ifndef QSECONDBTN8_1080_H
#define QSECONDBTN8_1080_H

#include <QPushButton>
#include "QSecondBaseBtn.h"

#ifdef SCRENN_1280_800
#include "ui_QSecondBtn8_800.h"
#else
#include "ui_QSecondBtn8_1080.h"
#endif



class QSecondBtn8_1080 : public QSecondBaseBtn
{
	Q_OBJECT

public:
	QSecondBtn8_1080(QWidget *parent = 0);
	~QSecondBtn8_1080();

private:
#ifdef SCRENN_1280_800
	Ui::QSecondBtn8_800 ui;
#else
	Ui::QSecondBtn8_1080 ui;
#endif
};

#endif // QSECONDBTN8_1080_H
