#include<iostream>
#include<iomanip>
#include"Ashwin_Mahjan_task3_DateAndTime.h"

// Defining the constructor
DateAndTime::DateAndTime(int hour, int min, int sec, int day, int month, int year):Date(month,day,year),Time(hour,min,sec){}

// modify the tick function to call next day
void DateAndTime::tick(){
    Time::tick();
    if(getHour()==0 && getMinute()==0 && getSecond()==0){
        Date::nextDay();
    }
}

// Modify print universal format
void DateAndTime::printUniversal(){
    std::cout<<getMonth()<<"/"<<getDay()<<"/"<<getYear()<<"   "<<std::setfill( '0' ) << std::setw( 2 ) << getHour() << ":" << std::setw( 2 ) << getMinute() << ":" << std::setw( 2 ) << getSecond()<<std::endl;
}

// Modify to print standard form of date and time
void DateAndTime::printStandard(){
    int hr = (getHour()>=12) ? getHour() - 12 : getHour();
    std::string str = (getHour()>=12) ? "PM" : "AM";
    std::cout <<getDay()<<"/"<<getMonth()<<"/"<<getYear()<<"   "<< std::setfill( '0' ) << std::setw( 2 ) << hr << ":" << std::setw( 2 ) << getMinute() << ":" << std::setw( 2 ) << getSecond()<<" "<<str<<std::endl;    
}


