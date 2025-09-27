#include<iostream>
#include"Ashwin_Mahajan_task2_Complex.h"

int main(){

    // First create objects
    Complex c1(0,0);
    Complex c2(0,0);

    // Now test istream object
    std::cin>>c1;
    std::cin>>c2;

    // And check properly allocated or not
    std::cout<<"\n The c1 complex no is: "<<c1;
    std::cout<<"\n The c2 complex no is: "<<c2;

    // Check multiplication operation
    std::cout<<"\nMultiplication of two above complex no: "<<c1*c2<<std::endl;

    // Check addition and substrction
    std::cout<<"\nSubstraction of two above complex no: "<<c1-c2<<std::endl;
    std::cout<<"\nAddition of two above complex no: "<<c1+c2<<std::endl;

    // Check if both complex no are same
    if(c1==c2){
        std::cout<<"\nBoth complex no are same..."<<std::endl;
    }
    else{
        std::cout<<"\nBoth complex no are not same..."<<std::endl;
    }

    
}   