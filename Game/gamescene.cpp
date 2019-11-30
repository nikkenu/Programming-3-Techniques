#include "gamescene.h"
#include "objectmanager.h"
#include <QEvent>
#include <QGraphicsSceneMouseEvent>

#include <math.h>

namespace Student {


GameScene::GameScene(QWidget* parent,
                                 int width,
                                 int height,
                                 int scale):
    QGraphicsScene(parent),
    m_mapBoundRect(nullptr),
    m_width(10),
    m_height(10),
    m_scale(50)
{
    setSize(width, height);
    setScale(scale);
}

GameScene::~GameScene()
{
    delete m_mapBoundRect;
    delete m_menu;
    delete m_cursor;
}

void GameScene::setSize(int width, int height)
{
    if ( width >= SCENE_MAX_WIDTH.first && width <= SCENE_MAX_WIDTH.second )
    {
        m_width = width;
    }
    if ( height >= SCENE_MAX_HEIGHT.first && height <= SCENE_MAX_HEIGHT.second )
    {
        m_height = height;
    }
    resize();
}

void GameScene::setScale(int scale)
{
    if ( scale >= SCENE_MAX_SCALE.first && scale <= SCENE_MAX_SCALE.second )
    {
        m_scale = scale;
    }
    resize();
}

void GameScene::resize()
{
    if ( m_mapBoundRect != nullptr )
    {
        QGraphicsScene::removeItem(m_mapBoundRect);
    }

    // Left upper corner coords and then width and height
    QRect rect = QRect(0, 0, m_width * m_scale - 1, m_height * m_scale - 1);

    addRect(rect, QPen(Qt::black));
    setSceneRect(rect);
    m_mapBoundRect = itemAt(rect.topLeft(), QTransform());
    // Draw on the bottom of all items
    m_mapBoundRect->setZValue(-1);
}

int GameScene::getScale() const
{
    return m_scale;
}

std::pair<int, int> GameScene::getSize() const
{
    return {m_width, m_height};
}

void GameScene::updateItem(std::shared_ptr<Course::GameObject> obj)
{
    QList<QGraphicsItem*> items_list = items();
    if ( items_list.size() == 1 )
    {
        qDebug() << "Nothing to update.";
    } else {
        for ( auto item : items_list )
        {
            MapItem* mapItem = static_cast<MapItem*>(item);
            if (mapItem->isSameObj(obj))
            {
                mapItem->updateLoc();
            }
        }
    }
}

bool GameScene::event(QEvent *event)
{
    if(event->type() == QEvent::GraphicsSceneMousePress)
    {
        QGraphicsSceneMouseEvent* mouse_event =
                dynamic_cast<QGraphicsSceneMouseEvent*>(event);

        if ( sceneRect().contains(mouse_event->scenePos()) && mouse_event->button() == Qt::RightButton)
        {

            QPointF point = mouse_event->scenePos() / m_scale;

            point.rx() = floor(point.rx());
            point.ry() = floor(point.ry());

            QGraphicsItem* pressed = itemAt(point * m_scale, QTransform());

            if ( pressed != m_mapBoundRect )
            {
                contextMenu(point);
                return true;
            }

        }
    } else if (event->type() == QEvent::GraphicsSceneDrop)

    {
        QGraphicsSceneDragDropEvent* drop = dynamic_cast<QGraphicsSceneDragDropEvent*>(event);
        if(sceneRect().contains(drop->scenePos()))
        {
            QPointF point = drop->scenePos() / m_scale;
            point.rx() = floor(point.rx());
            point.ry() = floor(point.ry());

            QGraphicsItem* item = itemAt(point * m_scale, QTransform());
            if(item != m_mapBoundRect)
            {
                Student::MapItem* mapItem = static_cast<Student::MapItem*>(item);
                QString dropType = drop->mimeData()->text();
                Student::StaticStorage::Items itemAsEnum = Student::StaticStorage::getInstance().getItemNameAsEnum(dropType);

                if(Student::StaticStorage::getInstance().getWorkers().contains(itemAsEnum))
                {
                    if(m_objectManager->createWorker(dropType, point, m_objectManager))
                    {
                        mapItem->addWorker(Student::StaticStorage::getInstance().getItemPixmap(Student::StaticStorage::getInstance().getItemNameAsEnum(dropType)), dropType);
                        views().at(0)->viewport()->repaint();
                    }
                }

                if(Student::StaticStorage::getInstance().getBuildings().contains(itemAsEnum))
                {
                    if (m_objectManager->createBuilding(dropType, point, m_objectManager))
                    {
                        mapItem->addBuilding(Student::StaticStorage::getInstance().getItemPixmap(Student::StaticStorage::getInstance().getItemNameAsEnum(dropType)), dropType);
                        views().at(0)->viewport()->repaint();
                    }
                }
            }
        }
        emit this->resetLCDsignal();
        return true;
    }
    return false;
}



void GameScene::addObjectManager(std::shared_ptr<ObjectManager> objectManager)
{
    m_objectManager = objectManager;
}

void GameScene::contextMenu(QPointF point)
{
    QPointF newPoint = point;
    point.rx() = floor(point.rx());
    point.ry() = floor(point.ry());

    QGraphicsItem* item = itemAt(newPoint * m_scale, QTransform());
    Student::MapItem* mapItem = static_cast<Student::MapItem*>(item);

    m_menu = new QMenu();

    QAction *buildingInfo = new QAction("Tile information...", this);
    QObject::connect(buildingInfo, &QAction::triggered, std::bind(&GameScene::checkTileInformation, this, mapItem));
    m_menu->addAction(buildingInfo);

    if(mapItem->checkForBuildings())
    {
        QAction *removeAct = new QAction("Remove building", this);
        QObject::connect(removeAct, &QAction::triggered, std::bind(&GameScene::removeBuildingFromTile, this, newPoint, mapItem));
        m_menu->addAction(removeAct);
    }
    m_cursor = new QCursor();
    m_menu->exec(m_cursor->pos());

}

void GameScene::removeBuildingFromTile(QPointF point, MapItem* mapItem)
{
    if (m_objectManager->sellBuilding(point))
    {
        mapItem->removeBuilding();
        views().at(0)->viewport()->repaint();
    }
    emit this->resetLCDsignal();
}

void GameScene::checkTileInformation(MapItem *mapItem)
{
    QMessageBox msgBox;
    msgBox.setWindowTitle("Tile information");
    if(!mapItem->checkForBuildings())
    {
        msgBox.setText("Tile is empty.");
    }
    else
    {
        if(mapItem->checkForWorkers())
        {
            msgBox.setText("Tile has building and worker(s) on it.");
            QString workers = "Worker(s): ";
            for(QString workerName : mapItem->getWorkerNames())
            {
                workers += " " + workerName;
            }
            msgBox.setInformativeText("Building: " + mapItem->getBuildingName() + "\n" + workers);
        }
        else
        {
            msgBox.setText("Tile has building on it");
            msgBox.setInformativeText("Building: " + mapItem->getBuildingName());
        }
    }
    msgBox.exec();
}


void GameScene::removeItem(std::shared_ptr<Course::GameObject> obj)
{
    QList<QGraphicsItem*> items_list = items(obj->getCoordinate().asQpoint());
    if ( items_list.size() == 1 ){
        qDebug() << "Nothing to be removed at the location pointed by given obj.";
    } else {
        for ( auto item : items_list ){
            MapItem* mapitem = static_cast<MapItem*>(item);
            if ( mapitem->isSameObj(obj) ){
                delete mapitem;
            }
        }
    }
}

void GameScene::drawItem( std::shared_ptr<Course::GameObject> obj)
{
    MapItem* nItem = new MapItem(obj, m_scale);
    addItem(nItem);
}

}
