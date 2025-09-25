// Class DeckOfCards should contain:
// a) A vector of Cards named deck to store the Cards.
// b) An integer currentCard representing the next card to deal.
// c) A default constructor that initializes the Cards in the deck. The constructor should use
// vector function push_back to add each Card to the end of the vector after the Card is
// created and initialized. This should be done for each of the 52 Cards in the deck.
// d) A shuffle function that shuffles the Cards in the deck. The shuffle algorithm should
// iterate through the vector of Cards. For each Card, randomly select another Card in the
// deck and swap the two Cards.
// e) A dealCard function that returns the next Card object from the deck.
// f) A moreCards function that returns a bool value indicating whether there are more Cards
// to deal.
// The driver program should create a DeckOfCards object, shuffle the cards, then deal the 52 cards. 

// Header file for deck of cards

#ifndef DECK_OF_CARDS_H
#define DECK_OF_CARDS_H

#include"Ashwin_Mahajan_task2_Card.h"
#include<vector>

class DeckOfCards{
    private:
        std::vector<Card> cards;
        int currentCard;

    public:
        DeckOfCards();
        void shuffle();
        Card dealCard() ;
        bool moreCards() const; // will return true if deck is not over
};

#endif 