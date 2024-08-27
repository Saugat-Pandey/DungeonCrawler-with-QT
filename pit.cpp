#include "pit.h"

Pit::Pit(int row, int col, std::string texture):
    Tile(row, col, texture)
{
    setTex_ui(new QPixmap(":/textures/pit.png"));
}

std::string Pit::getTexture() const
{
    return Tile::getTexture();
}

bool Pit::onLeave(Tile* destTile, Character* who)
{
    auto tmp = destTile->getTexture();
    if(tmp == "_" || tmp == "<")
    {
        return true;
    }
    return false;
}

std::pair<bool, Tile*> Pit::onEnter(Character* who)
{
    return Tile::onEnter(who);
}

QPixmap* Pit::getTex_ui() const
{
    return Tile::getTex_ui();
}
