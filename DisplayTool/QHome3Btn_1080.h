#ifndef QHOME3BTN_1080_H
#define QHOME3BTN_1080_H

#include <QPushButton>
#include "QVideoBaseBtn.h"

#ifdef SCRENN_1280_800
#include "ui_QHome3Btn_800.h"
#else
#include "ui_QHome3Btn_1080.h"
#endif


class QHome3Btn_1080 : public QVideoBaseBtn
{
	Q_OBJECT

public:
	QHome3Btn_1080(QWidget *parent = 0);
	~QHome3Btn_1080();

private:
#ifdef SCRENN_1280_800
	Ui::QHome3Btn_800 ui;
#else
	Ui::QHome3Btn_1080 ui;
#endif

	
};

#endif // QHOME3BTN_1080_H
