// main function

#include<iostream>
#include"Ashwin_Mahajan_task3_global.h"

int main(){

    // switching the two values
    double val1 = 45.2;
    double val2 = 33.8;

    // Testing exchange function
    std::cout<<"\nVal1 : "<<val1<<" Val2 : "<<val2<<std::endl;
    std::cout<<"\nValues after swap: ";
    exchange(&val1 , &val2);
    std::cout<<"\nVal1 : "<<val1<<" Val2 : "<<val2<<std::endl;

    // Testing evaluate function
    std::cout<<"\n Sqaure with sum of same no 20 is : "<<evaluate(20, Poly)<<std::endl;

    // Initializing char array by two ways
    char vowel[] = "AEIOU";
    char vowel[6] = "AEIOU"; // last character is '\n'

    return 0;

}