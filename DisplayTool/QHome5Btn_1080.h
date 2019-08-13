#ifndef QHOME5BTN_1080_H
#define QHOME5BTN_1080_H

#include <QPushButton>
#include "ui_QHome5Btn_1080.h"
#include "QVideoBaseBtn.h"

class QHome5Btn_1080 : public QVideoBaseBtn
{
	Q_OBJECT

public:
	QHome5Btn_1080(QWidget *parent = 0);
	~QHome5Btn_1080();

private:
	Ui::QHome5Btn_1080 ui;
};

#endif // QHOME5BTN_1080_H
