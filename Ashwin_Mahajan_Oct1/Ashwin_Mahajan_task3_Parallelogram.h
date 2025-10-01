
// parallelogram header file

#include"Ashwin_Mahajan_task3_Trapezoid.h"

#ifndef PARALLELOGRAM_H
#define PARALLELOGRAM_H

class Parallelogram : public Trapezoid{
    public:
        Parallelogram(std::initializer_list<float> s, std::initializer_list<float> a);
        virtual bool isValid()  const override;
        virtual float area() const override;
};

#endif