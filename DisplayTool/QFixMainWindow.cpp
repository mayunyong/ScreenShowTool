#include "QFixMainWindow.h"
#include "QApplication"
#include "QDesktopWidget"
#include <QMessageBox>
#include "QFileInfo"

QFixMainWindow::QFixMainWindow(QWidget *parent)
	: QMainWindow(parent)
	,m_pPlayer(NULL)
{
	ui.setupUi(this);
	
	//!获取默认屏幕大小
	QDesktopWidget* desktop = QApplication::desktop();
	m_DeskRect = desktop->screenGeometry(-1);
	
	m_playDataObj.InitiaData();
	m_pAllPlayInfo = new QPlayInfo();
	QPlayData* allPlayData = m_playDataObj.GetData();
	m_pAllPlayInfo->dispalyID = -1;
	m_pAllPlayInfo->playData = allPlayData;

	connect(ui.page, SIGNAL(SignalClkIndexBtn(const QPlayInfo*)), this, SLOT(SlotClkIndexBtn(const QPlayInfo*)));
	connect(ui.page_2, SIGNAL(SignalClkIndexBtn(const QPlayInfo*)), this, SLOT(SlotClkIndexBtn(const QPlayInfo*)));
	connect(ui.page, SIGNAL(SignalMin()), this, SLOT(showMinimized()));
	connect(ui.page_2, SIGNAL(SignalMin()), this, SLOT(showMinimized()));
	m_pPlayer = new QPlayer();
	
}

QFixMainWindow::~QFixMainWindow()
{
	if (m_pAllPlayInfo)
	{
		m_pAllPlayInfo->playData = NULL;
		delete m_pAllPlayInfo;
		m_pAllPlayInfo = NULL;
	}
	if(m_pPlayer)
	{
		m_pPlayer->deleteLater();
	}
}

void QFixMainWindow::ShowHomePage()
{
	showFullScreen();
	//m_DeskRect = QRect(10,200,1280, 800);

	this->setGeometry(m_DeskRect); 
	ui.page->InitUIInfo(m_DeskRect, m_pAllPlayInfo);
}

void QFixMainWindow::SlotClkIndexBtn(const QPlayInfo* pStPlayDta)
{
	//!显示子级界面
	if(pStPlayDta)
	{
		if (QPlayInfo::folder == pStPlayDta->fileType)
		{
			if( pStPlayDta->playData
				&& pStPlayDta->HavePage())
			{
				ui.stackedWidget->setCurrentIndex(1); 
				ui.page_2->InitUIInfo(m_DeskRect, pStPlayDta);
			}
	
		}
		else
		{
			if(QFileInfo::exists(pStPlayDta->filePath) && QFileInfo(pStPlayDta->filePath).isFile())
			{
				//!视频播放
				m_pPlayer->PlayVideo(pStPlayDta->filePath);
			}
			else
			{
				QMessageBox::warning(this, QStringLiteral("提示"), QStringLiteral("视频文件不存在!"), QMessageBox::Yes );
			}
		//	ui.page_2->InitUIInfo(m_DeskRect, pStPlayDta);)
		}
		
		//ui.stackedWidget->setCurrentIndex(1);
	}
	else
	{
		ui.stackedWidget->setCurrentIndex(0); 
	}
}
