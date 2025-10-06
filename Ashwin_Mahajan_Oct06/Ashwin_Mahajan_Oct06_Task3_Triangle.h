
// Triangle header file

#ifndef TRIANGLE_H
#define TRIANGLE_H

#include"Ashwin_Mahajan_Oct06_Task3_TwoDimensionalShape.h"

class Triangle : public TwoDimensionalShape{
    private:
        float side1,side2,side3;

    public:
        Triangle(float,float,float);
        void printInfo() const;
        double getArea() const;
        double getPerimeter() const;
};

#endif