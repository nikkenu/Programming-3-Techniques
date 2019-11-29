#include "interfaces/igameeventhandler.h"
#include "core/playerbase.h"
#include "core/resourcemaps.h"
#include "player.h"
#include "mainwindow.h"

#ifndef GAMEEVENTHANDLER_H
#define GAMEEVENTHANDLER_H

namespace Student {

class ObjectManager;

/**
 * @brief The GameEventHandler class is used for handling player's modifying
 * player's resourses. It is used when player recruits a worker or gains resources.
 * The class is derived from cource's iGameEventHandler
 * @see iGameEventHandler
 */

class GameEventHandler : public Course::iGameEventHandler
{

public:

    /**
     * @brief Class constructor
     */
    GameEventHandler();

    /**
      *@brief Class deconstructor.
      */
    ~GameEventHandler();

    /**
     * @brief modifyResource is not used in our game.
     * @see modifyResources.
     */
    bool modifyResource(std::shared_ptr<Course::PlayerBase> player,
                                    Course::BasicResource resource,
                                    int amount);
    /**
     * @brief Called when player recruits a workers or a new round starts, when
     * resources are gained by all players. Calls deductRecruitmentCosts or
     * gainResources from Player-class depending on which case is it.
     * @param player points to the player whose resources need modifying.
     * @param resource is ResourceMap containing the resources which are
     * added and deducted from player resources and amount of them.
     * @return True if successful, false if not.
     *
     * @pre BasicResources must be in following order in resources:
     * money, food, wood, stone, ore.
     * @post Exception guarentee: basic.
     * @exception InvalidPointer, if pointer to player is invalid.
     */

    bool modifyResources(std::shared_ptr<Course::PlayerBase> player,
                                     Course::ResourceMap resources);

    /**
     * @brief Adds pointer to the student's ObjectManager.
     * @param objectManager points to the student's ObjectManager.
     * @post Exception guarantee: No-throw.
     */
    void addObjectManager(std::shared_ptr<ObjectManager> objectManager);

    /**
     * @brief Returns ObjectManager if not nullptr
     * @post Exception guarantee: No-throw.
     */
    std::shared_ptr<ObjectManager> getObjectManager();

    /**
     * @brief Called when 10 rounds has been player.
     * @return The player that has most amount of money.
     * @post Exception guarantee: basic.
     */
    QString getWinner();


private:
    std::shared_ptr<ObjectManager> m_objectManager;


}; // class GameEventHandler

} // namespace Student


#endif // GAMEEVENTHANDLER_H
