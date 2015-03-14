#ifndef BULLET
#define BULLET

#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QObject>

/**
 *  @class Bullet
 *  @brief The Bullet class
 *
 *  This class is an implementation of the bullets that the player shoots to the enemies.
 */
class Bullet : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    Bullet(QPixmap bullet);
public slots:
    void move();
};

#endif // BULLET
