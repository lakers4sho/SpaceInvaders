#include "score.h"

/*
 * This is the implementation of the Score object.
 * @param parent is the parent Widget responsible for its memory.
 */
Score::Score(QGraphicsTextItem* parent) : QGraphicsTextItem(parent) {
    // initialize the score to 0
    score = 0;

    // draw the text
    setPlainText(QString("Score: ") + QString::number(score));
    setDefaultTextColor(Qt::yellow);
    setFont(QFont("Helvetica", 15));
}


/* This function increases the score of the user */
void Score::increaseScore() {
    score+=100;

    // redraw the score
    setPlainText(QString("Score: ") + QString::number(score));
}

/* This function decreases the score of the user */
void Score::decreaseScore() {
    score-=100;

    // redraw the score
    setPlainText(QString("Score: ") + QString::number(score));

}

/* This function returns the score of the player
 * @returns the score
 */
int Score::getScore() {
    return score;
}
