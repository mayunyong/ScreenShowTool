#include "QSecondBtn3_1080.h"

QSecondBtn3_1080::QSecondBtn3_1080(QWidget *parent)
	: QSecondBaseBtn(parent)
{
	ui.setupUi(this);
	m_pNOLabel = ui.label;
	m_pNameLabel = ui.label_2;
}

QSecondBtn3_1080::~QSecondBtn3_1080()
{

}
