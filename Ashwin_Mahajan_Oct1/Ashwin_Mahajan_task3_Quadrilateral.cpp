
// Quadrilateral cpp file

#include<iostream>
#include"Ashwin_Mahajan_task3_Quadrilateral.h"
#include<string>

// constructor
Quadrilateral::Quadrilateral(std::initializer_list<float> s, std::initializer_list<float> a) {
    for(int i = 0; i < 4; i++) {
        std::copy(s.begin(),s.end(),sides);
        std::copy(a.begin(),a.end(),angles);
    }
}

// If sum of all angles is 360 it is valid
bool Quadrilateral::isValid() const{
    float sum = 0;
    for(int i=0;i<4;i++){
        sum += angles[i];
    }
    if(sum == 360.0f) {return true;}
    else {return false;}
}

// calculate and return area
float Quadrilateral::area() const{
    // as it is parallelogram return 0
    return 0;
}

// will return area
Quadrilateral::operator float() const{
    return this->area();
}

// will return perimeter
float Quadrilateral:: operator() () const{
    float perimeter = 0;
    for(int i=0;i<4;i++){
        perimeter += sides[i];
    }
    return perimeter;
}

// will return that the area are equal or not
bool Quadrilateral:: operator == (Quadrilateral* q2){
    if(this->area() == q2->area()) {return true;}
    else {return false;}
}

// for printing
std::ostream& operator <<(std::ostream& out, Quadrilateral* q2){
    out<<"Sides : ";
    for(int i=0;i<4;i++){
        out<<q2->sides[i]<<" ";
    }
    out<<std::endl<<"Angles : ";
    for(int i=0;i<4;i++){
        out<<q2->angles[i]<<" ";
    }
    out<<std::endl<<"Area: "<<q2->area()<<std::endl;
    out<<"Is Valid: "<<(q2->isValid() ? "Yes" : "No")<<std::endl;
    return out;
}