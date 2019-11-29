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
#include "mainwindow.h"
#include "miner.h"
#include "farmer.h"


#ifndef OBJECTMANAGER_H
#define OBJECTMANAGER_H
using ObjectId = unsigned int;

namespace Student {

/**
 * @brief The ObjectManager class is used for holding all GameObjects and
 * making changes to them. It's derived from cource's iObjectManager.
 * @see Course's iObjectManager
 */

class ObjectManager : public Course::iObjectManager
{
public:

    ObjectManager();

    ~ObjectManager();

    /**
     * @brief Copy a vector of tile to m_tiles.
     * @param tiles: a vector of tiles.
     * @post Exception guarentee: No-throw.
     */
    void addTiles(const std::vector<std::shared_ptr<Course::TileBase>>& tiles);

    /**
     * @brief Get tile by coordinate.
     * @param coordinate: Coordinate of wanted tile.
     * @return The tile wanted.
     * @post Exception guarentee: No-throw.
     */
    std::shared_ptr<Course::TileBase> getTile(const Course::Coordinate& coordinate);

    /**
     * @brief Get tile by it's id.
     * @param id: Id of the tile wanted.
     * @return The tile wanted.
     * @post Exception guarentee: No-throw.
     */
    std::shared_ptr<Course::TileBase> getTile(const ObjectId& id);

    /**
     * @brief Get multiple tiles from coordinates.
     * @param coordinates: Coordinates where wanted tiles are located.
     * @return Tiles in wanted coordinates
     * @post Exception guarentee: No-throw.
     */
    std::vector<std::shared_ptr<Course::TileBase>> getTiles(
                const std::vector<Course::Coordinate>& coordinates);

    /**
     * @brief Sets up all players to game.
     * @param Vector which includes all player names.
     * @post Exception guarentee: No-throw.
     */
    void setPlayers(std::vector<QString> names);

    /**
     * @brief Gets resources amounts from wanted player.
     * @param name: Name of the player whose resources are fetched.
     * @return Resource amounts in following order:
     * money, food, wood, stone, ore.
     */
    std::vector<int> playerWealth(std::string &name);

    /**
     * @brief Add GameEventHandler to this class,
     * because we need it to make builders and workers.
     * @param Gets GameEventHandler as shared_ptr from
     * MainWindow, so we are not creating new GameEventHandler.
     */
    void addGameEventHandler(std::shared_ptr<GameEventHandler> gameEventHandler);

    std::shared_ptr<GameEventHandler> getGameEventHandler();

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

    unsigned int getPlayerInTurn();

    bool sellBuilding(QPointF point);

    /**
     * @brief Gets the Player object wanted by name
     * @param playerName: name of wanted Player.
     * @return The Player object wanted.
     * @pre playerName must match an existing Player oject
     */
    std::shared_ptr<Player> getPlayer(std::string playerName);

    /**
     * @brief Get all of the Player objects.
     * @return All of the Player objects in a vector.
     */
    std::vector<std::shared_ptr<Student::Player>> getPlayers();

    /**
     * @brief Called when a new round starts. Calls Tilebase's genarateResources
     * for every tile.
     * @see Tilebase's generateResources from course's side.
     */
    void gainPlayerResources();

    std::vector<std::shared_ptr<Course::TileBase>> getAllTiles();


private:
    std::vector<std::shared_ptr<Course::TileBase>> m_tiles;
    std::vector<std::shared_ptr<Student::Player>> m_playerVector;
    std::vector<std::shared_ptr<Course::BuildingBase>> m_buildings;
    std::vector<std::shared_ptr<Course::WorkerBase>> m_workers;
    std::shared_ptr<GameEventHandler> m_gameEventHandler = nullptr;
    unsigned int m_intTurnNumber = 0;


}; // class ObjectManager

} // namespace Student


#endif // OBJECTMANAGER_H
