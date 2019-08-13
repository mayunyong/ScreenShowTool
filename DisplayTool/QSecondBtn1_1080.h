#ifndef QSECONDBTN1_1080_H
#define QSECONDBTN1_1080_H

#include <QPushButton>
#include "ui_QSecondBtn1_1080.h"
#include "QSecondBaseBtn.h"

class QSecondBtn1_1080 : public QSecondBaseBtn
{
	Q_OBJECT

public:
	QSecondBtn1_1080(QWidget *parent = 0);
	~QSecondBtn1_1080();

private:
	Ui::QSecondBtn1_1080 ui;
};

#endif // QSECONDBTN1_1080_H
