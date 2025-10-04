#include<iostream>
#include<string>
#include"Ashwin_Mahajan_task1_Sensor.h"
#include"Ashwin_Mahajan_task1_PressureSensor.h"

// constructor
PressureSensor::PressureSensor(int id, float value, float threshold) : Sensor(id,value,threshold){}

// Simulate fault
void PressureSensor:: simulateFault(){
    float oldFault = Sensor::getValue();
    Sensor::setValue(oldFault += 30.0);
     if(Sensor::isFaulty()){Sensor::setStatus("Faulty");}
    std::cout<<"Fault simulated for pressure sensor...."<<std::endl;
}

