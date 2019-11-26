#ifndef GAMEGRAPHICSVIEW_H
#define GAMEGRAPHICSVIEW_H

#include <QGraphicsView>
#include <QDropEvent>
#include <QDragMoveEvent>
#include <QDragEnterEvent>
#include <QDebug>

#include "gamescene.h"

namespace Student {

/**
 * @brief The GameGraphicsView is a subclass
 * from QGraphicsView. The only reason we made
 * new implementation of QGraphicsView was that
 * this allows Drag & Drop functionality.
 */

class GameGraphicsView : public QGraphicsView
{
public:

    /**
     * @brief Constructor
     * @param scene points to the student's GameScene.
     * @param parent
     */
    GameGraphicsView(GameScene* scene, QWidget *parent = 0);

    ~GameGraphicsView();

private:
    GameScene* m_scene = nullptr;
};

}



#endif // GAMEGRAPHICSVIEW_H
