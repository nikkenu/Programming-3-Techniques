#include "boardinit.h"

namespace Student {


BoardInit::BoardInit(std::shared_ptr<ObjectManager> objectManager, std::shared_ptr<GameEventHandler> gameEventHandler):
    m_objectManager(objectManager),
    m_gameEventHandler(gameEventHandler)
{
    initialiseWorldGenerator();
}

void BoardInit::initialiseWorldGenerator()
{
    Course::WorldGenerator::getInstance().addConstructor<Course::Forest>(7);
    Course::WorldGenerator::getInstance().addConstructor<Course::Grassland>(10);
    Course::WorldGenerator::getInstance().addConstructor<Rock>(3);
    Course::WorldGenerator::getInstance().addConstructor<Water>(3);
    Course::WorldGenerator::getInstance().addConstructor<Sand>(3);
    Course::WorldGenerator::getInstance().generateMap(10, 10, 10, m_objectManager, m_gameEventHandler);
}


}
