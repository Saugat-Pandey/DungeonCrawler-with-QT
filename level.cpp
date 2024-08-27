#include "level.h"
#include "portal.h"
#include "wall.h"
#include "floor.h"
#include "switch.h"
#include "door.h"
#include "pit.h"
#include "ramp.h"
#include "random.h"
#include "levelchanger.h"
#include "SetFloorTexture.h"
#include "attackcontroller.h"
#include <lootchest.h>

//#include "levelchanger.h"

Level::Level(int row, int col, std::string lvl):
    level_ch(nullptr),
    lvl_string(lvl),
    rows(row),
    cols(col)
{
    int index = 0;
    bool p1_used = false;
    bool p2_used = false;
    bool portal1_found = false;
    bool switch1_found = false;
    bool door1_found = false;
    Portal* portal1 = nullptr;
    Portal* portal2 = nullptr;
    Switch* switch1 = nullptr;
    Door* door1 = nullptr;

    field.resize(rows);
    for(int i = 0; i < rows; i++)
    {
        field[i].resize(cols, nullptr);
    }

    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            switch(lvl_string[index])
            {
            case '#':
                field[i][j] = new Wall(i, j, "#");
                index++;
                break;

            case '.':
                field[i][j] = new Floor(i, j, ".");
                index++;
                break;

            case 'O':
                if(p2_used) //no textures left for portals
                {
                    field[i][j] = new Wall(i, j, "#");
                    index++;
                    break;
                }
                if(!portal1_found)
                {
                    if(p1_used)
                    {
                        portal1 = new Portal(i, j, "O", 2);
                    }
                    else
                    {
                        portal1 = new Portal(i, j, "O", 1);
                    }
                    field[i][j] = portal1;
                    portal1_found = true;
                    index++;
                    break;
                }
                else
                {
                    if(p1_used)
                    {
                        portal2 = new Portal(i, j, "O", 2);
                        p2_used = true;
                    }
                    else
                    {
                        portal2 = new Portal(i, j, "O", 1);
                    }
                    field[i][j] = portal2;
                    portal2->setDestination(portal1);
                    portal1->setDestination(portal2);
                    portal1_found = false;
                    p1_used = true;
                    index++;
                    break;
                }
                index++;
                break;

            case '?':
                switch1 = new Switch(i, j, "?");
                field[i][j] = switch1;
                switch1_found = true;
                index++;
                break;

            case '-':
                door1 = new Door(i, j, "-");
                field[i][j] = door1;
                door1_found = true;
                index++;
                break;

            case '_':
                field[i][j] = new Pit(i, j, "_");
                index++;
                break;

            case '<':
                field[i][j] = new Ramp(i, j, "<");
                index++;
                break;

            case 'X':
            {
                field[i][j] = new Floor(i, j, ".");
                Character* new_char1 = new Character("X", 5, 5, true); //just placeholder for stats
                characters.push_back(new_char1);
                field[i][j]->setCharacter(new_char1);
                new_char1->setChar_tile(field[i][j]);
                index++;
                break;
            }

            case '1':
            {
                field[i][j] = new Floor(i, j, ".");
                index++;
                Character* new_char2 = new Character("1", 2, 2, false); //just placeholder for stats
                characters.push_back(new_char2);
                field[i][j]->setCharacter(new_char2);
                new_char2->setChar_tile(field[i][j]);
                break;
            }

            case '2':
            {
                field[i][j] = new Floor(i, j, ".");
                index++;
                Character* new_char3 = new Character("2", 1, 1, false); //just placeholder for stats
                characters.push_back(new_char3);
                field[i][j]->setCharacter(new_char3);
                new_char3->setChar_tile(field[i][j]);
                break;
            }

            case '3':
            {
                field[i][j] = new Floor(i, j, ".");
                index++;
                Character* new_char4 = new Character("3", 1, 1, false);

                characters.push_back(new_char4);
                field[i][j]->setCharacter(new_char4);
                new_char4->setChar_tile(field[i][j]);
                break;
            }

            case '4':
            {
                field[i][j] = new Floor(i, j, ".");
                index++;
                Character* new_char5 = new Character("4", 4, 4, false);
                auto abstrCon = new AttackController(this);
                new_char5->setAbstrCon(abstrCon);
                abstrCon->setAttacker(new_char5);
                characters.push_back(new_char5);
                field[i][j]->setCharacter(new_char5);
                new_char5->setChar_tile(field[i][j]);
                break;
            }

            case'&':
            {
                level_ch = new LevelChanger(i, j, "&");
                field[i][j] = level_ch;
                level_ch->setLevel_dest(this);
                index++;
                break;
            }

            case'W':
            {
                auto lootchest = new LootChest(i, j, "W");
                field[i][j] = lootchest;
                index++;
                break;
            }

            case'S':
            {
                char_set = new SetFloorTexture(i, j, "S");
                field[i][j] = char_set;
                index++;
                break;
            }

            default:
                field[i][j] = new Wall(i, j, "#");
                index++;
                break;
            }
            if(door1_found && switch1_found){
                switch1->attach(door1);
                door1_found = false;
                //switch1_found = false;
            }
        }
    }
    graph = Graph();
    createGraph();
    updateGraph();
     updateLvlString();
}

