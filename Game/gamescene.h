#ifndef GAMESCENE_H
#define GAMESCENE_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QDebug>
#include <QMimeData>
#include <QCursor>
#include <QMenu>
#include <QMessageBox>

#include <map>
#include <memory>

#include "core/gameobject.h"
#include "mapitem.h"

namespace Student {

class ObjectManager;

const std::pair<int, int> SCENE_MAX_WIDTH = {1, 100};
const std::pair<int, int> SCENE_MAX_HEIGHT = {1, 100};
const std::pair<int, int> SCENE_MAX_SCALE = {1, 500};

/**
 * @brief The GameScene is a custom QGraphicsScene that shows
 * the rendering of the game map.
 */
class GameScene : public QGraphicsScene
{
    Q_OBJECT

signals:

    /**
     * @brief Emitted when player uses his/hers resources or
     * removes a building. Recieced in class MainWindow.
     * @see reserLCDslot at Mainwindow.
     */
    void resetLCDsignal();

public:
    /**
         * @brief Constructor for the class.
         *
         * @param qt_parent points to the parent object per Qt's parent-child-system.
         * @param width in tiles for the game map.
         * @param height in tiles for the game map.
         * @param scale is the size in pixels of a single square tile.
         *
         * @pre 0 < width <= 100 && 0 < height <= 100 && 0 < scale <= 500. Otherwise
         * default values are used for the created object.
         */
    GameScene(QWidget* qt_parent = nullptr,
              int width = 10,
              int height = 10,
              int scale = 50
      );
    /**
     * @brief Destructor.
     */
    ~GameScene();

    void setSize(int width, int height);

    /**
     * @brief set the tile size, aka scale of the map and calls resize().
     * Function behaviour after objects has been drawn is not specified.
     * @param scale in pixels.
     * @pre 0 < scale <= 500
     * @post Scene scale is set to scale.
     * @post Exception guarantee: None
     */
    void setScale(int scale);

    /**
     * @brief resize recalculates the bounding rectangle
     */
    void resize();

    /**
     * @brief get the size of a single tile
     * @return the size of a tile in pixels.
     * @post Exception guarantee: No-throw
     */
    int getScale() const;

    /**
     * @brief get the size of the map.
     * @return pair<width, height> in tiles.
     * @post Exception guarantee: No-throw
     */
    std::pair<int,int> getSize() const;

    /**
     * @brief draw a new item to the map.
     * @param obj shared ptr to the object
     * @pre obj must have a valid coordinate property.
     * @post Exception guarantee: None
     */
    void drawItem( std::shared_ptr<Course::GameObject> obj);

    /**
     * @brief tries to remove drawn object at the location obj points to.
     * If there's multiple objects, will remove the one that matches obj.
     * @param obj shared ptr to the object being deleted.
     * @post Exception guarantee: None
     *
     */
    void removeItem( std::shared_ptr<Course::GameObject> obj);

    /**
     * @brief updates the position of obj.
     * @param obj shared ptr to the obj being updated.
     */
    void updateItem( std::shared_ptr<Course::GameObject> obj);

    /**
     * @brief simple event handler that notifies when objects or the play
     * area is clicked.
     * @param event that has happened.
     * @return True: if event was  handled in the handler.
     * False: if the event handling was passed over.
     */
    bool event(QEvent* event);

    /**
     * @brief Adds pointer to the student's ObjectManager.
     * @param objectManager points to the student's ObjectManager.
     * @post Exception guarantee: No-throw.
     */
    void addObjectManager(std::shared_ptr<ObjectManager> objectManager);

    /**
     * @brief contextMenu is called when player right-clicks on a tile and opens a menu.
     * If there's a buildig on the tile, the menu has options "Tile information" and
     * "Remove building", if not it has only the first one. On clicking "Tile information"
     * a new window opens that tells the tile's owner and possible building-types on the tile
     * and workes on the building if it has any.
     * @param point position on scene divided by scale.
     * @post Exception guarantee: No-throw.
     */
    void contextMenu(QPointF point);

public slots:

    /**
     * @brief Recieves a signal from contextMenu when player chooses to
     * sell a building.Calls sellBuilding from ObejctManager.
     * @param point is the coordinate of the building to be sold.
     * @param mapItem point's to the building to be sold.
     * @post Exception guarantee: No-throw.
     * @see sellBuilding from ObjectManager.
     */
    void removeBuildingFromTile(QPointF point, MapItem* mapItem);

    /**
     * @brief Opens a messagebox when player chooses to wiew tile's information.
     * @param mapItem points to the tile where player right-clicked.
     */
    void checkTileInformation(MapItem* mapItem);

private:
    QCursor* m_cursor;
    QMenu* m_menu;
    QGraphicsItem* m_mapBoundRect;
    std::shared_ptr<ObjectManager> m_objectManager = nullptr;
    int m_width;
    int m_height;
    int m_scale;
};
}



#endif // GAMESCENE_H
