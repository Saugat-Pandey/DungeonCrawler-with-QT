#include "startscreen.h"
#include "ui_startscreen.h"
#include "mainwindow.h"
#include <QPushButton>

StartScreen::StartScreen(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::StartScreen)
{
    ui->setupUi(this);
    this->setStyleSheet("background-color: rgb(0,0,0); border-image: url(:textures/startscreen.png);");

    auto* button = new QPushButton();
    button->setFixedSize(200, 100);
    button->setStyleSheet("border-image: url(:/textures/new_game_button.png);");
    ui->gridLayout->addWidget(button, 0, 0, Qt::AlignBottom);
    connect(button, SIGNAL(clicked()), this, SLOT(buttonclick()));
}

StartScreen::~StartScreen()
{
    delete ui;
    ui = nullptr;
}

void StartScreen::buttonclick()
{
    this->close();
}

void StartScreen::resizeEvent(QResizeEvent* event)
{
    QMainWindow::resizeEvent(event);

    const int h = ui->centralWidget->height()/8;
    const int w = ui->centralWidget->width()/8;

    const int tmp = std::min(h,w);
    auto* widget = ui->gridLayout->itemAtPosition(0,0)->widget();
    widget->setFixedSize(tmp*2.5,tmp*1.5);
}
