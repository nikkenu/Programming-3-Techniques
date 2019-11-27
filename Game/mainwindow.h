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

/**
 * @brief The MainWindow class contains the gameboard and is the place
 * where the actual playing happens. This class's responsibility is to
 * handle all modification to the main ui.
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    /**
      *@brief Constructor.
      */
    MainWindow(QWidget *parent = 0,
               std::shared_ptr<Student::GameEventHandler> handler = {}
               );

    /**
      * @brief Deconstuctor, all pointer that are not smart pointer
      * are deleted here.
      */
    ~MainWindow();
    /**
     * @brief sets a pointer to GameEventHandler
     * @param handler points to student's GameEventHandler.
     */
    void setGEHandler(std::shared_ptr<Student::GameEventHandler> handler);

    /**
     * @brief drawItem calls GameScene's drawItem.
     * @param obj points to the object to be drawn.
     * @see GameScene's drawItem method.
     */
    void drawItem( std::shared_ptr<Course::GameObject> obj);

    /**
     * @brief Calls GameScene's removeItem.
     * @param obj points to the object to be removed.
     * @see GameScene's removeItem method.
     */
    void removeItem( std::shared_ptr<Course::GameObject> obj);

    /**
     * @brief Calls GameScene's updateItem.
     * @param obj points to the object to be updated.
     * @see GameScene's updateItem method.
     */
    void updateItem( std::shared_ptr<Course::GameObject> obj);

public slots:
    /**
     * @brief Getting player names from start up dialog.
     * @see Dialog class.
     */
    void startGame(QStringList names);

    /**
     * @brief Resets LCD's when player resources are modified.
     */
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
    unsigned int m_round = 1;
    QString winner;
};



#endif // MAINWINDOW_H
