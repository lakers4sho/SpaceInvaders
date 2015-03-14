#include "health.h"

/*
 * This is the implementation of the Game object.
 * @param parent is the parent Widget responsible for its memory.
 */
Health::Health(QGraphicsTextItem* parent) : QGraphicsTextItem(parent) {
    // initialize the health to 3
    health = 3;

    // draw the text
    setPlainText(QString("Health: ") + QString::number(health));
    setDefaultTextColor(Qt::red);
    setFont(QFont("Helvetica", 15));
}


/* This function decreases the health of the player*/
void Health::decreaseHealth() {
    health-=1;
    // redraw the health
    setPlainText(QString("Health: ") + QString::number(health));
}

int Health::getHealth() {
    return health;
}
