#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include <memory>

#include "core/gameobject.h"
#include "core/playerbase.h"
#include "workers/basicworker.h"
#include "buildings/buildingbase.h"
#include "tiles/tilebase.h"
#include "workers/workerbase.h"

namespace Student {

/**
 * @class Player
 * @brief The Player class is a class for classes used to describe
 * a player in game. It's derived from course's PlayerBase.
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

    /**
     * @brief Deducts building costs from players's resources.
     * @param resources: Resources to be deducted from player resources.
     * @return True is successfull, false if player doesn't afford to build.
     * @pre BasicResources must be in following order at parameter:
     * money, food, wood, stone, ore.
     */
    bool deductBuildCosts(Course::ResourceMap resources);

    /**
     * @brief Deducts recruitment costs from players's resources.
     * @param resources: Resources to be deducted from player resources.
     * @return True is successfull, false if player doesn't afford to recruit.
     * @pre BasicResources must be in following order at parameter:
     * money, food, wood, stone, ore.
     */
    bool deductRecruitmentCosts(Course::ResourceMap resources);

    /**
     * @brief Adds selling prize to players's resources.
     * @param resources: Resources to be added to player resources.
     * @pre BasicResources must be in following order at parameter:
     * money, food, wood, stone, ore.
     */
    void collectSellingPrize(Course::ResourceMap prize);
    
    /**
     * @brief Adds resources gained from buildings and workers to players's resources.
     * @param resources: Resources to be added to player resources.
     * @pre BasicResources must be in following order at parameter:
     * money, food, wood, stone, ore.
     */
    void gainResorces(Course::ResourceMap resources);

    /**
     * @brief Add a pointer to players building to a vector.
     * @param building: points to the building to be added.
     */
    void addBuilding(std::shared_ptr<Course::BuildingBase> building);

    //Player resources. Can't be private because outside class access is needed.
    int money = 1500;
    int food = 1500;
    int wood = 1500;
    int stone = 1500;
    int ore = 1500;

private:
    std::string m_playerName;
    std::vector<std::weak_ptr<Course::GameObject> > m_playerObjects;
    std::vector<std::shared_ptr<Course::BuildingBase>> m_playerBuildings;

};

}

#endif // PLAYER_H
