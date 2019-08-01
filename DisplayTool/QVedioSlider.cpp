#include "QVedioSlider.h"
#include <QMouseEvent>

QVedioSlider::QVedioSlider(QWidget *parent)
	: QSlider(parent)
{

}

QVedioSlider::~QVedioSlider()
{

}

void QVedioSlider::mousePressEvent(QMouseEvent *ev)
{
	if (ev->button()|Qt::LeftButton && !isSliderDown())
	{
		int iWidth = width();
		QPoint posPnt =  ev->pos();
	
		if(iWidth > 10)
		{
			int iPos = posPnt.x() * maximum()/iWidth;
			setValue(iPos);
			emit valueClkChanged(iPos);
		}
	}

	QSlider::mousePressEvent(ev);
}
