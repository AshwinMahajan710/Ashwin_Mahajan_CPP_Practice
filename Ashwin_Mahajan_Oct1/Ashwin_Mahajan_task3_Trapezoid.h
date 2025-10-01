
// Trapezoid header file

#include"Ashwin_Mahajan_task3_Quadrilateral.h"

#ifndef TRAPEZOID_H
#define TRAPEZOID_H

class Trapezoid : public Quadrilateral{
    public:
        Trapezoid(std::initializer_list<float> s, std::initializer_list<float> a);
        virtual bool isValid()  const override;
        virtual float area() const override;
};

#endif