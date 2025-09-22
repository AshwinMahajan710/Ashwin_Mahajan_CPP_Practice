#include<iostream>
#include"Ashwin_Mahajan_task5_HealthProfile.h"
#include<ctime>
#include<chrono>

HealthProfile::HealthProfile(std::string f_name, std::string l_name, std::string gender, int day, int month, int year, float height, float weight){
    this->f_name = f_name;
    this->l_name = l_name;
    this->gender = setGenderUsingNames(gender);
    this->birth_day = day;
    this->birth_month = month;
    this->birth_year = year;
    this->height = height;
    this->weight = weight;
}

// Getters
std::string HealthProfile::getFirstName() const{return f_name;} // First name of patient
std::string HealthProfile::getLastName() const{return l_name;} // Last name of patient
std::string HealthProfile::getGender() const{return getGenderName(gender);} // Enum class for Gender
int HealthProfile::getBirthDay() const {return birth_day;}
int HealthProfile::getBirthMonth() const{return birth_month;}
int HealthProfile::getBirthYear() const {return birth_year;}
float HealthProfile::getHeight() const {return height;}
float HealthProfile::getWeight() const {return weight;}

// Setters
void HealthProfile::setFirstName(std::string fname) {this->f_name = fname;}
void HealthProfile::setLastName(std::string lname) {this->l_name = lname;}
void HealthProfile::setGender(std::string gender) {this->gender = setGenderUsingNames(gender);}
void HealthProfile::setBirthDay(int day){this->birth_day = day;}
void HealthProfile::setBirthMonth(int month){this->birth_month = month;}
void HealthProfile::setBirthYear(int year){this->birth_year = year;}
void HealthProfile::setHeight(int height){this->height = height;}
void HealthProfile::setWeight(int weight){this->weight = weight;}

// Get current date and time using chrono and calculate age using that
int HealthProfile::getPersonAge() const{
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
int HealthProfile::getMaxiumumHeartRate()const {
    return (220 - getPersonAge());
}

// Function to get target Heart rate
int HealthProfile::getTargetHeartRate() const{
    return int((80*getMaxiumumHeartRate())/100); // 80% of the max heart rate is target
}

// For BMI calculation
float HealthProfile::getBMI() const{
    return (weight/((height/100)*(height/100)));
}

// Special function to convert gender object to readable string
std::string HealthProfile::getGenderName(const Gender gender) const {
    if(gender == Gender::MALE){ return "MALE";}
    else if(gender == Gender::FEMALE){return "FEMALE";}
    else {return "Other";}
}

// Special function to convert string to gender object
Gender HealthProfile::setGenderUsingNames(const std::string name){
    if(name == "MALE"){
        return Gender::MALE;
    }
    else if(name == "FEMALE"){
        return Gender::FEMALE;
    }
    else{
        return Gender::OTHER;
    }
}