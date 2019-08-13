#include "QBtnImgLabel.h"

QBtnImgLabel::QBtnImgLabel(QWidget *parent)
	: QLabel(parent)
	,m_pageType(Page_Home)
{
	ui.setupUi(this);
	//show();
	
	QTextCharFormat format;
	format.setTextOutline (QPen (QColor(2,228,250), 1, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin)); // Color and width of outline
	format.setVerticalAlignment(QTextCharFormat::AlignMiddle);
	format.setFontWeight(66);
	ui.textEdit->mergeCurrentCharFormat(format);
	ui.textEdit->document()->setDefaultTextOption(QTextOption(Qt::AlignCenter));
}

QBtnImgLabel::~QBtnImgLabel()
{

}

void QBtnImgLabel::SetIMgText(const QString& strText)
{
	
	int iHeght = height();

	//!ÊÊÅä×ÖÌåÎ»ÖÃ
	ui.textEdit->setFontPointSize((qreal)iHeght/6.5);
	int iHeight = ui.textEdit->fontMetrics().height();
	ui.textEdit->setFixedHeight(iHeight + iHeght * 0.13);;

	ui.textEdit->setText(strText);
}