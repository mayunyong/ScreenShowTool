#include "QHeaderWgt.h"

QHeaderWgt::QHeaderWgt(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	connect(ui.closeButton_2, SIGNAL(clicked()), this, SIGNAL(SignCloseWdgt()));
}

QHeaderWgt::~QHeaderWgt()
{

}
