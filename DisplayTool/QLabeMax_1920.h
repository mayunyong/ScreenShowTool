#ifndef QLABEMAX_1920_H
#define QLABEMAX_1920_H

#include <QLabel>
#include "UserDef.h"
#ifdef SCRENN_1280_800
#include "ui_QLabeMax_800.h"
#else
#include "ui_QLabeMax_1920.h"
#endif

class QLabeMax_1920 : public QLabel
{
	Q_OBJECT

public:
	QLabeMax_1920(QWidget *parent = 0);
	~QLabeMax_1920();

private:
#ifdef SCRENN_1280_800
	Ui::QLabeMax_800 ui;
#else
	Ui::QLabeMax_1920 ui;
#endif
	
};

#endif // QLABEMAX_1920_H
