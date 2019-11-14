#include "mapwindow.hh"
#include "ui_mapwindow.h"
#include "staticstorage.h"

#include "mapitem.h"
#include "QDebug"
#include <math.h>

MapWindow::MapWindow(QWidget *parent,
                     std::shared_ptr<Student::GameEventHandler> handler):
    QMainWindow(parent),
    m_ui(new Ui::MapWindow),
    m_GEHandler(handler),
    m_scene(new Student::GameScene(this))
{
    m_ui->setupUi(this);
    Student::GameScene* sgs_rawptr = m_scene.get();

    m_ui->graphicsView->setScene(dynamic_cast<QGraphicsScene*>(sgs_rawptr));
    m_ui->graphicsView->setStyleSheet("background:transparent");

    m_boardInit = new BoardInit(sgs_rawptr);
    m_boardInit->initialiseWorldGenerator();

}

MapWindow::~MapWindow()
{
    delete m_ui;
}

void MapWindow::setGEHandler(
        std::shared_ptr<Student::GameEventHandler> nHandler)
{
    m_GEHandler = nHandler;
}

void MapWindow::setSize(int width, int height)
{
    m_scene->setSize(width, height);
}

void MapWindow::setScale(int scale)
{
    m_scene->setScale(scale);
}

void MapWindow::resize()
{
    m_scene->resize();
}

void MapWindow::updateItem(std::shared_ptr<Course::GameObject> obj)
{
    m_scene->updateItem(obj);
}

void MapWindow::resizeEvent(QResizeEvent *event)
{
    Q_UNUSED(event)
    m_ui->graphicsView->fitInView(m_scene.get()->sceneRect(), Qt::KeepAspectRatio);
}

void MapWindow::mousePressEvent(QMouseEvent *event)
{
    qDebug() << childAt(event->pos());
}

void MapWindow::removeItem(std::shared_ptr<Course::GameObject> obj)
{
    m_scene->removeItem(obj);
}

void MapWindow::drawItem( std::shared_ptr<Course::GameObject> obj)
{
    m_scene->drawItem(obj);
}
