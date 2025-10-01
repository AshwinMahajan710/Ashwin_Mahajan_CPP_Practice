#include<iostream>
#include"Ashwin_Mahajan_task1_HybridVehicle.h"
#include<string>

int main(){

    // Create two objects
    HybridVehicle v1("Prius", 120.5, 80.0, 4.5);
    HybridVehicle v2("Volt", 100.0, 90.0, 5.0);

    // Assign trips
    v1[0] = 50; v1[1] = 60;
    v2[0] = 70; v2[1] = 40;

    // Printing details using << operator
    std::cout<<"\nDetails of car v1: "<<std::endl;
    std::cout<<v1;
    std::cout<<"\nDetails of car v2: "<<std::endl;
    std::cout<<v2;

    // test the accessing of the index using suscript operator
    std::cout<<"\nTrip no :"<< 2 <<"  Distance Travelled: "<<v1[1]<<std::endl;

    // + operator
    std::cout<<"\nCombining two vehicle: "<<std::endl;
    std::cout<<v1+v2;

    // Deep copy check
    v1 = v2;
    std::cout<<"\nNew details of v1: "<<std::endl;
    std::cout<<v1;

    // increment operation check
    v1++;
    std::cout<<"\nAfter addig dummy trip: "<<std::endl;
    std::cout<<v1;

    // get efficiency
    std::cout<<"\nEfficieny of the vehicle is: "<<float(v1)<<" KMPL"<<std::endl;
    
    // get total distance
    std::cout<<"\nTotal Distance travelled by vehicle: "<<v1()<<" KM"<<std::endl;
    
    return 0;
}