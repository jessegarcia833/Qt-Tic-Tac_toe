#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Tic Tac Toe");
    // Initializing the values in the constructor
    draws = 0;
    AI = false;

    // This takes you to the function where
    // all of the buttons can be pressed
    startGame();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::startGame()
{
    // Clearing everything on the board to start the game
    clearBoard();

    // Signal and slots for when the user presses the button
    // to play there mark on their turn;

    // ------------------- Top Row Buttons ------------------------------------------
    connect(ui->topLeftButton, SIGNAL (clicked()), this, SLOT(topLeftButtonClick()));
    connect(ui->topMiddleButton, SIGNAL (clicked()), this, SLOT(topMiddleButtonClick()));
    connect(ui->topRightButton, SIGNAL (clicked()), this, SLOT(topRightButtonClick()));

    // ------------------- Middle Row Buttons ---------------------------------------
    connect(ui->leftButton, SIGNAL (clicked()), this, SLOT(leftButtonClick()));
    connect(ui->middleButton, SIGNAL (clicked()), this, SLOT(middleButtonClick()));
    connect(ui->rightButton, SIGNAL (clicked()), this, SLOT(rightButtonClick()));

    // ------------------- Bottom Row Buttons ---------------------------------------
    connect(ui->bottomLeftButton, SIGNAL (clicked()), this, SLOT(bottomLeftButtonClick()));
    connect(ui->bottomMiddleButton, SIGNAL (clicked()), this, SLOT(bottomMiddleButtonClick()));
    connect(ui->bottomRightButton, SIGNAL (clicked()), this, SLOT(bottomRightButtonClick()));

    displayPlayer();
    displayWins();
}

