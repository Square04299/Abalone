#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "hexcell.h"
#include "Game.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
  void on_confirm_clicked();
  void on_unselect_clicked();
  void on_rules_clicked();
  void on_hexcell_clicked(std::string value);
  void displayHex();

private:
    Ui::MainWindow *ui;
    std::vector<HexCell *> HexCells;
    std::string pos1;
    std::string pos2;
    Game game;
};
#endif // MAINWINDOW_H
