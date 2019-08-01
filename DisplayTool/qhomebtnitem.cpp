#include "qhomebtnitem.h"

QHomeBtnItem::QHomeBtnItem(QWidget *parent,int iWidth, int iHieght)
	: QWidget(parent)
	,m_iBtnIndex(-1)
{
	ui.setupUi(this);
	setFixedHeight(iHieght);
	setFixedWidth(iWidth);

	adjustSize();
}

QHomeBtnItem::~QHomeBtnItem()
{

}


void QHomeBtnItem::setPlayData(int iBtnIndex, const QPlayData& ePlayDta)
{
	m_iBtnIndex = iBtnIndex;
	ui.pushButton->setText(ePlayDta.displayName);
	connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(SlotClickBtn()));

	//!
}

void QHomeBtnItem::SlotClickBtn()
{
	if(m_iBtnIndex > -1 )
	{
		emit SignalClkIndexBtn(m_iBtnIndex);
	}
}
