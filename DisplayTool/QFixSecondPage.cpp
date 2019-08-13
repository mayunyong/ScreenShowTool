#include "QFixSecondPage.h"

QFixSecondPage::QFixSecondPage(QWidget *parent)
	: QBGBaseWgt(parent)
{
	ui.setupUi(this);
	//InitHomeButton();
	m_ePageType = Page_Second;
	m_pBackGroundixmap= new QPixmap(":/DisplayTool/SecondPage.png");
}

QFixSecondPage::~QFixSecondPage()
{

}

void QFixSecondPage::InitAllButton()
{
	//!首页有5个按钮，并且位置固定
	//show();
	if(!m_bInifFlag)
	{
		AddNewBtn(QPoint(86, 287));
		AddNewBtn(QPoint(443, 159));
		AddNewBtn(QPoint(811, 261));
		AddNewBtn(QPoint(1149, 181));
		AddNewBtn(QPoint(1505, 271));
		AddNewBtn(QPoint(86, 647));
		AddNewBtn(QPoint(497, 607));
		AddNewBtn(QPoint(975, 611));
		AddNewBtn(QPoint(1409, 639));

		m_bInifFlag = true;
	}


	if(m_pPlayData->children.size() > 0)
	{
		QMap<int, QVector<QPlayInfo*>>::const_iterator itr =  m_pPlayData->children.constBegin();
		const QVector<QPlayInfo*>& vecPlayInfo = itr.value();

		for (int index = 0; index < vecPlayInfo.size(); index++)
		{
			const int& iNum = vecPlayInfo[index]->dispalyID;
			if(m_VideoBtnMap.contains(iNum) && m_VideoBtnMap[iNum])
			{
				m_VideoBtnMap[iNum]->setPlayData(iNum, vecPlayInfo[index]);
			}
		}
	}

}