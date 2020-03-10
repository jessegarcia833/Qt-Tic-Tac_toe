#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QMessageBox>
#include <time.h>
#include "player_o.h"
#include "player_x.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void startGame();
    void displayWins();
    void checkWin();
    void clearBoard();
    void displayPlayer();
    void ai_play();
    unsigned int addDraw();
    void nextPlayer();
    bool spotFree();

private slots:
    void topLeftButtonClick();
    void topMiddleButtonClick();
    void topRightButtonClick();
    void leftButtonClick();
    void middleButtonClick();
    void rightButtonClick();
    void bottomLeftButtonClick();
    void bottomMiddleButtonClick();
    void bottomRightButtonClick();
    void on_AIpushButton_clicked();

private:
    Ui::MainWindow *ui;

    // Player Objects
    Player_X player_x;
    Player_O player_o;

    // Message Window boxes
    QMessageBox xWinsBox;
    QMessageBox oWinsBox;
    QMessageBox drawBox;

    // Variables
    QString winner;
    QString board[3][3];
    bool nextPlayerTurn;
    bool AI;
    unsigned int draws;

};

#endif // MAINWINDOW_H
