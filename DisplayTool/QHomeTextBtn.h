#ifndef QHOMETEXTBTN_H
#define QHOMETEXTBTN_H

#include <QPushButton>
#include "ui_QHomeTextBtn.h"

class QHomeTextBtn : public QPushButton
{
	Q_OBJECT

public:
	QHomeTextBtn(QWidget *parent = 0);
	~QHomeTextBtn();

private:
	Ui::QHomeTextBtn ui;
};

#endif // QHOMETEXTBTN_H
