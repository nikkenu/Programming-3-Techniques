#include <QtTest>
#include "objectmanager.h"
#include "gameeventhandler.h"
#include "core/worldgenerator.h"
#include "tiles/forest.h"
#include "gamescene.h"
#include "studentresourcemaps.h"

#include "sand.h"
#include <QDebug>

// add necessary includes here

class ObjectManagerTest : public QObject
{
    Q_OBJECT

public:
    ObjectManagerTest();
    ~ObjectManagerTest();

private slots:
    void initializeObjectManager();
    void initializeGameEventHandler();
    void testAddingGameEventHandler();
    void testAddScene();
    void testAddTiles();
    void testSetAndGetPlayers();
    void testGainPlayerResources();
    void testSetPlayerInTurn();
    void testCreateBuilding();

private:
    std::shared_ptr<Student::ObjectManager> m_objectManager;
    std::shared_ptr<Student::GameEventHandler> m_gameEventHandler;

};

ObjectManagerTest::ObjectManagerTest()
{

}

ObjectManagerTest::~ObjectManagerTest()
{

}

void ObjectManagerTest::initializeObjectManager()
{
    m_objectManager.reset();
    m_objectManager = std::make_shared<Student::ObjectManager>();
    QVERIFY(m_objectManager != nullptr);
}

void ObjectManagerTest::initializeGameEventHandler()
{
    m_gameEventHandler.reset();
    m_gameEventHandler = std::make_shared<Student::GameEventHandler>();
    QVERIFY(m_gameEventHandler != nullptr);
}

void ObjectManagerTest::testAddScene()
{
   QCOMPARE(m_objectManager->checkSceneIsAlive(), false);
   //FIX THIS!
   //m_objectManager->addScene(new Student::GameScene);
   //QCOMPARE(m_objectManager->checkSceneIsAlive(), true);
}

void ObjectManagerTest::testAddingGameEventHandler()
{
    m_objectManager->addGameEventHandler(m_gameEventHandler);
    QVERIFY(m_objectManager->getGameEventHandler() != nullptr);
}

void ObjectManagerTest::testAddTiles()
{
    /*const Course::Coordinate coord(0,0);
    std::vector<std::shared_ptr<Course::TileBase>> tiles;
    std::shared_ptr<Course::TileBase> tile = std::make_shared<Course::TileBase>(coord, m_gameEventHandler, m_objectManager);
    tiles.push_back(tile);
    m_objectManager->addTiles(tiles); // CRASHES HERE*/
}

void ObjectManagerTest::testSetAndGetPlayers()
{
    std::vector<QString> names;
    QString player1 = "a";
    QString player2 = "b";
    names.push_back(player1);
    names.push_back(player2);
    m_objectManager->setPlayers(names);
    QVERIFY(m_objectManager->getPlayer("a"));
    QVERIFY(m_objectManager->getPlayer("b"));
}

void ObjectManagerTest::testGainPlayerResources()
{
    //WTF
}

void ObjectManagerTest::testSetPlayerInTurn()
{
    unsigned int testNumber = 1;
    m_objectManager->setPlayerInTurn(testNumber);
    QCOMPARE(m_objectManager->getPlayerInTurn(), testNumber);
    testNumber = 2;
    m_objectManager->setPlayerInTurn(testNumber);
    QVERIFY(m_objectManager->getPlayerInTurn() == testNumber);
}

void ObjectManagerTest::testCreateBuilding()
{
    QString hq = "Headquarter";
    QPointF point(1,1);
    Course::Coordinate coord(1,1);

    std::vector<QString> names;
    QString player1 = "a";
    QString player2 = "b";
    names.push_back(player1);
    names.push_back(player2);
    m_objectManager->setPlayers(names);

    unsigned int playerTurn = 1;
    m_objectManager->setPlayerInTurn(playerTurn);
    m_objectManager->createBuilding(hq, point, m_objectManager);
    //m_objectManager->getTile(coord)->getBuildings();

}

QTEST_APPLESS_MAIN(ObjectManagerTest)

#include "tst_objectmanagertest.moc"
