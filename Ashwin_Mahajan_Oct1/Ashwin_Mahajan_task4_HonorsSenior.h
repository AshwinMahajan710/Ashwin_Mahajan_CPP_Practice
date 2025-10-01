
// HonourSenior header file

#include<iostream>
#include<string>
#include"Ashwin_Mahajan_task4_Senior.h"

#ifndef HONOURS_SENIORS_H
#define HONOURS_SENIORS_H

class HonorsSenior : public Senior{
    public:
        std::string thesisTitle;
        HonorsSenior(std::string name,std::string studentID,std::string department, int year, int creditsEarned, std::string thesisTitle);
        virtual void displayInfo() const;
        virtual std::string getLevel() const;
};

#endif