void MainWindow::ai_play()
{
    // Random number Generator for when the AI chooses
    // a random spot to pick
    srand(time(nullptr));

    // Points are to determine where the AI should choose
    // its next spot
    int xPoints = 0;
    int oPoints = 0;

    // Boolean values to determine whether a spot has been chosen by
    // the AI and when to see if there is a spot free when choosing a
    // random spot
    bool spotIsFree = false;
    bool doneWithTurn = false;

    // these will receive values for the GUI
    int row = 0;
    int col = 0;

    // Checking Each row for a possible win or loss
    // for both X and O
    if(!doneWithTurn)
    {
        // Uses nested for loops to iterate through the 2D array
            for (int i = 0; i < 3; i++)
            {
                xPoints = 0;
                oPoints = 0;

                for (int j = 0; j < 3; j++)
                {
                    if (board[i][j] == "X")
                    {
                        xPoints = xPoints + 5;

                        // When the points = 10 or -10 there is a possible chance of
                        // win or loss and the AI will choose the spot to prevent the loss
                        // or to win the game
                        if (xPoints == 10)
                        {
                            for (int j = 0; j < 3; j++)
                            {
                                if (board[i][j] == "")
                                {
                                    board[i][j] = player_o.play_turn();
                                    row = i;
                                    col = j;
                                    doneWithTurn = true;
                                }
                            }
                        }
                    }
                    else if (board[i][j] == "O")
                    {
                        oPoints = oPoints - 5;

                        if (oPoints == -10)
                        {
                            for (int j = 0; j < 3; j++)
                            {
                                if (board[i][j] == "")
                                {
                                    board[i][j] = player_o.play_turn();
                                    row = i;
                                    col = j;
                                    doneWithTurn = true;

                                }
                            }
                        }
                    }
                }
            }
       }

    // checking each col row possible win or loss
    // for both X and O
    // same logic applies from the above
    if(!doneWithTurn)
    {
            for (int j = 0; j < 3; j++)
            {
                xPoints = 0;
                oPoints = 0;

                for (int i = 0; i < 3; i++)
                {
                    if (board[i][j] == "X")
                    {
                        xPoints = xPoints + 5;

                        if (xPoints == 10)
                        {
                            for (int i = 0; i < 3; i++)
                            {
                                if (board[i][j] == "")
                                {
                                    board[i][j] = player_o.play_turn();
                                    row = i;
                                    col = j;
                                    doneWithTurn = true;
                                }
                            }
                        }
                    }
                    else if (board[i][j] == "O")
                    {
                        oPoints = oPoints - 5;

                        if (oPoints == -10)
                        {
                            for (int i = 0; i < 3; i++)
                            {
                                if (board[i][j] == "")
                                {
                                     board[i][j] = player_o.play_turn();
                                     row = i;
                                     col = j;
                                    doneWithTurn = true;
                                }
                            }
                        }
                    }
                }
            }
    }

    // Checking diags possible win or loss for X
    if(!doneWithTurn)
    {
            if (board[0][0] == "X" && board[1][1] == "X" && board[2][2] == "")
            {
                board[2][2] = player_o.play_turn();
                row = 2;
                col = 2;
                doneWithTurn = true;

            }
            else if (board[0][0] == "X" && board[2][2] == "X" && board[1][1] == "")
            {
                board[1][1] = player_o.play_turn();
                row = 1;
                col = 1;
                doneWithTurn = true;

            }
            else if (board[1][1] == "X" && board[2][2] == "X" && board[0][0] == "")
            {
                board[0][0] = player_o.play_turn();
                row = 0;
                col = 0;
                doneWithTurn = true;

            }
            else if (board[0][2] == "X" && board[1][1] == "X" && board[2][0] == "")
            {
                board[2][0] = player_o.play_turn();
                row = 2;
                col = 0;
                doneWithTurn = true;

            }
            else if (board[0][2] == "X" && board[2][0] == "X" && board[1][1] == "")
            {
                board[1][1] = player_o.play_turn();
                row = 1;
                col = 1;
                doneWithTurn = true;

            }
            else if (board[2][0] == "X" && board[1][1] == "X" && board[0][2] == "")
            {
                board[0][2] = player_o.play_turn();
                row = 0;
                col = 2;
                doneWithTurn = true;

            }

            // Checking diags possible win or loss for O
            if (board[0][0] == "O" && board[1][1] == "O" && board[2][2] == "")
            {
                board[2][2] = player_o.play_turn();
                row = 2;
                col = 2;
                doneWithTurn = true;

            }
            else if (board[0][0] == "O" && board[2][2] == "O" && board[1][1] == "")
            {
                board[1][1] = player_o.play_turn();
                row = 1;
                col = 1;
                doneWithTurn = true;

            }
            else if (board[1][1] == "O" && board[2][2] == "O" && board[2][2] == "")
            {
                board[0][0] = player_o.play_turn();
                row = 0;
                col = 0;
                doneWithTurn = true;

            }
            else if (board[0][2] == "O" && board[1][1] == "O" && board[2][0] == "")
            {
                board[2][0] = player_o.play_turn();
                row = 2;
                col = 0;
                doneWithTurn = true;

            }
            else if (board[0][2] == "O" && board[2][0] == "O" && board[1][1] == "")
            {
                board[1][1] = player_o.play_turn();
                row = 1;
                col = 1;
                doneWithTurn = true;

            }
            else if (board[2][0] == "O" && board[1][1] == "O" && board[0][2] == "")
            {
                board[0][2] = player_o.play_turn();
                row = 0;
                col = 2;
                doneWithTurn = true;
            }
    }

    // When no conditions are met from the above logic of winning or losing, the AI will choose a
    // random spot. If the spot is taken, it will choose another spot according to the random
    // numbers that are generated from 0-3
            int tempRow = rand() % 3;
            int tempCol = rand() % 3;
            if (!doneWithTurn)
            {
                while (!spotIsFree)
                {
                    if (board[tempRow][tempCol] != "")
                    {
                        tempRow = rand() % 3;
                        tempCol = rand() % 3;
                    }
                    else
                    {
                        board[tempRow][tempCol] = player_o.play_turn();
                        row = tempRow;
                        col = tempCol;
                        spotIsFree = true;
                        doneWithTurn = true;
                    }
                }
            }

    // This takes in the Row and Col values that were assigned from either of the above situtation
    // and is used to properly configure the GUI
    if(row == 0 && col == 0)
    {
        ui->topLeftButton->hide();
        ui->topLeftLabel->setText("O");
    }
    else if(row == 0 && col == 1)
    {
        ui->topMiddleButton->hide();
        ui->topMiddleLabel->setText("O");
    }
    else if(row == 0 && col == 2)
    {
        ui->topRightButton->hide();
        ui->topRightLabel->setText("O");
    }
    else if(row == 1 && col == 0)
    {
        ui->leftButton->hide();
        ui->leftLabel->setText("O");
    }
    else if(row == 1 && col == 1)
    {
        ui->middleButton->hide();
        ui->middleLabel->setText("O");
    }
    else if(row == 1 && col == 2)
    {
        ui->rightButton->hide();
        ui->rightLabel->setText("O");
    }
    else if(row == 2 && col == 0)
    {
        ui->bottomLeftButton->hide();
        ui->bottomLeftLabel->setText("O");
    }
    else if(row == 2 && col == 1)
    {
        ui->bottomMiddleButton->hide();
        ui->bottomMiddleLabel->setText("O");
    }
    else if(row == 2 && col == 2)
    {
        ui->bottomRightButton->hide();
        ui->bottomRightLabel->setText("O");
    }

    nextPlayer();
}

