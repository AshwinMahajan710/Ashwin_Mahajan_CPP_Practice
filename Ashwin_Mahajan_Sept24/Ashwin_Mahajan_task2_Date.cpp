#include <iostream>
#include "Ashwin_Mahajan_task2_Date.h"

// Date Constructor
Date::Date( int m, int d, int y ){
    setDate(m,d,y);
} 

// This are the days in particular
int Date::days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

//print date
void Date::print() const
{
    std::cout << month << '/' << day << '/' << year<<std::endl;
} 

// incrementing the day
void Date::nextDay(){
    days[2] = isLeap(year) ? 29 : 28;
    day++;
    if(day>days[month]){
        day = 1;
        month++;
        if(month>12){
            month = 1;
            year++;
            if(year>10000){
                year = 1;
            }
        }
    }
    std::cout<<" Day Incremented..."<<std::endl;
    print();
}

// Checking that the year is leap year or not for accurate days
bool Date::isLeap(int year) const{
    if(year%400==0 || (year%4==0 && year%100!=0)){
        return true;
    }
    else {
        return false;
    }
}

// Function to validate day
bool Date::Validate_day(int day, int month, int year){

    days[2] = isLeap(year) ? 29 : 28; // as leap year has extra day

    return (day>0 && day<=days[month]);
}

// Setters
void Date::setDate(int month, int day, int year){
    setYear(year);
    setMonth(month);
    setDay(day);
}

// setting month
void Date::setMonth(int month){
    this->month = (month > 12 || month <= 0) ? 1 : month;
}

// setting year
void Date::setYear(int year){
    this->year= (year >10000 || year <= 0) ? 1 : year;
}

// setting day
void Date::setDay(int day){
    this->day = Validate_day(day,this->month,this->year) ? day : 1;
}

// Getting the values of day month and year
int Date::getDay() const {return day;};
int Date::getMonth() const{return month;};
int Date::getYear() const { return year;};