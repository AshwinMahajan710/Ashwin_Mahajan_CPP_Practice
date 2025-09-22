// Source file --> define the class

#include<iostream>
#include<ctime>
#include<chrono>
#include"Ashwin_Mahajan_task4_HeartRates.h"

// Constructor ---> 
HeartRates::HeartRates(std::string f_name, std::string l_name, int day, int month, int year){
    this->f_name = f_name;
    this->l_name = l_name;
    this->birth_day = day;
    this->birth_month = month;
    this->birth_year = year;
}

// Getters
std::string HeartRates::getFirstName() const{return f_name;};
std::string HeartRates::getLastName() const{return l_name;};
int HeartRates::getBirthDay() const{return birth_day;};
int HeartRates::getBirthMonth() const{return birth_month;};
int HeartRates::getBirthYear() const{return birth_year;};

// Setters
void HeartRates::setFirstName(std::string f_name) {this->f_name = f_name;}
void HeartRates::setLastName(std::string l_name){this->l_name = l_name;}
void HeartRates::setBirthDay(int day){this->birth_day = day;}
void HeartRates::setBirthMonth(int month){this->birth_month = month;};
void HeartRates::setBirthYear(int year){this->birth_year = year;}


// Get current date and time using chrono and calculate age using that
int HeartRates::getPersonAge(){
    // Get today's date
    auto today = std::chrono::system_clock::now();
    time_t tt = std::chrono::system_clock::to_time_t(today);
    tm local_tm = *localtime(&tt);

    int current_year = local_tm.tm_year + 1900;
    int current_month = local_tm.tm_mon + 1; 
    int current_day   = local_tm.tm_mday;

    // age = current year - birth year
    int age = (current_year - this->birth_year);

    if (current_month < this->birth_month || 
    (current_month == this->birth_month && current_day < this->birth_day)) {
    age--;
    }
    return age;
} 

// Function to get maximum heartrate
int HeartRates::getMaxiumumHeartRate(){
    return (220 - getPersonAge());
}

// Function to get target Heart rate
int HeartRates::getTargetHeartRate(){
    return int((80*getMaxiumumHeartRate())/100); // 80% of the max heart rate is target
}
