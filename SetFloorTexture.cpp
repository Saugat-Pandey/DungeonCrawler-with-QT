#include "SetFloorTexture.h"
SetFloorTexture::SetFloorTexture(int row, int col, std::string texture)
    : Tile(row, col, texture) {
    int tmp = getRandom(1, 5);
    if (tmp == 1) {
        setTex_ui(new QPixmap(":/textures/floor/floor1.png"));
    } else if (tmp == 2) {
        setTex_ui(new QPixmap(":/textures/floor/floor2.png"));
    } else if (tmp == 3) {
        setTex_ui(new QPixmap(":/textures/floor/floor3.png"));
    } else if (tmp == 4) {
        setTex_ui(new QPixmap(":/textures/floor/floor4.png"));
    } else if (tmp == 5) {
        setTex_ui(new QPixmap(":/textures/floor/floor5.png"));
    } else {
        setTex_ui(new QPixmap(":/textures/floor/floor5.png"));
    }
}