// Alternates between the players X and O
void MainWindow::nextPlayer()
{
    if(!nextPlayerTurn)
        nextPlayerTurn = true;
    else
        nextPlayerTurn = false;
}

// This functions checks to see if all the spots are taken
// return true if no spots left. return false if there is one left
bool MainWindow::spotFree()
{
    if(board[0][0] != "" && board[0][1] != "" && board[0][2] != ""
        && board[1][0] != "" && board[1][1] != "" && board[1][2] != ""
        && board[2][0] != "" && board[2][1] != "" && board[2][2] != "")
    {
        return false;
    }
    else
        return true;
}

/* When a button is clicked on the UI, if will go into one of these functions where
 * it will hide the button from being pressed again and exacute the play depending on
 * what player is making the move. If the AI is ON, the AI will take the place of the
 * O player. There are extra checks if the AI is on
*/

// ------- Top Row -----------------
void MainWindow::topLeftButtonClick()
{
    ui->topLeftButton->hide();
    if(!nextPlayerTurn)
    {
        board[0][0] = player_x.play_turn();
        ui->topLeftLabel->setText(board[0][0]);

    }
    else
    {
        if(!AI)
        {
            board[0][0] = player_o.play_turn();
            ui->topLeftLabel->setText(board[0][0]);
        }
    }

    if(AI && spotFree())
        ai_play();

     nextPlayer();
     checkWin();
     displayPlayer(); 
}

void MainWindow::topMiddleButtonClick()
{
    ui->topMiddleButton->hide();
    if(!nextPlayerTurn)
    {
        board[0][1] = player_x.play_turn();
        ui->topMiddleLabel->setText(board[0][1]);

    }
    else
    {
        if(!AI)
        {
            board[0][1] = player_o.play_turn();
            ui->topMiddleLabel->setText(board[0][1]);
        }
    }

    if(AI && spotFree())
        ai_play();

    nextPlayer();
    checkWin();
    displayPlayer();
}

void MainWindow::topRightButtonClick()
{
    ui->topRightButton->hide();
    if(!nextPlayerTurn)
    {
        board[0][2] = player_x.play_turn();
        ui->topRightLabel->setText(board[0][2]);

    }
    else
    {
        if(!AI)
        {
            board[0][2] = player_o.play_turn();
            ui->topRightLabel->setText(board[0][2]);
        }
    }

    if(AI && spotFree())
        ai_play();

    nextPlayer();
    checkWin();
    displayPlayer();
}
//-----------------------------------

// ------- Middle Row -----------------
void MainWindow::leftButtonClick()
{
    ui->leftButton->hide();
    if(!nextPlayerTurn)
    {
        board[1][0] = player_x.play_turn();
        ui->leftLabel->setText(board[1][0]);

    }
    else
    {
        if(!AI)
        {
            board[1][0] = player_o.play_turn();
            ui->leftLabel->setText(board[1][0]);
        }
    }

    if(AI && spotFree())
        ai_play();

    nextPlayer();
    checkWin();
    displayPlayer();
}

void MainWindow::middleButtonClick()
{
    ui->middleButton->hide();
    if(!nextPlayerTurn)
    {
        board[1][1] = player_x.play_turn();
        ui->middleLabel->setText(board[1][1]);

    }
    else
    {
        if(!AI)
        {
            board[1][1] = player_o.play_turn();
            ui->middleLabel->setText(board[1][1]);
        }
    }

    if(AI && spotFree())
        ai_play();

    nextPlayer();
    checkWin();
    displayPlayer();
}

void MainWindow::rightButtonClick()
{
    ui->rightButton->hide();
    if(!nextPlayerTurn)
    {
        board[1][2] = player_x.play_turn();
        ui->rightLabel->setText(board[1][2]);

    }
    else
    {
        if(!AI)
        {
            board[1][2] = player_o.play_turn();
            ui->rightLabel->setText(board[1][2]);
        }
    }

    if(AI && spotFree())
        ai_play();

    nextPlayer();
    checkWin();
    displayPlayer();
}
//-----------------------------------

// ------- Bottom Row -----------------
void MainWindow::bottomLeftButtonClick()
{
    ui->bottomLeftButton->hide();
    if(!nextPlayerTurn)
    {
        board[2][0] = player_x.play_turn();
        ui->bottomLeftLabel->setText(board[2][0]);

    }
    else
    {
        if(!AI)
        {
            board[2][0] = player_o.play_turn();
            ui->bottomLeftLabel->setText(board[2][0]);
        }
    }

    if(AI && spotFree())
        ai_play();

    nextPlayer();
    checkWin();
    displayPlayer();
}

