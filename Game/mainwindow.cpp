#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"

MainWindow::MainWindow(QWidget *parent, std::shared_ptr<Student::GameEventHandler> handler):
    QMainWindow(parent),
    m_ui(new Ui::MainWindow),
    m_GEHandler(handler),
    m_scene(new Student::GameScene(this))
{
    m_ui->setupUi(this);

    m_objectManager = std::make_shared<Student::ObjectManager>();
    m_GEHandler = std::make_shared<Student::GameEventHandler>();
    Student::GameScene* gameScene_ptr = m_scene.get();
    m_graphicsView = std::make_shared<Student::GameGraphicsView>(gameScene_ptr);
    m_graphicsView->setScene(gameScene_ptr);
    m_ui->verticalLayout->addWidget(m_graphicsView.get());
    m_scene->addObjectManager(m_objectManager);
    m_objectManager->addGameEventHandler(m_GEHandler);
    m_GEHandler->addObjectManager(m_objectManager);
    initializeGame();
    QObject::connect(m_scene.get(), &Student::GameScene::resetLCDsignal,
                     this, &MainWindow::resetLCDslot);
    connect(m_ui->endTurnPushButton, &QPushButton::clicked,
            this, &MainWindow::changeTurn);

}

MainWindow::~MainWindow()
{
    delete m_ui;
    delete m_boardInit;
    delete m_workerLayout;
    delete m_buildingLayout;
}

void MainWindow::setGEHandler(std::shared_ptr<Student::GameEventHandler> handler)
{
    m_GEHandler = handler;
}

void MainWindow::drawItem(std::shared_ptr<Course::GameObject> obj)
{
    m_scene->drawItem(obj);
}

void MainWindow::removeItem(std::shared_ptr<Course::GameObject> obj)
{
    m_scene->removeItem(obj);
}

void MainWindow::updateItem(std::shared_ptr<Course::GameObject> obj)
{
    m_scene->updateItem(obj);
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    Q_UNUSED(event)
    m_graphicsView->fitInView(m_scene.get()->sceneRect(), Qt::KeepAspectRatio);
}


void MainWindow::startGame(QStringList names)
{
    for(QString name : names)
    {
        m_playerNames.push_back(name);
    }

    setTurnLabel();
    m_objectManager->setPlayers(m_playerNames);  
    setLCDs();
}

void MainWindow::resetLCDslot()
{
    setLCDs();
}


void MainWindow::setLCDs()
{
    std::vector<int> numbers = m_objectManager->playerWealth(m_inTurn);
    m_ui->moneyLCDNumber->display(numbers.at(0));
    m_ui->foodLCDNumber->display(numbers.at(1));
    m_ui->woodLCDNumber->display(numbers.at(2));
    m_ui->stoneLCDNumber->display(numbers.at(3));
    m_ui->oreLCDNumber->display(numbers.at(4));
}

void MainWindow::setLCDpalette()
{
    m_ui->moneyLCDNumber->setPalette(Qt::black);
    m_ui->foodLCDNumber->setPalette(Qt::black);
    m_ui->woodLCDNumber->setPalette(Qt::black);
    m_ui->stoneLCDNumber->setPalette(Qt::black);
    m_ui->oreLCDNumber->setPalette(Qt::black);
}

void MainWindow::initializeWorkerMenu()
{
    m_workerLayout = new QGridLayout();
    Student::ItemLabel* worker = new Student::ItemLabel(Student::StaticStorage::WORKER);
    Student::ItemLabel* farmer = new Student::ItemLabel(Student::StaticStorage::FARMER);
    Student::ItemLabel* miner = new Student::ItemLabel(Student::StaticStorage::MINER);

    m_workerLayout->addWidget(worker, 0, 0);
    m_workerLayout->addWidget(farmer, 0, 1);
    m_workerLayout->addWidget(miner, 0, 2);

    m_ui->verticalLayout_4->addLayout(m_workerLayout);
}

void MainWindow::initializeBuildingMenu()
{
    m_buildingLayout = new QGridLayout();
    Student::ItemLabel* headquarter = new Student::ItemLabel(Student::StaticStorage::HEADQUARTER);
    Student::ItemLabel* outpost = new Student::ItemLabel(Student::StaticStorage::OUTPOST);
    Student::ItemLabel* farm = new Student::ItemLabel(Student::StaticStorage::FARM);
    Student::ItemLabel* oilrig = new Student::ItemLabel(Student::StaticStorage::OILRIG);
    Student::ItemLabel* mine = new Student::ItemLabel(Student::StaticStorage::MINE);

    m_buildingLayout->addWidget(headquarter, 0, 0);
    m_buildingLayout->addWidget(outpost, 0, 1);
    m_buildingLayout->addWidget(farm, 0, 2);
    m_buildingLayout->addWidget(oilrig, 1, 0);
    m_buildingLayout->addWidget(mine, 1, 1);

    m_ui->verticalLayout_5->addLayout(m_buildingLayout);
}

void MainWindow::initializeGame()
{
    m_boardInit = new Student::BoardInit(m_objectManager, m_GEHandler);
    initializeWorkerMenu();
    initializeBuildingMenu();
    setLCDpalette();

    for(auto k : m_objectManager->getAllTiles())
    {
        m_scene->drawItem(k);
    }
}

void MainWindow::changeTurn()
{

    if (m_inTurnNumber == m_playerNames.size() - 1)
    {      
        if (m_round == 10)
        {
            winner = m_GEHandler->getWinner();
            QMessageBox msgBox;
            msgBox.setWindowTitle("Game over");
            msgBox.setText(winner + " won!");
            msgBox.exec();
            this->close();
        }
        else
        {
            m_inTurnNumber = 0;
            m_round++;
            QString roundText = "Round: " + QString::number(m_round);
            m_ui->roundLabel->setText(roundText);
            m_objectManager->setPlayerInTurn(m_inTurnNumber);
            m_objectManager->gainPlayerResources();
        }
    }
    else
    {
        m_inTurnNumber++;
        m_objectManager->setPlayerInTurn(m_inTurnNumber);
    }
    setTurnLabel();
    setLCDs();

}

void MainWindow::setTurnLabel()
{
    QString turnText = "Turn: " + m_playerNames.at(m_inTurnNumber);
    m_inTurn = m_playerNames.at(m_inTurnNumber).toStdString();
    m_ui->playerTurnLabel->setText(turnText);
}



