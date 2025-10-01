
// Sophomore header file

#include"Ashwin_Mahajan_task4_UndergraduateStudent.h"
#include<string>
#include<iostream>

#ifndef SOPHOMORE_H
#define SOPHOMORE_H

class Sophomore:public UndergraduateStudent{
    public:
        Sophomore(std::string name,std::string studentID,std::string department, int year, int creditsEarned);
        virtual void displayInfo() const;
        virtual std::string getLevel() const;
};

#endif