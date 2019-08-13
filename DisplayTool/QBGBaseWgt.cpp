#include "QBGBaseWgt.h"
#include "qevent.h"
#include "QPainter"
#include "UserDef.h"
#include "QSecondBtnItem.h"



QBGBaseWgt::QBGBaseWgt(QWidget *parent)
	: QWidget(parent)
	,m_pBGLabel(NULL)
	,m_pPlayData(NULL)
	,m_strBGSrc(":/DisplayTool/HomePage.png")
	,m_bInifFlag(false)
{
	m_pBGLabel = new QLabel(this);
	//m_pBGLabel->move()
}

QBGBaseWgt::~QBGBaseWgt()
{

}

void QBGBaseWgt::InitUIInfo(const QRect& deskRect, QPlayData* pPlayData)
{
	m_WgtRect = deskRect;
	m_Wgtsize = deskRect.size();
	m_pPlayData = pPlayData;
	////m_WgtRect = deskRect;
	//setPixmap(m_pBackGroundixmap->scaled(m_Wgtsize, Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation));
	if(m_pBGLabel)
	{
		m_pBGLabel->resize(m_Wgtsize);
		m_pBGLabel->setPixmap(m_pBackGroundixmap->scaled(m_Wgtsize, Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation));

	}

	InitAllButton();
}

void QBGBaseWgt::resizeEvent(QResizeEvent * rSizeevent)
{
	//m_Wgtsize = rSizeevent->size();
	////m_WgtRect = deskRect;
	//setPixmap(m_pBackGroundixmap->scaled(m_Wgtsize, Qt::KeepAspectRatio, Qt::SmoothTransformation));

	QWidget::resizeEvent(rSizeevent);
}

void QBGBaseWgt::paintEvent(QPaintEvent *event)
{
		//QPainter painter(this);
		//////QPixmap pix;
		//painter.drawPixmap(rect(), *m_pBackGroundixmap);
		QWidget::paintEvent(event);
}



void QBGBaseWgt::AddNewBtn(QPoint pPos)
{
	int nxPos = pPos.x();
	int nyPos = pPos.y();
	QRect wgtRect = rect();

	QHomeBtnItem* m_pBtn = NULL;
	if(Page_Second == m_ePageType)
	{
		m_pBtn = new QSecondBtnItem(this, wgtRect.size());
	}
	else
	{
		m_pBtn = new QHomeBtnItem(this, wgtRect.size());
	}

	if (m_pBtn)
	{
		//£¡¼ÇÂ¼btn
		int iNum = m_VideoBtnMap.size()+1;
		m_VideoBtnMap[iNum] = m_pBtn;
		m_pBtn->setUIInfo(m_ePageType, iNum);

		//!ÐÞ¸ÄÎ»ÖÃ
		int iXPos = wgtRect.width() * nxPos / c_iBGImgWidth;
		int iYPos = wgtRect.height() * nyPos / c_iBGImgHeight;
		m_pBtn->move(iXPos, iYPos);
	}
}