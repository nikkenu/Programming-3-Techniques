#include "player.h"
#include <QDebug>

namespace Student {

Player::Player(const std::string& name,
               const std::vector<std::shared_ptr<Course::GameObject> > objects):

    Course::PlayerBase(name, objects)
{

}

bool Player::deductBuildCosts(Course::ResourceMap resources)
{
    if (resources.at(Course::BasicResource::MONEY) > money ||
        resources.at(Course::BasicResource::FOOD) > food ||
        resources.at(Course::BasicResource::WOOD) > wood)
    {
        return false;
    }
    if (resources.find(Course::BasicResource::STONE) != resources.end())
    {
        if (resources.at(Course::BasicResource::STONE) > stone)
        {
            return false;
        }
        stone = stone - resources.at(Course::BasicResource::STONE);
    }
    if (resources.find(Course::BasicResource::ORE) != resources.end())
    {
        if (resources.at(Course::BasicResource::ORE) > ore)
        {
            return false;
        }
        ore = ore - resources.at(Course::BasicResource::ORE);
    }
    money = money - resources.at(Course::BasicResource::MONEY);
    food = food - resources.at(Course::BasicResource::FOOD);
    wood = wood - resources.at(Course::BasicResource::WOOD);


    return true;
}

bool Player::deductRecruitmentCosts(Course::ResourceMap resources)
{
    if (resources.at(Course::BasicResource::MONEY) > money ||
        resources.at(Course::BasicResource::FOOD) > food)
    {
        return false;
    }
    money = money - resources.at(Course::BasicResource::MONEY);
    food = food - resources.at(Course::BasicResource::FOOD);
    return true;
}

} // namesace Student


