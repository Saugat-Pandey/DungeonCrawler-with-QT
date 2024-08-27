#include "floor.h"

Floor::Floor(int row, int col, std::string texture):
    Tile(row, col, texture)
{
    int tmp = getRandom(1,5);
    switch(tmp)
    {
        case 1:
            setTex_ui(new QPixmap(":/textures/floor/floor1.png"));
            break;
        case 2:
            setTex_ui(new QPixmap(":/textures/floor/floor2.png"));
            break;
        case 3:
            setTex_ui(new QPixmap(":/textures/floor/floor3.png"));
            break;
        case 4:
            setTex_ui(new QPixmap(":/textures/floor/floor4.png"));
            break;
        case 5:
            setTex_ui(new QPixmap(":/textures/floor/floor5.png"));
            break;
        default:
            setTex_ui(new QPixmap(":/textures/floor/floor5.png"));
            break;
    }
}

std::string Floor::getTexture() const
{
    return Tile::getTexture();
}

bool Floor::onLeave(Tile* destTile, Character* who)
{
    return true;
}

std::pair<bool, Tile*> Floor::onEnter(Character* who)
{
    return Tile::onEnter(who);
}

QPixmap* Floor::getTex_ui() const
{
    return Tile::getTex_ui();
}
