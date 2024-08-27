#ifndef CHARACTER_H
#define CHARACTER_H
#include <string>
#include "abstractcontroller.h"

class Tile;

class Character
{
public:
    Character(std::string texture, int strength, int stamina, bool hum = true);

    std::string getTexture() const;
    Input_gui move();
    ~Character();
    Tile* getChar_tile() const;
    void setChar_tile(Tile* newChar_tile);
    void setMoveDirection(Input_gui newMoveDirection);
    Input_gui getMoveDirection() const;
    bool isHuman() const;
    int getMaxHP() const;
    int getStrength() const;
    int getStamina() const;
    int getHitpoints() const;
    void setStamina(int newStamina);
    void setHitpoints(int newHitpoints);
    void setStrength(int newStrength);

    bool getAlive() const;
    void setAlive(bool newAlive);
    AbstractController *getAbstrCon() const;
    void setAbstrCon(AbstractController *newAbstrCon);
private:
    std::string texture;
    Tile* char_tile;
    AbstractController* abstrCon;
    Input_gui moveDirection;
    bool human;
    int strength;
    int stamina;
    int hitpoints;
    bool alive;
};

#endif // CHARACTER_H
