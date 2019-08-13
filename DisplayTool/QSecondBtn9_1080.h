#ifndef QSECONDBTN9_1080_H
#define QSECONDBTN9_1080_H

#include <QPushButton>
#include "ui_QSecondBtn9_1080.h"
#include "QSecondBaseBtn.h"

class QSecondBtn9_1080 : public QSecondBaseBtn
{
	Q_OBJECT

public:
	QSecondBtn9_1080(QWidget *parent = 0);
	~QSecondBtn9_1080();

private:
	Ui::QSecondBtn9_1080 ui;
};

#endif // QSECONDBTN9_1080_H
