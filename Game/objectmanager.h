#include "interfaces/igameeventhandler.h"

#ifndef OBJECTMANAGER_H
#define OBJECTMANAGER_H

namespace Student {
class ObjectManager : public Course::iGameEventHandler
{
public:
    ObjectManager();

    ~ObjectManager();

    bool modifyResource(std::shared_ptr<Course::PlayerBase> player,
                                    Course::BasicResource resource,
                                    int amount);

    bool modifyResources(std::shared_ptr<Course::PlayerBase> player,
                                     Course::ResourceMap resources);
};

}


#endif // OBJECTMANAGER_H
