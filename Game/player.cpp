#include "player.h"
#include <QDebug>
#include <cmath>

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

void Player::collectSellingPrize(Course::ResourceMap prize)
{
    if (prize.find(Course::BasicResource::STONE) != prize.end())
    {
        stone = stone + floor(prize.at(Course::BasicResource::STONE) / 2);
    }
    if (prize.find(Course::BasicResource::ORE) != prize.end())
    {
        ore = ore + floor(prize.at(Course::BasicResource::ORE) / 2);
    }
    money = money + floor(prize.at(Course::BasicResource::MONEY) / 2);
    food = food + floor(prize.at(Course::BasicResource::FOOD) / 2);
    wood = wood + floor(prize.at(Course::BasicResource::WOOD) / 2);
}

void Player::addBuilding(std::shared_ptr<Course::BuildingBase> building)
{
    m_playerBuildings.push_back(building);
}

void Player::gainResorces(Course::ResourceMap resources)
{    
    if ( resources.find(Course::BasicResource::MONEY) != resources.end() )
    {
      money += resources.at(Course::BasicResource::MONEY);
    }
    if ( resources.find(Course::BasicResource::FOOD) != resources.end() )
    {
      food += resources.at(Course::BasicResource::FOOD);
    }
    if ( resources.find(Course::BasicResource::WOOD) != resources.end() )
    {
      wood += resources.at(Course::BasicResource::WOOD);
    }
    if ( resources.find(Course::BasicResource::STONE) != resources.end() )
    {
      stone += resources.at(Course::BasicResource::STONE);
    }
    if ( resources.find(Course::BasicResource::ORE) != resources.end() )
    {
      ore += resources.at(Course::BasicResource::ORE);
    }

}

} // namesace Student


