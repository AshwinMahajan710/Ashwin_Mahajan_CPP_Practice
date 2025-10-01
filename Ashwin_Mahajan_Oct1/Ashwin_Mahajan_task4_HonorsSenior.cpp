
// HonoursSenior CPP file

#include<iostream>
#include"Ashwin_Mahajan_task4_Senior.h"
#include"Ashwin_Mahajan_task4_HonorsSenior.h"
#include<string>

// Honours Senior constructor
HonorsSenior::HonorsSenior(std::string name,std::string studentID,std::string department, int year, int creditsEarned,std::string thesisTitle): Senior(name,studentID, department, year, creditsEarned){
    this->thesisTitle = thesisTitle;
};

// display function
void HonorsSenior::displayInfo()const{
    Senior::displayInfo();
    std::cout<<"Thesis Title: "<<this->thesisTitle<<std::endl;
}

// Get level function
std::string HonorsSenior::getLevel() const{
    return "HonorsSenior";
}