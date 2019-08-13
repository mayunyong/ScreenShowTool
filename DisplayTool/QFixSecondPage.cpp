#include "QFixSecondPage.h"
#include "QSecondBtn1_1080.h"
#include "QSecondBtn2_1080.h"
#include "QSecondBtn3_1080.h"
#include "QSecondBtn4_1080.h"
#include "QSecondBtn5_1080.h"
#include "QSecondBtn6_1080.h"
#include "qsecondbtn7_1080.h"
#include "QSecondBtn8_1080.h"
#include "QSecondBtn9_1080.h"


QFixSecondPage::QFixSecondPage(QWidget *parent)
	: QBGBaseWgt(parent)
{
	ui.setupUi(this);
	//InitHomeButton();
	m_ePageType = Page_Second;
	m_pBackGroundixmap= new QPixmap(":/DisplayTool/SecondPage.png");

	connect(ui.toolButton, SIGNAL(clicked()), this, SLOT(SlotClkBack()));
	connect(ui.toolButton_2, SIGNAL(clicked()), this, SLOT(SlotClkNext()));
	connect(ui.toolButton_3, SIGNAL(clicked()), this, SIGNAL(SignalMin()));

	AddNewBtn(new QSecondBtn1_1080(this), QPoint(86, 287));
	AddNewBtn(new QSecondBtn2_1080(this), QPoint(443, 159));
	AddNewBtn(new QSecondBtn3_1080(this), QPoint(811, 261));
	AddNewBtn(new QSecondBtn4_1080(this), QPoint(1149, 181));
	AddNewBtn(new QSecondBtn5_1080(this), QPoint(1505, 271));
	AddNewBtn(new QSecondBtn6_1080(this), QPoint(86, 647));
	AddNewBtn(new QSecondBtn7_1080(this), QPoint(497, 607));
	AddNewBtn(new QSecondBtn8_1080(this), QPoint(975, 611));
	AddNewBtn(new QSecondBtn9_1080(this), QPoint(1409, 639));
}

QFixSecondPage::~QFixSecondPage()
{

}

void QFixSecondPage::InitAllButton()
{
	if(!m_pPlayInfo)
	{
		return;
	}
	
	ui.toolButton_2->hide();
	ui.label->setText(m_pPlayInfo->displayName);
	if(m_iAllPageSize > 1)
	{
		ui.toolButton_2->show();
	}

	ShowPage(1);
}

void QFixSecondPage::SlotClkNext()
{
	//throw std::logic_error("The method or operation is not implemented.");
	int iPageIndex = m_iCurPage + 1;

	if(m_pPlayInfo &&
		m_pPlayInfo->playData)
	{
		if(m_pPlayInfo->playData->children.contains(iPageIndex))
		{
			ShowPage(iPageIndex);
		}

		if(!m_pPlayInfo->playData->children.contains(++iPageIndex))
		{
			ui.toolButton_2->hide();
		}
	}
}

void QFixSecondPage::SlotClkBack()
{
	if(m_pPlayInfo)
	{
		if (1 == m_iCurPage)
		{
			emit SignalClkIndexBtn(m_pPlayInfo->pParentInfo);
		}
		//!非第一页，则返回至上一页
		else if(m_iCurPage > 1)
		{
			int iPageIndex = m_iCurPage - 1;

			if(m_pPlayInfo &&
				m_pPlayInfo->playData)
			{
				if(m_pPlayInfo->playData->children.contains(iPageIndex))
				{
					ShowPage(iPageIndex);
					ui.toolButton_2->show();
				}
			}
		}
	}
}
