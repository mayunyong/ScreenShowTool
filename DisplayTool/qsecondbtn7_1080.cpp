#include "qsecondbtn7_1080.h"

QSecondBtn7_1080::QSecondBtn7_1080(QWidget *parent)
	: QSecondBaseBtn(parent)
{
	ui.setupUi(this);
	m_pNOLabel = ui.label;
	m_pNameLabel = ui.label_2;
}

QSecondBtn7_1080::~QSecondBtn7_1080()
{

}
