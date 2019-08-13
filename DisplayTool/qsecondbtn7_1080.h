#ifndef QSECONDBTN7_1080_H
#define QSECONDBTN7_1080_H

#include <QPushButton>
#include "ui_qsecondbtn7_1080.h"
#include "QSecondBaseBtn.h"

class QSecondBtn7_1080 : public QSecondBaseBtn
{
	Q_OBJECT

public:
	QSecondBtn7_1080(QWidget *parent = 0);
	~QSecondBtn7_1080();

private:
	Ui::QSecondBtn7_1080 ui;
};

#endif // QSECONDBTN7_1080_H
