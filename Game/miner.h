#ifndef MINER_H
#define MINER_H

#include "workers/workerbase.h"
#include "studentresourcemaps.h"


namespace Student {

/**
 * @brief The Miner class represents miner.
 *
 * Miner has following production-efficiency: \n
 * * Money - 0.25 \n
 * * Food - 1.00 \n
 * * Wood - 0.75 \n
 * * Stone - 1.50 \n
 * * Ore - 1.50 \n
 *
 * Miner consume Food and money. \n
 * * 1 Food - Or Miner refuses to work. \n
 * * 1 Money - Or Miner works at 50% efficiency. \n
 * * Resourcefocus adds 25% efficiency for the focused resource,
 * even if the miner is refusing work.
 */

class Miner : public Course::WorkerBase
{
public:

    Miner() = delete;

    Miner(const std::shared_ptr<Course::iGameEventHandler>& eventhandler,
                const std::shared_ptr<Course::iObjectManager>& objectmanager,
                const std::shared_ptr<Course::PlayerBase>& owner,
                const int& tilespaces = 1,
                const Course::ResourceMap& cost =
                    Student::ConstResourceMaps::RECRUITMENT_COST,
                const Course::ResourceMapDouble& efficiency =
                    Student::ConstResourceMaps::MINER_EFFICIENCY
                );

    /**
     * @brief Default destructor.
     */
    virtual ~Miner() = default;

    /**
     * @copydoc GameObject::getType()
     */
    virtual std::string getType() const override;

    /**
     * @brief Check if the miner can be placed on the Tile according to
     * it's placement rule. Only rule is that the Tile must have same owner
     * as the miner.
     * @param target is the Tile that miner is being placed on.
     * @return
     * True - If baseclass' method return true and target Tile has space
     * for miner.
     * False - If both conditions aren't met.
     * @note Override to change placement rules for derived miner.
     * @post Exception guarantee: Basic
     */
    bool canBePlacedOnTile(
            const std::shared_ptr<Course::TileBase> &target);

    /**
     * @brief Performs the miner's default action.
     */
    virtual void doSpecialAction() override;

    /**
     * @brief Returns miner's efficiency at resource production.
     * Miner consumes FOOD and MONEY. Resource consumption and resource
     * focus determine final multiplier that is based on MINER_EFFICIENCY.
     *
     * @return
     */
    virtual const Course::ResourceMapDouble tileWorkAction() override;

}; // class Miner

} // namespace Student

#endif // MINER_H
