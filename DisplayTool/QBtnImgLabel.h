#ifndef QBTNIMGLABEL_H
#define QBTNIMGLABEL_H

#include <QLabel>
#include "ui_QBtnImgLabel.h"
#include <QTextEdit>
#include "UserDef.h"

class QBtnImgLabel : public QLabel
{
	Q_OBJECT

public:
	QBtnImgLabel(QWidget *parent = 0);
	~QBtnImgLabel();

	void SetIMgText(const QString& strText);
private:
	Ui::QBtnImgLabel ui;

	EN_PageType m_pageType;
};

#endif // QBTNIMGLABEL_H
