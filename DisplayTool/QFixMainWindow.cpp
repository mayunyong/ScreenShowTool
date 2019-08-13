#include "QFixMainWindow.h"
#include "QApplication"
#include "QDesktopWidget"

QFixMainWindow::QFixMainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	//!��ȡĬ����Ļ��С
	QDesktopWidget* desktop = QApplication::desktop();
	m_DeskRect = desktop->screenGeometry(-1);
	m_playDataObj.InitiaData();

	connect(ui.page, SIGNAL(SignalClkIndexBtn(const QPlayInfo*)), this, SLOT(SlotClkIndexBtn(const QPlayInfo*)));
	connect(ui.page_2, SIGNAL(SignalClkIndexBtn(const QPlayInfo*)), this, SLOT(SlotClkIndexBtn(const QPlayInfo*)));
}

QFixMainWindow::~QFixMainWindow()
{

}

void QFixMainWindow::ShowHomePage()
{
	show();
	//m_DeskRect = QRect(100,200,1600, 900);
	QPlayData* allPlayData = m_playDataObj.GetData();
	this->setGeometry(m_DeskRect); 
	ui.page->InitUIInfo(m_DeskRect, allPlayData);
}

void QFixMainWindow::SlotClkIndexBtn(const QPlayInfo* pStPlayDta)
{
	//!��ʾ�Ӽ�����
	if(pStPlayDta)
	{
		ui.stackedWidget->setCurrentIndex(1); 
		ui.page_2->InitUIInfo(m_DeskRect, pStPlayDta->playData);
		//ui.stackedWidget->setCurrentIndex(1);
	}
}
