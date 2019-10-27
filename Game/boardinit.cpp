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
    Course::WorldGenerator::getInstance().addConstructor<Course::Forest>(7);
    Course::WorldGenerator::getInstance().addConstructor<Course::Grassland>(10);
    Course::WorldGenerator::getInstance().addConstructor<Student::Rock>(3);
    Course::WorldGenerator::getInstance().addConstructor<Student::Water>(3);
    Course::WorldGenerator::getInstance().addConstructor<Student::Sand>(3);
    Course::WorldGenerator::getInstance().generateMap(10, 10, 10, m_objectManager, m_gameEventHandler);
}
