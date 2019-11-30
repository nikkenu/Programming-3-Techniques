#include "core/worldgenerator.h"
#include "tiles/forest.h"
#include "tiles/grassland.h"
#include "tiles/tilebase.h"
#include "rock.h"
#include "water.h"
#include "sand.h"
#include "gameeventhandler.h"
#include "objectmanager.h"

#ifndef BOARDINIT_H
#define BOARDINIT_H

namespace Student {

/**
 * @brief The BoardInit class is used for initialize map drawing with
 * WorldGenareator. It gets instance from WorldGenerator and calls its's
 * addConstructor class for every tile type and then calls genrateMap,
 * which generates a 10x10 map.
 */

class BoardInit
{
public:

    /**
     * @brief Constructor for the class.
     *
     * @param scene points to the student's GameScene.
     * @param objectManger points to the student's ObjectManager.
     * @param eventhandler points to the student's GameEventHandler.
     * @param descriptions contains descriptions and flavor texts.
     *
     * @post Exception guarantee: No guarantee.
     * @exception InvalidPointer, if one more of parameters are invalid
     */
    BoardInit(std::shared_ptr<ObjectManager> objectManager,
              std::shared_ptr<GameEventHandler> gameEventHandler);


    /**
     * @brief Gets instance from worldGenerator and call it's addConstructor and
     * generateMap methods.
     * @post Exception guarentee: No-throw
     */
    void initialiseWorldGenerator();


private:
    std::shared_ptr<ObjectManager> m_objectManager = nullptr;
    std::shared_ptr<GameEventHandler> m_gameEventHandler = nullptr;
};
}
#endif // BOARDINIT_H
