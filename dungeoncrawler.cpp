#include "dungeoncrawler.h"
#include "graphicalui.h"
#include <fstream>
#include <iostream>
#include <istream>
#include "attackcontroller.h"
#include"abstractcontroller.h"
#include"stationarycontroller.h"
#include"guardiancontroller.h"
#include<sstream>
#include<stdexcept>
#include"door.h"
DungeonCrawler::DungeonCrawler() {}

DungeonCrawler::DungeonCrawler(Level* level):
    level(level),
    level_num(0)
{
    lootchest_found = false;
    human_alive = true;
    push_level_back(level);
}

DungeonCrawler::DungeonCrawler(int rows, int cols, std::string l):
 level(new Level(rows, cols, l)),
    level_num(0)
{
    lootchest_found = false;
    human_alive = true;
    push_level_back(level);
}

DungeonCrawler::~DungeonCrawler()
{
    saveGame();
    delete gr_ui;
    gr_ui = nullptr;
    //delete current_level;
  level = nullptr;
}

void DungeonCrawler::setGr_ui(GraphicalUI* newGr_ui)
{
    gr_ui = newGr_ui;
}

void DungeonCrawler::push_level_back(Level *level_n)
{
    level_list.push_back(level_n);
    if(level_list.second_to_last() == nullptr)
    {
        (level_list.begin().operator *())->getLevel_ch()->setDestination(level_n->getChar_set());
        (level_list.begin().operator *())->getLevel_ch()->setLevel_dest(level_n);

        if(!(level_n->getLevel_ch() == nullptr))
        {
            level_n->getLevel_ch()->setDestination((level_list.begin().operator *())->getChar_set());
            level_n->getLevel_ch()->setLevel_dest((level_list.begin().operator *()));
        }
    }
    else
    {
        level_list.second_to_last()->getLevel_ch()->setDestination(level_n->getChar_set());
        level_list.second_to_last()->getLevel_ch()->setLevel_dest(level_n);

        if(!(level_n->getLevel_ch() == nullptr))
        {
            level_n->getLevel_ch()->setDestination(level_list.begin().operator *()->getChar_set());
            level_n->getLevel_ch()->setLevel_dest(level_list.begin().operator *());
        }
    }

    if(level_list.begin().operator *() != level_n){
        for(auto chara:level_list.begin().operator *()->getCharacters()){
            if(chara->isHuman()){
                level_n->addCharacter(chara);
            }
        }
    }
}

void DungeonCrawler::check_alive()
{
    int ind = 0;
    for(auto charac : level->getCharacters())
    {
        if(!(charac->getAlive()))
        {
            if(charac->isHuman())
            {
                human_alive = false;
            }
            charac->getChar_tile()->setCharacter(nullptr);
            level->removeCharacter(ind);
        }
        ind++;
    }
}

bool DungeonCrawler::isHuman_alive() const
{
    return human_alive;
}

bool DungeonCrawler::getLootchest_found() const
{
    return lootchest_found;
}

