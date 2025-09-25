#include<iostream>
#include"Ashwin_Mahajan_task2_DeckOfCards.h"
#include"Ashwin_Mahajan_task2_Card.h"
#include<string>
#include<ctime>
#include<algorithm>

// Constructor --> initializing each 52 cards
DeckOfCards::DeckOfCards(){
    for(int i=0;i<std::size(Card::faces);i++){
        for(int j=0;j<std::size(Card::suits);j++){
            cards.push_back(Card(i,j));
            currentCard = 0;
        }
    }
}

// Shuffle function to shuffle cards from the deck
void DeckOfCards::shuffle() {
    srand(time(nullptr));
    for (int i = cards.size() - 1; i > 0; --i) {
        int j = rand() % (i + 1);  
        std::swap(cards[i], cards[j]);
    }
}

// return the next card
Card DeckOfCards::dealCard() {
    if (moreCards()) {
        return cards[currentCard++];  // give the next card, after that increment
    }
    throw std::out_of_range("\nCards in the deck are over...");
}

// checks deck has more cards or not
bool DeckOfCards::moreCards() const{
    if (currentCard == 52) {return false;}
    else {return true;} 
}