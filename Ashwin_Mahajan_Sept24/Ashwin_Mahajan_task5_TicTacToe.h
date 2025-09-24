// (TicTacToe Class) Create a class TicTacToe that will enable you to write a complete program
// to play the game of tic-tac-toe. The class contains as private data a 3-by-3 two-dimensional array
// of integers. The constructor should initialize the empty board to all zeros. Allow two human players.
// Wherever the first player moves, place a 1 in the specified square. Place a 2 wherever the second play-
// er moves. Each move must be to an empty square. After each move, determine whether the game
// has been won or is a draw. If you feel ambitious, modify your program so that the computer makes
// the moves for one of the players. Also, allow the player to specify whether he or she wants to go first
// or second. If you feel exceptionally ambitious, develop a program that will play three-dimensional
// tic-tac-toe on a 4-by-4-by-4 board. [Caution: This is an extremely challenging project that could
// take many weeks of effort!]

#ifndef TIC_TAC_TOE_H
#define TIC_TAC_TOE_H
class TicTacToe{
    private:
        char board[3][3];
        char currentPlayer;
    public:
        
        TicTacToe(); // Initialiing the board
        void printBoard() const; // Printing the board
        bool makeMove(int , int ); // Making the move and if moved then only mark as true
        bool checkWin() const; // Checking the win by comparing rows
        bool checkDraw()const; // If all cells are full it is draw
        void switchPlayer(); // This will switch player
        char getCurrentPlayer() const; // will return the current player by value

};

#endif
