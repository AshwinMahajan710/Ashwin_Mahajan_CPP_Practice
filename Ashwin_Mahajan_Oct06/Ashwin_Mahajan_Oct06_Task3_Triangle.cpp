#include"Ashwin_Mahajan_Oct06_Task3_TwoDimensionalShape.h"
#include"Ashwin_Mahajan_Oct06_Task3_Triangle.h"
#include<cmath>
#include<iostream>

// Constructor
Triangle::Triangle(float side1, float side2, float side3){
    this->side1 = side1;
    this->side2 = side2;
    this->side3 = side3;
}

// Get area
double Triangle::getArea() const{
    double s = getPerimeter()/2.0; // semiPerimeter
    return (sqrt(s*(s-side1)*(s-side2)*(s-side3)));
}

// Get Perimeter
double Triangle::getPerimeter() const{
    return (side1 + side2 + side3);
}

// Print function
void Triangle::printInfo() const{
    std::cout<<"Shape: Triangle"<<std::endl;
    std::cout<<"Sides: "<<side1<<" "<<side2<<" "<<side3<<std::endl;
    std::cout<<"Area: "<<getArea()<<std::endl;
    std::cout<<"Perimeter: "<<getPerimeter()<<std::endl;
}