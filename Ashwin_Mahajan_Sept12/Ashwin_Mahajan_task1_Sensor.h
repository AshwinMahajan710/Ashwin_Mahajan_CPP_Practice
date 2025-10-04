
// SENSOR_H header file

#ifndef SENSOR_H
#define SENSOR_H

#include<iostream>
#include<string>

// Class Sensor
class Sensor{
    private:
       int id; 
       float value;
       float threshold;
       std::string status;
    
    public:
        Sensor(int id, float value, float threshold);
        virtual void simulateFault() = 0;
        bool isFaulty() const;
        
        // Getters
        float getValue() const;
        int getId() const;
        float getThreshold() const;
        std::string getStatus() const;
        
        // Setter for value
        void setValue(float);

        // setter for status and threshold
        void setStatus(std::string );
        void setThreshold(float) ;
        
        // Printing the info
        void printInfo() const;

};

#endif