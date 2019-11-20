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

namespace Student {



class BoardInit
{
public:
    BoardInit(GameScene* scene, std::shared_ptr<ObjectManager>, std::shared_ptr<GameEventHandler> handler);

    void initialiseWorldGenerator();

    void startGame();


private:
    std::shared_ptr<ObjectManager> m_objectManager = nullptr;
    std::shared_ptr<GameEventHandler> m_gameEventHandler = nullptr;
    GameScene* m_scene;
};
}
#endif // BOARDINIT_H
