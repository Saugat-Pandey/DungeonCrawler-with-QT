#include "tile.h"
#include "random.h"

Tile::Tile(int row, int col, std::string texture):
    portal_type(0),
    floor_tile_type(getRandom(1,5)),
    texture(texture),
    character(nullptr),
    row(row),
    col(col),
    tex_ui(nullptr)
{

}

Tile::~Tile()
{
    delete tex_ui;
    tex_ui = nullptr;
    delete character;
    character = nullptr;
}

std::string Tile::getTexture() const
{
    return texture;
}

bool Tile::hasCharacter() const
{
    if(character!=nullptr){
        return true;
    }
    return false;
}

bool Tile::moveTo(Tile* destTile, Character* who)
{
    std::pair<bool, Tile*> tempEnter = destTile->onEnter(who);
    if(tempEnter.first == false)
    {
        return false;
    }
    bool tempLeave = this->onLeave(destTile, who);

    if(tempLeave&&tempEnter.first)
    {
        if(tempEnter.second==nullptr)
        {
            destTile->setCharacter(who);
            this->setCharacter(nullptr);
            who->setChar_tile(destTile);
            return true;
        }
        else
        {
            if(tempEnter.second->getTexture() == "O")
            {
                Tile* por_dest = tempEnter.second;
                por_dest->setCharacter(who);
                this->setCharacter(nullptr);
                who->setChar_tile(por_dest);
                return true;
            }
            if(tempEnter.second->getTexture() == "&")
            {
                Tile* por_dest = tempEnter.second;
                por_dest->setCharacter(who);
                this->setCharacter(nullptr);
                who->setChar_tile(por_dest);
                return true;
            }
            if(tempEnter.second->getTexture() == "S")
            {
                Tile* port_dest = tempEnter.second;
                port_dest->setCharacter(who);
                this->setCharacter(nullptr);
                who->setChar_tile(port_dest);
                return true;
            }
        }
    }
    return false;
}

bool Tile::onLeave(Tile* destTile, Character* who)
{
    return true;
}

std::pair<bool, Tile*> Tile::onEnter(Character* who)
{
    if(this->hasCharacter()){
        Character* present_char = this->getCharacter();
        if((!who->isHuman() && !present_char->isHuman()) || (who->isHuman() && present_char->isHuman())){
            return {false, nullptr};
        }
        present_char->setHitpoints(present_char->getHitpoints() - who->getStrength());
        who->setHitpoints(who->getHitpoints() - present_char->getStrength());
        if(present_char->getHitpoints() <= 0 || who->getHitpoints() <= 0)
        {
            if(who->getHitpoints() <= 0){
                who->setAlive(false);
            }
            if(present_char->getHitpoints() <= 0){
                present_char->setAlive(false);
            }
            return {false, nullptr};
        }
        else
        {
            return {false, nullptr};
        }
    }
    return {true, nullptr};
}

Character* Tile::getCharacter() const
{
    return character;
}

void Tile::setCharacter(Character* newCharacter)
{
    character = newCharacter;
}

int Tile::getRow() const
{
    return row;
}

int Tile::getCol() const
{
    return col;
}

QPixmap *Tile::getTex_ui() const
{
    return tex_ui;
}

void Tile::setTex_ui(QPixmap *newTex_ui)
{
    tex_ui = newTex_ui;
}

int Tile::getPortal_type() const
{
    return portal_type;
}

void Tile::setPortal_type(int newPortal_type)
{
    portal_type = newPortal_type;
}

int Tile::getFloor_tile_type() const
{
    return floor_tile_type;
}

void Tile::setFloor_tile_type(int newFloor_tile_type)
{
    floor_tile_type = newFloor_tile_type;
}

Tile* getDestination_2()
{
    return nullptr;
}

std::pair<int, int> Tile::getCords() const
{
    return {row, col};
}
