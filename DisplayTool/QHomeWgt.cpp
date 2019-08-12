#include "QHomeWgt.h"

QHomeWgt::QHomeWgt(QWidget *parent)
	: QBGBaseWgt(parent)
{
	ui.setupUi(this);
	//InitHomeButton();
	m_ePageType = Page_Home;
}

QHomeWgt::~QHomeWgt()
{

}

void QHomeWgt::InitHomeButton()
{
	//!首页有5个按钮，并且位置固定
	//show();
	AddNewBtn(QPoint(105, 210));
	AddNewBtn(QPoint(448, 62));
	AddNewBtn(QPoint(746, 255));
	AddNewBtn(QPoint(714, 610));
	AddNewBtn(QPoint(130, 720));
}

