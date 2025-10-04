#ifndef SIMULATE_ENGINE_H
#define SIMULATE_ENGINE_H

#include"Ashwin_Mahajan_task1_ConfigManager.h"
#include"Ashwin_Mahajan_task1_FaultLogger.h"
#include"Ashwin_Mahajan_task1_FaultInjector.h"

class SimulationEngine{
    private:
        ConfigManager& config;
        FaultLogger* logger;
        FaultInjector* fi;        

    public:
        SimulationEngine(ConfigManager&, FaultLogger*);
        void runCycle();
};

#endif