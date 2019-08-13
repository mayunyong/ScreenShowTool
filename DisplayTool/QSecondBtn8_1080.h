#ifndef QSECONDBTN8_1080_H
#define QSECONDBTN8_1080_H

#include <QPushButton>
#include "ui_QSecondBtn8_1080.h"
#include "QSecondBaseBtn.h"

class QSecondBtn8_1080 : public QSecondBaseBtn
{
	Q_OBJECT

public:
	QSecondBtn8_1080(QWidget *parent = 0);
	~QSecondBtn8_1080();

private:
	Ui::QSecondBtn8_1080 ui;
};

#endif // QSECONDBTN8_1080_H
