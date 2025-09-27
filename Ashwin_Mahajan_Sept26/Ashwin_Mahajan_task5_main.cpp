#include<iostream>
#include"Ashwin_Mahajan_task5_Polynomial.h"

int main(){

    // Lets first initialize the polynomial array
    Polynomial poly1(4);

    // try to print it
    std::cout<<"Polynomial is: "<<poly1;

    // try to get input from user
    std::cin>>poly1;
    std::cout<<"\nPolynomial 1 is: "<<poly1;

    // Get one more polynomial and try to test addition
    Polynomial poly2(0);
    std::cin>>poly2;
    std::cout<<"\nPolynomial 2 is: "<<poly2;
    std::cout<<"\nAddition of both polynomial is: "<<(poly1 + poly2);

    // Substraction will be same
    // lets try multiplication
    std::cout<<"\nMultiplication of both polynomial is: "<<(poly1*poly2);

    // Now try assignment operator
    poly1 *= poly2;
    std::cout<<"\nAfter multiplication assignment: "<<poly1;
    return 0;
}