void DungeonCrawler::saveGame() {
    std::ofstream file("save1.txt");

    if (!file) {
        std::cerr << "Unable to open file" << std::endl;
        return;

    }

    if (file.is_open()) {
        file << level->getRows() << std::endl;
        file << level->getCols() << std::endl;
        file << lootchest_found << std::endl;
        file << human_alive << std::endl;

        for (auto it = level_list.begin(); it != level_list.end(); ++it) {
            Level* level = *it;
            file << level->getRows() << " " << level->getCols() << std::endl;
            file << level->getLvl_string() << std::endl;

            // Save door states
            for (int i = 0; i < level->getRows(); i++) {
                for (int j = 0; j < level->getCols(); j++) {
                    Tile* tile = level->getTile(i, j);
                    if (Door* door = dynamic_cast<Door*>(tile)) {
                        file << i << " " << j << " " << door->getOpen() << std::endl;
                    }
                }
            }

            file << "EndDoors" << std::endl;

            // Save characters
            for (auto character : level->getCharacters()) {
                file << character->getTexture() << " "
                     << character->getChar_tile()->getRow() << " "
                     << character->getChar_tile()->getCol() << " "
                     << character->getStrength() << " "
                     << character->getStamina() << " "
                     << character->isHuman() << std::endl;
                if (!character->isHuman() && character->getAbstrCon()) {
                    if (dynamic_cast<AttackController*>(character->getAbstrCon())) {
                        file << "Controller Attack" << std::endl;
                    } else if (dynamic_cast<StationaryController*>(character->getAbstrCon())) {
                        file << "Controller Stationary" << std::endl;
                    } else if (auto guardController = dynamic_cast<GuardianController*>(character->getAbstrCon())) {
                        file << "Controller Guardian " << guardController->getMove_str()<< std::endl;
                    }
                }
            }

            file << "EndCharacters" << std::endl;
        }

        file << "EndLevel" << std::endl;
    }
    file.close();
}
void DungeonCrawler::loadGame() {
    std::remove("save.txt");
    std::ifstream file("save1.txt");

    if (!file) {
        std::cerr << "Unable to open file for loading" << std::endl;
        return;

    }
    try {


        int rows, cols;
        bool lootchestFound, humanAlive;

        file >> rows >> cols >> lootchestFound >> humanAlive;
        lootchest_found = lootchestFound;
        human_alive = humanAlive;

        // Clear existing levels
        for (auto it = level_list.begin(); it != level_list.end(); ++it) {
            delete *it;
        }


        std::string line;
        while (std::getline(file, line)) {
            if (line == "EndLevel") break;

            std::istringstream iss(line);
            iss >> rows >> cols;

            std::string lvl_string;
            std::getline(file, lvl_string);

            Level* newLevel = new Level(rows, cols, lvl_string);

            // Load door states
            while (std::getline(file, line) && line != "EndDoors") {
                std::istringstream iss(line);
                int row, col;
                bool isOpen;
                iss >> row >> col >> isOpen;
                if (Door* door = dynamic_cast<Door*>(newLevel->getTile(row, col))) {
                    door->setOpen(isOpen);
                }
            }

            // Load characters
            while (std::getline(file, line) && line != "EndCharacters") {
                std::istringstream iss(line);
                std::string texture;
                int row, col, strength, stamina;
                bool isHuman;
                iss >> texture >> row >> col >> strength >> stamina >> isHuman;

                Character* character = new Character(texture, strength, stamina, isHuman);
                newLevel->placeCharacter(character, row, col);
                newLevel->addCharacter(character);

                if (!isHuman) {
                    std::getline(file, line);
                    if (line.substr(0, 10) == "Controller") {
                        std::string controllerType = line.substr(11);
                        AbstractController* controller = nullptr;

                        if (controllerType == "Attack") {
                            controller = new AttackController(newLevel);
                            static_cast<AttackController*>(controller)->setAttacker(character);
                        } else if (controllerType == "Stationary") {
                            controller = new StationaryController();
                        } else if (controllerType.substr(0, 8) == "Guardian") {
                            std::string behavior = controllerType.substr(9);
                            controller = new GuardianController(behavior);
                        }

                        if (controller) {
                            character->setAbstrCon(controller);
                        }
                    }
                }
            }

            level_list.push_back(newLevel);
        }

        // Set current level
        level = *level_list.begin();
        for (int i = 0; i < level_num; i++) {
            level = level->getLevel_ch()->getLevel_dest();
        }

        file.close();
    }


    catch (const std::exception &e)
    {
        std::cerr<<"error "<<e.what()<<std::endl;
    }
}

int DungeonCrawler::getLevel_num() const
{
    return level_num;
}

void DungeonCrawler::setLevel_num(int newLevel_num)
{
    level_num = newLevel_num;
}

