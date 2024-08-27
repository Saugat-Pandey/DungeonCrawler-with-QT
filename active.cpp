#include "active.h"

Active::Active() {}

Active::~Active()
{
    for(auto passive:list_of_passive)
    {
        detach(passive);
    }
}

void Active::attach(Passive* p)
{
    for(auto passive:list_of_passive)
    {
        if(passive==p)
        {
            return;
        }
    }
    list_of_passive.push_back(p);
}

void Active::detach(Passive* p)
{
    for(unsigned int i = 0; i < list_of_passive.size(); i++)
    {
        if(list_of_passive[i] == p)
        {
            list_of_passive.erase(list_of_passive.begin()+i);
        }
    }
}

void Active::activate()
{
    for(auto passive:list_of_passive)
    {
        passive->notify();
    }
}

std::vector<Passive *> Active::getList_of_passive() const
{
    return list_of_passive;
}
