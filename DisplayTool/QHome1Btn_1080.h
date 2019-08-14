#ifndef QHOME1BTN_1080_H
#define QHOME1BTN_1080_H

#include <QPushButton>
#include "QVideoBaseBtn.h"

#ifdef SCRENN_1280_800
#include "ui_QHome1Btn_800.h"
#else
#include "ui_QHome1Btn_1080.h"
#endif



class QHome1Btn_1080 : public QVideoBaseBtn
{
	Q_OBJECT

public:
	QHome1Btn_1080(QWidget *parent = 0);
	~QHome1Btn_1080();

private:
#ifdef SCRENN_1280_800
	Ui::QHome1Btn_800 ui;
#else
	Ui::QHome1Btn_1080 ui;
#endif
	
};

#endif // QHOME1BTN_1080_H
