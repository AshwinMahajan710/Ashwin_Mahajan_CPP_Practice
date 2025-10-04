#include"Ashwin_Mahajan_task1_Sensor.h"
#include"Ashwin_Mahajan_task1_TemperatureSensor.h"
#include"Ashwin_Mahajan_task1_PressureSensor.h"
#include"Ashwin_Mahajan_task1_Actuator.h"
#include"Ashwin_Mahajan_task1_FaultInjector.h"
#include"Ashwin_Mahajan_task1_ConfigManager.h"
#include"Ashwin_Mahajan_task1_FaultLogger.h"
#include"Ashwin_Mahajan_task1_SimulationEngine.h"
#include<string>
#include<iostream>

// Constructor
SimulationEngine::SimulationEngine(ConfigManager& config, FaultLogger* logger): config(config), logger(logger){
    fi = new FaultInjector();
}

// run
void SimulationEngine::runCycle(){
    
    TemperatureSensor* t1 = new TemperatureSensor(101, 95.0, 90.0);
    PressureSensor* p1 = new PressureSensor(102, 45.0, 50.0);
    PressureSensor* p2 = new PressureSensor(12, 5.0, 100.0);
    Actuator* a1 = new Actuator(201, "Idle", 120);
    Actuator* a2 = new Actuator(202, "Idle", 10);
    fi->sensors.push_back(t1);
    fi->sensors.push_back(p1);
    fi->sensors.push_back(p2);
    fi->actuators.push_back(a1);
    fi->actuators.push_back(a2);

    fi->injectAllFaults();
    fi->injectActuatorDelay(*(fi->actuators[0]));
    fi->injectSensorFault(fi->sensors[0]);
    fi->reportStatus();

    // log sensor
    for(int i=0;i<fi->sensors.size();i++){
        logger->log(*(fi->sensors[i]));
    }

    // call confi manager
    config.updateThreshold(*(fi->sensors[0]), 100);
    fi->sensors[0]->printInfo();
    
}



