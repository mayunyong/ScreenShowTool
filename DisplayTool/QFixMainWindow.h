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
	//!显示首页
	void ShowHomePage();

private slots:
	//!点击某个指定按钮
	void SlotClkIndexBtn(const QPlayInfo* pStPlayDta);
	void SlotConfigPath();

private:
	Ui::QFixMainWindow ui;
	QRect m_DeskRect;
	//!播放数据
	CPlayData* m_pPlayDataObj;
	QPlayInfo* m_pAllPlayInfo;
	//!选择窗口
	QFileDialog *m_pFileDlg;

	//！播放器
	QPlayer* m_pPlayer;
};

#endif // QFIXMAINWINDOW_H
