#include "switch.h"

Switch::Switch(int row, int col, std::string texture):
    Tile(row, col, texture)
{
    setTex_ui(new QPixmap(":/textures/switch.png"));
}

std::string Switch::getTexture() const
{
    return Tile::getTexture();
}

bool Switch::onLeave(Tile* destTile, Character* who)
{
    if(destTile->getTexture()=="_")
    {
        return false;
    }
    return true;
}

std::pair<bool, Tile*> Switch::onEnter(Character* who)
{
    this->activate();
    return{true, nullptr};
}

QPixmap* Switch::getTex_ui() const
{
    return Tile::getTex_ui();
}
