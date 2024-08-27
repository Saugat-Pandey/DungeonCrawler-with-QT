#ifndef DOOR_H
#define DOOR_H
#include "tile.h"
#include "passive.h"

class Door : public Tile, public Passive
{
public:
    Door(int row, int col, std::string texture);
    ~Door() = default;
    std::string getTexture() const override;
    bool onLeave(Tile* destTile, Character* who) override;
    std::pair<bool, Tile*> onEnter(Character* who) override;
    bool getOpen() const;
    void notify() override;
    QPixmap* getTex_ui() const override;


    void setOpen(bool newOpen);

private:
    bool open;
};

#endif // DOOR_H
