#ifndef QSECONDBTN5_1080_H
#define QSECONDBTN5_1080_H

#include <QPushButton>
#include "QSecondBaseBtn.h"

#ifdef SCRENN_1280_800
#include "ui_QSecondBtn5_800.h"
#else
#include "ui_QSecondBtn5_1080.h"
#endif


class QSecondBtn5_1080 : public QSecondBaseBtn
{
	Q_OBJECT

public:
	QSecondBtn5_1080(QWidget *parent = 0);
	~QSecondBtn5_1080();

private:
#ifdef SCRENN_1280_800
	Ui::QSecondBtn5_800 ui;
#else
	Ui::QSecondBtn5_1080 ui;
#endif
};

#endif // QSECONDBTN5_1080_H
