#include "QVideoBaseBtn.h"

QVideoBaseBtn::QVideoBaseBtn(QWidget *parent)
	: QPushButton(parent)
{
	connect(this, SIGNAL(clicked()), this, SLOT(SlotClickBtn()));
	connect(this, SIGNAL(SignalClkIndexBtn(const QPlayInfo*)), parent, SIGNAL(SignalClkIndexBtn(const QPlayInfo*)));
}

QVideoBaseBtn::~QVideoBaseBtn()
{

}

void QVideoBaseBtn::setPlayData(int iBtnIndex, const QPlayInfo* pStPlayDta)
{
	m_iBtnIndex = iBtnIndex;
	m_pPlayData = pStPlayDta;
}

void QVideoBaseBtn::setUIInfo(EN_PageType m_ePageType, int iNum, bool bVideoFlag /*= false*/)
{
	m_strSrcPath = ":/DisplayTool/home1.png";
	if (Page_Home == m_ePageType)
	{
		m_strSrcPath = QString(":/DisplayTool/home%1.png").arg(iNum);
	}
	if (Page_Second == m_ePageType)
	{
		m_strSrcPath = QString(":/DisplayTool/Second%1.png").arg(iNum);
		if(bVideoFlag)
		{
			m_strSrcPath = QString(":/DisplayTool/SecondVideo%1.png").arg(iNum);
		}
	}
}

void QVideoBaseBtn::SlotClickBtn()
{
	if(m_iBtnIndex > -1 && 
		m_pPlayData && 
		m_pPlayData->playData&&
		m_pPlayData->playData->HaveChild())
	{
		emit SignalClkIndexBtn(m_pPlayData);
	}
}
