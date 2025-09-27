#include<iostream>
#include"Ashwin_Mahajan_task4_RationalNumber.h"

int main(){
    
    // try constructor
    RationalNumber r1(11,22);
    RationalNumber r2(23,24);

    // try accpting new values
    std::cin>>r1;
    std::cin>>r2;

    // Try to print
    std::cout<<"\nFirst Rational No is: "<<r1;
    std::cout<<"\nSecond Rational No is: "<<r2;

    // Check the greatness or equal ness
    (r1==r2) ? std::cout<<"\nBoth r1 and r2 are same..." : ((r1>r2) ? std::cout<<"\nr1 is greater than r2..." : std::cout<<"\nr2 is greater than r1...");

    // check + * - and /
    std::cout<<"\nAddition is: "<<(r1+r2);
    std::cout<<"\nSubstraction is: "<<(r1-r2);
    std::cout<<"\nMultiplication is: "<<(r1*r2);
    std::cout<<"\nDivision is: "<<(r1/r2);

    

    return 0;
}