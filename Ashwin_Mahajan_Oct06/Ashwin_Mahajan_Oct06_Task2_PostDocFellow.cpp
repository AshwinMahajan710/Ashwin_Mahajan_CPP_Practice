
// PostDocFellow cpp file

#include"Ashwin_Mahajan_Oct06_Task2_DoctoralStudent.h"
#include"Ashwin_Mahajan_Oct06_Task2_PostDocFellow.h"
#include<iostream>
#include<string>

// Constructor
PostDocFellow::PostDocFellow(std::string name,std::string studentID,std::string department,std::string advisor, std::string dissertationTitle, int yearsInProgram,std::string researchGrant) : DoctoralStudent(name,studentID,department,advisor,dissertationTitle, yearsInProgram){
    this->researchGrant = researchGrant;
}

// display function
void PostDocFellow::displayInfo() const{
    DoctoralStudent::displayInfo();
    std::cout<<"Research Grant: "<<this->researchGrant<<std::endl;
}

// get level function
std::string PostDocFellow::getLevel() const{
    return "PostDocFellow";
}