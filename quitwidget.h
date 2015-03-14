#ifndef QUITWIDGET_H
#define QUITWIDGET_H
#include <QWidget>
#include <QLabel>
#include <QPushButton>


/**
 *  @class QuitWidget
 *  @brief The QuitWidget class
 *
 *  This is the window that pops out when the user tries to exit the game, asks for confirmation.
 */
class QuitWidget : public QWidget
{
public:
    explicit QuitWidget(QWidget *parent = 0);
    ~QuitWidget();

    QPushButton* quit_ok;
private:
    QLabel* quit_label;
    QPushButton* quit_cancel;

};

#endif // QUITWIDGET_H
