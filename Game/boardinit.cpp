#include "boardinit.h"

BoardInit::BoardInit(Course::SimpleGameScene* scene): m_scene(scene)
{
    m_objectManager = std::make_shared<Student::ObjectManager>();
    m_objectManager->addScene(m_scene);
    m_gameEventHandler = std::make_shared<Student::GameEventHandler>();
    initialiseWorldGenerator();
}

void BoardInit::initialiseWorldGenerator()
{
    Course::WorldGenerator::getInstance().addConstructor<Course::Forest>(1);
    Course::WorldGenerator::getInstance().addConstructor<Course::Grassland>(3);
    Course::WorldGenerator::getInstance().addConstructor<Course::TileBase>(10);
    Course::WorldGenerator::getInstance().generateMap(10, 10, 10, m_objectManager, m_gameEventHandler);
}
