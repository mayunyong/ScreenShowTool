#include "QHomeWgt.h"
#include "QHome1Btn_1080.h"
#include "QHome2Btn_1080.h"
#include "QHome3Btn_1080.h"
#include "QHome4Btn_1080.h"
#include "QHome5Btn_1080.h"
#include "QGlobalSystemConfig.h"

QHomeWgt::QHomeWgt(QWidget *parent)
	: QBGBaseWgt(parent)
{
	ui.setupUi(this);
	//InitHomeButton();
	m_ePageType = Page_Home;
	QString strValue = ":/DisplayTool/HomePage.png";

	#ifdef SCRENN_1280_800
		strValue = ":/DisplayTool_1280/HomePage.png";
	#endif // _DEBUG

	
	m_pBackGroundixmap= new QPixmap(strValue);

	QMap<int, QPoint> posMap = QGlobalSystemConfig::Instance()->GetHomeBtnPosMap();

	AddNewBtn(new QHome1Btn_1080(this), posMap.contains(1)? posMap[1]:QPoint(105, 210));
	AddNewBtn(new QHome2Btn_1080(this), posMap.contains(2)? posMap[2]:QPoint(448, 62));
	AddNewBtn(new QHome3Btn_1080(this), posMap.contains(3)? posMap[3]:QPoint(836, 255));
	AddNewBtn(new QHome4Btn_1080(this), posMap.contains(4)? posMap[4]:QPoint(714, 610));
	AddNewBtn(new QHome5Btn_1080(this),posMap.contains(5)? posMap[5]: QPoint(130, 720));

	connect(ui.toolButton_3, SIGNAL(clicked()), this, SIGNAL(SignalMin()));
	connect(ui.tBtn_Close, SIGNAL(clicked()), this, SIGNAL(SignalClose()));
	connect(ui.tBtn_Set, SIGNAL(clicked()), this, SIGNAL(SignalSet()));
}

QHomeWgt::~QHomeWgt()
{

}

void QHomeWgt::InitAllButton()
{

	////!首页有5个按钮，并且位置固定
	//if(!m_bInifFlag)
	//{
	//	AddNewBtn(QPoint(105, 210));
	//	AddNewBtn(QPoint(448, 62));
	//	AddNewBtn(QPoint(836, 255));
	//	AddNewBtn(QPoint(714, 610));
	//	AddNewBtn(QPoint(130, 720));

	//	m_bInifFlag = true;
	//}
	if(!m_pPlayInfo)
	{
		return;
	}


	ShowPage(1);
	/*if(m_pPlayInfo->playData && m_pPlayInfo->playData->children.size() > 0)
	{
		QMap<int, QVector<QPlayInfo*>>::const_iterator itr =  m_pPlayInfo->playData->children.constBegin();
		const QVector<QPlayInfo*>& vecPlayInfo = itr.value();

		for (int index = 0; index < vecPlayInfo.size(); index++)
		{
			const int& iNum = vecPlayInfo[index]->dispalyID;
			if(m_VideoBtnMap.contains(iNum) && m_VideoBtnMap[iNum])
			{
				m_VideoBtnMap[iNum]->setPlayData(iNum, vecPlayInfo[index]);
			}
		}
	}*/

}

