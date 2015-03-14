#include "instructions.h"

/*
 * This is the implementation of the Instructions window.
 * @param parent is the parent Widget responsible for its memory.
 */
Instructions::Instructions(QWidget *parent) : QWidget(parent)
{
    instructions_ok = new QPushButton("OK");
    instruction = new QLabel();
    instruction->setText("Press the arrow keys to move the ship, spacebar to fire.");

    layout = new QVBoxLayout();
    layout->addWidget(instruction);
    layout->addWidget(instructions_ok);

    central = new QWidget();
    central->setLayout(layout);
    central->show();

    QObject::connect(instructions_ok, SIGNAL(clicked()), central, SLOT(close()));
}

void Instructions::closeWindow() {
    this->close();
}

/* Destructor for Instructions object */
Instructions::~Instructions()
{

}
