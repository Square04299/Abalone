#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <cmath>

#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow),
      HexCells {},
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

    QFont  font = QFont();
    font.setPointSize(50/3);

    ui->confirm->setText("Confirm");
    ui->unselect->setText("Unselect");
    ui->rules->setText("Rules");

    ui->itemTextPos1->setText("Marble 1 :");
    ui->itemTextPos1->setFont(font);
    ui->itemTextPos2->setText("Marble 2 :");
    ui->itemTextPos2->setFont(font);


    ui->itemPos1->setText("");
    ui->itemPos1->setFont(font);
    ui->itemPos2->setText("");
    ui->itemPos2->setFont(font);

    ui->player1->setText("Player 1 : White");
    ui->player2->setText("Player 2 : Black");

    QString str1 = QString::number(game.getPlayers().at(0).getDeadMarble());
    ui->player1Life->setText("Life left : " + str1);

    QString str2 = QString::number(game.getPlayers().at(1).getDeadMarble());
    ui->player2Life->setText("Life left : " +str2);

    ui->label->setText("Game : The WHITE player will start moving this marble");

    ui->hex->addWidget(view);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_confirm_clicked(){
    if (pos1.empty() || pos2.empty()) {
        ui->label->setText("Game : You hasn't selected 2 marble");
    }else {
        try {
            game.moveMarble(pos1,pos2);
            nextPlayer();
        }catch (const std::logic_error& ex) {
            QMessageBox::warning(this,"Logic Error",ex.what());
        }catch (const std::exception& ex){
            QMessageBox::warning(this,"Exception",ex.what());
        }catch (...){
            QMessageBox::critical(this,"What the Fuck did","What did you press to break me so hard ??");
        }

    }
    qDebug() << "call confirm clicked";
}

void MainWindow::nextPlayer(){
    QString str1 = QString::number(game.getPlayers().at(0).getDeadMarble());
    ui->player1Life->setText("Life left : " + str1);

    QString str2 = QString::number(game.getPlayers().at(1).getDeadMarble());
    ui->player2Life->setText("Life left : " +str2);

    for (unsigned i = 0; i < HexCells.size() ;i++ ) {
        HexCells.at(i)->updateColor();
    }
    if (game.isGameOver() != nullptr) {
        game.setState(OVER);
        this->setDisabled(true);
        endGame();
        close();
    }else{
        game.setState(NEXTPLAYER);
        game.nextPlayer();
        switch (game.getCurrent().getColor()) {
        case WHITE:
            ui->label->setText("Game : It's WHITE turn");
            break;
        case BLACK:
            ui->label->setText("Game : It's BLACK turn");
            break;
        default:
            ui->label->setText("Game : There must be an error");
            break;
        }
    }
}
void MainWindow::on_unselect_clicked(){
    ui->itemPos1->setText("");
    ui->itemPos2->setText("");
    ui->label->setText("Game :You've unselected your Marble\n CLEARED");
    qDebug() << "call unselected clicked";
}
void MainWindow::on_rules_clicked(){
    ui->label->setText("The board consists of 61 hexagonal spaces arranged in a hexagon, five on a side.\n"
                       "Each player has 14 marbles that rest in the spaces and are initially arranged.\n"
                       "The players take turns with the white marbles moving first.\n"
                       "For each move, a player moves a straight line of one, two or three marbles of one color one space in one of six directions.\n"
                       "If 3 marble exit the hexagon board the other player wins the game."
                       "");
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
    //ui->label->setText(value.c_str());
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
        HexCells.push_back(new HexCell(((2 * 35) * 3 / 4) * 4, (sqrt(3) * 35/2) * i , "A" + std::to_string(((i-2)/2)-1), b, 9, (((i-2)/2)-1), nullptr));
        //I
        HexCells.push_back(new HexCell(((2 * 35) * 3 / 4) * -4, (sqrt(3) * 35/2) * i , "I" + std::to_string(((i/2)+3)-1), b, 1, (((i/2)+3)-1), nullptr));
    }
    //H and B
    for (int i = 4; i < 15 ;i++ ) {
        i++;
        //B
        HexCells.push_back(new HexCell(((2 * 35) * 3 / 4) * 3, (sqrt(3) * 35/2) * i , "B" + std::to_string(((i-4/2)-1)/2), b, 8, (((i-4/2)-1)/2), nullptr));
        //H
        HexCells.push_back(new HexCell(((2 * 35) * 3 / 4) * -3, (sqrt(3) * 35/2) * i , "H" + std::to_string(i/2+2), b, 2, ((i/2+2)), nullptr));
    }
    //C and G
    for (int i = 3; i < 16 ;i++ ) {
        i++;
        //C
        HexCells.push_back(new HexCell(((2 * 35) * 3 / 4) * 2, (sqrt(3) * 35/2) * i , "C" + std::to_string((i-2)/2), b, 7, ((i-2)/2), nullptr));
        //G
        HexCells.push_back(new HexCell(((2 * 35) * 3 / 4) * -2, (sqrt(3) * 35/2) * i , "G" + std::to_string(i/2+1), b, 3, ((i/2+1)), nullptr));
    }
    //D and F
    for (int i = 2; i < 18 ;i++ ) {
        i++;
        //D
        HexCells.push_back(new HexCell(((2 * 35) * 3 / 4) * 1, (sqrt(3) * 35/2) * i, "D" + std::to_string(i/2), b, 6, ((i/2)), nullptr));
        //F
        HexCells.push_back(new HexCell(((2 * 35) * 3 / 4) * -1, (sqrt(3) * 35/2) * i, "F" + std::to_string(i/2+1), b, 4, ((i/2+1)), nullptr));
    }
    //E
    for (int i = 1; i < 19 ;i++ ) {
        i++;
        HexCells.push_back(new HexCell(((2 * 35) * 3 / 4) * 0, (sqrt(3) * 35/2) * i , "E" + std::to_string(i/2), b, 5, ((i/2)), nullptr));
    }
}

void MainWindow::endGame(){
    const Player &winner = game.end();
    Color win = winner.getColor();
    int winningMessage = win;

    QMessageBox msgBox;


    switch (winningMessage) {
    case 0:
        msgBox.setText("The WHITE player won the Game,\n      Congratulations");
        msgBox.setInformativeText("Game is over !");
        msgBox.exec();
        //QMessageBox::information(this,"Game is over","The WHITE player won the Game,\n Congratulations");
        break;
    case 1:
        msgBox.setText("The BLACK player won the Game,\n      Congratulations");
        msgBox.setInformativeText("Game is over !");
        msgBox.exec();
        //QMessageBox::information(this,"Game is over","The BLACK player won the Game,\n Congratulations");
        break;
    }
}
