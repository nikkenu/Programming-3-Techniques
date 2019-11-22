#include "objectmanager.h"
#include <QDebug>

namespace Student {

ObjectManager::ObjectManager()
{

}

ObjectManager::~ObjectManager()
{

}

void ObjectManager::addTiles(const std::vector<std::shared_ptr<Course::TileBase> > &tiles)
{
    m_tiles = tiles;
    drawTiles();
}

std::shared_ptr<Course::TileBase> ObjectManager::getTile(const Course::Coordinate &coordinate)
{
    for(auto const& tile : m_tiles)
    {
        if(tile->getCoordinate() == coordinate)
        {
            return tile;
        }
    }

    return nullptr;
}

std::shared_ptr<Course::TileBase> ObjectManager::getTile(const ObjectId &id)
{
    for(auto const& tile : m_tiles)
    {
        if(tile->ID == id)
        {
            return tile;
        }
    }

    return nullptr;
}

std::vector<std::shared_ptr<Course::TileBase> > ObjectManager::getTiles(const std::vector<Course::Coordinate> &coordinates)
{
    std::vector<std::shared_ptr<Course::TileBase>> temporaryContainer;

    for(auto const& coordinate : coordinates)
    {
        for(auto const& tile : m_tiles)
        {
            if(coordinate == tile->getCoordinate())
            {
                temporaryContainer.push_back(tile);
            }
        }
    }
    return temporaryContainer;
}

void ObjectManager::addScene(Student::GameScene *scene)
{
    m_scene = scene;
}

void ObjectManager::drawTiles()
{
    for(auto const &tile : m_tiles)
    {
        m_scene->drawItem(tile);
    }
}

void ObjectManager::setPlayers(std::vector<QString> names)
{

    for (unsigned int i = 0; i < names.size(); i++)
    {
        std::string name = names.at(i).toStdString();
        std::shared_ptr<Player> player = std::make_shared<Player>(name);
        player->setName(name);
        m_playerVector.push_back(player);
    }

}

std::vector<int> ObjectManager::playerWealth(std::string &name)
{
    std::vector<int> wealth;
    for (unsigned int i = 0; i < m_playerVector.size(); i++)
    {
        if (name == m_playerVector.at(i)->getName())
        {
            wealth.push_back(m_playerVector.at(i)->money);
            wealth.push_back(m_playerVector.at(i)->food);
            wealth.push_back(m_playerVector.at(i)->wood);
            wealth.push_back(m_playerVector.at(i)->stone);
            wealth.push_back(m_playerVector.at(i)->ore);
        }
    }
    return wealth;
}

void ObjectManager::addGameEventHandler(std::shared_ptr<GameEventHandler> gameEventHandler)
{
    m_gameEventHandler = gameEventHandler;
}

void ObjectManager::createBuilding(QString buildingType, QPointF point, std::shared_ptr<ObjectManager> objectManager)
{
    int xCoord = static_cast<int>(point.rx());
    int yCoord = static_cast<int>(point.ry());
    const Course::Coordinate coord(xCoord, yCoord);
    std::shared_ptr<Course::TileBase> tile = getTile(coord);

    if(tile == nullptr)
    {
        qDebug() << "Tile was null returning from method";
        return;
    }
    std::shared_ptr<Course::BuildingBase> building;
    if(buildingType == "Headquarter")
    {
       building = std::make_shared<Course::HeadQuarters>(m_gameEventHandler, objectManager, m_playerVector.at(m_intTurnNumber));
        qDebug() << "Added headquarter to the tile";
    }
    else if(buildingType == "Outpost")
    {
        building = std::make_shared<Course::Outpost>(m_gameEventHandler, objectManager, m_playerVector.at(m_intTurnNumber));
        qDebug() << "Added outpost to the tile";
    }
    else if(buildingType == "Farm")
    {
        building = std::make_shared<Course::Farm>(m_gameEventHandler, objectManager, m_playerVector.at(m_intTurnNumber));
        qDebug() << "Added farm to the tile";
    }
    else if(buildingType == "Oilrig")
    {
        building = std::make_shared<OilRig>(m_gameEventHandler, objectManager, m_playerVector.at(m_intTurnNumber));
        qDebug() << "Added oilrig to the tile";
    }
    else if(buildingType == "Mine")
    {
        building = std::make_shared<Mine>(m_gameEventHandler, objectManager, m_playerVector.at(m_intTurnNumber));
        qDebug() << "Added mine to the tile";
    }
    else
    {
        qDebug() << "No such building";
        return;
    }
    if (m_gameEventHandler->modifyResources(m_playerVector.at(m_intTurnNumber), building->BUILD_COST))
    {
        tile->addBuilding(building);
    }

}

void ObjectManager::createWorker(QString workerType, QPointF point, std::shared_ptr<ObjectManager> objectManager)
{
    int xCoord = static_cast<int>(point.rx());
    int yCoord = static_cast<int>(point.ry());
    const Course::Coordinate coord(xCoord, yCoord);
    std::shared_ptr<Course::TileBase> tile = getTile(coord);

    if(tile == nullptr)
    {
        qDebug() << "Tile was null returning from method";
        return;
    }

    if(workerType == "Worker")
    {
        std::shared_ptr<Course::BasicWorker> worker
                = std::make_shared<Course::BasicWorker>(m_gameEventHandler, objectManager, m_playerVector.at(m_intTurnNumber));
        tile->addWorker(worker);
        qDebug() << "Added worker to the tile";
    }
    else if(workerType == "Miner")
    {
        std::shared_ptr<Miner> miner
                = std::make_shared<Miner>(m_gameEventHandler, objectManager, m_playerVector.at(m_intTurnNumber));
        tile->addWorker(miner);
        qDebug() << "Added miner to the tile";
    }
    else if(workerType == "Farmer")
    {
        std::shared_ptr<Farmer> farmer
                = std::make_shared<Farmer>(m_gameEventHandler, objectManager, m_playerVector.at(m_intTurnNumber));
        tile->addWorker(farmer);
        qDebug() << "Added farmer to the tile";
    }
}

}


