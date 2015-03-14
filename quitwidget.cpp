#include "quitwidget.h"
#include <QHBoxLayout>
#include <QVBoxLayout>

/*
 * This is the implementation of the QuitWidget object, a window which confirms the quit action for the player.
 * @param parent is the parent Widget responsible for its memory.
 */
QuitWidget::QuitWidget(QWidget* parent) : QWidget(parent)
{
    quit_label = new QLabel("Are you sure?");
    quit_ok = new QPushButton("OK");
    quit_cancel = new QPushButton("Cancel");

    QHBoxLayout* quit_hlayout = new QHBoxLayout;
    quit_hlayout->addWidget(quit_cancel);
    quit_hlayout->addWidget(quit_ok);

    QVBoxLayout* quit_vlayout = new QVBoxLayout;
    quit_vlayout->addWidget(quit_label);
    quit_vlayout->addLayout(quit_hlayout);

    this->setLayout(quit_vlayout);

    QObject::connect(quit_cancel, SIGNAL(clicked()), this, SLOT(hide()));
    QObject::connect(quit_ok, SIGNAL(clicked()), this,SLOT(close()));
}

/* This is the destructor for the QuitWidget object*/
QuitWidget::~QuitWidget()
{

}
