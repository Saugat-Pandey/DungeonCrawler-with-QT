#include "guardiancontroller.h"

GuardianController::GuardianController(std::string move_str)
{
    for(char c : move_str)
    {
        if(isdigit(c))
        {
            results.push_back(c - '0');
        }
    }
}

Input_gui GuardianController::move()
{
    int index = results[0];
    results.erase(results.begin()+0);
    results.push_back(index);

    while(true)
    {
        switch(index)
        {
            case 8:
                return up;
                break;
            case 6:
                return right;
                break;
            case 2:
                return down;
                break;
            case 4:
                return left;
                break;
            default:
                return stand;
                break;
        }
    }
}

GuardianController::~GuardianController()
{
    results.clear();
}

std::string GuardianController::getMove_str() const
{
    return move_str;
}
