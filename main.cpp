#include "mainwindow.h"
#include "startscreen.h"
#include "dungeoncrawler.h"
#include "graphicalui.h"
#include "level.h"
#include <QApplication>
#include <fstream>
#include <iostream>
#include <istream>
#include<QDir>
int main(int argc, char* argv[])
{QApplication a(argc, argv);
    const std::string l={
        "##########"
        "#O...#.&.#"
        "#...<#...#"
        "#..__#.3.#"
        "#11__#...#"
        "#..SX#...#"
        "#######-##"
        "#O...2...#"
        "#...?....#"
        "##########"
    };

    const std::string l_n{
        "##########"
        "#O.......#"
        "#......###"
        "#.....4#&#"
        "#S...###.#"
        "#....#...#"
        "######-###"
        "#O......1#"
        "#...2...?#"
        "##########"
    };

    const std::string l_2{
        "##########"
        "#O...#..W#"
        "#...<#...#"
        "#..__#.2.#"
        "#11__#..2#"
        "#..S.#...#"
        "######-###"
        "#O...2...#"
        "#...?...4#"
        "##########"
    };

    std::string tmp_l;
    int rows;
    int cols;
    int level_num_tmp;
    const std::string filename="save.txt";

    std::ofstream file(filename);
    file << 2 << std::endl;
    file << 10 << std::endl;
    file << 10 << std::endl;
    file << l << std::endl;
    file << 10 << std::endl;
    file << 10 << std::endl;
    file << l_n << std::endl;
    file << 10 << std::endl;
    file << 10 << std::endl;
    file << l_2 << std::endl;
    file << -1 << std::endl;
    file.close();

    std::ifstream infile(filename);
    infile >> level_num_tmp;
    infile >> rows;
    infile >> cols;
    infile >> tmp_l;
    StartScreen s;
    s.show();
    a.exec();
    MainWindow w(rows, cols, tmp_l, nullptr);
    GraphicalUI* UI = new GraphicalUI(&w);
    w.getDc()->setGr_ui(UI);
    while(!infile.eof())
    {
        infile >> rows;
        infile >> cols;
        infile >> tmp_l;
        if(rows<=0 || cols<=0 || tmp_l=="")
        {
            break;
        }
        w.getDc()->push_level_back(new Level(rows, cols, tmp_l));
    }
    infile.close();

    UI->draw();
    w.show();
    a.exec();
    return 0;
}

