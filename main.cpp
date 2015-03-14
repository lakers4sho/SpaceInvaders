#include <QApplication>
#include "game.h"
#include "mainwindow.h"
#include "quitwidget.h"


Game* game;

int main(int argc, char *argv[]) {

    QApplication a(argc, argv);
    /*
    game = new Game();
    game->show();
    */

    MainWindow* w = new MainWindow();
    QuitWidget* quit = new QuitWidget();
    game = new Game();
    w->setGame(game);
    w->setQuitWidget(quit);
    // w->setGame();
    w->show();

    QObject::connect(quit->quit_ok, SIGNAL(clicked()), &a, SLOT(quit()));

    return a.exec();
}
