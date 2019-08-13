#include "qhomebtnitem.h"
#include "UserDef.h"

QHomeBtnItem::QHomeBtnItem(QWidget *parent, QSize btnSize)
	: QVideoBaseBtn(parent)
	,m_iBtnIndex(-1)
{
	ui.setupUi(this);
	btnSize.setHeight(btnSize.height() * c_dyBtnImgRadio);
	btnSize.setWidth(btnSize.width() * c_dxBtnImgRadio);
	
	show();
	setFixedSize(btnSize);
	hide();

	/*connect(this, SIGNAL(clicked()), this, SLOT(SlotClickBtn()));
	connect(this, SIGNAL(SignalClkIndexBtn(const QPlayInfo*)), parent, SIGNAL(SignalClkIndexBtn(const QPlayInfo*)));*/
}

QHomeBtnItem::~QHomeBtnItem()
{

}


void QHomeBtnItem::setPlayData(int iBtnIndex, const QPlayInfo* stPlayDta)
{
	QVideoBaseBtn::setPlayData(iBtnIndex, stPlayDta);
	show();
	ui.label->SetIMgText(stPlayDta->displayName);
	//show();
}

void QHomeBtnItem::setUIInfo(EN_PageType ePageType, int iNum, bool bVideoFlag)
{
	//!ÉèÖÃ
	QVideoBaseBtn::setUIInfo(ePageType, iNum, bVideoFlag);
	Qt::AspectRatioMode eRatioMode = Qt::KeepAspectRatio;
	QPixmap * pPixMap= new QPixmap(m_strSrcPath);

	if(pPixMap->height() > height())
	{
		eRatioMode = Qt::KeepAspectRatio;
	}
	ui.label->setPixmap(pPixMap->scaled(ui.label->size(), eRatioMode, Qt::SmoothTransformation));
}

void QHomeBtnItem::SlotClickBtn()
{
	if(m_iBtnIndex > -1 && 
	m_pPlayData && 
	m_pPlayData->playData&&
	m_pPlayData->playData->HaveChild())
	{
		emit SignalClkIndexBtn(m_pPlayData);
	}

	//int ii = 0;
}
