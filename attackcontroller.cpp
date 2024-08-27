#include "attackcontroller.h"
#include <map>

AttackController::AttackController(Level *level) : level(level),Attacker_Mov(0)
{
}
void AttackController::setAttacker(Character *newAttacker)
{
    Attacker = newAttacker;
}

std::pair<int, int> AttackController::getAttackerPosition()
{
    std::pair<int, int> AttackerPosition;
    AttackerPosition = Attacker->getChar_tile()->getCords();
    return AttackerPosition;
}

std::pair<int, int> AttackController::getCharPosition()
{
    for(auto charac: level->getCharacters()){
        if(charac->isHuman()){
            return charac->getChar_tile()->getCords();
        }
    }
    return std::make_pair(-1,-1);
}

Input_gui AttackController::move() {
    Attacker_Mov++;
    if (Attacker_Mov % 3 == 1) {
        Attacker_Mov = 1;
        return terminate;
    }

    std::pair<int, int> from = getAttackerPosition();
    std::pair<int, int> to = getCharPosition();

    if (to == std::pair<int, int>(-1, -1)) {
        return terminate;
    }

    auto path = level->getPath(from, to);
    if (path.empty() || path.size() == 1) {
        return terminate;
    }

    std::pair<int, int> nextTile = path[1]->position;

    std::map<std::pair<int, int>, Input_gui> directionMap = {
        {{from.first - 1, from.second - 1}, upleft},
        {{from.first - 1, from.second}, up},
        {{from.first - 1, from.second + 1}, upright},
        {{from.first, from.second - 1}, left},
        {{from.first, from.second}, terminate},
        {{from.first, from.second + 1}, right},
        {{from.first + 1, from.second - 1}, downleft},
        {{from.first + 1, from.second}, down},
        {{from.first + 1, from.second + 1}, downright}
    };

    auto it = directionMap.find(nextTile);
    if (it != directionMap.end()) {
        return it->second;
    }

    return terminate;
}


