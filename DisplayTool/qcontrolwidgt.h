#ifndef QCONTROLWIDGT_H
#define QCONTROLWIDGT_H

#include <QWidget>
#include "ui_qcontrolwidgt.h"
#include <QMediaPlayer>
class QControlWidgt : public QWidget
{
	Q_OBJECT

public:
	QControlWidgt(QWidget *parent = 0, QMediaPlayer *m_pPlayer = NULL);
	~QControlWidgt();

	void InitStartPlay();
private:
	Ui::QControlWidgt ui;

signals:
	void SignalVideoPlayFinish();

public slots:
		//！位置改变
		void positionChanged(qint64 iPos);
		//！时长改变
		void durationChanged(qint64 iPos);
		//!设置声音
		void SlotVolume();
		//!更新当前时间
		void updateDurationInfo(qint64 i_currentInfo);
		//！拖到指定位置
		void seek(int iPos);
		//！播放
		void slotPlayBtn();
		//！播放状态改变
		void mediaStateChanged(QMediaPlayer::State ePlayState);

private:
	//！播放器
	QMediaPlayer *m_pPlayer;
	//！当前时长
	qint64 m_iduration;
};

#endif // QCONTROLWIDGT_H
