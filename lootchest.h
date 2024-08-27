#ifndef LOOTCHEST_H
#define LOOTCHEST_H
#include "tile.h"

class LootChest : public Tile
{
public:
    LootChest(int row, int col, std::string texture);
    std::string getTexture() const override;
    bool onLeave(Tile* destTile, Character* who) override;
    std::pair<bool, Tile*> onEnter(Character* who) override;
};

#endif // LOOTCHEST_H
