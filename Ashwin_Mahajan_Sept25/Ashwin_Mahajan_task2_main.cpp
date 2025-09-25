// Main file

#include<iostream>
#include"Ashwin_Mahajan_task2_DeckOfCards.h"
#include"Ashwin_Mahajan_task2_Card.h"

int main(){

    // creating the object first
    DeckOfCards deck;

    // first shuffle
    deck.shuffle();

    // will give 52 shuffled cards and then code will terminate as no cards are remaining in the deck
    std::cout<<"Let's See Shuffled cards : "<<std::endl;
    for(int i=0;i<53;i++){
        std::cout<<"Card "<<i+1<<" : "<<deck.dealCard().toString()<<std::endl;
    }

}