#include "displaytool.h"
#include "qhomebtnitem.h"
#include "QTableWidget"

const int c_iMaxlevel = 3;

DisplayTool::DisplayTool(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	//!首页按钮
	connect(ui.homeButton, SIGNAL(clicked()), this, SLOT(SlotShowHomePage()));
	connect(ui.BackBtn, SIGNAL(clicked()), this, SLOT(SlotShowBackPage()));

	ui.TopPage->SetLevel(0);
	ui.secondPage->SetLevel(1);
	ui.thirdPage->SetLevel(2);
	m_BtnPageMap[0] = ui.TopPage;
	m_BtnPageMap[1] = ui.secondPage;
	m_BtnPageMap[2] = ui.thirdPage;

	connect(ui.TopPage, SIGNAL( SignShowPlayData(QPlayData*, int )), this, SLOT(SlotShowPlayData(QPlayData*, int)));
	connect(ui.secondPage,SIGNAL( SignShowPlayData(QPlayData*, int )), this, SLOT(SlotShowPlayData(QPlayData*, int)));
	connect(ui.thirdPage, SIGNAL( SignShowPlayData(QPlayData*, int )), this, SLOT(SlotShowPlayData(QPlayData*, int)));
	
	m_playData.InitiaData();
	InitHomeBtns();
}

DisplayTool::~DisplayTool()
{

}

void DisplayTool::SlotShowPlayData(QPlayData* pPlayData, int iIndex)
{
	if(pPlayData && iIndex > -1 && iIndex <m_BtnPageMap.size())
	{
		m_BtnPageMap[iIndex]->InitPlayerData(pPlayData);
		ui.stackedWidgetHome->setCurrentIndex(iIndex);
	}

	if (0 == iIndex)
	{
		ui.BackBtn->setEnabled(false);
	}
	else
	{
		ui.BackBtn->setEnabled(true);
	}
}

void DisplayTool::SlotShowBackPage()
{
	int iShowCurIndex = ui.stackedWidgetHome->currentIndex() - 1;
	if(iShowCurIndex > -1 &&iShowCurIndex < m_BtnPageMap.size())
	{
		ui.stackedWidgetHome->setCurrentIndex(iShowCurIndex);
	}

	if (0 == iShowCurIndex)
	{
		ui.BackBtn->setEnabled(false);
	}
}

//！初始化主页按钮
void DisplayTool::InitHomeBtns()
{
	/* QGridLayout *gridHomeBtnLay = new QGridLayout(ui.widgetHome);
	 gridHomeBtnLay->setSpacing(6);
	 gridHomeBtnLay->setContentsMargins(11, 11, 11, 11);*/
	
	 //！创建主页按钮
	QPlayData* pPlayData = m_playData.GetData();
	//ui.TopPage->InitPlayerData(pPlayData);
	SlotShowPlayData(pPlayData, 0);
	/*if(pPlayData && pPlayData->HaveChild())
	{
	for (int iBtnIndex = 0; iBtnIndex <pPlayData->children.size(); iBtnIndex++)
	{
	QHomeBtnItem* pHomeBtnItemWgt = new QHomeBtnItem(ui.widgetHome);
	pHomeBtnItemWgt->setPlayData(iBtnIndex, pPlayData->children[iBtnIndex]);
	gridHomeBtnLay->addWidget(pHomeBtnItemWgt, iBtnIndex/2, iBtnIndex%2, 1, 1);

	connect(pHomeBtnItemWgt, SIGNAL(SignalClkIndexBtn(int)), this, SLOT(SlotClkBtnIndex(int)));
	}
	}*/
}

//！显示主页
void DisplayTool::SlotShowHomePage()
{
	ui.stackedWidgetHome->setCurrentIndex(0);
}

//！点击主页按钮
void DisplayTool::SlotClkBtnIndex(int iBtnIndex)
{
	QPlayData* pPlayData = m_playData.GetData();
	if(pPlayData && pPlayData->children.size() > iBtnIndex)
	{
		ui.page_4->setPlayData(&pPlayData->children[iBtnIndex]);
		ui.stackedWidget->setCurrentIndex(1);
	}
}
