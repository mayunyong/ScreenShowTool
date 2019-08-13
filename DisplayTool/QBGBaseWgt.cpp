#include "QBGBaseWgt.h"
#include "qevent.h"
#include "QPainter"
#include "UserDef.h"
#include "QSecondBtnItem.h"



QBGBaseWgt::QBGBaseWgt(QWidget *parent)
	: QWidget(parent)
	,m_pBGLabel(NULL)
	,m_pPlayInfo(NULL)
	,m_strBGSrc(":/DisplayTool/HomePage.png")
	,m_bInifFlag(false)
	,m_iCurPage(0)
	,m_iAllPageSize(1)
{
	m_pBGLabel = new QLabel(this);
	//m_pBGLabel->move()
}

QBGBaseWgt::~QBGBaseWgt()
{

}

void QBGBaseWgt::InitUIInfo(const QRect& deskRect, const QPlayInfo* pPlayInfo)
{
	m_WgtRect = deskRect;
	m_Wgtsize = deskRect.size();
	m_pPlayInfo = pPlayInfo;

	m_iAllPageSize = 0;
	if(m_pPlayInfo->playData && m_pPlayInfo->playData)
	{
		m_iAllPageSize = m_pPlayInfo->playData->children.size();
	}
	////m_WgtRect = deskRect;
	//setPixmap(m_pBackGroundixmap->scaled(m_Wgtsize, Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation));
	if(m_pBGLabel)
	{
		m_pBGLabel->resize(m_Wgtsize);
		m_pBGLabel->setPixmap(m_pBackGroundixmap->scaled(m_Wgtsize, Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation));

	}

	foreach(QVideoBaseBtn* pBtn, m_VideoBtnMap)
	{
		if(pBtn)
		{
			pBtn->hide();
		}
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
		//！记录btn
		int iNum = m_VideoBtnMap.size()+1;
		m_VideoBtnMap[iNum] = m_pBtn;
		m_pBtn->setUIInfo(m_ePageType, iNum);

		//!修改位置
		int iXPos = wgtRect.width() * nxPos / c_iBGImgWidth;
		int iYPos = wgtRect.height() * nyPos / c_iBGImgHeight;
		m_pBtn->move(iXPos, iYPos);
	}
}

void QBGBaseWgt::AddNewBtn(QVideoBaseBtn* pBtn, QPoint pPos)
{
	//！记录btn
	int iNum = m_VideoBtnMap.size()+1;
	m_VideoBtnMap[iNum] = pBtn;

	pBtn->move(pPos);
}

void QBGBaseWgt::ShowPage(int iPage /*= 0*/)
{
	if(m_pPlayInfo &&
		m_pPlayInfo->playData 
		&& m_pPlayInfo->playData->children.contains(iPage))
	{
		foreach(QVideoBaseBtn* pBtn, m_VideoBtnMap)
		{
			if(pBtn)
			{
				pBtn->hide();
			}
		}

		const QVector<QPlayInfo*>& vecPlayInfo = m_pPlayInfo->playData->children[iPage];

		for (int index = 0; index < vecPlayInfo.size(); index++)
		{
			const int& iNum = vecPlayInfo[index]->dispalyID;
			if(m_VideoBtnMap.contains(iNum) && m_VideoBtnMap[iNum])
			{
				m_VideoBtnMap[iNum]->setPlayData(iNum, vecPlayInfo[index]);
			}
		}

		 m_iCurPage = iPage;
	}


}
