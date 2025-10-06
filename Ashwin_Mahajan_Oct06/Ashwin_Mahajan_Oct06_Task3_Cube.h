
// Cube header file

#ifndef CUBE_H
#define CUBE_H

#include"Ashwin_Mahajan_Oct06_Task3_ThreeDimensionalShape.h"

class Cube : public ThreeDimensionalShape{
    private:
        int side;
    
    public:
        Cube(float);
        void printInfo() const;
        double getVolume() const;
        double getSurfaceArea()const;
};  


#endif