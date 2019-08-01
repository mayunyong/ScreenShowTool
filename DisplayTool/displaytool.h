#ifndef DISPLAYTOOL_H
#define DISPLAYTOOL_H

#include <QtWidgets/QMainWindow>
#include "ui_displaytool.h"
#include "PlayData.h"

class DisplayTool : public QMainWindow
{
	Q_OBJECT

public:
	DisplayTool(QWidget *parent = 0);
	~DisplayTool();

private:
	Ui::DisplayToolClass ui;

	
	
private:
	void InitHomeBtns();

private slots:
	//�������ť
	void SlotClkBtnIndex(int iBtnIndex);
	void SlotShowHomePage();
	void SlotShowPlayData(QPlayData* pPlayData,  int iIndex);
	void SlotShowBackPage();
private:
	//����������
	CPlayData m_playData;
	//!��ťҳ��map
	QMap<int, QBtnListWdgt*> m_BtnPageMap;
};

#endif // DISPLAYTOOL_H
