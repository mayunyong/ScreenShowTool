#ifndef QVEDIOSLIDER_H
#define QVEDIOSLIDER_H

#include <QSlider>
class QMouseEvent;

class QVedioSlider : public QSlider
{
	Q_OBJECT

public:
	QVedioSlider(QWidget *parent);
	~QVedioSlider();

signals:
	//£¡µã»÷ÐÅºÅ
	void valueClkChanged(int iValue);

private:
	void mousePressEvent(QMouseEvent *ev);
};

#endif // QVEDIOSLIDER_H
