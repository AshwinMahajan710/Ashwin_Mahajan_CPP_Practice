
// DoctoralStudent cpp file

#include"Ashwin_Mahajan_task4_DoctoralStudent.h"
#include"Ashwin_Mahajan_task4_GraduateStudent.h"
#include<iostream>
#include<string>

// Constructor
DoctoralStudent::DoctoralStudent(std::string name,std::string studentID,std::string department,std::string advisor, std::string dissertationTitle, int yearsInProgram) : GraduateStudent(name,studentID,department,advisor){
    this->yearsInProgram = yearsInProgram;
    this->dissertationTitle = dissertationTitle;
}

// display function
void DoctoralStudent::displayInfo() const{
    GraduateStudent::displayInfo();
    std::cout<<"Dissertation Title: "<<this->dissertationTitle;
    std::cout<<"Years in program: "<<this->yearsInProgram;
}

// get level function
std::string DoctoralStudent::getLevel() const{
    return "DoctoralStudent";
}