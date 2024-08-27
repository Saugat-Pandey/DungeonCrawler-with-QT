#include "ramp.h"

Ramp::Ramp(int row, int col, std::string texture):
    Tile(row, col, texture)
{
    setTex_ui(new QPixmap(":/textures/ramp.png"));
}

std::string Ramp::getTexture() const
{
    return Tile::getTexture();
}

bool Ramp::onLeave(Tile* destTile, Character* who){
    return true;
}

std::pair<bool, Tile*> Ramp::onEnter(Character* who)
{
    return Tile::onEnter(who);
}

QPixmap* Ramp::getTex_ui() const
{
    return Tile::getTex_ui();
}
