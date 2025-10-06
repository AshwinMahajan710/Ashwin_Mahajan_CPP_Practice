
// Sphere header file

#ifndef SPHERE_H
#define SPHERE_H

#include"Ashwin_Mahajan_Oct06_Task3_ThreeDimensionalShape.h"

class Sphere: public ThreeDimensionalShape{
    private:
        int radius;
    
    public:
        Sphere(float);
        void printInfo() const;
        double getVolume() const;
        double getSurfaceArea()const;
};  


#endif

