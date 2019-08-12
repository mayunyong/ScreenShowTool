#include "QBtnImgLabel.h"

QBtnImgLabel::QBtnImgLabel(QWidget *parent)
	: QLabel(parent)
{
	ui.setupUi(this);
}

QBtnImgLabel::~QBtnImgLabel()
{

}

void QBtnImgLabel::SetIMgText(const QString& strText)
{
	ui.label->setText(strText);
}