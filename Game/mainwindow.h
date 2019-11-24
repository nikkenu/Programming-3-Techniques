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
    /**
     * @brief Getting player names from start up dialog.
     * @see Dialog class.
     */
    void startGame(QStringList names);
    void resetLCDslot();

private:

    /**
     * @brief When window is resized, event is trigged, which
     * automatically fits the QGraphicsScene to QGraphicsView.
     * @param event that has happened.
     */
    void resizeEvent(QResizeEvent* event);

    /**
     * @brief Sets player resource in UI.
     */
    void setLCDs();

    /**
     * @brief Sets LCDNumber palette to wanted color
     */
    void setLCDpalette();

    /**
     * @brief Create custom worker labels, then
     * add them to UI.
     * @see ItemLabel class
     */
    void initializeWorkerMenu();

    /**
     * @brief Create custom building labels, then
     * add them to UI.
     * @see ItemLabel class
     */
    void initializeBuildingMenu();

    /**
     * @brief Mostly done, because we are avoiding to
     * initialize everything in MainWindow constructor
     */
    void initializeGame();

    /**
     * @brief Changes the turn when "End Turn"-button
     * is pressed
     * @see ObjectManager class
     */
    void changeTurn();

    /**
     * @brief Set's the name of the player who's in turn
     * to the label at mainwindow.
     */
    void setTurnLabel();

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
    unsigned int m_inTurnNumber = 0;
};



#endif // MAINWINDOW_H
