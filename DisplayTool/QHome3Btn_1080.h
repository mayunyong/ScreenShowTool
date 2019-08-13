#ifndef QHOME3BTN_1080_H
#define QHOME3BTN_1080_H

#include <QPushButton>
#include "ui_QHome3Btn_1080.h"
#include "QVideoBaseBtn.h"

class QHome3Btn_1080 : public QVideoBaseBtn
{
	Q_OBJECT

public:
	QHome3Btn_1080(QWidget *parent = 0);
	~QHome3Btn_1080();

private:
	Ui::QHome3Btn_1080 ui;
};

#endif // QHOME3BTN_1080_H
