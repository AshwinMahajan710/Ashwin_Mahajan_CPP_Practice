
// Square cpp file

#include"Ashwin_Mahajan_task3_Rectangle.h"
#include"Ashwin_Mahajan_task3_Square.h"
#include<cmath>

// COnstructor
Square::Square(std::initializer_list<float> s, std::initializer_list<float> a) : Rectangle(s,a){};

// overrided isValid function
bool Square::isValid() const {
    if(!Rectangle::isValid()) {return false;} // as quadrilateral validation failed
    if(sides[0]==sides[1] && sides[1] == sides[2] && sides[2] == sides[3] && angles[0] == 90 && angles[1]==90 && angles[2] == 90 && angles[3] == 90){ // opposite sides of parallelogram are equal
        return true;
    }
    else {return false;}
}

// overrided area function
float Square::area() const{
    return (sides[0] * sides[1]);
}

