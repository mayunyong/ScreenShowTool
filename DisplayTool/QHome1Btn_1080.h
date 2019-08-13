#ifndef QHOME1BTN_1080_H
#define QHOME1BTN_1080_H

#include <QPushButton>
#include "ui_QHome1Btn_1080.h"
#include "QVideoBaseBtn.h"

class QHome1Btn_1080 : public QVideoBaseBtn
{
	Q_OBJECT

public:
	QHome1Btn_1080(QWidget *parent = 0);
	~QHome1Btn_1080();

private:
	Ui::QHome1Btn_1080 ui;
};

#endif // QHOME1BTN_1080_H
