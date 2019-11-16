#include "gameeventhandler.h"
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
    Q_UNUSED(player) Q_UNUSED(resources)
    return true;
}


}
