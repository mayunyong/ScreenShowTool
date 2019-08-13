#ifndef QHOMEPAGE_1080_H
#define QHOMEPAGE_1080_H

#include <QWidget>
#include "ui_QHomePage_1080.h"

class QHomePage_1080 : public QWidget
{
	Q_OBJECT

public:
	QHomePage_1080(QWidget *parent = 0);
	~QHomePage_1080();

private:
	Ui::QHomePage_1080 ui;
};

#endif // QHOMEPAGE_1080_H
