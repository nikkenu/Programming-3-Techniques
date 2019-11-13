#include "objectmanager.h"
#include "gameeventhandler.h"
#include "core/worldgenerator.h"
#include "gamescene.h"
#include "tiles/forest.h"
#include "tiles/grassland.h"
#include "tiles/tilebase.h"
#include "rock.h"
#include "water.h"
#include "sand.h"

#ifndef BOARDINIT_H
#define BOARDINIT_H


class BoardInit
{
public:
    BoardInit(Student::GameScene* scene);

    void initialiseWorldGenerator();


private:
    std::shared_ptr<Student::ObjectManager> m_objectManager = nullptr;
    std::shared_ptr<Student::GameEventHandler> m_gameEventHandler = nullptr;
    Student::GameScene* m_scene;
};

#endif // BOARDINIT_H
