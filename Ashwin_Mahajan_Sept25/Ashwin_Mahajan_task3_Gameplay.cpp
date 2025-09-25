// 10.12 (Card Shuffling and Dealing) Use the functions from Exercise 10.11 to write a program
// that deals two five-card poker hands, evaluates each hand and determines which is the better hand.
#include<iostream>
#include"Ashwin_Mahajan_task2_Card.h"
#include"Ashwin_Mahajan_task2_DeckOfCards.h"
#include<vector>
#include"Ashwin_Mahajan_task3_Gameplay.h"

// distribute each of five cards among 2 players
void assignCards(std::vector<Card>& vec1,std::vector<Card>& vec2, DeckOfCards& deck){
    vec1.clear();
    vec2.clear();
    for(int i=0;i<5;i++){
        vec1.push_back(deck.dealCard()); // will give the card to each player
        vec2.push_back(deck.dealCard());
    }
}

// Show player cards
void showCards(std::vector<Card>& vec){
    for(int i=0;i<vec.size();i++){
        std::cout<<"Card "<<i<<": "<<vec[i].toString()<<std::endl;
    }
}

// Compare triplets --> for 5 card game
bool hasTriplets(std::vector<Card>& vec){
    for(int i=0;i<vec.size()-2;i++){
        for(int j=i+1;j<vec.size()-1;j++){
            for(int k=j+1;k<vec.size();k++){
                if((vec[i].getFace()==vec[j].getFace()) && (vec[j].getFace()==vec[k].getFace())){
                    return true;
                }
            }
        }
    }
    return false;
}

// Compare duplates
bool hasDuplates(std::vector<Card>& vec){
    for(int i=0;i<vec.size()-1;i++){
        for(int j=i+1;j<vec.size();j++){
            if((vec[i].getFace()==vec[j].getFace())){
                return true;   
            }
        }
    }
    return false;
}


// Compare 3 same suits --> for 5 card game
bool hasSameSuits(std::vector<Card>& vec){
    for(int i=0;i<vec.size()-2;i++){
        for(int j=i+1;j<vec.size()-1;j++){
            for(int k=j+1;k<vec.size();k++){
                if((vec[i].getSuit()==vec[j].getSuit()) && (vec[j].getSuit()==vec[k].getSuit())){
                    return true;
                }
            }
        }
    }
    return false;
}

// Compare the face card with maximum value
int maxFace(std::vector<Card>& vec) {
    int maxFace = vec[0].getFace();
    for (int i = 1; i < vec.size(); i++) {
        int curr = vec[i].getFace();

        if (curr == 0 && maxFace != 0) {
            maxFace = curr;  
        }

        else if (maxFace != 0 && curr > maxFace) {
            maxFace = curr;
        }
    }
    return maxFace;
}
