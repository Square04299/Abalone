#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <cmath>

#include <QDebug>
#include <QGraphicsScene>
#include <QGraphicsView>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow),
      HexCells {},
      pos1{},
      pos2{},
      game{Game()}
{

    ui->setupUi(this);

    displayHex();

    auto scene = new QGraphicsScene();

    std::for_each(begin(HexCells), end(HexCells),
    [this, scene](HexCell * e) {
        e->setPos(e->y(), e->x());
        scene->addItem(e);
        QObject::connect(e,
                         SIGNAL(sendValue(std::string)),
                         this,
                         SLOT(on_hexcell_clicked(std::string)));
    });
    auto view = new QGraphicsView(scene);
    view->update();

    QFont  fontMoves = QFont();
    fontMoves.setPointSize(50/3);

    ui->confirm->setText("Confirm");
    ui->unselect->setText("Unselect");
    ui->rules->setText("Rules");

    ui->itemTextPos1->setText("Marble 1 :");
    ui->itemTextPos1->setFont(fontMoves);
    ui->itemTextPos2->setText("Marble 2 :");
    ui->itemTextPos2->setFont(fontMoves);

    ui->itemPos1->setText("");
    ui->itemPos1->setFont(fontMoves);
    ui->itemPos2->setText("");
    ui->itemPos2->setFont(fontMoves);

    ui->player1->setText("Player 1 : White");
    ui->player2->setText("Player 2 : Black");

    QString str1 = QString::number(game.getPlayers().at(0).getDeadMarble());
    ui->player1Life->setText("Life left : " + str1);

    QString str2 = QString::number(game.getPlayers().at(1).getDeadMarble());
    ui->player2Life->setText("Life left : " +str2);

    ui->label->setText("Game : The player one can start playing (White Hexagon)");

    ui->hex->addWidget(view);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_confirm_clicked(){
    ui->label->setText("Cicked");
    if (pos1.empty() || pos2.empty()) {
        ui->label->setText("Game : You hasn't selected 2 marble");
    }else {
        try {
            game.moveMarble(pos1,pos2);
        }catch (...) {
            ui->label->setText("Game : You did an illegal move");
        }
        QString str1 = QString::number(game.getPlayers().at(0).getDeadMarble());
        ui->player1Life->setText("Life left : " + str1);

        QString str2 = QString::number(game.getPlayers().at(1).getDeadMarble());
        ui->player2Life->setText("Life left : " +str2);
        game.nextPlayer();
        update();
    }
    qDebug() << "call confirm clicked";
}
void MainWindow::on_unselect_clicked(){
    ui->label->setText("You've unselected your Marble");
    ui->itemPos1->setText("");
    ui->itemPos2->setText("");
    ui->label->setText("You've unselected your Marble\n CLEARED");
    qDebug() << "call unselected clicked";
}
void MainWindow::on_rules_clicked(){
    ui->label->setText("FUCK THE RULES, Every Player need to move 3 different marble out of the board game to win the game\n"
                       "The white player will start playing first and can move 1 marble or a max of 3 if pushing");
    qDebug() << "call rules clicked";
}

void MainWindow::on_hexcell_clicked(std::string value)
{
    if (pos1.empty()) {
        pos1=value;
    }else if (pos2.empty()) {
        pos2=value;
    }else{
        pos1 = value;
        pos2 = "";
    }
    ui->itemPos1->setText(pos1.c_str());
    ui->itemPos2->setText(pos2.c_str());
    //Print Bottom
    ui->label->setText(value.c_str());
    std::string s = "receveive value from ghexacell ";
    s.append(value);
    qDebug() << s.c_str();
}

void MainWindow::displayHex(){
    game.startGame();
    Board b = game.getBoard();
    //I and A
    for (int i = 5; i < 15 ;i++ ) {
        i++;
        //A
        HexCells.push_back(new HexCell(((2 * 35) * 3 / 4) * 4, (sqrt(3) * 35/2) * i , "A" + std::to_string(((i-2)/2)-1),b.getColor(9,((i-2)/2)-1), nullptr));
        //I
        HexCells.push_back(new HexCell(((2 * 35) * 3 / 4) * -4, (sqrt(3) * 35/2) * i , "I" + std::to_string(((i/2)+3)-1),b.getColor(1,((i/2)+3)-1), nullptr));
    }
    //H and B
    for (int i = 4; i < 15 ;i++ ) {
        i++;
        //B
        HexCells.push_back(new HexCell(((2 * 35) * 3 / 4) * 3, (sqrt(3) * 35/2) * i , "B" + std::to_string(((i-4/2)-1)/2),b.getColor(8,((i-4/2)-1)/2), nullptr));
        //H
        HexCells.push_back(new HexCell(((2 * 35) * 3 / 4) * -3, (sqrt(3) * 35/2) * i , "H" + std::to_string(i/2+2),b.getColor(2,(i/2+2)), nullptr));
    }
    //C and G
    for (int i = 3; i < 16 ;i++ ) {
        i++;
        //C
        HexCells.push_back(new HexCell(((2 * 35) * 3 / 4) * 2, (sqrt(3) * 35/2) * i , "C" + std::to_string((i-2)/2),b.getColor(7,(i-2)/2), nullptr));
        //G
        HexCells.push_back(new HexCell(((2 * 35) * 3 / 4) * -2, (sqrt(3) * 35/2) * i , "G" + std::to_string(i/2+1),b.getColor(3,(i/2+1)), nullptr));
    }
    //D and F
    for (int i = 2; i < 18 ;i++ ) {
        i++;
        //D
        HexCells.push_back(new HexCell(((2 * 35) * 3 / 4) * 1, (sqrt(3) * 35/2) * i, "D" + std::to_string(i/2),b.getColor(6,(i/2)), nullptr));
        //F
        HexCells.push_back(new HexCell(((2 * 35) * 3 / 4) * -1, (sqrt(3) * 35/2) * i, "F" + std::to_string(i/2+1),b.getColor(4,(i/2+1)), nullptr));
    }
    //E
    for (int i = 1; i < 19 ;i++ ) {
        i++;
        HexCells.push_back(new HexCell(((2 * 35) * 3 / 4) * 0, (sqrt(3) * 35/2) * i , "E" + std::to_string(i/2),b.getColor(5,(i/2)), nullptr));
    }
}

