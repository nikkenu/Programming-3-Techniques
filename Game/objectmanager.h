#include "interfaces/iobjectmanager.h"
#include "tiles/tilebase.h"
#include "gamescene.h"
#include "player.h"
#include <vector>
#include <string>
#include <buildings/headquarters.h>
#include <buildings/farm.h>
#include <buildings/outpost.h>
#include "oilrig.h"
#include "mine.h"
#include "gameeventhandler.h"
#include "workers/basicworker.h"
#include "core/placeablegameobject.h"
#include "core/basicresources.h"
#include "workers/workerbase.h"
#include "miner.h"
#include "farmer.h"


#ifndef OBJECTMANAGER_H
#define OBJECTMANAGER_H
using ObjectId = unsigned int;

namespace Student {

class ObjectManager : public Course::iObjectManager
{
public:
    ObjectManager();

    ~ObjectManager();

    void addTiles(const std::vector<std::shared_ptr<Course::TileBase>>& tiles);

    std::shared_ptr<Course::TileBase> getTile(const Course::Coordinate& coordinate);

    std::shared_ptr<Course::TileBase> getTile(const ObjectId& id);

    std::vector<std::shared_ptr<Course::TileBase>> getTiles(
                const std::vector<Course::Coordinate>& coordinates);

    void addScene(Student::GameScene* scene);

    void drawTiles();

    void setPlayers(std::vector<QString> names);


    std::vector<int> playerWealth(std::string &name);

    /**
     * @brief Add GameEventHandler to this class,
     * because we need it to make builders and workers.
     * @param Gets GameEventHandler as shared_ptr from
     * MainWindow, so we are not creating new GameEventHandler.
     */
    void addGameEventHandler(std::shared_ptr<GameEventHandler> gameEventHandler);

    /**
     * @brief Creates specific building to a tile.
     * @param buildType ex."Mine", point gives tile position in scene
     * and it gets ObjectManager as shared_ptr, because otherwise
     * we would need to cast "this" to shared_ptr so this was much trivial.
     */
    bool createBuilding(QString buildingType, QPointF point, std::shared_ptr<ObjectManager> objectManager);

    /**
     * @brief Creates specific worker to a tile.
     * @param workerType ex."Miner", point gives tile position in scene
     * and it gets ObjectManager as shared_ptr, because otherwise
     * we would need to cast "this" to shared_ptr so this was much trivial.
     */
    bool createWorker(QString workerType, QPointF point, std::shared_ptr<ObjectManager> objectManager);

    /**
     * @brief Sets the player in turn.
     * @param New player number in turn.
     */
    void setPlayerInTurn(unsigned int inTurnNumber);

    bool sellBuilding(QPointF point);

    std::shared_ptr<Player> getPlayer(std::string playerName);

    std::vector<std::shared_ptr<Student::Player>> getPlayers();

    void gainPlayerResources();


private:
    Student::GameScene* m_scene;
    std::vector<std::shared_ptr<Course::TileBase>> m_tiles;
    std::vector<std::shared_ptr<Student::Player>> m_playerVector;
    std::vector<std::shared_ptr<Course::BuildingBase>> m_buildings;
    std::vector<std::shared_ptr<Course::WorkerBase>> m_workers;
    std::shared_ptr<GameEventHandler> m_gameEventHandler = nullptr;
    unsigned int m_intTurnNumber = 0;


}; // class ObjectManager

} // namespace Student


#endif // OBJECTMANAGER_H
