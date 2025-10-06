
// Square header file

#ifndef SQUARE_H
#define SQUARE_H

#include"Ashwin_Mahajan_Oct06_Task3_TwoDimensionalShape.h"

class Square : public TwoDimensionalShape{
    private:
        float side;

    public:
        Square(float);
        void printInfo() const;
        double getArea() const;
        double getPerimeter() const;
};

#endif