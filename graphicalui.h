#ifndef GRAPHICALUI_H
#define GRAPHICALUI_H
#include "abstractcontroller.h"
#include "dungeoncrawler.h"

class MainWindow;

class GraphicalUI : public AbstractController
{
public:
    GraphicalUI(MainWindow* mw);
    void draw();
    virtual ~GraphicalUI();
    Input_gui move() override;

private:
    MainWindow* ui_m;
};

#endif // GRAPHICALUI_H
