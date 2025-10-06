
// Sophomore CPP file

#include<iostream>
#include"Ashwin_Mahajan_Oct06_Task2_UndergraduateStudent.h"
#include"Ashwin_Mahajan_Oct06_Task2_Sophomore.h"
#include<string>

// Freshman constructor
Sophomore::Sophomore(std::string name,std::string studentID,std::string department, int year, int creditsEarned): UndergraduateStudent(name,studentID, department, year, creditsEarned){};

// display function
void Sophomore::displayInfo()const{
    UndergraduateStudent::displayInfo();
}

// Get level function
std::string Sophomore::getLevel() const{
    return "Sophomore";
}