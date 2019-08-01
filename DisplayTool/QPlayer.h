#ifndef QPLAYER_H
#define QPLAYER_H

#include <QWidget>
#include "ui_QPlayer.h"
#include <QMediaPlayer>
#include <QVideoWidget>
class QCloseEvent;
class QHeaderWgt;
class QControlWidgt;

class QPlayer : public QWidget
{
	Q_OBJECT

public:
	QPlayer(QWidget *parent = 0);
	~QPlayer();

public:
	//！播放指定目录视频
	void PlayVideo(QString& strVideoPath);

private:
	Ui::QPlayer ui;

	//视频播放器
	QMediaPlayer *m_pPlayer;
	//！视频路径
	QString m_strVideoPath;
	//！头部控件
	QHeaderWgt* m_pHeaderWgt;
	//！底部控制控件
	QControlWidgt* m_pContorlWgt;
	
private:
	void mouseMoveEvent(QMouseEvent *ev);
	void closeEvent(QCloseEvent* ev);
};

#endif // QPLAYER_H
