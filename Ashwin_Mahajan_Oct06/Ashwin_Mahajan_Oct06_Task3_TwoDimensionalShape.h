
// Two Dimensional shape class header file  --> no need of cpp file as it is abstract base class

#ifndef TWO_DIMENSIONAL_SHAPE_H
#define TWO_DIMENSIONAL_SHAPE_H

#include"Ashwin_Mahajan_Oct06_Task3_Shape.h"

// Shape class
class TwoDimensionalShape : public Shape{
    public:
        virtual void printInfo() const = 0;
        virtual double getArea() const = 0 ;
        virtual double getPerimeter() const = 0;
};  

#endif