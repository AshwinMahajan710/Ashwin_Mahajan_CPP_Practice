
// Sensor Reading header file

#ifndef SENSOR_READING_H
#define SENSOR_READING_H

#include<string>
#include"Ashwin_Mahajan_Oct08_Task1_SeverityLevel.h"

// class sensor reading
class SensorReading{
    private:
        std::string sensorName;
        double value;
        SeverityLevel severity ;

    public: 
        SensorReading();
        SensorReading(std::string name, double val, SeverityLevel severity);
        void display() const;
        std::string retrieveSeverity() const;

        // Getters
        std::string getSensorName() const;
        double getValue() const;
        SeverityLevel getSeverity() const;
};

#endif