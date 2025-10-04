
// Config manager definition file

#include<iostream>
#include"Ashwin_Mahajan_task1_ConfigManager.h"
#include"Ashwin_Mahajan_task1_Sensor.h"

void ConfigManager::updateThreshold(Sensor& s, float newThreshold){
    s.setThreshold(newThreshold);
}