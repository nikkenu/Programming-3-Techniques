#ifndef OILRIG_H
#define OILRIG_H

#include "buildings/buildingbase.h"
#include "studentresourcemaps.h"


namespace Student {

/**
 * @brief The OilRig class represents an oil rig in the game.
 */
class OilRig : public Course::BuildingBase
{
public:
    /**
     * @brief Disabled parameterless constructor.
     */
    OilRig() = delete;

    /**
     * @brief Constructor for the class.
     *
     * @param eventhandler points to the student's GameEventHandler.
     * @param owner points to the owning player.
     * @param tile points to the tile upon which the building is constructed.
     *
     * @post Exception Guarantee: No guarantee.
     * @exception OwnerConflict - if the building conflicts with tile's
     * ownership.
     */
    explicit OilRig(
            const std::shared_ptr<Course::iGameEventHandler>& eventhandler,
            const std::shared_ptr<Course::iObjectManager>& objectmanager,
            const std::shared_ptr<Course::PlayerBase>& owner,
            const int& tilespaces = 1,
            const Course::ResourceMap& buildcost = Student::ConstResourceMaps::OILRIG_BUILD_COST,
            const Course::ResourceMap& production = Student::ConstResourceMaps::OILRIG_PRODUCTION
            );

    /**
     * @brief Default destructor.
     */
    virtual ~OilRig() = default;

    /**
     * @copydoc GameObject::getType()
     */
    virtual std::string getType() const override;

}; // class OilRig

} // namespace Student


#endif // MINE_H
