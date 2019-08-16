#include "QPlayer.h"
#include <QFileInfo>
#include "QDesktopWidget"
#include "QApplication"
#include "QTime"
#include <QMouseEvent>
#include "QHeaderWgt.h"
#include "qcontrolwidgt.h"

QPlayer::QPlayer(QWidget *parent)
	: QWidget(parent)
	,m_pPlayer(NULL)
	,m_pHeaderWgt(NULL)
	,m_pContorlWgt(NULL)
{
	ui.setupUi(this);

	setWindowFlags(Qt::FramelessWindowHint);
	m_pPlayer = new QMediaPlayer(this);
	m_pPlayer->setVideoOutput(ui.videoWidget);

	m_pHeaderWgt= new QHeaderWgt(this);
	m_pContorlWgt = new QControlWidgt(this, m_pPlayer);
	m_pContorlWgt->hide();
	m_pHeaderWgt->hide();

	connect(m_pHeaderWgt, SIGNAL(SignCloseWdgt()), this, SLOT(close()));
	connect(m_pContorlWgt, SIGNAL(SignalVideoPlayFinish()), this, SLOT(close()));
	connect(m_pPlayer, SIGNAL(videoAvailableChanged(bool)), this, SLOT(SlotShowWgt(bool)));
	//connect(m_pPlayer, SIGNAL(error(QMediaPlayer::Error)), this, SLOT(handleError()));
}

QPlayer::~QPlayer()
{

}

//！播放视频
void QPlayer::PlayVideo(const QString& strVideoPath)
{
	m_pContorlWgt->hide();
	if(!QFileInfo::exists(strVideoPath)
		|| !m_pContorlWgt
		|| !m_pPlayer)
	{
		return;
	}

	m_pPlayer->setMedia(QUrl::fromLocalFile(strVideoPath));
	m_pPlayer->play();
	m_pContorlWgt->InitStartPlay();

	//SlotPlaying();
}


//鼠标移动事件
void QPlayer::mouseMoveEvent(QMouseEvent *ev)
{
	if(m_pContorlWgt && m_pHeaderWgt && m_pPlayer)
	{
		int iheight = height();
		QPoint posPnt =  ev->pos();
		int iPosY = posPnt.y();
		if((iPosY >0 && iPosY<40 ))
		{	
			if(m_pHeaderWgt->isHidden())
			{
				m_pHeaderWgt->setFixedWidth(width());
				m_pHeaderWgt->show();
				qDebug()<<QStringLiteral("位置%1").arg(iPosY);

			}

		/*	if(!m_pContorlWgt->isHidden() && m_pPlayer->state() == QMediaPlayer::PlayingState)
			{
				m_pContorlWgt->hide();
			}*/
		}
		else if(iPosY > iheight-50 && iPosY < iheight)
		{
			if(m_pContorlWgt->isHidden())
			{
				m_pContorlWgt->setFixedWidth(width());
				m_pContorlWgt->move(0, height()-60);
				m_pContorlWgt->show();
			}

			/*if(!m_pHeaderWgt->isHidden()&& m_pPlayer->state() == QMediaPlayer::PlayingState)
			{
				m_pHeaderWgt->hide();
			}*/
		}
		else
		{
			if(!m_pHeaderWgt->isHidden()&& m_pPlayer->state() == QMediaPlayer::PlayingState)
			{
				m_pHeaderWgt->hide();
			}
			if(!m_pContorlWgt->isHidden()&& m_pPlayer->state() == QMediaPlayer::PlayingState)
			{
				m_pContorlWgt->hide();
			}
		}

	}

	QWidget::mouseMoveEvent(ev);
}

void QPlayer::closeEvent(QCloseEvent* ev)
{
	m_pPlayer->stop();
}

//!显示播放器
void QPlayer::SlotShowWgt(bool)
{
	if(isHidden())
	{
		QDesktopWidget* desktop = QApplication::desktop();
		if(desktop)
		{
			int iCount = desktop->screenCount();
			int iNum = 	desktop->primaryScreen();
			if (iCount > 1)
			{
				for (int iIndex = 0; iIndex < iCount; iIndex++)
				{
					if(iNum != iIndex)
					{
						iNum = iIndex;
						break;
					}
				}
			}

			show();
			this->setGeometry(desktop->screenGeometry(iNum)); 
		}
	}
}

