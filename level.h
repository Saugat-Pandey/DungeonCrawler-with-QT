#ifndef LEVEL_H
#define LEVEL_H
#include <string>
#include <vector>
#include "tile.h"
#include "levelchanger.h"
#include "SetFloorTexture.h"
#include "graph.h"

class Level
{
public:
    Level(int row, int col, std::string lvl);
    ~Level();
    Level(const Level& l);
    Level& operator=(const Level& l);
    LevelChanger *getLevel_ch();
    void setLevel_ch(LevelChanger *newLevel_ch);
    bool operator!=(Level lhs);
    void eraseAllCharacters();
    bool operator==(Level lhs);
    void setCharacters(const std::vector<Character *> &newCharacters);
    void removeCharacter(Character *c);
    SetFloorTexture *getChar_set() const;
    void setChar_set(SetFloorTexture *newChar_set);
    void createGraph();
    void updateGraph();
    std::vector<Node*> getPath(std::pair<int,int> from, std::pair<int,int> to);
    Tile* getTile(int row, int col);
    void removeCharacter(int ind);
    std::vector<Character*> getCharacters() const;
    std::string getLvl_string() const;
    std::vector<std::vector<Tile*>> getField() const;
    void setField(const std::vector<std::vector<Tile *> > &newField);
    void addCharacter(Character* newCharacter);
    void setLvl_string(const std::string &newLvl_string);
    void setCols(int newCols);
    void setRows(int newRows);
    void placeCharacter(Character* c, int row, int col);
    int getRows() const;
    int getCols() const;
    void setRows();
    void setCols();
 void updateLvlString();
private:
    std::vector<std::pair<int, int>> char_positions;
    std::vector<std::vector<Tile*>> field;
    std::vector<Character*> characters;
    std::string lvl_string;
    LevelChanger* level_ch;
    SetFloorTexture* char_set;
    int rows;
    int cols;
    Graph graph;

};

#endif // LEVEL_H
