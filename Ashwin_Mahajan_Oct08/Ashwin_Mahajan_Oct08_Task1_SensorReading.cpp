
// Sensor reading cpp file
#include"Ashwin_Mahajan_Oct08_Task1_SeverityLevel.h"
#include"Ashwin_Mahajan_Oct08_Task1_SensorReading.h"
#include<iostream>
#include<string>

// constructor
SensorReading::SensorReading(){
    this->sensorName = "";
    this->value = 0;
    this->severity = SeverityLevel::LOW;
}

// constructor
SensorReading::SensorReading(std::string name, double val, SeverityLevel severity){
    this->sensorName = name;
    this->value = val;
    this->severity = severity;
}
        
// display function
void SensorReading::display() const{
    std::cout<<"Sensor Name: "<<this->sensorName<<std::endl;
    std::cout<<"Sensor Value: "<<this->value<<std::endl;
    std::cout<<"Sensor Severity: "<<this->retrieveSeverity()<<std::endl;
}

// get string value of severity
std::string SensorReading::retrieveSeverity() const{
    switch (this->severity){

        case SeverityLevel::CRITICAL:{
            return "CRITICAL";
            break;
        }

        case SeverityLevel::HIGH:{
            return "HIGH";
            break;
        }
        
        case SeverityLevel::LOW:{
            return "LOW";
            break;
        }
        
        case SeverityLevel::MEDIUM:{
            return "MEDIUM";
            break;
        }

        default:{
            return "";
            break;

        }
    }
}

// get Sensor name
std::string SensorReading:: getSensorName() const{
    return this->sensorName;
}

// get Sensor value
double SensorReading::getValue() const{
    return this->value;
}

// get severity
SeverityLevel SensorReading::getSeverity() const{
    return this->severity;
}