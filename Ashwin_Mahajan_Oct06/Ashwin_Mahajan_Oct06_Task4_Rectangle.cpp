
// Rectangle cpp file

#include"Ashwin_Mahajan_Oct06_Task4_Rectangle.h"
#include"Ashwin_Mahajan_Oct06_Task4_Parallelogram.h"
#include<cmath>

// COnstructor
Rectangle::Rectangle(std::initializer_list<float> s, std::initializer_list<float> a) : Parallelogram(s,a){};

// overrided isValid function
bool Rectangle::isValid() const {
    if(!Parallelogram::isValid()) {return false;} // as quadrilateral validation failed
    if((sides[0]==sides[2]) && (sides[1] == sides[3]) && angles[0] == 90 && angles[1]==90 && angles[2] == 90 && angles[3] == 90){ // opposite sides of parallelogram are equal
        return true;
    }
    else {return false;}
}

// overrided area function
float Rectangle::area() const{
    return (sides[0] * sides[1]);
}

