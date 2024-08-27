#ifndef SETFLOORTEXTURE_H
#define SETFLOORTEXTURE_H
#include "tile.h"

class SetFloorTexture : public Tile
{
public:
    SetFloorTexture(int row, int col, std::string texture);
};

#endif
