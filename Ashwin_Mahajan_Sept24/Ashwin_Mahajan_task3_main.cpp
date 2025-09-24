#include<iostream>
#include"Ashwin_Mahjan_task3_DateAndTime.h"

int main(){
    DateAndTime dt(23,51,15,12,9,2025); // Creating object

    // Running the loop for 10000 sec to check that day changes successfully or not
    for(int i=1;i<=10000;i++){
        dt.tick(); // as overloaded no conflict will happen
        std::cout<<"\n Second Increment..."<<std::endl;
        std::cout<<"The universal format(MM-DD-YYYY): ";
        dt.printUniversal();
        std::cout<<"The standard format(DD-MM-YYYY): ";
        dt.printStandard();
    }

    return 0;
}