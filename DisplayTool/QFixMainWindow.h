#ifndef QFIXMAINWINDOW_H
#define QFIXMAINWINDOW_H

#include <QMainWindow>
#include "ui_QFixMainWindow.h"
#include "QRect"
#include "PlayData.h"
#include "QPlayer.h"
#include <QFileDialog>

class QFixMainWindow : public QMainWindow
{
	Q_OBJECT

public:
	QFixMainWindow(QWidget *parent = 0);
	~QFixMainWindow();

public:
	//!��ʾ��ҳ
	void ShowHomePage();

private slots:
	//!���ĳ��ָ����ť
	void SlotClkIndexBtn(const QPlayInfo* pStPlayDta);
	void SlotConfigPath();

private:
	Ui::QFixMainWindow ui;
	QRect m_DeskRect;
	//!��������
	CPlayData* m_pPlayDataObj;
	QPlayInfo* m_pAllPlayInfo;
	//!ѡ�񴰿�
	QFileDialog *m_pFileDlg;

	//��������
	QPlayer* m_pPlayer;
};

#endif // QFIXMAINWINDOW_H