bool Level::operator!=(Level lhs)
{
    if(this->field == lhs.getField() &&
        this->characters == lhs.getCharacters() &&
        this->lvl_string == lhs.getLvl_string() &&
        this->rows == lhs.getRows() &&
        this->cols == lhs.getCols()){

        return false;
    }
    return true;
}

bool Level::operator==(Level lhs)
{
    if(this->field == lhs.getField() &&
        this->characters == lhs.getCharacters() &&
        this->lvl_string == lhs.getLvl_string() &&
        this->rows == lhs.getRows() &&
        this->cols == lhs.getCols()){

        return true;
    }
    return false;
}

void Level::eraseAllCharacters()
{
    for(auto& x:this->characters)
    {
        delete x;
    }
    characters.clear();
}

void Level::setCharacters(const std::vector<Character *> &newCharacters)
{
    characters = newCharacters;
}

Level &Level::operator=(const Level &l)
{
    lvl_string = l.getLvl_string();
    rows = l.getRows();
    cols = l.getCols();
    level_ch = nullptr;
    //insert = condition
    int index = 0;
    bool p1_used = false;
    bool p2_used = false;
    bool portal1_found = false;
    bool switch1_found = false;
    bool door1_found = false;
    Portal* portal1 = nullptr;
    Portal* portal2 = nullptr;
    Switch* switch1 = nullptr;
    Door* door1 = nullptr;

    //clear vector before use
    for(auto& x:this->field)
    {
        for(auto y : x)
        {
            delete y;
        }
    }
    this->field.clear();

    for(auto& z:this->characters)
    {
        delete z;
    }
    this->characters.clear();

    //resizing to match new level size
    field.resize(rows);
    for(int i = 0; i < rows; i++)
    {
        field[i].resize(cols, nullptr);
    }

    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            switch(lvl_string[index])
            {
            case '#':
                field[i][j] = new Wall(i, j, "#");
                index++;
                break;

            case '.':
                field[i][j] = new Floor(i, j, ".");
                index++;
                break;

            case 'O':
                if(p2_used) //no textures left for portals
                {
                    field[i][j] = new Wall(i, j, "#");
                    index++;
                    break;
                }
                if(!portal1_found)
                {
                    if(p1_used)
                    {
                        portal1 = new Portal(i, j, "O", 2);
                    }
                    else
                    {
                        portal1 = new Portal(i, j, "O", 1);

                    }
                    field[i][j] = portal1;
                    portal1_found = true;
                    index++;
                    break;
                }
                else
                {
                    if(p1_used)
                    {
                        portal2 = new Portal(i, j, "O", 2);
                        p2_used = true;
                    }
                    else
                    {
                        portal2 = new Portal(i, j, "O", 1);
                    }
                    field[i][j] = portal2;
                    portal2->setDestination(portal1);
                    portal1->setDestination(portal2);
                    portal1_found = false;
                    p1_used = true;
                    index++;
                    break;
                }
                index++;
                break;

            case '?':
                switch1 = new Switch(i, j, "?");
                field[i][j] = switch1;
                switch1_found = true;
                index++;
                break;

            case '-':
                door1 = new Door(i, j, "-");
                field[i][j] = door1;
                door1_found = true;
                index++;
                break;

            case '_':
                field[i][j] = new Pit(i, j, "_");
                index++;
                break;

            case '<':
                field[i][j] = new Ramp(i, j, "<");
                index++;
                break;

            case 'X':
            {
                field[i][j] = new Floor(i, j, ".");
                Character* new_char1 = new Character("X", 5, 5, true); //just placeholder for stats
                characters.push_back(new_char1);
                field[i][j]->setCharacter(new_char1);
                new_char1->setChar_tile(field[i][j]);
                index++;
                break;
            }

            case '1':
            {
                field[i][j] = new Floor(i, j, ".");
                index++;
                Character* new_char2 = new Character("1", 2, 2, false); //just placeholder for stats
                characters.push_back(new_char2);
                field[i][j]->setCharacter(new_char2);
                new_char2->setChar_tile(field[i][j]);
                break;
            }

            case '2':
            {
                field[i][j] = new Floor(i, j, ".");
                index++;
                Character* new_char3 = new Character("2", 1, 1, false);
                characters.push_back(new_char3);
                field[i][j]->setCharacter(new_char3);
                new_char3->setChar_tile(field[i][j]);
                break;
            }

            case '3':
            {
                field[i][j] = new Floor(i, j, ".");
                index++;
                Character* new_char4 = new Character("3", 1, 1, false);
                characters.push_back(new_char4);
                field[i][j]->setCharacter(new_char4);
                new_char4->setChar_tile(field[i][j]);
                break;
            }

            case'&':
            {
                level_ch = new LevelChanger(i, j, "&");
                field[i][j] = level_ch;
                level_ch->setLevel_dest(this);
                index++;
                break;
            }

            case'W':
            {
                auto lootchest = new LootChest(i, j, "W");
                field[i][j] = lootchest;
                index++;
                break;
            }

            case'S':
            {
                char_set = new SetFloorTexture(i, j, "S");
                field[i][j] = char_set;
                index++;
                break;
            }

            default:
                field[i][j] = new Wall(i, j, "#");
                index++;
                break;
            }
            if(door1_found && switch1_found){
                switch1->attach(door1);
                door1_found = false;
                //switch1_found = false;
            }
        }
    }

    return *this;
}

