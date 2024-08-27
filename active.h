#ifndef ACTIVE_H
#define ACTIVE_H
#include <vector>
#include "passive.h"

class Active
{
public:
    Active();
    ~Active();
    void attach(Passive*);
    void detach(Passive*);
    void activate();
    std::vector<Passive *> getList_of_passive() const;

private:
    std::vector<Passive*>list_of_passive;
};

#endif // ACTIVE_H
