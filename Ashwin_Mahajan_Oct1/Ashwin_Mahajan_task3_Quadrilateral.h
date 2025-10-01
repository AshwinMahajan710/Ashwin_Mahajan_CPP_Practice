
// Quadrilateral header file

#include<iostream>

#ifndef QUADRILATERAL_H
#define QUADRILATERAL_H

//  Quadrilateral class
class Quadrilateral{
    public:
        
        float sides[4];
        float angles[4];
    
        Quadrilateral(std::initializer_list<float>,std::initializer_list<float>);
        virtual bool isValid() const;
        virtual float area() const;
        bool operator == (Quadrilateral* q2);
        friend std::ostream& operator <<(std::ostream& out, Quadrilateral* q2);
        operator float() const; // will return area;
        float operator() () const; // will return perimeter;
};

#endif
