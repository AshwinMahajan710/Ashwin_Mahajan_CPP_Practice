#include<iostream>
#include"Ashwin_Mahajan_task5_TicTacToe.h"

int main(){

    TicTacToe board; // create the object
    int row, col; // for row and col

    // Print the board first
    std::cout<<"Current board: "<<std::endl;
    board.printBoard();

    // Now play the game
    while(true) {
        std::cout << "\n\nPlayer " << board.getCurrentPlayer()<< ", enter row and column (0-2): ";
        std::cin >> row >> col;

        // only move if we are able to move
        if(board.makeMove(row, col)) {
            board.printBoard(); // after making move print the board completely
            if(board.checkWin()) {
                std::cout << "\nPlayer " << board.getCurrentPlayer() << " wins!\n";
                break;
            } 
            // Everytime after a valid move check for draw
            if(board.checkDraw()) {
                std::cout << "\n It's a draw!\n";
                break;
            }
            board.switchPlayer(); // after evry valid move switch player
        }
    }

}