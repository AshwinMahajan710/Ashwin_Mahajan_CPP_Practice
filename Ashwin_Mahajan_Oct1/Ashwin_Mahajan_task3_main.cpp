
// Main file

#include<iostream>
#include<string>
#include"Ashwin_Mahajan_task3_Quadrilateral.h"
#include"Ashwin_Mahajan_task3_Rectangle.h"
#include"Ashwin_Mahajan_task3_Parallelogram.h"
#include"Ashwin_Mahajan_task3_Square.h"
#include"Ashwin_Mahajan_task3_Trapezoid.h"


int main(){

    // Create objects of each things in Quadrilateral* arr
    Quadrilateral* arr[5];
    arr[0] = new Square ({5,5,5,5}, {90,90,90,90});
    arr[1] = new Rectangle ({6,4,6,4}, {90,90,90,90});
    arr[2] = new Parallelogram ({6,4,6,4}, {110,70,110,70});
    arr[3] = new Trapezoid ({6,5,4,3}, {100,80,100,80});
    arr[4] = new Quadrilateral({3,4,5,6},{90,90,90,90});  

    // Printing each thing and also its perimeter
    std::cout<<"\nSquare: ";
    std::cout<<arr[0];
    std::cout<<"Perimeter of square: "<<(*arr[0])()<<std::endl;

    std::cout<<"\nRectangle: ";
    std::cout<<arr[1];
    std::cout<<"Perimeter of rectangle: "<<(*arr[1])()<<std::endl;

    std::cout<<"\nParallelogram: ";
    std::cout<<arr[2];
    std::cout<<"Perimeter of parallelogram: "<<(*arr[2])()<<std::endl;

    std::cout<<"\nTrapezoidal: ";
    std::cout<<arr[3];
    std::cout<<"Perimeter of Trapezoid: "<<(*arr[3])()<<std::endl;

    std::cout<<"\nQuadrilateral: ";
    std::cout<<arr[4];
    std::cout<<"Perimeter of Quadrilateral: "<<(*arr[4])()<<std::endl;

    // Compare area of rectangle and square
    (arr[0] == arr[1]) ? std::cout<<"\nArea of square and rectangle is same..."<<std::endl : std::cout<<"\nArea of square and rectangle is not same..."<<std::endl;


    return 0;
}