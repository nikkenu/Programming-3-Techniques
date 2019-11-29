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
    return false;
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

std::shared_ptr<ObjectManager> GameEventHandler::getObjectManager()
{
    return m_objectManager;
}

QString GameEventHandler::getWinner()
{
    std::vector<std::shared_ptr<Student::Player>> playerVector = m_objectManager->getPlayers();
    std::shared_ptr<Student::Player> winner = playerVector.at(0);
    for (auto const player : playerVector)
    {
        if (player->money > winner->money)
        {
            winner = player;
        }
    }
    return QString::fromStdString(winner->getName());
}

}
