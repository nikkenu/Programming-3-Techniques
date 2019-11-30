#include "gamegraphicsview.h"

namespace Student {

GameGraphicsView::GameGraphicsView(GameScene* scene, QWidget *parent):
    QGraphicsView(parent),
    m_scene(scene)
{
    setAcceptDrops(true);
    setMinimumSize(500,500);
    setFrameStyle(0);
    setStyleSheet("background:transparent");
    setContextMenuPolicy(Qt::CustomContextMenu);
}

GameGraphicsView::~GameGraphicsView()
{
    delete m_scene;
}

}


