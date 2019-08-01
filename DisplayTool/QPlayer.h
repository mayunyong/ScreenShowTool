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
	//������ָ��Ŀ¼��Ƶ
	void PlayVideo(QString& strVideoPath);

private:
	Ui::QPlayer ui;

	//��Ƶ������
	QMediaPlayer *m_pPlayer;
	//����Ƶ·��
	QString m_strVideoPath;
	//��ͷ���ؼ�
	QHeaderWgt* m_pHeaderWgt;
	//���ײ����ƿؼ�
	QControlWidgt* m_pContorlWgt;
	
private:
	void mouseMoveEvent(QMouseEvent *ev);
	void closeEvent(QCloseEvent* ev);
};

#endif // QPLAYER_H
