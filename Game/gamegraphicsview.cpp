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

}


