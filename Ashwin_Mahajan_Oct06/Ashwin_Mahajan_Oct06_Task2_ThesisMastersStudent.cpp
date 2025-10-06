// ThesisMastersStudent cpp file

#include"Ashwin_Mahajan_Oct06_Task2_MastersStudent.h"
#include"Ashwin_Mahajan_Oct06_Task2_ThesisMastersStudent.h"
#include<iostream>
#include<string>

// Constructor
ThesisMastersStudent::ThesisMastersStudent(std::string name,std::string studentID,std::string department,std::string advisor, std::string thesisTitle) : MastersStudent(name,studentID,department,advisor){
    this->thesisTitle = thesisTitle;
}

// display function
void ThesisMastersStudent::displayInfo() const{
    MastersStudent::displayInfo();
    std::cout<<"Thesis Title: "<<this->thesisTitle<<std::endl;
}

// get level function
std::string ThesisMastersStudent::getLevel() const{
    return "ThesisMastersStudent";
}