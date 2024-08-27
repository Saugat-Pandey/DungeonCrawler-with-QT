#ifndef TILE_H
#define TILE_H
#include <QPixmap>
#include <string>
#include "character.h"
#include "random.h"

class Tile
{
protected:
    Tile(int row, int col, std::string texture);

public:
    virtual ~Tile();
    virtual std::string getTexture() const;
    virtual bool hasCharacter() const;
    virtual bool moveTo(Tile* destTile, Character* who);
    virtual bool onLeave(Tile* destTile, Character* who);
    virtual std::pair<bool,Tile*> onEnter(Character* who);
    virtual Character* getCharacter() const;
    virtual void setCharacter(Character* newCharacter);
    virtual int getPortal_type() const;
    virtual void setPortal_type(int newPortal_type);
    virtual int getFloor_tile_type() const;
    virtual void setFloor_tile_type(int newFloor_tile_type);
    std::pair<int, int> getCords() const;

    int getRow() const;
    int getCol() const;

    virtual QPixmap *getTex_ui() const;
    virtual void setTex_ui(QPixmap *newTex_ui);

private:
    int portal_type;
    int floor_tile_type;
    std::string texture;
    Character* character;
    const int row;
    const int col;
    QPixmap* tex_ui;
};

#endif // TILE_H
