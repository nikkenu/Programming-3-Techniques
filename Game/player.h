#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include <memory>

#include "core/gameobject.h"
#include "core/playerbase.h"
#include "workers/basicworker.h"

namespace Student {

/**
 * @class Player
 * @brief The Player class is a class for classes used to describe
 * a player in game.
 *
 * The class can be used to store and access GameObjects.
 * Expired weak pointers are automatically removed when requesting or removing
 * objects.
 *
 * @note Objects are stored as weak pointers.
 */
class Player : public Course::PlayerBase
{
public:
    /**
     * @brief Constructor for the class
     * @param name A std::string for player's name
     * @param objects (optional) A std::vector of shared-pointers to
     * GameObjects.
     */
    Player(const std::string& name,
               const std::vector<std::shared_ptr<Course::GameObject> > objects ={});

    /**
     * @brief Default destructor
     */
    virtual ~Player() = default;

    bool deductBuildCosts(Course::ResourceMap resources);

    bool deductRecruitmentCosts(Course::ResourceMap resources);

    int money = 1000;
    int food = 1000;
    int wood = 1000;
    int stone = 1000;
    int ore = 1000;

private:
    std::string playerName;
    std::vector<std::weak_ptr<Course::GameObject> > playerObjects;

};

}

#endif // PLAYER_H
