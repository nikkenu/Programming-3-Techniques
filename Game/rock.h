#ifndef ROCK_H
#define ROCK_H

#include "tiles/tilebase.h"
#include "studentresourcemaps.h"

namespace Student {

class Rock : public Course::TileBase
{
public:
    static const unsigned int MAX_BUILDINGS;
    static const unsigned int MAX_WORKERS;
    static const Course::ResourceMap BASE_PRODUCTION;

    Rock() = delete;

    Rock(const Course::Coordinate& location,
          const std::shared_ptr<Course::iGameEventHandler>& eventhandler,
          const std::shared_ptr<Course::iObjectManager>& objectmanager,
          const unsigned int& max_build = 3,
          const unsigned int& max_work = 4,
          const Course::ResourceMap& production = Student::ConstResourceMaps::ROCK_BP);

    virtual ~Rock() = default;

    virtual std::string getType() const override;

    void addBuilding(const std::shared_ptr<Course::BuildingBase>& building) override;
};

}



#endif // ROCK_H
