#include "qhomebtnitem.h"
#include "UserDef.h"

QHomeBtnItem::QHomeBtnItem(QWidget *parent, QSize btnSize)
	: QPushButton(parent)
	,m_iBtnIndex(-1)
{
	ui.setupUi(this);
	btnSize.setHeight(btnSize.height() * c_dyBtnImgRadio);
	btnSize.setWidth(btnSize.width() * c_dxBtnImgRadio);
	//setFixedHeight(c_iBGImgWidth);
	setFixedSize(btnSize);
	show();
	//adjustSize();

	ui.label->SetIMgText(QStringLiteral("Éè¼Æ"));
}

QHomeBtnItem::~QHomeBtnItem()
{

}


void QHomeBtnItem::setPlayData(int iBtnIndex, const QPlayData& stPlayDta)
{
	m_iBtnIndex = iBtnIndex;
	//ui.pushButton->setText(stPlayDta.displayName);
	//connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(SlotClickBtn()));
	m_playData = stPlayDta;
	//!
}

void QHomeBtnItem::setUIInfo(EN_PageType m_ePageType, int iNum)
{
	QString strSrcImg = ":/DisplayTool/home1.png";
	if (Page_Home == m_ePageType)
	{
		strSrcImg = QString(":/DisplayTool/home%1.png").arg(iNum + 1);
	}

	//!ÉèÖÃ
	Qt::AspectRatioMode eRatioMode = Qt::KeepAspectRatio;
	QPixmap * pPixMap= new QPixmap(strSrcImg);
	if(pPixMap->height() > height())
	{
		eRatioMode = Qt::KeepAspectRatio;
	}
	ui.label->setPixmap(pPixMap->scaled(ui.label->size(), eRatioMode, Qt::SmoothTransformation));
}

void QHomeBtnItem::SlotClickBtn()
{
	if(m_iBtnIndex > -1 && m_playData.HaveChild())
	{
		emit SignalClkIndexBtn(m_iBtnIndex);
	}
}
