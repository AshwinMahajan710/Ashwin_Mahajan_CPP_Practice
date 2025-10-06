
// Three Dimensional shape class header file  --> no need of cpp file as it is abstract base class

#ifndef THREE_DIMENSIONAL_SHAPE_H
#define THREE_DIMENSIONAL_SHAPE_H

#include"Ashwin_Mahajan_Oct06_Task3_Shape.h"

// Shape class
class ThreeDimensionalShape : public Shape{
    public:
        virtual void printInfo() const = 0;
        virtual double getVolume() const = 0 ;
        virtual double getSurfaceArea() const = 0;
};  

#endif