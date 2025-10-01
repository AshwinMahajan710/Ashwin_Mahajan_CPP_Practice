

// Trapezoid cpp file

#include"Ashwin_Mahajan_task3_Trapezoid.h"
#include"Ashwin_Mahajan_task3_Quadrilateral.h"
#include<cmath>

// COnstructor
Trapezoid::Trapezoid(std::initializer_list<float> s, std::initializer_list<float> a) : Quadrilateral(s,a){};

// overrided isValid function --> at least one pair is parallel
bool Trapezoid::isValid() const {
    if(!Quadrilateral::isValid()) {return false;} // as quadrilateral validation failed
    bool case1 = (angles[0] + angles[1] == 180) || (angles[1] + angles[2] == 180) || (angles[2] + angles[3] == 180) || (angles[3] + angles[0] == 180);
    return case1;
}

// overrided area function
float Trapezoid::area() const{
    float h = sides[0] * sin(angles[0] * M_PI / 180.0f);  // height
    float newArea = 0.5f * (sides[0] + sides[1]) * h; 
    return newArea;
}

