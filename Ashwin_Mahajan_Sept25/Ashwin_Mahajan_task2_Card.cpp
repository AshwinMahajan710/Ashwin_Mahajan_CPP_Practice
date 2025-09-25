// Source file --> Class defintion

#include<iostream>
#include"Ashwin_Mahajan_task2_Card.h"
#include<string>

// Initializing the static arrays
const std::string Card::faces[13] = {"Ace", "Two", "Three", "Four", "Five", "Six","Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
const std::string Card::suits[4] = {"Hearts", "Diamonds", "Clubs", "Spades"};

// Constructor
Card::Card(int face, int suit){
    this->face = face;
    this->suit = suit;
}

// Will return complete name of the particular card
std::string Card::toString() const{
    return (faces[face] + " of " + suits[suit]);
}

// getters for task3
int Card::getFace() const{return face;};
int Card::getSuit() const{return suit;};


