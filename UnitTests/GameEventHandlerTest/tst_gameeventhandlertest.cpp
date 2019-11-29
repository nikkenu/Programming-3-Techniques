#include <QtTest>
#include "objectmanager.h"

// add necessary includes here

class GameEventHandlerTest : public QObject
{
    Q_OBJECT

public:
    GameEventHandlerTest();
    ~GameEventHandlerTest();

private slots:
    void testAddObjectManager();
    void testModifyResources();
    void testGetWinner();

private:
    std::shared_ptr<Student::GameEventHandler> m_gameEventHandler = nullptr;
    std::shared_ptr<Student::ObjectManager> m_objectManager = nullptr;
};

GameEventHandlerTest::GameEventHandlerTest()
{
    m_gameEventHandler.reset();
    m_gameEventHandler = std::make_shared<Student::GameEventHandler>();
    QVERIFY(m_gameEventHandler != nullptr);
}

GameEventHandlerTest::~GameEventHandlerTest()
{  

}

void GameEventHandlerTest::testAddObjectManager()
{
    QVERIFY(m_gameEventHandler->getObjectManager() == nullptr);
    m_objectManager = std::make_shared<Student::ObjectManager>();
    m_gameEventHandler->addObjectManager(m_objectManager);
    QVERIFY(m_gameEventHandler->getObjectManager() != nullptr);
}

void GameEventHandlerTest::testModifyResources()
{
    std::shared_ptr<Student::Player> player = std::make_shared<Student::Player>("Player");

    Course::ResourceMap playerRes = {
        {Course::BasicResource::MONEY, 1},
        {Course::BasicResource::FOOD, 1},
    };

    int moneyAtStart = player->money;
    int foodAtStart = player->food;

    m_gameEventHandler->modifyResources(player, playerRes);

    int moneyAfter = player->money;
    int foodAfter = player->food;

    QVERIFY(moneyAtStart > moneyAfter);
    QVERIFY(foodAtStart > foodAfter);
    qDebug() << "Money at the start: " << moneyAtStart << " Food: " << foodAtStart << "\n" <<
                "Money after" << moneyAfter << " Food: " << foodAfter;

}

void GameEventHandlerTest::testGetWinner()
{
    QString player1 = "First";
    QString player2 = "Second";
    std::vector<QString> players = {};
    players.push_back(player1);
    players.push_back(player2);

    Course::ResourceMap playerRes = {
        {Course::BasicResource::MONEY, 100},
    };

    m_objectManager->setPlayers(players);
    m_gameEventHandler->modifyResources(m_objectManager->getPlayer("First"), playerRes);

    QString winner = m_gameEventHandler->getWinner();
    QVERIFY(winner == "First");
}


QTEST_APPLESS_MAIN(GameEventHandlerTest)

#include "tst_gameeventhandlertest.moc"