bool DungeonCrawler::turn()
{
    bool stop = false;

    bool Moved = false;
    for(Character* character:level->getCharacters()){
        bool dooropended = false;
        if(stop)
        {
            break;
        }


        if(character!=nullptr){
            Tile* current_tile = character->getChar_tile();

            int dest_row = current_tile->getRow();
            int dest_col = current_tile->getCol();

            Input_gui input_terminal;

            if(character->isHuman()){
                input_terminal = gr_ui->move();
            }
            else{
                input_terminal = character->move();
            }

            if(input_terminal == up)
            {
                dest_row-=1;
                Tile* dest_tile = level->getTile(dest_row, dest_col);
                if(dest_tile->getTexture()=="&")
                {
                    level = level->getLevel_ch()->getLevel_dest();
                    level_num++;
                    stop = true;
                    level->updateLvlString();
                }
                if(dest_tile->getTexture()=="W")
                {
                    lootchest_found = true;

                }
                if(dest_tile->getTexture()=="?")
                {
                    dooropended = true;
                    level->updateLvlString();
                }
                if(current_tile->moveTo(dest_tile, character))
                {
                    character->setMoveDirection(up);
                    Moved = true;
                    level->updateLvlString();
                }
                continue;
            }
            if(input_terminal == upleft)
            {
                dest_row-=1;
                dest_col-=1;
                Tile* dest_tile =level->getTile(dest_row, dest_col);
                if(dest_tile->getTexture()=="&")
                {
                    level = level->getLevel_ch()->getLevel_dest();
                    level_num++;
                    stop = true;
                    level->updateLvlString();
                }
                if(dest_tile->getTexture()=="W")
                {
                    lootchest_found = true;
                }
                if(dest_tile->getTexture()=="?")
                {
                    dooropended = true;
                    level->updateLvlString();
                }
                if(current_tile->moveTo(dest_tile, character))
                {
                    character->setMoveDirection(left);
                    Moved = true;
                    level->updateLvlString();

                }
                continue;
            }
            if(input_terminal == upright)
            {
                dest_row-=1;
                dest_col+=1;
                Tile* dest_tile = level->getTile(dest_row, dest_col);
                if(dest_tile->getTexture()=="&")
                {
                    level = level->getLevel_ch()->getLevel_dest();
                    level_num++;
                    stop = true;
                    level->updateLvlString();
                }
                if(dest_tile->getTexture()=="W")
                {
                    lootchest_found = true;
                }
                if(dest_tile->getTexture()=="?")
                {
                    dooropended = true;
                    level->updateLvlString();
                }
                if(current_tile->moveTo(dest_tile, character))
                {
                    character->setMoveDirection(right);
                    Moved = true;
                    level->updateLvlString();
                }
                continue;
            }
            if(input_terminal == down)
            {
                dest_row+=1;
                Tile* dest_tile = level->getTile(dest_row, dest_col);
                if(dest_tile->getTexture()=="&")
                {
                    level = level->getLevel_ch()->getLevel_dest();
                    level_num++;
                    stop = true;
                    level->updateLvlString();
                }
                if(dest_tile->getTexture()=="W")
                {
                    lootchest_found = true;
                }
                if(dest_tile->getTexture()=="?")
                {
                    dooropended = true;
                    level->updateLvlString();
                }
                if(current_tile->moveTo(dest_tile, character))
                {
                    character->setMoveDirection(down);
                    Moved = true;
                    level->updateLvlString();
                }
                continue;
            }
            if(input_terminal == downright)
            {
                dest_row+=1;
                dest_col+=1;
                Tile* dest_tile = level->getTile(dest_row, dest_col);
                if(dest_tile->getTexture()=="&")
                {
                    level = level->getLevel_ch()->getLevel_dest();
                    level_num++;
                    stop = true;
                    level->updateLvlString();
                }
                if(dest_tile->getTexture()=="W")
                {
                    lootchest_found = true;
                }
                if(dest_tile->getTexture()=="?")
                {
                    dooropended = true;
                    level->updateLvlString();
                }
                if(current_tile->moveTo(dest_tile, character))
                {
                    character->setMoveDirection(right);
                    Moved = true;
                    level->updateLvlString();
                }
                continue;
            }
            if(input_terminal == downleft)
            {
                dest_row+=1;
                dest_col-=1;
                Tile* dest_tile = level->getTile(dest_row, dest_col);
                if(dest_tile->getTexture()=="&")
                {
                    level = level->getLevel_ch()->getLevel_dest();
                    level_num++;
                    stop = true;
                    level->updateLvlString();
                }
                if(dest_tile->getTexture()=="W")
                {
                    lootchest_found = true;
                }
                if(dest_tile->getTexture()=="?")
                {
                    dooropended = true;
                    level->updateLvlString();
                }
                if(current_tile->moveTo(dest_tile, character))
                {
                    character->setMoveDirection(left);
                    Moved = true;
                    level->updateLvlString();
                }
                continue;
            }
            if(input_terminal == right)
            {
                dest_col+=1;
                Tile* dest_tile = level->getTile(dest_row, dest_col);
                if(dest_tile->getTexture()=="&")
                {
                    level = level->getLevel_ch()->getLevel_dest();
                    level_num++;
                    stop = true;
                    level->updateLvlString();
                }
                if(dest_tile->getTexture()=="W")
                {
                    lootchest_found = true;
                }
                if(dest_tile->getTexture()=="?")
                {
                    dooropended = true;
                    level->updateLvlString();
                }
                if(current_tile->moveTo(dest_tile, character))
                {
                    character->setMoveDirection(right);
                    Moved = true;
                    level->updateLvlString();
                }
                continue;
            }
            if(input_terminal == left)
            {
                dest_col-=1;
                Tile* dest_tile = level->getTile(dest_row, dest_col);
                if(dest_tile->getTexture()=="&")
                {
                    level = level->getLevel_ch()->getLevel_dest();
                    level_num++;
                    stop = true;
                    level->updateLvlString();
                }
                if(dest_tile->getTexture()=="W")
                {
                    lootchest_found = true;
                }
                if(dest_tile->getTexture()=="?")
                {
                    dooropended = true;
                    level->updateLvlString();
                }
                if(current_tile->moveTo(dest_tile, character))
                {
                    character->setMoveDirection(left);
                    Moved = true;
                    level->updateLvlString();
                }
                continue;
            }
            if(input_terminal == terminate)
            {
                character->setMoveDirection(terminate);
                continue;
            }
            if(input_terminal == stand)
            {
                character->setMoveDirection(character->getMoveDirection());
                Moved = true;
                level->updateLvlString();
                continue;
            }

        }
        if(dooropended){
            level->updateGraph();
            level->updateLvlString();
        }

    }
    check_alive();
    return Moved;
}

Level *DungeonCrawler::getCurrentLevel() const
{
    return level;
}
