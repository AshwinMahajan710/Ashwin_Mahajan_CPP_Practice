
// Temperature Sensor Header file

#ifndef TEMPERATURE_SENSOR_H
#define TEMPERATURE_SENSOR_H

#include<iostream>
#include"Ashwin_Mahajan_task1_Sensor.h"


// class temperature sensor
class TemperatureSensor : public Sensor{
    public: 
        TemperatureSensor(int id, float value, float threshold);
        void simulateFault();
        
};

#endif

