#include "portal.h"

Portal::Portal(int row, int col, std::string texture, int connector):
    Tile(row, col, texture),
    destination(nullptr),
    connector(connector)
{
    switch(getConnector())
    {
        case 1:
            setTex_ui(new QPixmap(":/textures/portal/portal1.png"));
            break;
        case 2:
            setTex_ui(new QPixmap(":/textures/portal/portal2.png"));
            break;
        default:
            break;
    }
}

Portal::~Portal()
{
    destination = nullptr;
}

std::string Portal::getTexture() const
{
    return Tile::getTexture();
}

bool Portal::onLeave(Tile* destTile, Character* who)
{
    return true;
}

std::pair<bool, Tile*> Portal::onEnter(Character* who)
{
    return {true, destination};
}

Portal* Portal::getDestination() const
{
    return destination;
}

int Portal::getConnector() const
{
    return connector;
}

void Portal::setConnector(int newConnector)
{
    connector = newConnector;
}

void Portal::setDestination(Portal* newDestination)
{
    destination = newDestination;
}

int Portal::getPortal_type() const
{
    return Tile::getPortal_type();
}

void Portal::setPortal_type(int newPortal_type)
{
    Tile::setPortal_type(newPortal_type);
}

QPixmap *Portal::getTex_ui() const
{
    return Tile::getTex_ui();
}

