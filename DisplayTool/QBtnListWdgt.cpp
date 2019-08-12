#include "QBtnListWdgt.h"
#include "QGridLayout"
#include "qhomebtnitem.h"
#include "QApplication"
#include "QDesktopWidget"

const  int c_iCloumnNum = 3;

QBtnListWdgt::QBtnListWdgt(QWidget *parent)
	: QWidget(parent)
	,m_pPlayData(NULL)
	,m_gridHomeBtnLay(NULL)
	,m_iLevel(0)
{
	ui.setupUi(this);
	
	//!设置布局
	QDesktopWidget *pDesktop = QApplication::desktop();
	if(pDesktop)
	{
		m_DeskTopRect = pDesktop->screenGeometry();
	}
}

QBtnListWdgt::~QBtnListWdgt()
{

}

void QBtnListWdgt::InitUIByData(QPlayData* pPlayData)
{

	bool bNewWdgtFlag = true;
	if(m_gridHomeBtnLay)
	{
		QRect oldRect=  ui.scrollArea->geometry();
		ui.scrollArea->takeWidget();
		ui.scrollAreaWidget->deleteLater();

		ui.scrollAreaWidget = new QWidget();
	//	ui.scrollAreaWidget->setAutoFillBackground(true);


	//	ui.scrollArea->setWidgetResizable(true);
	//	//ui.scrollAreaWidget->adjustSize();
	//	//ui.scrollArea->adjustSize();
	///*	updateGeometry()*/
	}
	else
	{
		bNewWdgtFlag = false;
	}

//QRect oldRect=  ui.scrollArea->geometry();
	m_gridHomeBtnLay = new QGridLayout(ui.scrollAreaWidget);
	m_gridHomeBtnLay->setVerticalSpacing(6);
	m_gridHomeBtnLay->setContentsMargins(11, 11, 11, 11);
	ui.scrollAreaWidget->setLayout(m_gridHomeBtnLay);
		//ui.scrollArea->updateGeometry();
	//！创建按钮
	if(pPlayData && pPlayData->HaveChild())
	{
		int iCloumnCount = c_iCloumnNum;
		int iBtnSize = pPlayData->children.size();
		if(iBtnSize == 4)
		{
			iCloumnCount = 2;
		}

		for (int iBtnIndex = 0; iBtnIndex <pPlayData->children.size(); iBtnIndex++)
		{
			QHomeBtnItem* pHomeBtnItemWgt = new QHomeBtnItem(ui.scrollAreaWidget, m_DeskTopRect.width()/(c_iCloumnNum+1), m_DeskTopRect.height()/4);
			pHomeBtnItemWgt->setPlayData(iBtnIndex, pPlayData->children[iBtnIndex]);
			m_gridHomeBtnLay->addWidget(pHomeBtnItemWgt, iBtnIndex/iCloumnCount, iBtnIndex%iCloumnCount);
			//m_gridHomeBtnLay->setRowStretch(iBtnIndex/3,1);
			//m_gridHomeBtnLay->setColumnStretch(iBtnIndex%3, 1);
			connect(pHomeBtnItemWgt, SIGNAL(SignalClkIndexBtn(int)), this, SLOT(SlotClkBtnIndex(int)));
		}
	}
	
	//ui.scrollAreaWidget->updateGeometry();
	//ui.scrollAreaWidget->adjustSize();
	////ui.scrollArea->adjustSize();
	////adjustSize();
	if(bNewWdgtFlag)
	{
		ui.scrollArea->setWidget(ui.scrollAreaWidget);
		ui.scrollAreaWidget->show();
	}
}

void QBtnListWdgt::InitPlayerData(QPlayData* pPlayData)
{
	if(pPlayData)
	{
		m_pPlayData = pPlayData;
	}
	
	InitUIByData(m_pPlayData);

}

//！点击主页按钮
void QBtnListWdgt::SlotClkBtnIndex(int iBtnIndex)
{
	if(m_pPlayData && m_pPlayData->children.size() > iBtnIndex)
	{
		emit SignShowPlayData(&m_pPlayData->children[iBtnIndex], m_iLevel+1);
	}
}