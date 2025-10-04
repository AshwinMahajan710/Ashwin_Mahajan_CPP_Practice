#include<iostream>
#include"Ashwin_Mahajan_task1_Sensor.h"

// Default constructor
Sensor::Sensor(int id, float value, float threshold){
    this->id = id;
    this->value = value;
    this->threshold = threshold;
    this->status = isFaulty() ? "Faulty" : "Working";
}

// Simulate fault
bool Sensor::isFaulty() const{
    if(this->value > this->threshold){
        return true;
    }
    return false;
}

// Getter and Setters for sensor 
void Sensor:: setValue(float val){
    this->value = val;
}
float Sensor:: getValue() const{
    return value;
}

// setter and getter for status 
void Sensor::setStatus(std::string other){
    this->status = other;
}

// Print the information
void Sensor:: printInfo() const{
    std::cout<<"Sensor ID: "<<id<<std::endl;
    std::cout<<"Value : "<<value<<std::endl;
    std::cout<<"Threshold: "<<threshold<<std::endl;
    std::cout<<"Status: "<<status<<std::endl;
}

void Sensor::setThreshold(float val){
    this->threshold = val;
    if(isFaulty()) {status = "Faulty";}
    else {status = "Working";}
}

int Sensor:: getId() const{
    return id;
}
float Sensor::getThreshold() const{
    return threshold;
}
std::string Sensor:: getStatus() const{
    return status;
}