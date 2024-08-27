#ifndef RAMP_H
#define RAMP_H
#include "tile.h"

class Ramp : public Tile
{
public:
    Ramp(int row, int col, std::string texture);
    std::string getTexture() const override;
    bool onLeave(Tile* destTile, Character* who) override;
    std::pair<bool, Tile*> onEnter(Character* who) override;
    QPixmap* getTex_ui() const override;
};

#endif // RAMP_H
