
// ExchangeSenior CPP file

#include<iostream>
#include"Ashwin_Mahajan_Oct06_Task2_ExchangeSenior.h"
#include"Ashwin_Mahajan_Oct06_Task2_Senior.h"
#include<string>

// ExchangeSenior constructor
ExchangeSenior::ExchangeSenior(std::string name,std::string studentID,std::string department, int year, int creditsEarned,std::string homeUniversity): Senior(name,studentID, department, year, creditsEarned){
    this->homeUniversity = homeUniversity;
};

// display function
void ExchangeSenior::displayInfo()const{
    Senior::displayInfo();
    std::cout<<"Home University Title: "<<this->homeUniversity<<std::endl;
}

// Get level function
std::string ExchangeSenior::getLevel() const{
    return "ExchangeSenior";
}