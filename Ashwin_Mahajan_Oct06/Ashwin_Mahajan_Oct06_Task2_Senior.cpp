
// Senior CPP file

#include<iostream>
#include"Ashwin_Mahajan_Oct06_Task2_UndergraduateStudent.h"
#include"Ashwin_Mahajan_Oct06_Task2_Senior.h"
#include<string>

// Freshman constructor
Senior::Senior(std::string name,std::string studentID,std::string department, int year, int creditsEarned): UndergraduateStudent(name,studentID, department, year, creditsEarned){};

// display function
void Senior::displayInfo()const{
    UndergraduateStudent::displayInfo();
}

// Get level function
std::string Senior::getLevel() const{
    return "Senior";
}