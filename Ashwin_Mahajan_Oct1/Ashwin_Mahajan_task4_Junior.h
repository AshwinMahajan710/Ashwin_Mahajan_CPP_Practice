
// Junior header file

#include<iostream>
#include<string>
#include"Ashwin_Mahajan_task4_UndergraduateStudent.h"

#ifndef JUNIOR_H
#define JUNIOR_H

class Junior : public UndergraduateStudent{
    public:
        Junior(std::string name,std::string studentID,std::string department, int year, int creditsEarned);
        virtual void displayInfo() const;
        virtual std::string getLevel() const;
};

#endif