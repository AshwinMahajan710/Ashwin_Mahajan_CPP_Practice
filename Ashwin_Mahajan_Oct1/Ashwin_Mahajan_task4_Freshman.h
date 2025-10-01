
// Freshman header file

#include<iostream>
#include<string>
#include"Ashwin_Mahajan_task4_UndergraduateStudent.h"

#ifndef FRESHMAN_H
#define FRESHMAN_H

class Freshman : public UndergraduateStudent{
    public:
        Freshman(std::string name,std::string studentID,std::string department, int year, int creditsEarned);
        virtual void displayInfo() const;
        virtual std::string getLevel() const;
};

#endif