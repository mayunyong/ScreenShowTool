#ifndef QSECONDBTN6_1080_H
#define QSECONDBTN6_1080_H

#include <QPushButton>
#include "ui_QSecondBtn6_1080.h"
#include "QSecondBaseBtn.h"

class QSecondBtn6_1080 : public QSecondBaseBtn
{
	Q_OBJECT

public:
	QSecondBtn6_1080(QWidget *parent = 0);
	~QSecondBtn6_1080();

private:
	Ui::QSecondBtn6_1080 ui;
};

#endif // QSECONDBTN6_1080_H
