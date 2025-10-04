#include<iostream>
#include<string>
#include"Ashwin_Mahajan_task1_Sensor.h"
#include"Ashwin_Mahajan_task1_TemperatureSensor.h"

// constructor
TemperatureSensor::TemperatureSensor(int id, float value, float threshold) : Sensor(id,value,threshold){}

// Simulate fault
void TemperatureSensor:: simulateFault(){
    float oldFault = Sensor::getValue();
    Sensor::setValue(oldFault += 20.0);
    if(Sensor::isFaulty()){Sensor::setStatus("Faulty");}
    std::cout<<"Fault simulated for temperature sensor...."<<std::endl;
}