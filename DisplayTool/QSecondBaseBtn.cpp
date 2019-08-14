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
	if(!m_pPlayData)
	{
		return;
	}

	if(m_pNOLabel)
	{
		QFont font = m_pNOLabel->font();
		font.setItalic(true);//Ğ±Ìå
		m_pNOLabel->setFont(font);
		//m_pNOLabel->set
		m_pNOLabel->setText(QString("%1").arg(m_pPlayData->displayNum));
	}
	if(m_pNameLabel)
	{
		m_pNameLabel->setText(m_pPlayData->displayName);
	}
	if(QPlayInfo::file == m_pPlayData->fileType)
	{
		m_pNameLabel->setStyleSheet(QStringLiteral("background:transparent;color: white;font: 15px \"Î¢ÈíÑÅºÚ\";"));
	}
	else
	{
		m_pNameLabel->setStyleSheet(QStringLiteral("background:transparent;color: #02e4fa;font: 15px \"Î¢ÈíÑÅºÚ\";"));
	}
	show();
}
