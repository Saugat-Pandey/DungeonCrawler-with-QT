#ifndef LEVELCHANGER_H
#define LEVELCHANGER_H
#include "portal.h"
#include "SetFloorTexture.h"

class Level;

class LevelChanger : public Portal
{
public:
    LevelChanger(int row, int col, std::string texture);
    ~LevelChanger() = default;
    void setDestination(SetFloorTexture* newDestination);
    Level* getLevel_dest() const;
    void setLevel_dest(Level* newLevel_dest);
    QPixmap* getTex_ui() const override;
    std::pair<bool, Tile*> onEnter(Character* who) override;
    SetFloorTexture* getDestination() const;

private:
    Level* level_dest;
    SetFloorTexture* destination;
};

#endif // LEVELCHANGER_H
