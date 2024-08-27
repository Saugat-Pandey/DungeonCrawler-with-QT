#ifndef ATTACKCONTROLLER_H
#define ATTACKCONTROLLER_H
#include "abstractcontroller.h"
#include <iostream>
#include <string>
#include "level.h"
#include "character.h"

class Character;
class Level;

class AttackController : public AbstractController
{
public:
    AttackController(Level* level);
    Input_gui move() override;
    ~AttackController() =default;
    std::pair<int,int> getAttackerPosition();
    std::pair<int,int> getCharPosition();
    void setAttacker(Character *newAttacker);
private:
    Level* level;
    Character* Attacker;
    int Attacker_Mov;
};

#endif // ATTACKCONTROLLER_H
