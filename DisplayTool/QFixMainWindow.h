#ifndef QFIXMAINWINDOW_H
#define QFIXMAINWINDOW_H

#include <QMainWindow>
#include "ui_QFixMainWindow.h"
#include "QRect"
#include "PlayData.h"

class QFixMainWindow : public QMainWindow
{
	Q_OBJECT

public:
	QFixMainWindow(QWidget *parent = 0);
	~QFixMainWindow();

public:
	void ShowHomePage();

private slots:
	//!点击某个指定按钮
	void SlotClkIndexBtn(const QPlayInfo* pStPlayDta);

private:
	Ui::QFixMainWindow ui;
	QRect m_DeskRect;
	//!播放数据
	CPlayData m_playDataObj;
	QPlayInfo* m_pAllPlayInfo;
	//QPlayData* m_pPlayData;
};

#endif // QFIXMAINWINDOW_H
