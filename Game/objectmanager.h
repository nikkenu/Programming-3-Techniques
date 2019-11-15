#include "interfaces/iobjectmanager.h"
#include "tiles/tilebase.h"
#include "gamescene.h"
#include "player.h"
#include <vector>
#include <string>


#ifndef OBJECTMANAGER_H
#define OBJECTMANAGER_H
using ObjectId = unsigned int;

namespace Student {

class ObjectManager : public Course::iObjectManager
{
public:
    ObjectManager();

    ~ObjectManager();

    void addTiles(const std::vector<std::shared_ptr<Course::TileBase>>& tiles);

    std::shared_ptr<Course::TileBase> getTile(const Course::Coordinate& coordinate);

    std::shared_ptr<Course::TileBase> getTile(const ObjectId& id);

    std::vector<std::shared_ptr<Course::TileBase>> getTiles(
                const std::vector<Course::Coordinate>& coordinates);

    void addScene(Student::GameScene* scene);

    void drawTiles();

    void setPlayers(std::vector<std::string> names);

    std::vector<int> playerWealth(std::string &name);

private:
    Student::GameScene* m_scene;
    std::vector<std::shared_ptr<Course::TileBase>> m_tiles;
    std::vector<std::shared_ptr<Student::Player>> playerVector;


}; // class ObjectManager

} // namespace Student


#endif // OBJECTMANAGER_H
