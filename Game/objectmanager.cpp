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
        playerVector.push_back(player);
    }

}

std::vector<int> ObjectManager::playerWealth(std::string &name)
{
    std::vector<int> wealth;
    for (unsigned int i = 0; i < playerVector.size(); i++)
    {
        if (name == playerVector.at(i)->getName())
        {
            wealth.push_back(playerVector.at(i)->money);
            wealth.push_back(playerVector.at(i)->food);
            wealth.push_back(playerVector.at(i)->wood);
            wealth.push_back(playerVector.at(i)->stone);
            wealth.push_back(playerVector.at(i)->ore);
        }
    }
    return wealth;
}

}


