#ifndef QHOME5BTN_1080_H
#define QHOME5BTN_1080_H

#include <QPushButton>
#include "QVideoBaseBtn.h"

#ifdef SCRENN_1280_800
#include "ui_QHome5Btn_800.h"
#else
#include "ui_QHome5Btn_1080.h"
#endif

class QHome5Btn_1080 : public QVideoBaseBtn
{
	Q_OBJECT

public:
	QHome5Btn_1080(QWidget *parent = 0);
	~QHome5Btn_1080();

private:
#ifdef SCRENN_1280_800
	Ui::QHome5Btn_800 ui;
#else
	Ui::QHome5Btn_1080 ui;
#endif
};

#endif // QHOME5BTN_1080_H
