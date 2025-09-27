#include<iostream>
#include<numeric>
#include"Ashwin_Mahajan_task4_RationalNumber.h"

// Divide number if possible to make it small
void RationalNumber::divide(){
    int gcd = std::gcd(numerator,denominator);
    numerator /= gcd;
    denominator/= gcd;
}

// constructor 
RationalNumber::RationalNumber(int num, int den){
    this->numerator = num;
    this->denominator = (den <= 0) ? 1 : den;
    divide();
}

//  operator + 
RationalNumber RationalNumber:: operator+(const RationalNumber& other) const{
    if(this->denominator == other.denominator){
        int newNumerator = other.numerator + this->numerator;
        return RationalNumber(newNumerator,this->denominator);
    }
    else{
        int newNumerator = (this->numerator*other.denominator) + (other.numerator*this->denominator);
        int newDenominator = other.denominator * this->denominator;
        RationalNumber newRationalNumber(newNumerator,newDenominator);
        newRationalNumber.divide();
        return newRationalNumber;
    }
}

//  operator - 
RationalNumber RationalNumber:: operator-(const RationalNumber& other) const{
    if(this->denominator == other.denominator){
        int newNumerator = this->numerator - other.numerator ;
        return RationalNumber(newNumerator,this->denominator);
    }
    else{
        int newNumerator = (this->numerator*other.denominator) - (other.numerator*this->denominator);
        int newDenominator = other.denominator * this->denominator;
        RationalNumber newRationalNumber(newNumerator,newDenominator);
        return newRationalNumber;
    }
}


//  operator *
RationalNumber RationalNumber:: operator*(const RationalNumber& other) const{
    int newNumerator = other.numerator * this->numerator;
    int newDenominator = other.denominator * this->denominator;
    RationalNumber newNumber(newNumerator,newDenominator);
    return newNumber;
}

//  operator /
RationalNumber RationalNumber:: operator/(const RationalNumber& other) const{
    int newNumerator = this->numerator * other.denominator;
    int newDenominator = this->denominator * other.numerator;
    RationalNumber newNumber(newNumerator,newDenominator);
    return newNumber;
}

// operator == 
bool RationalNumber::operator ==(const RationalNumber& other) const{
        return (this->numerator * other.denominator) == (other.numerator * this->denominator);
}

// Operator =
void RationalNumber::operator =(const RationalNumber& other){
    this->numerator = other.numerator;
    this->denominator = other.denominator;
}

// Operator !=
bool RationalNumber::operator !=(const RationalNumber& other) const{
    return (this->numerator * other.denominator) != (other.numerator * this->denominator);
}

bool RationalNumber::operator > (const RationalNumber& other) const{
    return (this->numerator * other.denominator) > (other.numerator * this->denominator);
} 

// overloading less than operator
bool RationalNumber::operator < (const RationalNumber& other) const{
    return (this->numerator * other.denominator) < (other.numerator * this->denominator);
}

// ostream
std::ostream& operator<<(std::ostream& out, const RationalNumber& other){
    out<<other.numerator<<" / "<<other.denominator<<std::endl;
    return out;
};

// istream
std::istream& operator >>(std::istream& in, RationalNumber& other){
    std::cout<<"\nEnter the value of numerator and denominator: ";
    in >> other.numerator >> other.denominator;
    other.divide();
    return in;
}

