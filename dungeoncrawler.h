#ifndef DUNGEONCRAWLER_H
#define DUNGEONCRAWLER_H
#include "level.h"
#include "list.h"

class GraphicalUI;

class DungeonCrawler : public List<Level*>
{
public:
    DungeonCrawler();
    ~DungeonCrawler();
    DungeonCrawler(Level* level);
    DungeonCrawler(int rows, int cols, std::string l);
    bool turn();
    Level* getCurrentLevel() const;
    void setGr_ui(GraphicalUI* newGr_ui);
    void push_level_back(Level* level);
    void check_alive();
    bool isHuman_alive() const;
    bool getLootchest_found() const;
    void saveGame();
    void loadGame();
    int getLevel_num() const;
    void setLevel_num(int newLevel_num);
private:
    List<Level*> level_list;
    GraphicalUI* gr_ui;
    Level* level;
    bool lootchest_found;
    bool human_alive;
    int level_num;
};

#endif // DUNGEONCRAWLER_H
