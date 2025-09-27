#include<iostream>
#include<string>
#include"Ashwin_Mahajan_task3_HugeInt.h"
#include<stdexcept>
#include<limits>

// Constructor --> reads bits from long number
HugeInt::HugeInt(long val){
    for(int i=0;i<32;i++){
        no[i] = 0; // first initialize all with zero
    }
    int max_idx = 31;
    while(val!=0){
        no[max_idx--] = val%10;
        val /= 10; 
    }
    bits_len = max_idx+1; //  set this to index from which we will traverse arr
}

// Constructor --> reads no from string 
HugeInt::HugeInt(const std::string& number){
    for(int i=0;i<32;i++){
        no[i] = 0; // first initialize all with zero
    }
    int max_len = (number.length() > 32) ? throw(std::out_of_range("String bits are more than 32")) : number.length();
    bits_len = 32-max_len; // set the bits len
    for(int i=bits_len; i<=31;i++){
        no[i] = number[i-bits_len] - '0';
    }
}

// Outstream object to print
std::ostream& operator<<( std::ostream &out, const HugeInt &num ){
    for (int  i = num.bits_len; i < 32; i++)
    {
        out<<num.no[i];
    }
    out<<std::endl;
    return out;
}

// Input stream object
std::istream& operator>>(std::istream & in, HugeInt &num){
    for(int i=0;i<32;i++){
        num.no[i] = 0; // first initialize all with zero
    }
    std::cout<<"\nEnter the new no(less than 32 bits): ";
    std::string number;
    getline(in,number);
    int max_len = (number.length() > 32) ? throw(std::out_of_range("String bits are more than 32")) : number.length();
    num.bits_len = 32-max_len; // set the bits len
    for(int i=num.bits_len; i<=31;i++){
        num.no[i] = number[i-num.bits_len] - '0';
    }
    return in;
}
   
// Addition operation
HugeInt HugeInt::operator+( const HugeInt & other) const{
    HugeInt newInt(0);
    int carry = 0; // will take care of the carry
    for(int i=31;i>=0;i--){
        newInt.no[i] = ((this->no[i] + other.no[i] + carry)%10);
        carry = (this->no[i] + other.no[i] + carry) / 10;
    }
    newInt.bits_len = 0;
    while (newInt.bits_len < 31 && newInt.no[newInt.bits_len] == 0) {
        newInt.bits_len++;
    }
    return newInt;
}

// Substraction operation
HugeInt HugeInt::operator-(const HugeInt & other) const {
    HugeInt newInt(0);
    int borrow = 0; 
    
    for(int i = 31; i >= 0; i--) {
        int diff = this->no[i] - other.no[i] - borrow;

        if(diff < 0) {
            diff += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }
        
        newInt.no[i] = diff;
    }
    
    newInt.bits_len = 0;
    while (newInt.bits_len < 31 && newInt.no[newInt.bits_len] == 0) {
        newInt.bits_len++;
    }
    
    if(borrow > 0) {
        std::cerr << "Warning: Subtraction result is negative. Underflow occurred.\n";
    }
    
    return newInt;
}

// Overloading * operator
HugeInt HugeInt::operator*( const HugeInt & other) const{
    // Problems : can hold max upto 18 19 place
    long long temp_other = 0;
    for(int i=other.bits_len;i<32;i++){
        temp_other = (temp_other*10) + other.no[i]; 
    }
    long long temp_this = 0;
    for(int i=this->bits_len;i<32;i++){
        temp_this = (temp_this*10) + this->no[i]; 
    }
    long long res = temp_other*temp_this;
    return HugeInt(res);
}

// operator /
HugeInt HugeInt::operator/( const HugeInt & other) const{
    // Problems : can hold max upto 18 19 place
    long long temp_other = 0;
    for(int i=other.bits_len;i<32;i++){
        temp_other = (temp_other*10) + other.no[i]; 
    }
    long long temp_this = 0;
    for(int i=this->bits_len;i<32;i++){
        temp_this = (temp_this*10) + this->no[i]; 
    }
    long long res = temp_this / temp_other;
    return HugeInt(res);
}

// operator =
bool HugeInt::operator==(const HugeInt & other) const{
    if(this->bits_len != other.bits_len) {return false;}
    for(int i=bits_len;i<32;i++){
        if(this->no[i] != other.no[i]){
            return false;
        }
    }
    return true;
}
