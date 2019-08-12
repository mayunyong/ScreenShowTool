#include "QFixMainWindow.h"
#include "QApplication"
#include "QDesktopWidget"

QFixMainWindow::QFixMainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	//!获取默认屏幕大小
	QDesktopWidget* desktop = QApplication::desktop();
	m_DeskRect = desktop->screenGeometry(-1);
}

QFixMainWindow::~QFixMainWindow()
{

}

void QFixMainWindow::ShowHomePage()
{
	show();
	//m_DeskRect = QRect(100,200,800, 450);
	this->setGeometry(m_DeskRect); 
	ui.page->InitUIInfo(m_DeskRect);
}
