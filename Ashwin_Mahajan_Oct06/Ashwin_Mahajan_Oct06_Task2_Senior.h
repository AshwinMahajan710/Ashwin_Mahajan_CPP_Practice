
// Senior header file

#include"Ashwin_Mahajan_Oct06_Task2_UndergraduateStudent.h"
#include<string>
#include<iostream>

#ifndef SENIOR_H
#define SENIOR_H

class Senior:public UndergraduateStudent{
    public:
        Senior(std::string name,std::string studentID,std::string department, int year, int creditsEarned);
        virtual void displayInfo() const;
        virtual std::string getLevel() const;
};

#endif