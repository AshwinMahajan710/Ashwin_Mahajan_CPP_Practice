#include<iostream>
#include"Ashwin_Mahajan_Oct06_Task3_Shape.h"
#include"Ashwin_Mahajan_Oct06_Task3_TwoDimensionalShape.h"
#include"Ashwin_Mahajan_Oct06_Task3_ThreeDimensionalShape.h"
#include"Ashwin_Mahajan_Oct06_Task3_Circle.h"
#include"Ashwin_Mahajan_Oct06_Task3_Triangle.h"
#include"Ashwin_Mahajan_Oct06_Task3_Square.h"
#include"Ashwin_Mahajan_Oct06_Task3_Sphere.h"
#include"Ashwin_Mahajan_Oct06_Task3_Cube.h"
#include<vector>

int main(){

    std::vector<Shape*> shapes;
    shapes.push_back(new Circle(5));
    shapes.push_back(new Square(4));
    shapes.push_back(new Triangle(3,3,3));
    shapes.push_back(new Sphere(5));
    shapes.push_back(new Cube(4));

    for(int i=0;i<shapes.size();i++){
        std::cout<<std::endl;
        shapes[i]->printInfo();
    }
    return 0;

}