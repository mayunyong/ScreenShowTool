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
	//！点击按钮
	void SlotClkBtnIndex(int iBtnIndex);
	void SlotShowHomePage();
	void SlotShowPlayData(QPlayData* pPlayData,  int iIndex);
	void SlotShowBackPage();
private:
	//！播放数据
	CPlayData m_playData;
	//!按钮页面map
	QMap<int, QBtnListWdgt*> m_BtnPageMap;
};

#endif // DISPLAYTOOL_H
