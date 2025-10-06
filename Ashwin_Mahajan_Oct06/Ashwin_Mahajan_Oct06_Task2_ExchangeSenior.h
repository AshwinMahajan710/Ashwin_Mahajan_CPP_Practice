// ExchangeSenior header file

#include<iostream>
#include<string>
#include"Ashwin_Mahajan_Oct06_Task2_Senior.h"

#ifndef EXCHANGE_SENIOR_H
#define EXCHANGE_SENIOR_H

// class exchange senior
class ExchangeSenior : public Senior{
    public:
        std::string homeUniversity;
        ExchangeSenior(std::string name,std::string studentID,std::string department, int year, int creditsEarned, std::string homeUniversity);
        virtual void displayInfo() const;
        virtual std::string getLevel() const;
};

#endif