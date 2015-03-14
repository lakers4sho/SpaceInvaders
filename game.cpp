#include "game.h"

/*
 * This is the implementation of the Game object.
 * @param parent is the parent Widget responsible for its memory.
 */
Game::Game(QWidget* parent) {

    QGraphicsScene* scene = new QGraphicsScene();

    QPixmap ship(":/images/ship");

    Player* player = new Player(ship);
    // player->setOffset(0,500); // ?????

    scene->addItem(player);

    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    // create score
    score = new Score();
    score->setPos(600,525);
    scene->addItem(score);

    // create health
    health = new Health();
    health->setPos(600,550);
    scene->addItem(health);

    QTimer* timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),player,SLOT(spawn()));
    timer->start(1000);

    QGraphicsView* view = new QGraphicsView(scene);

    view->setFixedSize(805,605);
    scene->setSceneRect(0,0,800,600);
    setScene(scene);

    QPixmap space(":/images/space");
    QPixmap sky(":/images/sky");
    QPixmap farback(":/images/farback");
    // scene->setBackgroundBrush(farback.scaled(800,600,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
    scene->setBackgroundBrush(space.scaled(800,600,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
    // scene->setBackgroundBrush(sky.scaled(800,600,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));

    // play background music
    QMediaPlayer* bgm = new QMediaPlayer();
    bgm->setMedia(QUrl("qrc:/sounds/bg"));
    bgm->play();
    if(bgm->state() == QMediaPlayer::StoppedState) bgm->play();

    setFocus();

    // show();

}

/* This function sets the background of the game. */
void Game::setBackground(QString background)
{
    this->background = background;
}
