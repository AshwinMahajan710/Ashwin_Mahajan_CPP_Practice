
// Freshman CPP file

#include<iostream>
#include"Ashwin_Mahajan_task4_UndergraduateStudent.h"
#include"Ashwin_Mahajan_task4_Freshman.h"
#include<string>

// Freshman constructor
Freshman::Freshman(std::string name,std::string studentID,std::string department, int year, int creditsEarned): UndergraduateStudent(name,studentID, department, year, creditsEarned){};

// display function
void Freshman::displayInfo()const{
    UndergraduateStudent::displayInfo();
}

// Get level function
std::string Freshman::getLevel() const{
    return "Freshman";
}