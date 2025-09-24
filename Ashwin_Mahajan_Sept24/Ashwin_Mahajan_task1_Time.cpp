//  Source file --> definition of class functions
#include<iostream>
#include "Ashwin_Mahajan_task1_Time.h"
#include<iomanip>
// Constructor will call set time which will validate and then will set the time
Time::Time( int hr, int min, int sec )
{
    setTime( hr, min, sec ); 
}

// setime function will call sethour, setminute and setsecond to accurately set the time
void Time::setTime( int hr, int min, int sec){
    setHour(hr); // set hour
    setMinute(min); // set minute
    setSecond(sec); // set second
}; 

// Validate and then set hour
void Time::setHour( const int hr){
    this->hour = (hr>=24 || hr<=0) ? 0 : hr;
}; 

//  Validate and then set minute
void Time::setMinute( const int minute){
    this->minute = (minute>=60 || minute<=0) ? 0:minute;
} 

//  Validate and then set second
void Time::setSecond(const int sec){
    this->second = (sec>=60 || sec<=0) ? 0:sec;
} 

int Time::getHour() const{return hour;}; // Rteurn time in hours
int Time::getMinute() const {return minute;}; // Return time in minutes
int Time::getSecond() const {return second;} // Return time in seconds

// Function to print the universal format
void Time::printUniversal() const{
    std::cout << std::setfill( '0' ) << std::setw( 2 ) << getHour() << ":" << std::setw( 2 ) << getMinute() << ":" << std::setw( 2 ) << getSecond()<<std::endl;
}

// Function to print Standard format
void Time::printStandard() const {
    int hr = (getHour()>=12) ? hour - 12 : hour;
    std::string str = (getHour()>=12) ? "PM" : "AM";
    std::cout << std::setfill( '0' ) << std::setw( 2 ) << hr << ":" << std::setw( 2 ) << getMinute() << ":" << std::setw( 2 ) << getSecond()<<" "<<str<<std::endl;
}

// Tick function to increment time
void Time::tick(){
    // Day has ended
    if(hour == 23 && minute == 59 && second == 59){
        setTime(0,0,0);
    }
    // hour has ended
    else if(minute == 59 && second == 59){
        setTime(hour+1, 0,0);
    }
    //minute has ended
    else if(second == 59){
        setTime(hour,minute+1, 0);
    }
    else{
        second++;
    }
}

