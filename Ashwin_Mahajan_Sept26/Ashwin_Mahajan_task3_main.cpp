#include<iostream>
#include"Ashwin_Mahajan_task3_HugeInt.h"
#include<string>

int main(){

    // Try constructors
    HugeInt no1(12345);
    HugeInt no2("1234567896753");

    // Try printing it
    std::cout<<"\nNo 1: "<<no1;
    std::cout<<"\nNo 2: "<<no2;

    // Try istream object
    std::cin>>no2;
    std::cout<<"\nNew no2 is: "<<no2;

    // Try addition
    std::cout<<"\nAddition of both numbers is: "<<(no1+no2)<<std::endl;

    // Try substraction
    std::cout<<"\nSubtraction of both numbers is: "<<(no1-no2)<<std::endl;

    // Try multiplication
    std::cout<<"\nMultiplication  of both numbers is: "<<(no1*no2)<<std::endl;

    // Try division
    std::cout<<"\nDivision of both numbers is: "<<(no1/no2)<<std::endl;

    // Try equality
    (no1==no2) ? std::cout<<"\nBoth no are same..":std::cout<<"Both numbers are not same..";
}