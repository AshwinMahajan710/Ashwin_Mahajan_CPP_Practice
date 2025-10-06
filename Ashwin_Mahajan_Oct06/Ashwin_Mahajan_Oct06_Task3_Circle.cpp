#include"Ashwin_Mahajan_Oct06_Task3_TwoDimensionalShape.h"
#include"Ashwin_Mahajan_Oct06_Task3_Circle.h"
#include<cmath>
#include<iostream>

// Constructor
Circle::Circle(float radius){
    this->radius = radius;
}

// Get area
double Circle::getArea() const{
    return (M_PI * radius * radius);
}

// Get Perimeter
double Circle::getPerimeter() const{
    return (2 * M_PI * radius);
}

// Print function
void Circle::printInfo() const{
    std::cout<<"Shape: Circle"<<std::endl;
    std::cout<<"Radius: "<<radius<<std::endl;
    std::cout<<"Area: "<<getArea()<<std::endl;
    std::cout<<"Perimeter: "<<getPerimeter()<<std::endl;
}