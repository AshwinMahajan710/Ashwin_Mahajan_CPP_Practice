#include"Ashwin_Mahajan_Oct06_Task3_TwoDimensionalShape.h"
#include"Ashwin_Mahajan_Oct06_Task3_Square.h"
#include<cmath>
#include<iostream>

// Constructor
Square::Square(float side){
    this->side = side;
}

// Get area
double Square::getArea() const{
    return (side * side);
}

// Get Perimeter
double Square::getPerimeter() const{
    return (4 * side);
}

// Print function
void Square::printInfo() const{
    std::cout<<"Shape: Square"<<std::endl;
    std::cout<<"Side: "<<side<<std::endl;
    std::cout<<"Area: "<<getArea()<<std::endl;
    std::cout<<"Perimeter: "<<getPerimeter()<<std::endl;
}