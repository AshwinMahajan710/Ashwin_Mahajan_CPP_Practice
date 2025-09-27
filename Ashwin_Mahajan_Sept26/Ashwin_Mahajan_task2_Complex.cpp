#include<iostream>
#include"Ashwin_Mahajan_task2_Complex.h"

// Constructor
Complex::Complex(double r, double i ){
    this->real = r;
    this->imaginary = i;
}

// Addition operator overloading --> Can't return Complex& as this copy of new Complex object is going to be get deleted
Complex Complex::operator+(const Complex& other)const{
    double newReal = this->real + other.real;
    double newImg = this->imaginary + other.imaginary;
    return Complex(newReal,newImg);
}

// Substraction operator overloading
Complex Complex::operator-(const Complex& other)const{
    double newReal = this->real - other.real;
    double newImg = this->imaginary - other.imaginary;
    return Complex(newReal,newImg);
}

// Output stream operator overloading
std::ostream& operator<<(std::ostream& out, const Complex& Complex){
    out<<Complex.real<<" + "<<Complex.imaginary<<"i"<<std::endl;
    return out;
}

// Input stream object overloading
std::istream& operator>>(std::istream& in, Complex& complex){
    std::cout<<"Enter Complex and real parts: "<<std::endl;
    in>>complex.real>>complex.imaginary;
    return in;
}

// Multiplication operator overloading
Complex Complex:: operator*( const Complex & other) const{
    double newReal = (this->real*other.real - this->imaginary*other.imaginary); // real part = (ac−bd)
    double newImg = (this->real*other.imaginary + this->imaginary*other.real); // img part = (ad+bc)
    return Complex(newReal,newImg);
}

// Equality operator overloading
bool Complex::operator==(const Complex& other)const{
    if((this->real == other.real) && (this->imaginary == other.imaginary)){
        return true;
    }
    else{
        return false;
    }
}

