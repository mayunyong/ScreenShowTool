#include "QVideoBaseBtn.h"
#include <QSound>

QVideoBaseBtn::QVideoBaseBtn(QWidget *parent)
	: QPushButton(parent)
	,m_bAdjustSize(false)
	,m_bNeedSetText(true)
	,m_iBtnIndex(0)
	,m_pPlayData(NULL)
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

	ShowPlayData();
}
//
//void QVideoBaseBtn::setUIInfo(EN_PageType m_ePageType, int iNum, bool bVideoFlag /*= false*/)
//{
//	m_strSrcPath = ":/DisplayTool/home1.png";
//	if (Page_Home == m_ePageType)
//	{
//		m_strSrcPath = QString(":/DisplayTool/home%1.png").arg(iNum);
//		if(!m_bNeedSetText)
//		{
//			m_strSrcPath = QString(":/DisplayTool/HomeText1%1.png").arg(iNum);
//		}
//	}
//	if (Page_Second == m_ePageType)
//	{
//		m_strSrcPath = QString(":/DisplayTool/Second%1.png").arg(iNum);
//		if(bVideoFlag)
//		{
//			m_strSrcPath = QString(":/DisplayTool/SecondVideo%1.png").arg(iNum);
//		}
//	}
//}

void QVideoBaseBtn::SlotClickBtn()
{
	QSound::play("sound/2.wav");
	if(m_iBtnIndex > -1 && 
		m_pPlayData 
		)
	{
		emit SignalClkIndexBtn(m_pPlayData);
	}
}

void QVideoBaseBtn::ShowPlayData()
{
	//throw std::logic_error("The method or operation is not implemented.");
	show();
}
