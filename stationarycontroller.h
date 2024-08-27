#ifndef STATIONARYCONTROLLER_H
#define STATIONARYCONTROLLER_H
#include "abstractcontroller.h"

class StationaryController : public AbstractController
{
public:
    StationaryController();
    Input_gui move() override;
    ~StationaryController();
};

#endif // STATIONARYCONTROLLER_H
