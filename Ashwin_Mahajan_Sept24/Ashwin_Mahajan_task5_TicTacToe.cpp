#include<iostream>
#include"Ashwin_Mahajan_task5_TicTacToe.h"

// Constructor
TicTacToe::TicTacToe(){
currentPlayer = 'X';
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            board[i][j] = ' ';
        }
    }
};

// Printing the board
void TicTacToe::printBoard()const{
    for(int i=0;i<3;i++){
        std::cout<<std::endl;
        for(int j=0;j<3;j++){
            std::cout<<" "<<board[i][j];
        }
    }
}

// make move only and only if cell is not already taken
bool TicTacToe::makeMove(int row, int col){
    if(row < 0 || row > 2 || col < 0 || col > 2) {
            std::cout << "Invalid position! Try again..."<<std::endl;
            return false;
        }
        if(board[row][col] != ' ') {
            std::cout << "Cell already taken! Try again..."<<std::endl;
            return false;
        }
        board[row][col] = currentPlayer;
        return true;
}

// Check if the player is won or not 
bool TicTacToe:: checkWin() const{
    // Rows and Columns
    for(int i=0; i<3; i++) {
        if(board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) {return true;}
        if(board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer) {return true;}
    }

    // Diagonals
    if(board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer){return true;}
    if(board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer){return true;}

    return false; // if no row or diagonal similar return false
}

// Check if match is draw or not
bool TicTacToe::checkDraw() const{
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            if(board[i][j] == ' ')
                return false;
        }
    }
    return true;
}

// Will switch the player after each move
void TicTacToe::switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

// will return the current player
char TicTacToe::getCurrentPlayer() const{
    return currentPlayer; 
}