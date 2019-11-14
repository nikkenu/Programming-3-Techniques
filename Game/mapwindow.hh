#ifndef MAPWINDOW_HH
#define MAPWINDOW_HH

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QMouseEvent>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>

#include <map>
#include "boardinit.h"
#include "interfaces/igameeventhandler.h"
#include "gamescene.h"
#include "gameeventhandler.h"


namespace Ui {
class MapWindow;
}

class MapWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MapWindow(QWidget *parent = 0,
                       std::shared_ptr<Student::GameEventHandler> GEHandler = {}
                       );
    ~MapWindow();

    void setGEHandler(std::shared_ptr<Student::GameEventHandler> nHandler);

    void setSize(int width, int height);
    void setScale(int scale);
    void resize();

    void drawItem( std::shared_ptr<Course::GameObject> obj);
    void removeItem( std::shared_ptr<Course::GameObject> obj);
    void updateItem( std::shared_ptr<Course::GameObject> obj);


private:
    void resizeEvent(QResizeEvent* event);
    void mousePressEvent(QMouseEvent* event);

    Ui::MapWindow* m_ui;
    BoardInit* m_boardInit; // Could this be shared_ptr?
    std::shared_ptr<Student::GameEventHandler> m_GEHandler = nullptr;
    std::shared_ptr<Student::GameScene> m_scene = nullptr;

};

#endif // MapWINDOW_HH

