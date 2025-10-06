
// Square header file

#include"Ashwin_Mahajan_Oct06_Task4_Rectangle.h"

#ifndef SQUARE_H
#define SQUARE_H

class Square : public Rectangle{
    public:
        Square(std::initializer_list<float> s, std::initializer_list<float> a);
        virtual bool isValid()  const override;
        virtual float area() const override;
};

#endif