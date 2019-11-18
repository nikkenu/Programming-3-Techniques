#ifndef GAMEGRAPHICSVIEW_H
#define GAMEGRAPHICSVIEW_H

#include <QGraphicsView>
#include <QDropEvent>
#include <QDragMoveEvent>
#include <QDragEnterEvent>
#include <QDebug>

#include "gamescene.h"

namespace Student {

class GameGraphicsView : public QGraphicsView
{
public:
    GameGraphicsView(GameScene* scene, QWidget *parent = 0);

private:
    GameScene* m_scene = nullptr;
};

}



#endif // GAMEGRAPHICSVIEW_H
