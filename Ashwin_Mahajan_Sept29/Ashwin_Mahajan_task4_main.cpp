#include<iostream>
#include<ctime>
#include<cstdlib> 
#include"Ashwin_Mahajan_task4_Race.h"

int main(){
    int track[71]; // total size 71 : 1 to 70 = 70 positions
    for(int i=1;i<=70;i++){
        track[i] = i;
    }

    // Initializing the hare and tortoise positions
    int* tortoise = &track[1]; 
    int * hare = &track[1]; // Initializing positions of both animals

    // Printing the hare start message
    std::cout<<"BANG !!!!!\nAND THEY'RE OFF !!!!!"<<std::endl;

    int step = 1;
    std::srand(std::time(0));
    while(true){
        std::cout<<"\nClock Tick ..... !!! "<<std::endl;
        std::cout<<"Time Step "<<step<<" : "<<std::endl;
        int randomSteps = (std::rand() % 10) + 1; // generate the random no in 1 to 10
        std::cout<<"Movement Steps: "<<randomSteps<<std::endl;
        moveHare(hare,randomSteps);
        moveTortoise(tortoise, randomSteps);
        std::cout<<" Race Stat : "<<std::endl;
        raceDisplay(*tortoise, *hare);
        step++;

        if(*tortoise == 70 && *hare == 70){
            std::cout<<"\nIt's a tie....";
            return 0;
        }
        else if(*tortoise == 70){
            std::cout<<"\nTORTOISE WINS!!! YAY!!!";
            return 0;
        }
        else if(*hare == 70){
            std::cout<<"\nHare wins. Yuch.";
            return 0;
        }
    }

    return 0;
}