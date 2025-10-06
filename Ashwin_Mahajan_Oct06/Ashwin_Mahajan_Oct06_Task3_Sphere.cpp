#include<iostream>
#include"Ashwin_Mahajan_Oct06_Task3_Sphere.h"
#include<cmath>

//constructor
Sphere::Sphere(float radius){
    this->radius = radius;
}

// Printing information
void Sphere::printInfo() const{
    std::cout<<"Shape: SPHERE"<<std::endl;
    std::cout<<"Radius: "<<radius<<std::endl;
    std::cout<<"Volume: "<<getVolume()<<std::endl;
    std::cout<<"Surface Area: "<<getSurfaceArea()<<std::endl;

}

// get volume
double Sphere::getVolume() const{
    return(M_PI * radius * radius * radius); 
}

// get surface area
double Sphere::getSurfaceArea()const{
    return (4 * M_PI * radius * radius);
}