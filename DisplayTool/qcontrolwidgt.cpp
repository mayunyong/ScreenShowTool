#include "qcontrolwidgt.h"
#include <QTime>

QControlWidgt::QControlWidgt(QWidget *parent, QMediaPlayer *pPlayer)
	: QWidget(parent)
	,m_pPlayer(pPlayer)
	,m_iduration(0)
{
	ui.setupUi(this);

	connect(ui.horizontalSlider, SIGNAL(sliderMoved(int)), this, SLOT(seek(int)));
	connect(ui.horizontalSlider, SIGNAL(valueClkChanged(int)), this, SLOT(seek(int)));

	ui.playButton->setEnabled(false);
	ui.playButton->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
	connect(ui.playButton, SIGNAL(clicked()), this, SLOT(slotPlayBtn()));
	ui.volumeSlider->setRange(0, 100);

	ui.volumeButton->setIcon(style()->standardIcon(QStyle::SP_MediaVolume));
	connect(ui.volumeButton, SIGNAL(clicked()), this, SLOT(SlotVolume()));
	connect(ui.volumeSlider, SIGNAL(sliderMoved(int)), m_pPlayer, SLOT(setVolume(int)));
	connect(ui.volumeSlider, SIGNAL(valueClkChanged(int)), m_pPlayer, SLOT(setVolume(int)));
	ui.volumeSlider->setValue(100);

	connect(m_pPlayer, SIGNAL(positionChanged(qint64)), this, SLOT(positionChanged(qint64)));
	connect(m_pPlayer, SIGNAL(durationChanged(qint64)), this, SLOT(durationChanged(qint64)));
	connect(m_pPlayer, SIGNAL(stateChanged(QMediaPlayer::State)),
			this, SLOT(mediaStateChanged(QMediaPlayer::State)));
}

QControlWidgt::~QControlWidgt()
{

}

//!��ʼ��������Ϣ
void QControlWidgt::InitStartPlay()
{
	if(m_pPlayer)
	{
		ui.playButton->setEnabled(true);
		ui.horizontalSlider->setRange(0, m_pPlayer->duration() / 1000);
		int iVolume = ui.volumeSlider->value();
		m_pPlayer->setVolume(iVolume);
	}
}

//!��Ƶ���ȸı�
void QControlWidgt::positionChanged(qint64 iPos)
{
	if (!ui.horizontalSlider->isSliderDown()) 
	{
		ui.horizontalSlider->setValue(iPos / 1000);
	}

	updateDurationInfo(iPos / 1000);
}

//��������ʱ���ı�
void QControlWidgt::durationChanged(qint64 iPos)
{
	m_iduration = iPos/1000;
	ui.horizontalSlider->setMaximum(iPos / 1000);
}

//������״̬�ı�
void QControlWidgt:: mediaStateChanged(QMediaPlayer::State ePlayState)
{
	switch(ePlayState) {
	case QMediaPlayer::PlayingState:
		{
			ui.playButton->setIcon(style()->standardIcon(QStyle::SP_MediaPause));
		}
		break;
	case QMediaPlayer::StoppedState:
		{
			ui.playButton->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
			emit SignalVideoPlayFinish();
		}
		break;
	default:
		ui.playButton->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
		break;
	}
}

//�����������ť��������
void QControlWidgt::SlotVolume()
{
	if(!m_pPlayer)
	{
		return;
	}

	bool bMuted = m_pPlayer->isMuted();
	m_pPlayer->setMuted(!bMuted);
	ui.volumeButton->setIcon(style()->standardIcon(!bMuted
		? QStyle::SP_MediaVolumeMuted
		: QStyle::SP_MediaVolume));
}

//�����µ�ǰ����ʱ��
void QControlWidgt::updateDurationInfo(qint64 i_currentInfo)
{
	QString tStr;
	if (i_currentInfo || m_iduration) {
		QTime currentTime((i_currentInfo/3600)%60, (i_currentInfo/60)%60, i_currentInfo%60, (i_currentInfo*1000)%1000);
		QTime totalTime((m_iduration/3600)%60, (m_iduration/60)%60, m_iduration%60, (m_iduration*1000)%1000);
		QString format = "mm:ss";
		if (m_iduration > 3600)
			format = "hh:mm:ss";
		tStr = currentTime.toString(format) + " / " + totalTime.toString(format);
	}

	ui.timeLabel->setText(tStr);
}

//!���ò��Ž���
void QControlWidgt::seek(int iPos)
{
	if(!m_pPlayer)
	{
		return;
	}
	m_pPlayer->setPosition(iPos * 1000);
}

//��������Ű�ť
void QControlWidgt::slotPlayBtn()
{
	if(!m_pPlayer)
	{
		return;
	}

	switch(m_pPlayer->state()) {
	case QMediaPlayer::PlayingState:
		m_pPlayer->pause();
		break;
	default:
		m_pPlayer->play();
		break;
	}
}