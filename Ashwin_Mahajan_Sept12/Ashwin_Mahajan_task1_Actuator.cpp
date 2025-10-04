#include<iostream>
#include"Ashwin_Mahajan_task1_Actuator.h"

//constructor
Actuator::Actuator(int id, std::string state, int responseTime){
    this->id = id;
    this->responseTime = responseTime;
    this->state = state;
}

// trigger action function
void Actuator::triggerAction(){
    std::cout<<"Action triggered for id: "<<id<<std::endl;
    state = "Triggered";
}

// printinfo
void Actuator::printInfo() const{
    std::cout<<"Actuator ID: "<<id<<std::endl;
    std::cout<<"Response Time: "<<responseTime<<std::endl;
    std::cout<<"State: "<<state<<std::endl;
}