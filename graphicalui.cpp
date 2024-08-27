#include "graphicalui.h"
#include "level.h"
#include <iostream>
#include "mainwindow.h"

GraphicalUI::GraphicalUI(MainWindow* mw):
    ui_m(mw)
{}

void GraphicalUI::draw()
{
    ui_m->draw();
}

GraphicalUI::~GraphicalUI()
{
    ui_m = nullptr;
}

Input_gui GraphicalUI::move()
{
    Input_gui LC = ui_m->getLastClicked();
    return LC;
}
