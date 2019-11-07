#include "player.h"

namespace Student {

Player::Player(const std::string& name,
               const std::vector<std::shared_ptr<Course::GameObject> > objects):
    playerName(name),
    playerObjects()
{
    for( auto it = objects.begin(); it != objects.end(); ++it)
    {
        playerObjects.push_back(std::weak_ptr<Course::GameObject>(*it));
    }
}

} // namesace Student


