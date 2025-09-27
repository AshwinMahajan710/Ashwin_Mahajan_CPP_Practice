
#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include<iostream>

class Polynomial{
    private:
        int* ptr; // can store upto 11 polynomial terms
        int size;

    public:
        Polynomial(int ); // constructor
        friend std::istream& operator >>(std::istream& in, Polynomial& other); // getting input
        friend std::ostream& operator << (std::ostream& in, const Polynomial& other) ;// getting output
        Polynomial operator+ (const Polynomial& other)const ; // operator +
        Polynomial operator- (const Polynomial& other)const ; // operator -
        Polynomial operator* (const Polynomial& other)const ; // operator *
        void operator= (const Polynomial& other); // operator =
        void operator+= (const Polynomial& other); // operator -+=
        void operator-= (const Polynomial& other); // operator -=
        void operator*= (const Polynomial& other); // operator *=
};

#endif 