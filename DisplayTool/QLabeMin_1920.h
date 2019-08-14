#ifndef QLABEMIN_1920_H
#define QLABEMIN_1920_H

#include <QLabel>
#include "UserDef.h"

#ifdef SCRENN_1280_800
#include "ui_QLabeMin_800.h"
#else
#include "ui_QLabeMin_1920.h"
#endif


class QLabeMin_1920 : public QLabel
{
	Q_OBJECT

public:
	QLabeMin_1920(QWidget *parent = 0);
	~QLabeMin_1920();

private:
#ifdef SCRENN_1280_800
	Ui::QLabeMin_800 ui;
#else
	Ui::QLabeMin_1920 ui;
#endif
	
};

#endif // QLABEMIN_1920_H
