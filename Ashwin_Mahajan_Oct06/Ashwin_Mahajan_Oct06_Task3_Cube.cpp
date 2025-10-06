#include<iostream>
#include"Ashwin_Mahajan_Oct06_Task3_Cube.h"

// constructor
Cube::Cube(float side){
    this->side = side;
}

// printinfo
void Cube::printInfo() const{
    std::cout<<"Shape: Cube"<<std::endl;
    std::cout<<"Side: "<<side<<std::endl;
    std::cout<<"Volume: "<<getVolume()<<std::endl;
    std::cout<<"Surface Area: "<<getSurfaceArea()<<std::endl;
    
}

// getvolume
double Cube::getVolume() const{
    return (side*side*side);
}

// getsurface area
double Cube::getSurfaceArea()const{
    return (6*side*side);
}