#include "enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include "stdlib.h"
#include "game.h"
#include <typeinfo>

extern Game* game;

/*
 * This is the constructor for the enemy object.
 */
Enemy::Enemy(QPixmap enemy) : QGraphicsPixmapItem(enemy) {

    int random_number = rand()%500; // randomizes the initial position of the enemy
    setPos(800,random_number);

    QTimer* timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50); // randomizes the times when the enemy appears
}

/*
 * This is the implementation of the enemy movement.
 */
void Enemy::move() {

    QList<QGraphicsItem*> colliding_items = collidingItems();
    for(size_t i=0,n=colliding_items.size();i<n;++i) {
        if(typeid(*colliding_items[i]) == typeid(Player)) { // check if the enemy collides with the player
            // decrease the health
            game->health->decreaseHealth();
            // remove enemy
            scene()->removeItem(this);
            // then deallocate memory
            delete this;
            return;
        }
    }

    setPos(x()-30,y());
    if(pos().x() < 0) {

        // decrease the score
        game->score->decreaseScore();

        scene()->removeItem(this);
        delete this;
    }

}
