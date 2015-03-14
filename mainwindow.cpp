#include "mainwindow.h"
#include "ui_mainwindow.h"

// Game* game;

/*
 * This is the implementation of the MainWindow object, which is the main menu for the game.
 * @param parent is the parent Widget responsible for its memory.
 */
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)

{
    welcome = new QLabel("Welcome to Space Invaders!");
    gamemode = new QLabel("Mode:");
    difficulty = new QLabel("Difficulty:");

    earth = new QRadioButton("Earth");
    space = new QRadioButton("Space");

    reasy = new QRadioButton("Easy");
    rmedium = new QRadioButton("Normal");
    rhard = new QRadioButton("Hero");

    instructions = new QPushButton("Instructions");
    startGame = new QPushButton("START");

    modes = new QVBoxLayout();
    modes->addWidget(gamemode);
    modes->addWidget(earth);
    modes->addWidget(space);

    diff = new QVBoxLayout();
    diff->addWidget(difficulty);
    diff->addWidget(reasy);
    diff->addWidget(rmedium);
    diff->addWidget(rhard);

    modegroup = new QButtonGroup();
    modegroup->addButton(earth);
    modegroup->addButton(space);

    diffgroup = new QButtonGroup();
    diffgroup->addButton(reasy);
    diffgroup->addButton(rmedium);
    diffgroup->addButton(rhard);

    combo = new QHBoxLayout();
    combo->addLayout(modes);
    combo->addLayout(diff);

    vLayout = new QVBoxLayout();
    vLayout->addWidget(welcome);
    vLayout->addLayout(combo);
    vLayout->addWidget(instructions);
    vLayout->addWidget(startGame);

    central = new QWidget();
    central->setLayout(vLayout);
    this->setCentralWidget(central);

    QObject::connect(instructions, SIGNAL(clicked()), this, SLOT(showInstructions()));

}

/* This is the destructor of the MainWindow object */
MainWindow::~MainWindow()
{

}

/* This function activates the game object, allowing the user to play */
void MainWindow::play()
{
    game->show();

}

/* This functions shows the instructions window */
void MainWindow::showInstructions() {

    instructionsWindow = new Instructions();

}

/* This function links the MainWindow object to the Game object
 * @param g is the Game object to be linked to.
 */
void MainWindow::setGame(Game* g)
{
    game = g;
    QObject::connect(startGame, SIGNAL(clicked()), this, SLOT(play()));

}

/* This function is the implementation of the Close event functionality, which responds when the user tries to exit
 * @param e is the Close Event object which handles the response
 */
void MainWindow::closeEvent(QCloseEvent *e) {

    e->ignore();
    qwidget->show();

}

/* This function links the MainWindow object to the QuitWidget object.
 * @param quit_widget is the QuitWidget object to be linked to
 */
void MainWindow::setQuitWidget(QuitWidget* quit_widget) {
    qwidget = quit_widget;

}
