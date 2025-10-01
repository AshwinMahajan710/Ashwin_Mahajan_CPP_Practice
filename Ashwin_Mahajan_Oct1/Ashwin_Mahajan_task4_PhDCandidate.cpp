
// DoctoralStudent cpp file

#include"Ashwin_Mahajan_task4_DoctoralStudent.h"
#include"Ashwin_Mahajan_task4_PhDCandidate.h"
#include<iostream>
#include<string>

// Constructor
PhDCandidate::PhDCandidate(std::string name,std::string studentID,std::string department,std::string advisor, std::string dissertationTitle, int yearsInProgram) : DoctoralStudent(name,studentID,department,advisor,dissertationTitle, yearsInProgram){}

// display function
void PhDCandidate::displayInfo() const{
    GraduateStudent::displayInfo();
}

// get level function
std::string PhDCandidate::getLevel() const{
    return "PhDCandidate";
}