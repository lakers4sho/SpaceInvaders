#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include "score.h"
#include <QMediaPlayer>

/**
 *  @class Player
 *  @brief The Player class
 *
 *  This is the implementation of the game player.
 */
class Player : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    Player(QPixmap player);

    void keyPressEvent(QKeyEvent* event);
public slots:
    void spawn();
private:
    QMediaPlayer* bulletsound;
};

#endif // PLAYER_H
