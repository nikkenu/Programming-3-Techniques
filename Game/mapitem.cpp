#include "mapitem.h"


namespace Student {

std::map<std::string, QColor> MapItem::c_mapcolors = {};

MapItem::MapItem(const std::shared_ptr<Course::GameObject> &obj, int size ):
    m_gameobject(obj), m_scenelocation(m_gameobject->getCoordinatePtr()->asQpoint()), m_size(size)
{
    addNewColor(m_gameobject->getType());
}

QRectF MapItem::boundingRect() const
{
    return QRectF(m_scenelocation * m_size, m_scenelocation * m_size + QPoint(m_size, m_size));
}

void MapItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED( option ) Q_UNUSED( widget )

    if ( m_gameobject->getType() == "Grassland" )
    {
    painter->fillRect(boundingRect(), Qt::green);
    }
    else if ( m_gameobject->getType() == "Forest" )
    {
       painter->fillRect(boundingRect(), Qt::darkGreen);
    }
    else if ( m_gameobject->getType() == "Rock" )
    {
       painter->fillRect(boundingRect(), Qt::darkGray);
    }
    else if ( m_gameobject->getType() == "Water" )
    {
       painter->fillRect(boundingRect(), Qt::cyan);
    }
    else if ( m_gameobject->getType() == "Sand" )
    {
        painter->fillRect(boundingRect(), Qt::yellow);
    }
    painter->drawRect(boundingRect());
    if(m_itemHasBuilding)
    {
        if(m_itemHasWorker)
        {
            painter->drawPixmap(static_cast<int>(boundingRect().x())+10, static_cast<int>(boundingRect().y()), m_size-20, m_size - 20, m_building);
            int workerSize = m_size / m_worker.size();
            int nextWorkerXposition = 0;
            for(QPixmap worker : m_worker)
            {
                painter->drawPixmap(static_cast<int>(boundingRect().x())+nextWorkerXposition, static_cast<int>(boundingRect().y())+30, 20, workerSize, worker);
                nextWorkerXposition += workerSize;
            }
            painter->drawRect(boundingRect());
        }
        else
        {
            painter->drawPixmap(boundingRect().toRect(), m_building);
            painter->drawRect(boundingRect());
        }
    }
}

const std::shared_ptr<Course::GameObject> &MapItem::getBoundObject()
{
    return m_gameobject;
}

void MapItem::updateLoc()
{
    if ( !m_gameobject ){
        delete this;
    } else {
        update(boundingRect()); // Test if necessary
        m_scenelocation = m_gameobject->getCoordinate().asQpoint();
    }
}

bool MapItem::isSameObj(std::shared_ptr<Course::GameObject> obj)
{
    return obj == m_gameobject;
}

int MapItem::getSize() const
{
    return m_size;
}

void MapItem::setSize(int size)
{
    if ( size > 0 && size <= 500 ){
        m_size = size;
    }
}

void MapItem::addBuilding(QPixmap building, QString buildingName)
{
    m_building = building;
    m_itemHasBuilding = true;
    m_buildingName = buildingName;
}

void MapItem::addWorker(QPixmap worker, QString workerName)
{
    m_worker.push_back(worker);
    m_itemHasWorker = true;
    m_workerNames.push_back(workerName);
}

void MapItem::removeBuilding()
{
    m_itemHasBuilding = false;
    m_itemHasWorker = false;
    m_buildingName = "";
    m_workerNames.empty();
}

bool MapItem::checkForBuildings()
{
    if(m_itemHasBuilding)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool MapItem::checkForWorkers()
{
    if(m_itemHasWorker)
    {
        return true;
    }
    else
    {
        return false;
    }
}

QString MapItem::getBuildingName()
{
    return m_buildingName;
}

QVector<QString> MapItem::getWorkerNames()
{
    return m_workerNames;
}

void MapItem::addNewColor(std::string type)
{
    if ( c_mapcolors.find(type) == c_mapcolors.end() ){
        std::size_t hash = std::hash<std::string>{}(type);
        c_mapcolors.insert({type, QColor((hash & 0xFF0000) >> 16, (hash & 0x00FF00 ) >> 8, (hash & 0x0000FF))});

    }
}

}
