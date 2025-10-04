
// Fault injector header file

#ifndef FAULT_INJECTOR_H
#define FAULT_INJECTOR_H
#include"Ashwin_Mahajan_task1_Sensor.h"
#include"Ashwin_Mahajan_task1_Actuator.h"
#include<vector>

// Class fault injector
class FaultInjector{
    public:
        FaultInjector();
        std::vector<Sensor*> sensors;
        std::vector<Actuator*> actuators;
        void injectSensorFault(Sensor* s);
        void injectActuatorDelay(Actuator& a);
        void injectAllFaults();
        void reportStatus();
};

#endif