#ifndef QHOME4BTN_1080_H
#define QHOME4BTN_1080_H

#include <QPushButton>
#include "QVideoBaseBtn.h"

#ifdef SCRENN_1280_800
#include "ui_QHome4Btn_800.h"
#else
#include "ui_QHome4Btn_1080.h"
#endif


class QHome4Btn_1080 : public QVideoBaseBtn
{
	Q_OBJECT

public:
	QHome4Btn_1080(QWidget *parent = 0);
	~QHome4Btn_1080();

private:
#ifdef SCRENN_1280_800
	Ui::QHome4Btn_800 ui;
#else
	Ui::QHome4Btn_1080 ui;
#endif
};

#endif // QHOME4BTN_1080_H
