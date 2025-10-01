// MastersStudent cpp file

#include"Ashwin_Mahajan_task4_MastersStudent.h"
#include"Ashwin_Mahajan_task4_GraduateStudent.h"
#include<iostream>
#include<string>

// Constructor
MastersStudent::MastersStudent(std::string name,std::string studentID,std::string department,std::string advisor) : GraduateStudent(name,studentID,department,advisor){}

// display function
void MastersStudent::displayInfo() const{
    GraduateStudent::displayInfo();
}

// get level function
std::string MastersStudent::getLevel() const{
    return "MastersStudent";
}