Level::~Level()
{
    for(auto& x:this->field)
    {
        for(auto y : x)
        {
            delete y;
        }
    }

    for(auto& z:this->characters)
    {
        delete z;
    }

    if(level_ch != nullptr)
    {
        //delete level_ch;
        level_ch = nullptr;
    }
}


Tile* Level::getTile(int row, int col)
{
    return field[row][col];
}

void Level::placeCharacter(Character* c, int row, int col)
{
    field[row][col]->setCharacter(c);
     updateLvlString();
}

int Level::getRows() const
{
    return rows;
}

int Level::getCols() const
{
    return cols;
}

std::vector<Character*> Level::getCharacters() const
{
    return characters;
}

std::string Level::getLvl_string() const
{
    return lvl_string;
}

std::vector<std::vector<Tile*>> Level::getField() const
{
    return field;
}

void Level::setField(const std::vector<std::vector<Tile*>> &newField)
{
    field = newField;
}

void Level::addCharacter(Character* newCharacter)
{
    characters.push_back(newCharacter);
     updateLvlString();
}

void Level::setLvl_string(const std::string &newlvl_string)
{
    lvl_string = newlvl_string;
}

void Level::setCols(int newCols)
{
    cols = newCols;
}

void Level::removeCharacter(int ind)
{
    //delete characters[ind];
    characters.erase(characters.begin() + ind);
     updateLvlString();
}

