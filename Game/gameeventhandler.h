#include "interfaces/igameeventhandler.h"
#include "core/playerbase.h"
#include "core/resourcemaps.h"
#include "player.h"

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

    void startGame(std::string name1, std::string name2);

    std::shared_ptr<Student::Player> player1;
    std::shared_ptr<Student::Player> player2;


}; // class GameEventHandler

} // namespace Student


#endif // GAMEEVENTHANDLER_H
