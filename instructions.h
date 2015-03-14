#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>

/**
 *  @class Instructions
 *  @brief The Instructions class
 *
 *  This is the window that describes the instructions on how to play the game. Pops out when the user clicks "Instructions" in the MainWindow.
 */
class Instructions : public QWidget
{
    Q_OBJECT

public:
    explicit Instructions(QWidget *parent = 0);
    ~Instructions();

public slots:
    void closeWindow();

private:
    QPushButton* instructions_ok;
    QLabel* instruction;

    QVBoxLayout* layout;
    QWidget* central;
};

#endif // INSTRUCTIONS_H
