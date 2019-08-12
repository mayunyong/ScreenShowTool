#ifndef QFIXMAINWINDOW_H
#define QFIXMAINWINDOW_H

#include <QMainWindow>
#include "ui_QFixMainWindow.h"
#include "QRect"

class QFixMainWindow : public QMainWindow
{
	Q_OBJECT

public:
	QFixMainWindow(QWidget *parent = 0);
	~QFixMainWindow();

public:
	void ShowHomePage();

private:
	Ui::QFixMainWindow ui;
	QRect m_DeskRect;
};

#endif // QFIXMAINWINDOW_H
