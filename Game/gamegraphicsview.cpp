#include "gamegraphicsview.h"

namespace Student {

GameGraphicsView::GameGraphicsView(GameScene* scene, QWidget *parent):
    QGraphicsView(parent)
{
    setAcceptDrops(true);
    m_scene = scene;
    setMinimumSize(500,500);
    setFrameStyle(0);
}

void GameGraphicsView::dropEvent(QDropEvent *event)
{
    event->acceptProposedAction();
    qDebug() << event->mimeData()->text();
    //qDebug() << event->pos();
}

}


