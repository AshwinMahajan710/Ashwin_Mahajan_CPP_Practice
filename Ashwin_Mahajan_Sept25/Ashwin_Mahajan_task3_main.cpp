// Main file

#include<iostream>
#include"Ashwin_Mahajan_task2_DeckOfCards.h"
#include"Ashwin_Mahajan_task2_Card.h"
#include"Ashwin_Mahajan_task3_Gameplay.h"
#include<vector>

int  main(){

    // Creating the object for deck of cards
    DeckOfCards deck;
    deck.shuffle(); // shuffle the cards

    // Creating the two players
    std::vector<Card> player1;// Two players
    std::vector<Card> player2;

    // Assign the cards
    assignCards(player1, player2, deck);
    
    // print both peoples car
    std::cout<<"\nPlayer 1 cards: "<<std::endl;
    showCards(player1);
    std::cout<<"\nPlayer 2 cards: "<<std::endl;
    showCards(player2);

    std::cout<<"\n"<<std::endl;
    if(hasTriplets(player1) && !hasTriplets(player2)){
        std::cout<<"Player 1 won by having triplets: "<<std::endl;
        showCards(player1);
    }

    else  if(!hasTriplets(player1) && hasTriplets(player2)){
        std::cout<<"Player 2 won by having triplets: "<<std::endl;
        showCards(player2);
    }

    else  if(!hasDuplates(player1) && hasDuplates(player2)){
        std::cout<<"Player 2 won by having duplates: "<<std::endl;
        showCards(player2);
    }
    else  if(hasDuplates(player1) && !hasDuplates(player2)){
        std::cout<<"Player 1 won by having duplates: "<<std::endl;
        showCards(player1);
    }
    else  if(hasSameSuits(player1) && !hasSameSuits(player2)){
        std::cout<<"Player 1 won by having Same 3 suits: "<<std::endl;
        showCards(player1);
    }
    else  if(!hasSameSuits(player1) && hasSameSuits(player2)){
        std::cout<<"Player 2 won by having Same 3 suits: "<<std::endl;
        showCards(player2);
    }
    else if(maxFace(player1)>maxFace(player2)){
        std::cout<<"Player 1 won by having max face card: "<<std::endl;
        showCards(player1);
    }
    else{
        std::cout<<"Player 2 won by having max face card: "<<std::endl;
        showCards(player2);
    }

    return 0;
}