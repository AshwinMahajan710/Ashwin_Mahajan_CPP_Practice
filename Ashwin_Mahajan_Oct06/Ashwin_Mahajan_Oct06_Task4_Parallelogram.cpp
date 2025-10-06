

// Paralelogram cpp

#include"Ashwin_Mahajan_Oct06_Task4_Parallelogram.h"
#include"Ashwin_Mahajan_Oct06_Task4_Trapezoid.h"
#include<cmath>

// COnstructor
Parallelogram::Parallelogram(std::initializer_list<float> s, std::initializer_list<float> a) : Trapezoid(s,a){};

// overrided isValid function
bool Parallelogram::isValid() const {
    if(!Quadrilateral::isValid()) {return false;} // as quadrilateral validation failed
    if((sides[0]==sides[2]) && (sides[1] == sides[3])){ // opposite sides of parallelogram are equal
        return true;
    }
    else {return false;}
}

// overrided area function
float Parallelogram::area() const{
    return sides[0] * sides[1] * sin(angles[0] * M_PI / 180.0f);
}

