#include "QSecondBtnItem.h"

QSecondBtnItem::QSecondBtnItem(QWidget *parent, QSize btnSize)
	: QHomeBtnItem(parent, btnSize)
{
	btnSize.setHeight(btnSize.height() * c_dxSecondBtnImgRadio);
	btnSize.setWidth(btnSize.width() * c_dySecondBtnImgRadio);

	show();
	setFixedSize(btnSize);
	hide();
}

QSecondBtnItem::~QSecondBtnItem()
{

}
