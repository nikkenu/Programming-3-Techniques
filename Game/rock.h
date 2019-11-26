#ifndef ROCK_H
#define ROCK_H

#include "tiles/tilebase.h"
#include "studentresourcemaps.h"

namespace Student {

/**
 * @brief The Rock class represents Rock in the gameworld.
 *
 * Rock has BasicProduction: \n
 * * Money = 2
 * * Food = 0
 * * Wood = 0
 * * Stone = 5
 * * Ore = 3
 *
 * Tile supports 3 buildings.
 */
class Rock : public Course::TileBase
{
public:
    static const unsigned int MAX_BUILDINGS;
    static const unsigned int MAX_WORKERS;
    static const Course::ResourceMap BASE_PRODUCTION;

    /**
     * @brief Disabled parameterless constructor.
     */
    Rock() = delete;

    /**
     * @brief Constructor for the class.
     *
     * @param location is the Coordinate where the Tile is located in the game.
     * @param eventhandler points to the student's GameEventHandler.
     */
    Rock(const Course::Coordinate& location,
          const std::shared_ptr<Course::iGameEventHandler>& eventhandler,
          const std::shared_ptr<Course::iObjectManager>& objectmanager,
          const unsigned int& max_build = 3,
          const unsigned int& max_work = 4,
          const Course::ResourceMap& production = Student::ConstResourceMaps::ROCK_BP);

    /**
     * @brief Default destructor.
     */
    virtual ~Rock() = default;

   /**
     * @copydoc GameObject::getType()
     */
    virtual std::string getType() const override;

    /**
     * @brief Adds a new building-object to the tile.
     * @post Exception guarantee: Strong
     * @exception OwnerConflict - If the tile's ownership prevents placing the
     * \b building.
     * @exception NoSpace - If the tile doesn't have enough space for
     * the \b building.
     */
    void addBuilding(const std::shared_ptr<Course::BuildingBase>& building) override;
};

}



#endif // ROCK_H
