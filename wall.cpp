#include "wall.h"

Wall::Wall(int row, int col, std::string texture):
    Tile(row, col, texture)
{
    setTex_ui(new QPixmap(":/textures/wall/wall1.png"));
}

std::string Wall::getTexture() const
{
    if(hasCharacter())
    {
        return "X";
    }
    return Tile::getTexture();
}

bool Wall::onLeave(Tile* destTile, Character* who)
{
    return true;
}

std::pair<bool, Tile*> Wall::onEnter(Character* who)
{
    return{false,nullptr};
}

QPixmap* Wall::getTex_ui() const
{
    return Tile::getTex_ui();
}
