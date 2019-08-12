#ifndef QHOMEWGT_H
#define QHOMEWGT_H

#include <QLabel>
#include "ui_QHomeWgt.h"
#include "QBGBaseWgt.h"
#include "qhomebtnitem.h"

class QVideoButton;

class QHomeWgt : public QBGBaseWgt
{
	Q_OBJECT

public:
	QHomeWgt(QWidget *parent = 0);
	~QHomeWgt();

private:
	//!��ʼ����ť
	void InitHomeButton();

	//void AddNewBtn(double wPercent,double hPercent);
private:
	Ui::QHomeWgt ui;

};

#endif // QHOMEWGT_H
