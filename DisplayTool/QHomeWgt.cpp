#include "QHomeWgt.h"

QHomeWgt::QHomeWgt(QWidget *parent)
	: QBGBaseWgt(parent)
{
	ui.setupUi(this);
	//InitHomeButton();
	m_ePageType = Page_Home;
	m_pBackGroundixmap= new QPixmap(":/DisplayTool/HomePage.png");
}

QHomeWgt::~QHomeWgt()
{

}

void QHomeWgt::InitAllButton()
{
	//!首页有5个按钮，并且位置固定
	if(!m_bInifFlag)
	{
		AddNewBtn(QPoint(105, 210));
		AddNewBtn(QPoint(448, 62));
		AddNewBtn(QPoint(836, 255));
		AddNewBtn(QPoint(714, 610));
		AddNewBtn(QPoint(130, 720));

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

