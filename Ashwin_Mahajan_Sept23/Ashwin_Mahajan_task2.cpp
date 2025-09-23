
#include <iostream>
#include <cstdlib> // contains prototypes for functions srand and rand
#include <ctime>   // contains prototype for function time

// rolls dice, calculates and displays sum
int rollDice()
{
    // pick random die values
    int die1 = 1 + rand() % 6; // first die roll
    int die2 = 1 + rand() % 6; // second die roll
    int sum = die1 + die2;     // compute sum of die values

    return sum;
} 

int main()
{
    int idx = 0; // index to keep track of arr
    int game_won_record[1000]; // for each game keeps track that game is won or lose
    int total_Games_won = 0; // Keeps track of how much games won until particular game
    int total_turns = 0; // keeps track of turns per game --> will help in calculation of average length of craps 

    // For game status
    enum Status
    {
        CONTINUE,
        WON,
        LOST
    };

    int myPoint;       // point if no win or loss on first roll
    Status gameStatus; // can contain CONTINUE, WON or LOST

    // randomize random number generator using current time
    srand(time(0));

    // Now play the game for 1000 rounds
    while(idx<1000){
        int sumOfDice = rollDice(); // first roll of the dice

        switch (sumOfDice)
        {
            case 7:  case 11:  // win on 7 or 11
                gameStatus = WON;
                break;

            case 2:  case 3:  case 12: // lost on 2 3 12
                gameStatus = LOST;
                break;

            default:                   // did not win or lose, so remember point
                gameStatus = CONTINUE; 
                myPoint = sumOfDice;   
                break; // optional at end of switch
        } 
        
        total_turns++; // as first round is played

        // while game is not complete
        while (gameStatus == CONTINUE) // not WON or LOST
        {
            sumOfDice = rollDice(); // roll dice again
            total_turns++;

            if (sumOfDice == myPoint){ // on the game
                gameStatus = WON;
            } 

            else if (sumOfDice == 7) { // Lose the game
                gameStatus = LOST;   
            }   
        
        }

        // display won or lost message
        if (gameStatus == WON){
            game_won_record[idx++] = ++total_Games_won;
        }
        else{
            game_won_record[idx++] = total_Games_won;
        }
        
    }
    std::cout<<"\nTotal Games won by player: "<<total_Games_won<<std::endl;

    std::cout<<"Games won by player on its 432th trial: "<<game_won_record[431]<<std::endl;
    std::cout<<"Games lost by player on its 432th trial: "<<(432-game_won_record[431])<<std::endl;

    std::cout<<"Chances of winning at craps: "<<(game_won_record[999] * 100) / 1000<<"%..."<<std::endl;

    std::cout<<"Average length of craps game: "<< int(total_turns/1000 )<<std::endl;

} 
