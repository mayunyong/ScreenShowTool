#include "QSecondBtn9_1080.h"

QSecondBtn9_1080::QSecondBtn9_1080(QWidget *parent)
	: QSecondBaseBtn(parent)
{
	ui.setupUi(this);
	m_pNOLabel = ui.label;
	m_pNameLabel = ui.label2;
}

QSecondBtn9_1080::~QSecondBtn9_1080()
{

}
