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
    void testAddTiles();
    void testSetAndGetPlayers();
    void testSetPlayerInTurn();
    void testCreateBuilding();
    void testCreateWorker();
    void testPlayerWealth();
    void testGainPlayerResources();
    void testSellBuilding();

private:
    std::shared_ptr<Student::ObjectManager> m_objectManager;
    std::shared_ptr<Student::GameEventHandler> m_gameEventHandler;
    std::shared_ptr<Student::GameScene> m_scene;
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


void ObjectManagerTest::testAddingGameEventHandler()
{
    m_objectManager->addGameEventHandler(m_gameEventHandler);
    QVERIFY(m_objectManager->getGameEventHandler() != nullptr);
}

void ObjectManagerTest::testAddTiles()
{
    QVERIFY(m_objectManager->getAllTiles().empty());
    Course::Coordinate coord(0,0);
    std::vector<std::shared_ptr<Course::TileBase>> tiles;
    QVERIFY(m_objectManager != nullptr);
    std::shared_ptr<Course::TileBase> tile = std::make_shared<Course::TileBase>(coord, m_gameEventHandler, m_objectManager);
    tiles.push_back(tile);
    m_objectManager->addTiles(tiles);
    QVERIFY(!m_objectManager->getAllTiles().empty());

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

void ObjectManagerTest::testSetPlayerInTurn()
{
    unsigned int testNumber = 1;
    m_objectManager->setPlayerInTurn(testNumber);
    QCOMPARE(m_objectManager->getPlayerInTurn(), testNumber);
    testNumber = 2;
    m_objectManager->setPlayerInTurn(testNumber);
    QVERIFY(m_objectManager->getPlayerInTurn() == testNumber);

    // Set player turn back to 1, for other tests...
    testNumber = 1;
    m_objectManager->setPlayerInTurn(testNumber);
}

void ObjectManagerTest::testCreateBuilding()
{
    QString hq = "Headquarter";
    Course::Coordinate coord(0,0);
    QPointF point(0,0);
    QVERIFY(m_objectManager->getTile(coord)->getBuildingCount() == 0);
    m_objectManager->createBuilding(hq, point, m_objectManager);
    QVERIFY(m_objectManager->getTile(coord)->getBuildingCount() == 1);
}

void ObjectManagerTest::testCreateWorker()
{
    QString worker = "Worker";
    Course::Coordinate coord(0,0);
    QPointF point(0,0);

    QVERIFY(m_objectManager->getTile(coord)->getWorkerCount() == 0);
    m_objectManager->createWorker(worker, point, m_objectManager);
    QVERIFY(m_objectManager->getTile(coord)->getWorkerCount() == 1);
}

void ObjectManagerTest::testPlayerWealth()
{
    std::string player = "a";
    std::vector<int> wealth = m_objectManager->playerWealth(player);
    for(unsigned int i = 0; i < wealth.size(); ++i)
    {
        QCOMPARE(wealth.at(i), 1500);
    }
}

void ObjectManagerTest::testSellBuilding()
{
    QPointF point(0,0);
    std::string player = "b";
    std::vector<int> wealthAtStart = m_objectManager->playerWealth(player);
    QCOMPARE(m_objectManager->sellBuilding(point), true);
    std::vector<int> wealthAfter = m_objectManager->playerWealth(player);
    QVERIFY(wealthAtStart.at(0) != wealthAfter.at(0));
    qDebug() << "Money before selling the building: " << wealthAtStart.at(0) << "\n" <<
                "Money after selling the building: " << wealthAfter.at(0);
}

void ObjectManagerTest::testGainPlayerResources()
{
    std::string player = "b";
    std::vector<int> wealthAtStart = m_objectManager->playerWealth(player);
    m_objectManager->gainPlayerResources();
    std::vector<int> wealthAfter = m_objectManager->playerWealth(player);
    QVERIFY(wealthAtStart.at(0) != wealthAfter.at(0));
    qDebug() << "Money before gain resource call the building: " << wealthAtStart.at(0) << "\n" <<
                "Money after gain resource call the building: " << wealthAfter.at(0);

}

QTEST_APPLESS_MAIN(ObjectManagerTest)

#include "tst_objectmanagertest.moc"
