#include<iostream>
#include<iomanip>
#include<cstdint>

int main(){

    // Declaring the double array[] holding 10 elements
    double arr [10]{0.0,1.10,2.2,3.30,4.4,5.5,6.6,7.7,8.8,9.9};

    // Decalring pointer which points at double variable
    double* nPtr;
    double* nPtr2;

    // Printing the array with precision of 1
    for(int i=0;i<10;i++){
        std::cout<<" "<<std::fixed<<std::setprecision(1)<<arr[i];
    }
    std::cout<<std::endl;

    // Writing the statement to point pointer nPtr to start of arr in two ways
    nPtr = arr; // first way
    nPtr2 = &arr[0]; // second way

    // Printing the array using pointer notation
    for(int i=0;i<10;i++){
        std::cout<<" "<<std::fixed<<std::setprecision(1)<<*(nPtr2 + i);
    }
    std::cout<<std::endl;

    // Printing the arr using arr name
    for(int i=0;i<10;i++){
        std::cout<<" "<<std::fixed<<std::setprecision(1)<<*(arr + i);
    }
    std::cout<<std::endl;

    // Refering to 4th element via
    std::cout<<arr[4]<<std::endl; // array subscript notation
    std::cout<<*(arr + 4)<<std::endl;// array name as pointer
    std::cout<<nPtr[4] <<std::endl;// using nPtr subscript

    // Printing the addresses of each ele
    std::cout<<"\nAddresses: ";
    for(int i=0;i<10;i++){
        std::cout << uintptr_t(nPtr+i) << " ";
    }

    // Accessing address and value at ptr + 8
    std::cout<<"\nAdress of ptr + i: "<<uintptr_t(nPtr + 8);
    std::cout<<"\nValue at ptr + i: "<<*(nPtr + 8);

    // Assume pointer points at position arr[5]
    // Now after nPtr -= 4 the pointer now point at arr[1]
    std::cout<<"\nAddress of nPtr point ting to 5: "<<uintptr_t(nPtr + 5);
    std::cout<<"\nAddress of nPtr after nPtr-=4: "<<uintptr_t((nPtr + 5) - 4);

    return 0;

}