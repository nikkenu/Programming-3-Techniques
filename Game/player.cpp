#include "player.h"

namespace Student {

Player::Player(const std::string& name,
               const std::vector<std::shared_ptr<Course::GameObject> > objects):

    Course::PlayerBase(name, objects)
{

}

} // namesace Student


