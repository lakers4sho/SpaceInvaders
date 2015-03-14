#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QObject>
#include <QKeyEvent>
#include <QPushButton>
#include <QRadioButton>
#include <QLabel>
#include <QVBoxLayout>
#include "game.h"
#include "quitwidget.h"
#include "instructions.h"

class Game;

namespace Ui {
class MainWindow;
}

/**
 *  @class MainWindow
 *  @brief The MainWindow class
 *
 *  This is the main menu that first pops out when the user starts the game. Has options for game mode, game difficulty, and a button for instructions.
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public slots:
    void play();
    void showInstructions();

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

     void setGame(Game* game);
     void setQuitWidget(QuitWidget* quit_widget);
     void closeEvent(QCloseEvent *e);

     Game* game;

private slots:
     void earthSelected() { };
     void skySelected() {};

private:

     QuitWidget* qwidget;

     QLabel* welcome;
     QLabel* gamemode;
     QLabel* difficulty;

     QRadioButton* earth;
     QRadioButton* space;

     QRadioButton* reasy;
     QRadioButton* rmedium;
     QRadioButton* rhard;

     QPushButton* startGame;
     QPushButton* instructions;

     QVBoxLayout* modes;
     QVBoxLayout* diff;

     QHBoxLayout* combo;

     QVBoxLayout* vLayout;

     QWidget* central;

     Instructions* instructionsWindow;
};

#endif // MAINWINDOW_H


/*
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
*/
