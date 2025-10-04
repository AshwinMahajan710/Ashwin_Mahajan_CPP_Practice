#include<iostream>
#include<string>
#include"Ashwin_Mahajan_task1_Sensor.h"
#include"Ashwin_Mahajan_task1_Actuator.h"
#include"Ashwin_Mahajan_task1_FaultInjector.h"

FaultInjector::FaultInjector(){};

// inject sensors
void FaultInjector:: injectSensorFault(Sensor* s){
    sensors.push_back(s);
}

// injecting actuator delay
void FaultInjector::injectActuatorDelay(Actuator& a){
    actuators.push_back(&a);
}

// Injecting faults in sensor
void FaultInjector::injectAllFaults(){
    for(int i=0;i<sensors.size();i++){
        sensors[i]->simulateFault();
    }
}

// report status function
void FaultInjector::reportStatus(){
    for(int i=0;i<sensors.size();i++){
        sensors[i]->printInfo();
    }
    for(int i=0;i<actuators.size();i++){
        actuators[i]->printInfo();
    }
}