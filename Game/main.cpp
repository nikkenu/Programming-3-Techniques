#include "mainwindow.h"
#include "dialog.h"

#include <QApplication>


int main(int argc, char* argv[])
{

    QApplication app(argc, argv);
    Dialog dialog;
    MainWindow mainWindow;
    mainWindow.setWindowTitle("PIRKANMAAN VALLOITUS");
    dialog.setWindowTitle("Welcome to Pirkanmaa!");
    QObject::connect(&dialog, &Dialog::playerNameSignal,
                     &mainWindow, &MainWindow::startGame);
    if (dialog.exec() != QDialog::Accepted)
    {
        return 1;
    }
    mainWindow.show();
    return app.exec();
}
