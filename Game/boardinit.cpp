#include "boardinit.h"

namespace Student {


BoardInit::BoardInit(Student::GameScene* scene): m_scene(scene)
{
    m_objectManager = std::make_shared<ObjectManager>();
    m_objectManager->addScene(m_scene);
    m_gameEventHandler = std::make_shared<GameEventHandler>();
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
