#include "objectmanager.h"

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

}


