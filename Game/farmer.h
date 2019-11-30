#ifndef FARMER_H
#define FARMER_H

#include "workers/workerbase.h"
#include "studentresourcemaps.h"


namespace Student {

/**
 * @brief The Farmer class represents a farmer.
 *
 * Farmer has following production-efficiency: \n
 * * Money - 0.25 \n
 * * Food - 1.50 \n
 * * Wood - 1.50 \n
 * * Stone - 0.25 \n
 * * Ore - 0.25 \n
 *
 * Farmer consume Food and money. \n
 * * 1 Food - Or Farmer refuses to work. \n
 * * 1 Money - Or Farmer works at 50% efficiency. \n
 * * Resourcefocus adds 25% efficiency for the focused resource,
 * even if the Farmer is refusing work.
 */

class Farmer : public Course::WorkerBase
{
public:

    Farmer() = delete;

    /**
     * @brief Class constructor
     * @param eventhandler points to the student's GameEventHandler.
     * @param objectmanager points to the student's ObjectManager.
     * @param owner points to the player how owns the building.
     * @param tilespaces number of tiles it takes, always 1.
     * @param cost is feched from StudentReserceMaps
     * @param efficiency is feched from StudentReserceMaps
     * @see StudentResourceMaps header.
     * @post Exception guarantee: No guarentee.
     * @exception InvalidPointer, if one or more of pointer are invalid.
     */
    Farmer(const std::shared_ptr<Course::iGameEventHandler>& eventhandler,
                const std::shared_ptr<Course::iObjectManager>& objectmanager,
                const std::shared_ptr<Course::PlayerBase>& owner,
                const int& tilespaces = 1,
                const Course::ResourceMap& cost =
                    Student::ConstResourceMaps::RECRUITMENT_COST,
                const Course::ResourceMapDouble& efficiency =
                    Student::ConstResourceMaps::FARMER_EFFICIENCY
                );

    /**
     * @brief Default destructor.
     */
    virtual ~Farmer() = default;

    /**
     * @copydoc GameObject::getType()
     */
    virtual std::string getType() const override;

    /**
     * @brief Check if the Farmer can be placed on the Tile according to
     * it's placement rule. Only rule is that the Tile must have same owner
     * as the Farmer.
     * @param target is the Tile that Farmer is being placed on.
     * @return
     * True - If baseclass' method return true and target Tile has space
     * for Farmer.
     * False - If both conditions aren't met.
     * @note Override to change placement rules for derived Farmer.
     * @post Exception guarantee: Basic
     */
    bool canBePlacedOnTile(
            const std::shared_ptr<Course::TileBase> &target);

    /**
     * @brief Performs the Farmer's default action.
     */
    virtual void doSpecialAction() override;

    /**
     * @brief Returns Farmer's efficiency at resource production.
     * Farmer consumes FOOD and MONEY. Resource consumption and resource
     * focus determine final multiplier that is based on Farmer.
     *
     * @return
     */
    virtual const Course::ResourceMapDouble tileWorkAction() override;


}; // class Farmer

} // namespace Student

#endif // FARMER_H
