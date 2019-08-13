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
	//!���ĳ��ָ����ť
	void SlotClkIndexBtn(const QPlayInfo* pStPlayDta);

private:
	Ui::QFixMainWindow ui;
	QRect m_DeskRect;
	//!��������
	CPlayData m_playDataObj;
	QPlayInfo* m_pAllPlayInfo;
	//QPlayData* m_pPlayData;
};

#endif // QFIXMAINWINDOW_H
