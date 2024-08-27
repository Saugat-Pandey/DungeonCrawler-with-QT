#ifndef GUARDIANCONTROLLER_H
#define GUARDIANCONTROLLER_H
#include "abstractcontroller.h"
#include <string>
#include <vector>

class GuardianController : public AbstractController
{
public:
    GuardianController(std::string move_str);
    Input_gui move() override;
    ~GuardianController();

    std::string getMove_str() const;

private:
    std::string move_str;
    std::vector<int> results;
};

#endif // GUARDIANCONTROLLER_H
