#include<iostream>
#include<cstdint>

const int SIZE = 5;

int main(){

    // Declaring array with unsigned int value of SIZE elements and assigning even values from 2 to 10
    unsigned int values[SIZE] = {2,4,6,8,10};

    // Creating pointer which points to that object
    unsigned int* vPtr1,* vPtr2;

    // Priniting array using array subscript notation
    std::cout<<"\nArrays Values: ";
    for(int i=0;i<SIZE;i++){
        std::cout<<values[i]<<" ";
    }

    // Writing two statements which assigns vPtr to array start
    vPtr1 = values; // direct assign
    vPtr2 = &values[0]; // assign to first element of array

    // Printing the array using pointer offset
    std::cout<<"\nArrays Values using Pointer: ";
    for(int i=0;i<SIZE;i++){
        std::cout<<*(vPtr2 + i)<<" ";
    }

    // Printing same array using the pointer which is assigned by array name
    std::cout<<"\nArrays Values using Pointer which points to arr name: ";
    for(int i=0;i<SIZE;i++){
        std::cout<<*(vPtr1 + i)<<" ";
    }

    // Printing same array using the pointer subscript method
    std::cout<<"\nArrays Values using Pointer subscript method: ";
    for(int i=0;i<SIZE;i++){
        std::cout<<vPtr1[i]<<" ";
    }

    // Refering the fifith element via pointer subscript notation, array subscript notation, dereferencing pointer notation
    std::cout<<"\n Value at 5 no is: "<<values[4]; // array subscript notation
    std::cout<<"\n Value at 5 no is: "<<vPtr1[4]; // Pointer subscript notation 
    std::cout<<"\n Value at 5 no is: "<<*(vPtr1 + 4);// using pointer

    // address and value at location vPtr1 + 3
    std::cout<<"\nValue at vPtr + 3: "<<*(vPtr1 + 3);
    std::cout<<"\nAddress at vPtr + 3: "<<uintptr_t(vPtr1 + 3);
    std::cout<<"\nAddress at vPtr + 4: "<<uintptr_t(vPtr1 + 4);
    
    // address at start
    std::cout<<"\nAddress at vPtr: "<<uintptr_t(vPtr1); // vPtr -= 4 when vPtr = vPtr + 4
    
    return 0;
}