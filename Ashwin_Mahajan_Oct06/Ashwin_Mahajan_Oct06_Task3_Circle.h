
// Circle header file

#ifndef CIRCLE_H
#define CIRCLE_H

#include"Ashwin_Mahajan_Oct06_Task3_TwoDimensionalShape.h"

class Circle : public TwoDimensionalShape{
    private:
        float radius;

    public:
        Circle(float);
        void printInfo() const;
        double getArea() const;
        double getPerimeter() const;
};

#endif