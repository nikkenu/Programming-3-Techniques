#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QMouseEvent>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include <QGridLayout>
#include <QLabel>
#include <QVector>
#include <QDrag>
#include <QMimeData>

#include <map>
#include "boardinit.h"
#include "interfaces/igameeventhandler.h"
#include "gamescene.h"
#include "gameeventhandler.h"
#include "objectmanager.h"
#include "itemlabel.h"
#include "gamegraphicsview.h"
#include "staticstorage.h"

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

public slots:
    void startGame(QString name1, QString name2, QString name3, QString name4);

private:
    void resizeEvent(QResizeEvent* event);

    void setLCDs();
    void setLCDpalette();
    void initializeWorkerMenu();
    void initializeBuildingMenu();
    void initializeGame();

    Ui::MainWindow* m_ui;
    Student::BoardInit* m_boardInit;
    QGridLayout* m_workerLayout;
    QGridLayout* m_buildingLayout;
    std::shared_ptr<Student::GameEventHandler> m_GEHandler = nullptr;
    std::shared_ptr<Student::GameScene> m_scene = nullptr;
    std::shared_ptr<Student::ObjectManager> m_objectManager = nullptr;
    std::shared_ptr<Student::GameGraphicsView> m_graphicsView = nullptr;
    std::vector<QString> m_playerNames;

    std::string m_inTurn;
};



#endif // MAINWINDOW_H
