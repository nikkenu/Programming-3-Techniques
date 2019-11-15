#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent,
                       std::shared_ptr<Student::GameEventHandler> handler):
    QMainWindow(parent),
    m_ui(new Ui::MainWindow),
    m_GEHandler(handler),
    m_scene(new Student::GameScene(this))
{
    m_ui->setupUi(this);
    Student::GameScene* gameScene_ptr = m_scene.get();
    m_ui->graphicsView->setScene(dynamic_cast<QGraphicsScene*>(gameScene_ptr));
    m_ui->graphicsView->setStyleSheet("background:transparent");
    m_boardInit = new BoardInit(gameScene_ptr);
    m_boardInit->initialiseWorldGenerator();
    m_objectManager = std::make_shared<Student::ObjectManager>();
}

MainWindow::~MainWindow()
{
    delete m_ui;
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
    m_ui->graphicsView->fitInView(m_scene.get()->sceneRect(), Qt::KeepAspectRatio);
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    qDebug() << childAt(event->pos());
}

void MainWindow::startGame()
{
    std::string player1 = "Player1";
    std::string player2 = "Player2";
    QString turnText = "Turn:" + QString::fromStdString(player1);
    m_playerNames.push_back(player1);
    m_playerNames.push_back(player2);
    //m_objectManager->setPlayers(playerNames);
    //m_ui->turnLabel->setText(turnText);
    setLCDs();
}

void MainWindow::setLCDs()
{
    //std::vector<int> numbers = m_objectManager->playerWealth(inTurn);
    //m_ui->moneyAmount->display(numbers.at(0));
}


