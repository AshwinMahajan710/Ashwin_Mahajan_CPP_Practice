#include<iostream>
#include"Ashwin_Mahajan_task5_Polynomial.h"

// constructor
Polynomial::Polynomial(int size){
    this->size = size ;
    ptr = new int[101]; // hardcode this as multiplication can require more space 
    for(int i=100;i>=0;i--){
        ptr[i] = 0;
    }
} 

 // getting input
std::istream& operator >>(std::istream& in, Polynomial& other){
    delete[] other.ptr;
    std::cout<<"\nEnter highest degree: ";
    in>>other.size;
    other.ptr = new int[101];
    for(int i=other.size;i>=0;i--){
        std::cout<<"\nEnter coefficient of exponent X^"<<i<<": ";
        in>>other.ptr[i];     
    }
    return in;
}

// writing output
std::ostream& operator << (std::ostream& out, const Polynomial& other){
    for(int i = other.size; i>0; i--){
        if(other.ptr[i]!=0){
            out<<other.ptr[i]<<"X^"<<i<<" + ";
        }
    }
    out<<other.ptr[0];
    out<<std::endl;
    return out;
}

// operator +
Polynomial Polynomial::operator+ (const Polynomial& other)const {
    int max_size = (other.size > this->size) ? other.size : this->size;
    Polynomial newPolynomial(max_size);
    for(int i=0;i<=max_size;i++){
        newPolynomial.ptr[i] = other.ptr[i] + this->ptr[i];
    }
    return newPolynomial;
} 

// Operator -
Polynomial Polynomial::operator- (const Polynomial& other)const{
    int max_size = (other.size > this->size) ? other.size : this->size;
    Polynomial newPolynomial(max_size);
    for(int i=0;i<=max_size;i++){
        newPolynomial.ptr[i] = this->ptr[i] - other.ptr[i];
    }
    return newPolynomial;
}

// operator *
Polynomial Polynomial::operator* (const Polynomial& other)const{
    int max_size = this->size + other.size;
    Polynomial newPolynomial(max_size);

    for (int i = 0; i <= this->size; i++) {
        for (int j = 0; j <= other.size; j++) {
            newPolynomial.ptr[i + j] += this->ptr[i] * other.ptr[j];
        }
    }

    int new_size = max_size;
    while (new_size > 0 && newPolynomial.ptr[new_size] == 0) {
        new_size--;
    }
    newPolynomial.size = new_size;

    return newPolynomial;
}

// operator =
void Polynomial::operator= (const Polynomial& other){
    this->size = other.size;
    for(int i=0;i<=this->size;i++){
        this->ptr[i] = other.ptr[i];
    }
} 

// operator +=
void Polynomial::operator+= (const Polynomial& other){
    int max_size = (other.size > this->size) ? other.size : this->size;
    this->size = max_size;
    for(int i=0;i<=this->size;i++){
        this->ptr[i] += other.ptr[i];
    }
    int new_size = max_size;
    while (new_size > 0 && this->ptr[new_size] == 0) {
        new_size--;
    }
    this->size = new_size;
}

// operator -=
void Polynomial::operator-= (const Polynomial& other){
    int max_size = (other.size > this->size) ? other.size : this->size;
    this->size = max_size;
    for(int i=0;i<=this->size;i++){
        this->ptr[i] -= other.ptr[i];
    }
    int new_size = max_size;
    while (new_size > 0 && this->ptr[new_size] == 0) {
        new_size--;
    }
    this->size = new_size;
}

// operator *=
void Polynomial::operator*= (const Polynomial& other){
    int max_size = this->size + other.size;
    int temp[101] = {0};  

    for (int i = 0; i <= this->size; i++) {
        for (int j = 0; j <= other.size; j++) {
            temp[i + j] += this->ptr[i] * other.ptr[j];
        }
    }

    for (int k = 0; k <= max_size; k++) {
        this->ptr[k] = temp[k];
    }
    int new_size = max_size;
    while (new_size > 0 && this->ptr[new_size] == 0) {
        new_size--;
    }
    this->size = new_size;
}
