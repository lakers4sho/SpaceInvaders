#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsTextItem>
#include <QFont>

/**
 *  @class Score
 *  @brief The Score class
 *
 *  This is the implementation of the game score.
 */
class Score : public QGraphicsTextItem {
public:
    Score(QGraphicsTextItem* parent = 0);
    void increaseScore();
    void decreaseScore();
    int getScore();
private:
    int score;
};

#endif // SCORE_H
