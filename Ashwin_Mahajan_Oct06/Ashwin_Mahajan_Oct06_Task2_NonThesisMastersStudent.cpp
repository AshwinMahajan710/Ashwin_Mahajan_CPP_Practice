// NonThesisMastersStudent cpp file

#include"Ashwin_Mahajan_Oct06_Task2_MastersStudent.h"
#include"Ashwin_Mahajan_Oct06_Task2_NonThesisMastersStudent.h"
#include<iostream>
#include<string>

// Constructor
NonThesisMastersStudent::NonThesisMastersStudent(std::string name,std::string studentID,std::string department,std::string advisor, std::string projectTitle) : MastersStudent(name,studentID,department,advisor){
    this->projectTitle = projectTitle;
}

// display function
void NonThesisMastersStudent::displayInfo() const{
    MastersStudent::displayInfo();
    std::cout<<"Project Title: "<<this->projectTitle<<std::endl;
}

// get level function
std::string NonThesisMastersStudent::getLevel() const{
    return "NonThesisMastersStudent";
}