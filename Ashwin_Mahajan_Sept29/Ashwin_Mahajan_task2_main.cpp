#include<iostream>
#include<cstdint>

int main(){

    // declare two numbers and initialize no1; 
    double number1 = 7.3;
    double number2;

    //  Declare pointer to char arr
    char* ptr;

    // Arrays s1 and s2 are char arrays of size 100 each and initialized with string literals
    char s1[100] = "Ashwin Mahajan is my name...";
    char s2[100] = "I am graduated and have degree in AI and Data Science...";

    // Declare fPtr as pointer at double and assign it no1 address
    double* fPtr = &number1;
    
    // Printing value using ptr
    std::cout<<"\nValue at address fPtr = "<<*fPtr;

    // Now assign that value to no2
    number2 = *fPtr;

    // Printing the value of no2;
    std::cout<<"\nValue of number 2 = "<<number2;

    // Printing the address if no 1;
    std::cout<<"\nAddress of number 1 = "<<uintptr_t(&number1);

    // Printing address of fPtr
    std::cout<<"\nAddress of fPtr = "<<uintptr_t(fPtr);

    return 0;
}