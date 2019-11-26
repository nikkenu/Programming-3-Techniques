#ifndef WATER_H
#define WATER_H

#include "tiles/tilebase.h"
#include "studentresourcemaps.h"

namespace Student {

/**
 * @brief The Water class represents Water in the gameworld.
 *
 * Water has BasicProduction: \n
 * * Money = 2
 * * Food = 1
 * * Wood = 0
 * * Stone = 0
 * * Ore = 0
 *
 * Tile supports 1 building.
 */
class Water : public Course::TileBase
{
public:
    static const unsigned int MAX_BUILDINGS;
    static const unsigned int MAX_WORKERS;
    static const Course::ResourceMap BASE_PRODUCTION;

    /**
     * @brief Disabled parameterless constructor.
     */
    Water() = delete;

    /**
     * @brief Constructor for the class.
     *
     * @param location is the Coordinate where the Tile is located in the game.
     * @param eventhandler points to the student's GameEventHandler.
     */
    Water(const Course::Coordinate& location,
          const std::shared_ptr<Course::iGameEventHandler>& eventhandler,
          const std::shared_ptr<Course::iObjectManager>& objectmanager,
          const unsigned int& max_build = 1,
          const unsigned int& max_work = 3,
          const Course::ResourceMap& production = Student::ConstResourceMaps::WATER_BP);

    /**
     * @brief Default destructor.
     */
    virtual ~Water() = default;

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



#endif // WATER_H
