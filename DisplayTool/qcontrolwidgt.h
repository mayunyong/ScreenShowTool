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
		//��λ�øı�
		void positionChanged(qint64 iPos);
		//��ʱ���ı�
		void durationChanged(qint64 iPos);
		//!��������
		void SlotVolume();
		//!���µ�ǰʱ��
		void updateDurationInfo(qint64 i_currentInfo);
		//���ϵ�ָ��λ��
		void seek(int iPos);
		//������
		void slotPlayBtn();
		//������״̬�ı�
		void mediaStateChanged(QMediaPlayer::State ePlayState);

private:
	//��������
	QMediaPlayer *m_pPlayer;
	//����ǰʱ��
	qint64 m_iduration;
};

#endif // QCONTROLWIDGT_H
