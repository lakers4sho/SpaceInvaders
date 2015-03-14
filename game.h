#ifndef GAME_H
#define GAME_H

#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QGraphicsView>
#include <QPixmap>
#include <QTimer>
#include <QGraphicsTextItem>
#include "player.h"
#include "score.h"
#include "health.h"
#include "game.h"
#include <QMediaPlayer>
#include <QString>

class Health;

/**
 *  @class Game
 *  @brief The Game class
 *
 *  This is the implementation of the actual game; includes pointers to the player, score, and health for easy reference.
 */
class Game : public QGraphicsView{
public:
    Game(QWidget* parent = 0);

    QGraphicsScene* scene;
    Player* player;
    Score* score;
    Health* health;

    QString mode;
    QString background;

    void setBackground(QString background);


};

#endif // GAME_H
