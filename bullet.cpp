#include "bullet.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "game.h"
#include "enemy.h"
#include <typeinfo>

#include<QDebug>

extern Game* game; // there is an external game object

/*
 * This is the constructor for the Bullet object.
 */
Bullet::Bullet(QPixmap bullet) : QGraphicsPixmapItem(bullet) {
    QTimer* timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);
}

/*
 * This function is the implementation for the movement of the bullet.
 */
void Bullet::move() {
    // if bullet collides with enemy, destroy both
    QList<QGraphicsItem*> colliding_items = collidingItems();
    for(size_t i=0,n=colliding_items.size();i<n;++i) {
        if(typeid(*colliding_items[i]) == typeid(Enemy)) { // check if the bullet collides with the enemy
            // increase the score
            game->score->increaseScore();
            // remove both
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            // then deallocate memory
            delete colliding_items[i];
            delete this;
            return;
        }
    }

    // moves bullet right
    setPos(x()+30,y());
    if(pos().x() > 800) {
        scene()->removeItem(this);
        delete this;
    }
}
