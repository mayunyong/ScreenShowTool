#include "QvideoListTree.h"
#include "QFileInfo"
#include "qtreedefmodel.h"
#include <QMessageBox>
#include "QPlayer.h"
#include "PlayData.h"


QvideoListTree::QvideoListTree(QWidget *parent)
	: QWidget(parent)
	,m_pPlayer(NULL)
	,m_pPlayData(NULL)
	,m_pPlayerModel(NULL)
{
	ui.setupUi(this);
	m_pPlayerModel = new QtreeDefModel(ui.treeView);
	m_pPlayer = new QPlayer();

	ui.treeView->setHeaderHidden(true);
	connect(ui.treeView, SIGNAL(clicked(const QModelIndex &)), this, SLOT(SlotClkVideo(const QModelIndex &)));
}

QvideoListTree::~QvideoListTree()
{
	if(m_pPlayer)
	{
		m_pPlayer->deleteLater();
	}
}

//!点击视频
void QvideoListTree::SlotClkVideo(const QModelIndex &index)
{
	QPlayData* stVedioDate = (QPlayData*)index.internalPointer();
	if(stVedioDate && stVedioDate->isExist)
	{
		QString strValue = stVedioDate->filePath;
		//strValue = QStringLiteral("I:\\电视剧\\余罪第二季01.mp4");
		
		if(!QFileInfo::exists(strValue))
		{
			QMessageBox::warning(NULL, QStringLiteral("警告"), QStringLiteral("视频文件不存在,请浏览其他视频！"));
		}
		else if(m_pPlayer)
		{
			m_pPlayer->PlayVideo(strValue);
		}
	}
}

//！设置播放数据
void QvideoListTree::setPlayData(QPlayData* pPlayData)
{
	if(pPlayData && m_pPlayerModel)
	{
		ui.treeView->reset();

		m_pPlayData = pPlayData;
		m_pPlayerModel->setPlayerData(pPlayData);

		ui.treeView->setModel(m_pPlayerModel);
	}
}