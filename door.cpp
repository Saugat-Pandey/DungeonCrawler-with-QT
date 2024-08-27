#include "door.h"

Door::Door(int row, int col, std::string texture):
    Tile(row, col, texture),
    open(false)
{
    setTex_ui(new QPixmap(":/textures/doors/door1.png"));
}

std::string Door::getTexture() const
{
    if(open)
    {
        return "\\";
    }
    return Tile::getTexture();
}

bool Door::onLeave(Tile* destTile, Character* who)
{
    return true;
}

std::pair<bool, Tile*>Door::onEnter(Character* who)
{
    if(open)
    {
        return Tile::onEnter(who);
    }
    return {false,nullptr};
}

void Door::notify()
{

    open =!(open);
    if(open)
    {
        setTex_ui(new QPixmap(":textures/doors/door2.png"));
    }
    else
    {
        setTex_ui(new QPixmap(":textures/doors/door1.png"));
    }

}

QPixmap* Door::getTex_ui() const
{
    return Tile::getTex_ui();
}

void Door::setOpen(bool newOpen)
{
    open = newOpen;
}

bool Door::getOpen() const
{
    return open;
}
