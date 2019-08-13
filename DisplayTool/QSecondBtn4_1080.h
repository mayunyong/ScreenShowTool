#ifndef QSECONDBTN4_1080_H
#define QSECONDBTN4_1080_H

#include <QPushButton>
#include "ui_QSecondBtn4_1080.h"
#include "QSecondBaseBtn.h"

class QSecondBtn4_1080 : public QSecondBaseBtn
{
	Q_OBJECT

public:
	QSecondBtn4_1080(QWidget *parent = 0);
	~QSecondBtn4_1080();

private:
	Ui::QSecondBtn4_1080 ui;
};

#endif // QSECONDBTN4_1080_H
