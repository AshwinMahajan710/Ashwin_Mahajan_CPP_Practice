// Main file

#include<iostream>
#include"Ashwin_Mahajan_task2_Date.h"

int main(){
    Date date(9,24,2025);
    std::cout<<"\n Thousand days starting from today: "<<std::endl;

    // Trying to run the loop for 1000 days for testing
    for(int i=1;i<=1000;i++){
        std::cout<<"\nday: "<<i<<std::endl;
        std::cout<<"The next day is: " ;
        date.nextDay();
    }
    return 0;
}