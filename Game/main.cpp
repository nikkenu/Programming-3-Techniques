#include "mapwindow.hh"

#include <QApplication>


int main(int argc, char* argv[])
{

    QApplication app(argc, argv);

    MapWindow mapWindow;
    mapWindow.setWindowTitle("PIRKANMAAN VALLOITUS");
    mapWindow.show();
    return app.exec();
}
