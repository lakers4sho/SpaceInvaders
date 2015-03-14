#include "player.h"
#include "bullet.h"
#include "enemy.h"
#include <QGraphicsScene>
#include <QKeyEvent>

/*
 * This is the implementation of the Player object.
 * @param player is the parent Widget responsible for its memory.
 */
Player::Player(QPixmap player) : QGraphicsPixmapItem(player) {
    bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl("qrc:/sounds/fire"));

}

/*
 * This function is the implementation of the key action events which changes the state of the player depending on the key presses of the user.
 * @param event is the Key Press event which handles the responses.
 */
void Player::keyPressEvent(QKeyEvent* event) {
    if(event->key() == Qt::Key_Left) {
        if(pos().x() > 0) setPos(x()-20,y());
    }
    else if(event->key() == Qt::Key_Right) {
        if(pos().x()+59 < 800) setPos(x()+20,y());
    }
    else if(event->key() == Qt::Key_Up) {
        if(pos().y() > 0) setPos(x(),y()-20);
    }
    else if(event->key() == Qt::Key_Down) {
        if(pos().y()+77 < 600) setPos(x(),y()+20);
    }
    else if(event->key() == Qt::Key_Space) {
        QPixmap bulletpic(":/images/bullet");
        Bullet* bullet = new Bullet(bulletpic);
        bullet->setPos(x(),y());
        scene()->addItem(bullet);

        // play sound
        if(bulletsound->state() == QMediaPlayer::PlayingState) { // check if sound is already playing
            bulletsound->setPosition(0);
        }
        else if(bulletsound->state() == QMediaPlayer::StoppedState) bulletsound->play();
    }
}

/* This function is the implementation fo the enemy spawns. */
void Player::spawn() {
    QPixmap enemy1(":/images/enemy1");
    Enemy* enemy1e = new Enemy(enemy1);
    scene()->addItem(enemy1e);
}
