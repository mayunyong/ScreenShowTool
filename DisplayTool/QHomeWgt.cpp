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
	//!��ҳ��5����ť������λ�ù̶�
	//show();
	AddNewBtn(QPoint(105, 210));
	AddNewBtn(QPoint(448, 62));
	AddNewBtn(QPoint(746, 255));
	AddNewBtn(QPoint(714, 610));
	AddNewBtn(QPoint(130, 720));
}

