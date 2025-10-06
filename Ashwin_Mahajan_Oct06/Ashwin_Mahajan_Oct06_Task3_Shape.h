
// Shape class header file --> no need of cpp file as it is abstract base class

#ifndef SHAPE_H
#define SHAPE_H

// Shape class
class Shape{
    public:
        virtual void printInfo() const = 0; // pure virtual function
};

#endif