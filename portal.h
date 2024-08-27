#ifndef PORTAL_H
#define PORTAL_H
#include "tile.h"

class Portal : public Tile
{
public:
    Portal(int row, int col, std::string texture, int connector);
    virtual ~Portal();
    std::string getTexture() const override;
    bool onLeave(Tile *destTile, Character *who) override;
    std::pair<bool, Tile *> onEnter(Character *who) override;
    Portal* getDestination() const;
    int getConnector() const;
    void setConnector(int newConnector);
    void setDestination(Portal* newDestination);
    int getPortal_type() const override;
    void setPortal_type(int newPortal_type) override;
    virtual QPixmap* getTex_ui() const override;

private:
    Portal* destination;
    int connector;
};

#endif // PORTAL_H
