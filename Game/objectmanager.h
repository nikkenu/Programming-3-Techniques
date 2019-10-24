#include "interfaces/iobjectmanager.h"
#include "tiles/tilebase.h"
#include "graphics/simplegamescene.h"

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

    void addScene(Course::SimpleGameScene* scene);

    void drawTiles();

private:
    Course::SimpleGameScene* m_scene;
    std::vector<std::shared_ptr<Course::TileBase>> m_tiles;

}; // class ObjectManager

} // namespace Student


#endif // OBJECTMANAGER_H
