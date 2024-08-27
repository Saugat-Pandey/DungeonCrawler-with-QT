#ifndef FLOOR_H
#define FLOOR_H
#include "tile.h"

class Floor : public Tile
{
public:
    Floor(int row, int col, std::string texture);
    virtual ~Floor() = default;
    std::string getTexture() const override;
    bool onLeave(Tile* destTile, Character* who) override;
    std::pair<bool, Tile*>onEnter(Character* who) override;
    QPixmap* getTex_ui() const override;

};

#endif // FLOOR_H
