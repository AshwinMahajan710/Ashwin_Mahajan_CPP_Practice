#include<iostream>
#include"Ashwin_Mahajan_task1_DoubleSubscriptedArray.h"

int main(){

    // Firstly initialize the array with rows and col
    DoubleSubscriptedArray arr(2,2);
    DoubleSubscriptedArray arr2(2,2);
    
    // user input using istream object
    std::cin>> arr;
    std::cin>> arr2;

    // Displaying the array

    std::cout<<"\nMatrix 1: "<<std::endl;
    std::cout<<arr;
    std::cout<<"\nMatrix 2: "<<std::endl;
    std::cout<<arr2;

    // Chekcing the equality of both arrays
    (arr==arr2) ? std::cout<<"\nBoth arrays are equal.." : std::cout<<"\n Both arrays are not equal..";

    //Access the [2][3] by using subscript function (const value)
    std::cout<<"\nThe no at position 1,1 of array: "<<arr(1,1)<<std::endl; 

    // Now get the value in arr by reference and then change it
    int& val = arr(1,1);
    val = 45;

    // Now matrix will not be same compare both for equality
    // Chekcing the equality of both arrays
    (arr==arr2) ? std::cout<<"\n Both arrays are equal.." : std::cout<<"\n Both arrays are not equal..";

}