void Level::removeCharacter(Character* c)
{
    for(auto it = characters.begin(); it != characters.end(); it++)
    {
        if(*it == c)
        {
            characters.erase(it);
             updateLvlString();
            break;
        }
    }
}
void Level::setRows(int newRows)
{
    rows = newRows;
}

LevelChanger *Level::getLevel_ch()
{
    return level_ch;
}

void Level::setLevel_ch(LevelChanger *newLevel_ch)
{
    level_ch = newLevel_ch;
}

SetFloorTexture *Level::getChar_set() const
{
    return char_set;
}

void Level::setChar_set(SetFloorTexture *newChar_set)
{
    char_set = newChar_set;
}

void Level::createGraph()
{
    for(auto row: field){
        for(auto tile: row){
            if(tile->getTexture() != "#"){
                graph.addNode(tile->getRow(), tile->getCol());
            }
        }
    }
}

void Level::updateGraph() {
    Tile* primaryPortal = nullptr;
    Tile* secondaryPortal = nullptr;
    bool primaryPortalFound = false;
    std::vector<int> neighbors{-1, 0, 1};
    graph.clearKanten();

    for (const auto& row : field) {
        for (const auto& currentTile : row) {
            if (currentTile->getTexture() != "#" && currentTile->getTexture() != "-") {
                int currentRow = currentTile->getRow();
                int currentCol = currentTile->getCol();

                for (int rowOffset : neighbors) {
                    for (int colOffset : neighbors) {
                        if (rowOffset == 0 && colOffset == 0) continue;

                        int neighborRow = currentRow + rowOffset;
                        int neighborCol = currentCol + colOffset;

                        if (neighborRow >= 0 && neighborRow < getRows() && neighborCol >= 0 && neighborCol < getCols()) {
                            Tile* adjacentTile = getTile(neighborRow, neighborCol);
                            std::string adjacentTexture = adjacentTile->getTexture();

                            if (currentTile->getTexture() == "_") {
                                if (adjacentTexture == "_" || adjacentTexture == "<") {
                                    graph.addKante(currentRow, currentCol, neighborRow, neighborCol);
                                }
                            }

                            if (currentTile->getTexture() == "O") {
                                if (!primaryPortalFound) {
                                    primaryPortal = currentTile;
                                    primaryPortalFound = true;
                                } else {
                                    secondaryPortal = currentTile;
                                    graph.addKante(primaryPortal->getRow(), primaryPortal->getCol(), secondaryPortal->getRow(), secondaryPortal->getCol());
                                    graph.addKante(secondaryPortal->getRow(), secondaryPortal->getCol(), primaryPortal->getRow(), primaryPortal->getCol());
                                }
                            }

                            if (adjacentTexture != "-" && adjacentTexture != "&" && adjacentTexture != "#") {
                                graph.addKante(currentRow, currentCol, neighborRow, neighborCol);
                            }
                        }
                    }
                }
            }
        }
    }
}

std::vector<Node*> Level::getPath(std::pair<int, int> start, std::pair<int, int> destination) {
    std::vector<Node*> path{};
    Node* destinationNode = nullptr;
     auto shortestPaths = graph.bfsTraversal(start);
    for (auto& node : shortestPaths)
     {
        if (node.position == destination)
        {
            destinationNode = &node;
            break;
        }
    }
    auto limit =std::numeric_limits<int>::max();

    if (destinationNode == nullptr || destinationNode->distance == limit)
    {
        return path;
    }

    path.resize(destinationNode->distance);
    Node* currentNode = destinationNode;
    int step = 1;
    while (currentNode->parent->position != start)
    {
        path.at(destinationNode->distance - step) = currentNode->parent;
        currentNode = currentNode->parent;
        step++;
    }
    if(step==1)
    {
        path.resize(2);
        path.at(0)=nullptr;
        path.at(1)=currentNode;
    }
    return path;
}
void Level::updateLvlString() {
    std::string newLvlString;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (field[i][j]->getCharacter()) {
                newLvlString += field[i][j]->getCharacter()->getTexture();
            } else {
                newLvlString += field[i][j]->getTexture();
            }
        }
    }
    lvl_string = newLvlString;
}
