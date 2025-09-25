#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include"Ashwin_Mahajan_task2_Card.h"
#include"Ashwin_Mahajan_task2_DeckOfCards.h"
#include<vector>


// All are the global functions
void assignCards(std::vector<Card>& vec1,std::vector<Card>& vec2, DeckOfCards& deck);
void showCards(std::vector<Card>& vec);
bool hasTriplets(std::vector<Card>& vec);
bool hasDuplates(std::vector<Card>& vec);
bool hasSameSuits(std::vector<Card>& vec);
int maxFace(std::vector<Card>& vec);

#endif