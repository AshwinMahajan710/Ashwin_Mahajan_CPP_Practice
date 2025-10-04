
// PressureSensor Header file

#ifndef PRESSURE_SENSOR_H
#define PRESSURE_SENSOR_H

#include<iostream>
#include"Ashwin_Mahajan_task1_Sensor.h"


// class temperature sensor
class PressureSensor : public Sensor{
    public: 
        PressureSensor(int id, float value, float threshold);
        void simulateFault();
};

#endif