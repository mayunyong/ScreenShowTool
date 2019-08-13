#ifndef QSECONDBTN3_1080_H
#define QSECONDBTN3_1080_H

#include <QPushButton>
#include "ui_QSecondBtn3_1080.h"
#include "QSecondBaseBtn.h"

class QSecondBtn3_1080 : public QSecondBaseBtn
{
	Q_OBJECT

public:
	QSecondBtn3_1080(QWidget *parent = 0);
	~QSecondBtn3_1080();

private:
	Ui::QSecondBtn3_1080 ui;
};

#endif // QSECONDBTN3_1080_H
