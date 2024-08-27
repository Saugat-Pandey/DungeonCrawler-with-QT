

#include "character.h"
#include "stationarycontroller.h"
#include "guardiancontroller.h"
#include "tile.h"

Character::Character(std::string texture, int strength, int stamina, bool hum):
    texture(texture),
    char_tile(nullptr),
    moveDirection(down),
    human(hum),
    strength(strength),
    stamina(stamina),
    hitpoints(getMaxHP()),
    alive(true)
{
    if(!human)
    {
        if(texture == "1"){
            abstrCon = new StationaryController();
        }
        if(texture == "2"){
            abstrCon = new GuardianController("66444466");
        }
        if(texture == "3"){
            abstrCon = new GuardianController("2288664444668822");
        }
    }
}

Character::~Character()
{}

std::string Character::getTexture() const
{
    return texture;
}

Input_gui Character::move()
{
    return abstrCon->move();
}

Tile* Character::getChar_tile() const
{
    return char_tile;
}

void Character::setChar_tile(Tile* newChar_tile)
{
    char_tile = newChar_tile;
}

void Character::setMoveDirection(Input_gui newMoveDirection)
{
    moveDirection = newMoveDirection;
}

Input_gui Character::getMoveDirection() const
{
    return moveDirection;
}

bool Character::isHuman() const
{
    return human;
}

int Character::getMaxHP() const
{
    return 20+(this->stamina*5);
}

int Character::getStrength() const
{
    return strength;
}

void Character::setStrength(int newStrength)
{
    strength = newStrength;
}

bool Character::getAlive() const
{
    return alive;
}

void Character::setAlive(bool newAlive)
{
    alive = newAlive;
}

AbstractController *Character::getAbstrCon() const
{
return abstrCon;
}

void Character::setAbstrCon(AbstractController *newAbstrCon)
{
    abstrCon = newAbstrCon;
}

void Character::setStamina(int newStamina)
{
    stamina = newStamina;
}

int Character::getStamina() const
{
    return stamina;
}

int Character::getHitpoints() const
{
    return hitpoints;
}

void Character::setHitpoints(int newHitpoints)
{
    hitpoints = newHitpoints;
}
