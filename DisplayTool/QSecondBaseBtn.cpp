#include "QSecondBaseBtn.h"

QSecondBaseBtn::QSecondBaseBtn(QWidget *parent)
	: QVideoBaseBtn(parent)
	,m_pNOLabel(NULL)
	,m_pNameLabel(NULL)
{
	
}

QSecondBaseBtn::~QSecondBaseBtn()
{

}

void QSecondBaseBtn::ShowPlayData()
{
	if(!m_pPlayData || !m_pNOLabel || !m_pNameLabel)
	{
		return;
	}

	m_pNOLabel->setText(QString("%1").arg(m_pPlayData->displayNum));
	m_pNameLabel->setText(m_pPlayData->displayName);

	if(QPlayInfo::file == m_pPlayData->fileType)
	{
		m_pNameLabel->setStyleSheet(QStringLiteral("background:transparent;color: white;font: 15px \"΢���ź�\";"));
	}
	else
	{
		m_pNameLabel->setStyleSheet(QStringLiteral("background:transparent;color: #02e4fa;font: 15px \"΢���ź�\";"));
	}

	show();
}
