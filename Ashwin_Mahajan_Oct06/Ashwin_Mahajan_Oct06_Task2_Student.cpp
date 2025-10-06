
// Student cpp file
#include<iostream>
#include<string>
#include"Ashwin_Mahajan_Oct06_Task2_Student.h"

// constructor
Student::Student(std::string name,std::string studentID,std::string department){
    this->name = name;
    this->studentID = studentID;
    this->department = department;
}

// Display information function
void Student::displayInfo() const{
    std::cout<<"Student-ID: "<<this->studentID<<std::endl;
    std::cout<<"Name of student: "<<this->name<<std::endl;
    std::cout<<"Department: "<<this->department<<std::endl;
}

// Returning the level;
std::string Student::getLevel() const{
    return "Student";
}