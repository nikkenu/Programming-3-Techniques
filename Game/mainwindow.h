#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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
#include "objectmanager.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0,
               std::shared_ptr<Student::GameEventHandler> handler = {}
               );
    ~MainWindow();

    void setGEHandler(std::shared_ptr<Student::GameEventHandler> handler);
    void drawItem( std::shared_ptr<Course::GameObject> obj);
    void removeItem( std::shared_ptr<Course::GameObject> obj);
    void updateItem( std::shared_ptr<Course::GameObject> obj);

private:
    void resizeEvent(QResizeEvent* event);
    void mousePressEvent(QMouseEvent* event);
    void startGame();
    void setLCDs();
    void setLCDpalette();

    Ui::MainWindow* m_ui;
    Student::BoardInit* m_boardInit;
    std::shared_ptr<Student::GameEventHandler> m_GEHandler = nullptr;
    std::shared_ptr<Student::GameScene> m_scene = nullptr;
    std::shared_ptr<Student::ObjectManager> m_objectManager = nullptr;
    std::vector<std::string> m_playerNames;
    std::string m_inTurn = "Player 1";
};



#endif // MAINWINDOW_H
