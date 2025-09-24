#include<iostream>
#include"Ashwin_Mahajan_task1_Time.h"

int main(){

    Time time(12,11,13); // Creating object

    for(int i=0;i<10000;i++){
        time.tick(); // Incrementing second
        std::cout<<"\nCurrent new second: "<<i+1<<std::endl;        
        std::cout<<"Current Universal Time: ";
        time.printUniversal();
        std::cout<<"Current Standard Time: ";
        time.printStandard();
    }

    return 0;
}
