#include "gamegraphicsview.h"

namespace Student {

GameGraphicsView::GameGraphicsView(GameScene* scene, QWidget *parent):
    QGraphicsView(parent)
{
    setAcceptDrops(true);
    m_scene = scene;
}

void GameGraphicsView::dragEnterEvent(QDragEnterEvent *event)
{
    event->accept();
}

void GameGraphicsView::dropEvent(QDropEvent *event)
{
    event->acceptProposedAction();
    qDebug() << event->pos();
}

}


