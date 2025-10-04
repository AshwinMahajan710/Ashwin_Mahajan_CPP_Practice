
// Config manager header file

#ifndef CONFIG_MANAGER_H
#define CONFIG_MANAGER_H

#include<iostream>
#include"Ashwin_Mahajan_task1_Sensor.h"

class ConfigManager{
    public:
        void updateThreshold(Sensor& s, float newThreshold);
};
#endif