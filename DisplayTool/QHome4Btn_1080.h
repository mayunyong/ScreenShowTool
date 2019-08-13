#ifndef QHOME4BTN_1080_H
#define QHOME4BTN_1080_H

#include <QPushButton>
#include "ui_QHome4Btn_1080.h"
#include "QVideoBaseBtn.h"

class QHome4Btn_1080 : public QVideoBaseBtn
{
	Q_OBJECT

public:
	QHome4Btn_1080(QWidget *parent = 0);
	~QHome4Btn_1080();

private:
	Ui::QHome4Btn_1080 ui;
};

#endif // QHOME4BTN_1080_H
