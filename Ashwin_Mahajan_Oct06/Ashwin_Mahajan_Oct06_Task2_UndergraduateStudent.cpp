
// UndergraduateStudent cpp file

#include"Ashwin_Mahajan_Oct06_Task2_Student.h"
#include"Ashwin_Mahajan_Oct06_Task2_UndergraduateStudent.h"
#include<iostream>
#include<string>

// Constructor
UndergraduateStudent::UndergraduateStudent(std::string name,std::string studentID,std::string department, int year, int creditsEarned) : Student(name,studentID,department){
    this->year = year;
    this->creditsEarned = creditsEarned;
}

// display function
void UndergraduateStudent::displayInfo() const{
    Student::displayInfo();
    std::cout<<"Year: "<<this->year<<std::endl;
    std::cout<<"Credits Earned: "<<this->creditsEarned<<std::endl;
}

// get level function
std::string UndergraduateStudent::getLevel() const{
    return "UndergraduateStudent";
}