
// Junior CPP file

#include<iostream>
#include"Ashwin_Mahajan_task4_UndergraduateStudent.h"
#include"Ashwin_Mahajan_task4_Junior.h"
#include<string>

// Freshman constructor
Junior::Junior(std::string name,std::string studentID,std::string department, int year, int creditsEarned): UndergraduateStudent(name,studentID, department, year, creditsEarned){};

// display function
void Junior::displayInfo()const{
    UndergraduateStudent::displayInfo();
}

// Get level function
std::string Junior::getLevel() const{
    return "Junior";
}