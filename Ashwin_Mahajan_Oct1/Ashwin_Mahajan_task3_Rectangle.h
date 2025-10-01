
// Rectangle header file

#include"Ashwin_Mahajan_task3_Parallelogram.h"

#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle : public Parallelogram{
    public:
        Rectangle(std::initializer_list<float> s, std::initializer_list<float> a);
        virtual bool isValid()  const override;
        virtual float area() const override;
};

#endif