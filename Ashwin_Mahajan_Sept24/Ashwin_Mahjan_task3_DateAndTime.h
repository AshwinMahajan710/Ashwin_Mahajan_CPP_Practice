
// Header File --. class declaration

#include"Ashwin_Mahajan_task2_Date.h"
#include"Ashwin_Mahajan_task1_Time.h"

#ifndef DATE_TIME_H
#define DATE_TIME_H
class DateAndTime : public Date, public Time{
    public:
        DateAndTime(int hour, int min, int sec, int day, int month, int year);  
        void tick(); // overloading tick from Time class
        void printUniversal(); // Overloading printUniversal and printStandard
        void printStandard();
};

#endif