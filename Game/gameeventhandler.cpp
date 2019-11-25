#include "gameeventhandler.h"
#include "objectmanager.h"
#include <string>

namespace Student {

GameEventHandler::GameEventHandler()
{

}

GameEventHandler::~GameEventHandler()
{

}

bool Student::GameEventHandler::modifyResource(std::shared_ptr<Course::PlayerBase> player, Course::BasicResource resource, int amount)
{
    Q_UNUSED(player) Q_UNUSED(resource) Q_UNUSED(amount)
    return true;
}

bool Student::GameEventHandler::modifyResources(std::shared_ptr<Course::PlayerBase> player, Course::ResourceMap resources)
{
    std::shared_ptr<Player> derivedPlayer = std::dynamic_pointer_cast<Player>(player);
    if (resources.size() == 2)
    {
        if (derivedPlayer->deductRecruitmentCosts(resources))
        {
            return true;
        }
        return false;
    }
    derivedPlayer->gainResorces(resources);
    return true;

}


void GameEventHandler::addObjectManager(std::shared_ptr<ObjectManager> objectManager)
{
    m_objectManager = objectManager;
}

}
