#include "QCenterTextEdit.h"

QCenterTextEdit::QCenterTextEdit(QWidget *parent)
	: QTextEdit(parent)
{
	setAlignment(Qt::AlignCenter);
	setAlignment( Qt::AlignCenter|Qt::AlignBottom|Qt::AlignHCenter );
}

QCenterTextEdit::~QCenterTextEdit()
{

}
