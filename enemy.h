#ifndef ENEMY_H
#define ENEMY_H


#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QObject>
#include "health.h"

/**
 *  @class Enemy
 *  @brief The Enemy class
 *
 *  This class is the implementation of the enemies in the game that the player must defeat.
 */
class Enemy : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    Enemy(QPixmap enemy);
public slots:
    void move();
};


#endif // ENEMY_H
