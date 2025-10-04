#include"Ashwin_Mahajan_task1_ConfigManager.h"
#include"Ashwin_Mahajan_task1_FaultLogger.h"
#include"Ashwin_Mahajan_task1_SimulationEngine.h"
#include<iostream>

int main(){
    ConfigManager config;
    FaultLogger logger;
    SimulationEngine engine(config, &logger);
    engine.runCycle();
    return 0;
}