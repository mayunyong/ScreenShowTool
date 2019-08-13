#ifndef QHOME2BTN_1080_H
#define QHOME2BTN_1080_H

#include <QPushButton>
#include "ui_QHome2Btn_1080.h"
#include "QVideoBaseBtn.h"

class QHome2Btn_1080 : public QVideoBaseBtn
{
	Q_OBJECT

public:
	QHome2Btn_1080(QWidget *parent = 0);
	~QHome2Btn_1080();

private:
	Ui::QHome2Btn_1080 ui;
};

#endif // QHOME2BTN_1080_H