void MainWindow::bottomMiddleButtonClick()
{
    ui->bottomMiddleButton->hide();
    if(!nextPlayerTurn)
    {
        board[2][1] = player_x.play_turn();
        ui->bottomMiddleLabel->setText(board[2][1]);

    }
    else
    {
        if(!AI)
        {
            board[2][1] = player_o.play_turn();
            ui->bottomMiddleLabel->setText(board[2][1]);
        }
    }

    if(AI && spotFree())
        ai_play();

    nextPlayer();
    checkWin();
    displayPlayer();
}

void MainWindow::bottomRightButtonClick()
{
    ui->bottomRightButton->hide();
    if(!nextPlayerTurn)
    {
        board[2][2] = player_x.play_turn();
        ui->bottomRightLabel->setText(board[2][2]);

    }
    else
    {
        if(!AI)
        {
            board[2][2] = player_o.play_turn();
            ui->bottomRightLabel->setText(board[2][2]);
        }
    }

    if(AI && spotFree())
        ai_play();

    nextPlayer();
    checkWin();
    displayPlayer();
}
//-----------------------------------

// Displays the number of wins to the UI
void MainWindow::displayWins()
{

    ui->xWinsLabel->setText(QString::number(player_x.get_score()));
    ui->oWinsLabel->setText(QString::number(player_o.get_score()));
    ui->drawLabel->setText(QString::number(draws));
}

// Displays whos turn it is on the UI
void MainWindow::displayPlayer()
{
   if(!nextPlayerTurn)
       ui->playerLabel->setText(player_x.play_turn());
   else
       ui->playerLabel->setText(player_o.play_turn());
}

// Adds draw count if no one wins
unsigned int MainWindow::addDraw()
{
    draws+=1;

    return draws;
}

// Checking for wins
void MainWindow::checkWin()
{
    // Scans all the rows and Col for a win
    for(int i = 0; i < 3; i ++)
    {
        if(board[i][0] == "X" && board[i][1] == "X" && board[i][2] == "X")
            winner = "X";
        else if(board[0][i] == "X" && board[1][i] == "X" && board[2][i] == "X")
            winner = "X";
        else if(board[i][0] == "O" && board[i][1] == "O" && board[i][2] == "O")
            winner = "O";
        else if(board[0][i] == "O" && board[1][i] == "O" && board[2][i] == "O")
            winner = "O";
    }

    // Scans both diags for a win
    if(board[0][0] == "X" && board[1][1] == "X" && board[2][2] == "X")
        winner = "X";
    else if(board[2][0] == "X" && board[1][1] == "X" && board[0][2] == "X")
        winner = "X";
    else if(board[0][0] == "O" && board[1][1] == "O" && board[2][2] == "O")
        winner = "O";
    else if(board[2][0] == "O" && board[1][1] == "O" && board[0][2] == "O")
        winner = "O";

    // Which ever player wins, it will display a window indicating who won and
    // add a win to who won.

    // the last case is if there are no spots free indicating a draw
    if(winner == "X")
    {
        player_x.add_score();
        displayWins();
        oWinsBox.setText("Player X Wins!");
        oWinsBox.exec();
        clearBoard();
    }
    else if(winner == "O")
    {
        player_o.add_score();
        displayWins();
        oWinsBox.setText("Player O Wins!");
        oWinsBox.exec();
        clearBoard();
    }
    else if(!spotFree())
    {
        addDraw();
        displayWins();
        drawBox.setText("Draw");
        drawBox.exec();
        clearBoard();
    }
}

void MainWindow::clearBoard()
{
    // Clearing the board of X and O's
    nextPlayerTurn = false;
    winner = "";

    ui->topLeftLabel->setText("");
    ui->topMiddleLabel->setText("");
    ui->topRightLabel->setText("");

    ui->leftLabel->setText("");
    ui->middleLabel->setText("");
    ui->rightLabel->setText("");

    ui->bottomLeftLabel->setText("");
    ui->bottomMiddleLabel->setText("");
    ui->bottomRightLabel->setText("");

    // Showing all of the buttons again to play
    ui->topLeftButton->show();
    ui->topMiddleButton->show();
    ui->topRightButton->show();

    ui->rightButton->show();
    ui->middleButton->show();
    ui->leftButton->show();

    ui->bottomLeftButton->show();
    ui->bottomMiddleButton->show();
    ui->bottomRightButton->show();

    //reseting the 2D array board
    for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
                board[i][j] = "";
        }
}

// The AI button is on the bottom of the UI and when its pressed,
// It will let the user know that the AI is on and the AI will be
// making the moves for the player O.
void MainWindow::on_AIpushButton_clicked()
{
    if(!AI)
    {
        AI = true;
        clearBoard();
        ui->AIpushButton->setText("AI ON");
    }
    else
    {
        AI = false;
        clearBoard();
        ui->AIpushButton->setText("AI OFF");
    }
}
