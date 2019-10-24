#include "interfaces/igameeventhandler.h"
#ifndef GAMEEVENTHANDLER_H
#define GAMEEVENTHANDLER_H

namespace Student {

class GameEventHandler : public Course::iGameEventHandler
{
public:
    GameEventHandler();

    ~GameEventHandler();

    bool modifyResource(std::shared_ptr<Course::PlayerBase> player,
                                    Course::BasicResource resource,
                                    int amount);

    bool modifyResources(std::shared_ptr<Course::PlayerBase> player,
                                     Course::ResourceMap resources);

}; // class GameEventHandler

} // namespace Student


#endif // GAMEEVENTHANDLER_H
