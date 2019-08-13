#ifndef QDISPLAYWINDOW_H
#define QDISPLAYWINDOW_H

#include <QMainWindow>
#include "ui_QDisplayWindow.h"

class QDisplayWindow : public QMainWindow
{
	Q_OBJECT

public:
	QDisplayWindow(QWidget *parent = 0);
	~QDisplayWindow();

private:
	Ui::QDisplayWindow ui;
};

#endif // QDISPLAYWINDOW_H
