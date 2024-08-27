#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "dungeoncrawler.h"
#include "graphicalui.h"
#include "abstractcontroller.h"
#include <QWidget>
#include <QLabel>
#include <vector>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class DungeonCrawler;
class GraphicalUI;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(DungeonCrawler* dc, QWidget *parent = nullptr);
    MainWindow(int row, int col, std::string level, QWidget *parent = nullptr);
    ~MainWindow();
    void keyPressEvent(QKeyEvent* event) override;

    void resizeEvent(QResizeEvent *event) override;
    void draw();
    void remove_exis_char();

    Input_gui getLastClicked() const;

    DungeonCrawler *getDc() const;

    void check_Won();
private slots:

    void on_upleft_clicked();

    void on_upright_clicked();

    void on_up_clicked();

    void on_left_clicked();

    void on_right_clicked();

    void on_downright_clicked();

    void on_down_clicked();

    void on_downleft_clicked();

    void on_turn_clicked();

private:
    Ui::MainWindow *ui_m;
    Level* current_level;
    DungeonCrawler* dc;

    int cur_pos_row{};
    int cur_pos_col{};
    std::vector<std::pair<int,int>> characters;
    Input_gui LastClicked;

    // QWidget interface
};
#endif // MAINWINDOW_H
