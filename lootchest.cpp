#include "lootchest.h"

LootChest::LootChest(int row, int col, std::string texture):
    Tile(row, col, texture)
{
    setTex_ui(new QPixmap(":/textures/chest.png"));
}

std::string LootChest::getTexture() const
{
    return Tile::getTexture();
}

bool LootChest::onLeave(Tile* destTile, Character* who)
{
    return true;
}

std::pair<bool, Tile*>LootChest::onEnter(Character* who)
{
    return {who->isHuman(), nullptr};
}
