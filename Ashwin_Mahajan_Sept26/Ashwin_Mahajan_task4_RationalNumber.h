//  Header file

#ifndef RATIONAL_NUMBER_H
#define RATIONAL_NUMBER_H

#include<iostream>

// Class rational number
class RationalNumber{
    private:
        int denominator; 
        int numerator;
    
    public:
        RationalNumber(int, int ); // Constructor
        RationalNumber operator+(const RationalNumber& other) const; //  Addition operator
        RationalNumber operator-(const RationalNumber& other) const; //  substraction operator
        RationalNumber operator/(const RationalNumber& other) const; //Division operator
        RationalNumber operator*(const RationalNumber& other) const; // multiplication operator
        bool operator ==(const RationalNumber& other) const; // equality check operator
        void operator =(const RationalNumber& other) ; // Assignment operator
        bool operator !=(const RationalNumber& other) const; // Assignment operator
        friend std::ostream& operator<<(std::ostream& out, const RationalNumber& other);
        friend std::istream& operator>>(std::istream& in, RationalNumber& other);
        bool operator > (const RationalNumber& other) const; // overloading less than and greater than operator
        bool operator < (const RationalNumber& other) const; 
        void divide(); // Special function which will divide numerator and denominator and make it smaller if possible 

};

#endif