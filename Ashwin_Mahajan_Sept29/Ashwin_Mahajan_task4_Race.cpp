// Source file --->  global function definitions

#include<iostream>
#include"Ashwin_Mahajan_task4_Race.h"

const int MAX_SQUARE = 70;
const int MIN_SQUARE = 1;

// Function to print race track
void raceDisplay(int tortoise, int hare ){
    for(int i=1;i<=70;i++){

        // If both are on same square
        if(tortoise == hare && hare == i){
            std::cout<<"OUCH!!! ";
        }

        // tortoise square
        else if(i == tortoise){
            std::cout<<"T ";
        }

        // Hare square
        else if(i == hare){
            std::cout<<"H ";
        }

        // normal squares
        else {
            std::cout<<"- ";
        }
    }
    std::cout<<std::endl;
}

// Move Tortoise function
void moveTortoise(int*& pos, int getStep){
    if(getStep <=5 ) {
        int getDiff = (MAX_SQUARE - (*pos)) >= 3 ? 3 : (MAX_SQUARE - (*pos)); // get Position that how much squares can be incremented
        pos += getDiff; // if crosses 70 cap it to 70;
    }

    else if(getStep == 6 || getStep == 7){
        int getDiff = ((*pos) - MIN_SQUARE) > 6 ? 6 : ((*pos) - MIN_SQUARE);
        pos -= getDiff;
    }

    else {
        int getDiff = (MAX_SQUARE - (*pos)) >=1 ? 1 : 0;
        pos += getDiff;
    }
} 

// move Hare function
void moveHare(int*& pos, int getStep){
    if(getStep == 1 || getStep == 2){ // Hare sleeps
        return;
    }
    else if(getStep == 3 || getStep == 4){ // big hop
        int getDiff = (MAX_SQUARE - (*pos)) >= 9 ? 9 : (MAX_SQUARE - (*pos)); // get Position that how much squares can be incremented
        pos += getDiff; // if crosses 70 cap it to 70;
    }
    else if(getStep == 5){ // big sleep
        int getDiff = ((*pos) - MIN_SQUARE) > 12 ? 12 : ((*pos) - MIN_SQUARE);
        pos -= getDiff;
    }
    else if(getStep >=6 && getStep<=8){ // small hop
        int getDiff = (MAX_SQUARE - (*pos)) >=1 ? 1 : 0;
        pos += getDiff;
    }
    else { // small slip
        int getDiff = ((*pos) - MIN_SQUARE) > 2 ? 2 : ((*pos) - MIN_SQUARE);
        pos -= getDiff;
    }
}
