
#include<iostream>

#ifndef COMPLEX_H
#define COMPLEX_H

// Complex class 
class Complex{

    private:
        double real; // real part
        double imaginary; // imaginary part

    public:
        Complex( double = 0.0, double = 0.0 ); // constructor
        Complex operator+( const Complex & )const; // addition
        Complex operator-( const Complex & )const; // subtraction
        friend std::ostream& operator<<(std::ostream& out, const Complex& Complex); // outstream obj overloading
        friend std::istream& operator>>(std::istream& in, Complex& Complex); // istream obj overloading
        Complex operator*( const Complex & )const; // multiplication operator overloading
        bool operator==(const Complex& other)const; // to compare complex no equality
};

#endif