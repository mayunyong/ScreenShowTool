#ifndef QHOME2BTN_1080_H
#define QHOME2BTN_1080_H

#include <QPushButton>
#include "QVideoBaseBtn.h"

#ifdef SCRENN_1280_800
#include "ui_QHome2Btn_800.h"
#else
#include "ui_QHome2Btn_1080.h"
#endif




class QHome2Btn_1080 : public QVideoBaseBtn
{
	Q_OBJECT

public:
	QHome2Btn_1080(QWidget *parent = 0);
	~QHome2Btn_1080();

private:
#ifdef SCRENN_1280_800
	Ui::QHome2Btn_800 ui;
#else
	Ui::QHome2Btn_1080 ui;
#endif

};

#endif // QHOME2BTN_1080_H
