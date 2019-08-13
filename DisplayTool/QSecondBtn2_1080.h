#ifndef QSECONDBTN2_1080_H
#define QSECONDBTN2_1080_H

#include <QPushButton>
#include "ui_QSecondBtn2_1080.h"
#include "QSecondBaseBtn.h"

class QSecondBtn2_1080 : public QSecondBaseBtn
{
	Q_OBJECT

public:
	QSecondBtn2_1080(QWidget *parent = 0);
	~QSecondBtn2_1080();

private:
	Ui::QSecondBtn2_1080 ui;
};

#endif // QSECONDBTN2_1080_H
