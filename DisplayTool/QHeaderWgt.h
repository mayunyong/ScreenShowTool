#ifndef QHEADERWGT_H
#define QHEADERWGT_H

#include <QWidget>
#include "ui_QHeaderWgt.h"

class QHeaderWgt : public QWidget
{
	Q_OBJECT

public:
	QHeaderWgt(QWidget *parent = 0);
	~QHeaderWgt();

private:
	Ui::QHeaderWgt ui;

signals:
	void SignCloseWdgt();
};

#endif // QHEADERWGT_H
