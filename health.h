#ifndef HEALTH_H
#define HEALTH_H


#include <QGraphicsTextItem>
#include <QFont>
#include "game.h"

/**
 *  @class Health
 *  @brief The Health class
 *
 *  This is the implementation of the player's health in the game.
 */
class Health : public QGraphicsTextItem {
public:
    Health(QGraphicsTextItem* parent = 0);
    void decreaseHealth();
    int getHealth();
private:
    int health;
};
#endif // HEALTH_H
