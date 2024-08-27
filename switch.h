#ifndef SWITCH_H
#define SWITCH_H
#include "tile.h"
#include "active.h"

class Switch : public Tile, public Active
{
public:
    Switch(int row, int col, std::string texture);
    ~Switch() = default;
    std::string getTexture() const override;
    bool onLeave(Tile* destTile, Character* who) override;
    std::pair<bool, Tile*> onEnter(Character* who) override;
    QPixmap* getTex_ui() const override;
};

#endif // SWITCH_H
