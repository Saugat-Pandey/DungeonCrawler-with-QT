#ifndef PIT_H
#define PIT_H
#include "tile.h"

class Pit : public Tile
{
public:
    Pit(int row, int col, std::string texture);
    std::string getTexture() const override;
    bool onLeave(Tile* destTile, Character* who) override;
    std::pair<bool, Tile*> onEnter(Character* who) override;
    QPixmap* getTex_ui() const override;
};

#endif // PIT_H
