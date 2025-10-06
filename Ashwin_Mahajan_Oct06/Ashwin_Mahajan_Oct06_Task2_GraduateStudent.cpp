
// GraduateStudent cpp file

#include"Ashwin_Mahajan_Oct06_Task2_Student.h"
#include"Ashwin_Mahajan_Oct06_Task2_GraduateStudent.h"
#include<iostream>
#include<string>

// Constructor
GraduateStudent::GraduateStudent(std::string name,std::string studentID,std::string department,std::string advisor) : Student(name,studentID,department){
    this->advisor = advisor;
}

// display function
void GraduateStudent::displayInfo() const{
    Student::displayInfo();
    std::cout<<"Advisor: "<<this->advisor<<std::endl;
}

// get level function
std::string GraduateStudent::getLevel() const{
    return "GraduateStudent";
}