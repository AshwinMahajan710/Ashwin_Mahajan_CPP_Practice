#include<iostream>
#include"Ashwin_Mahajan_task1_Sensor.h"
#include"Ashwin_Mahajan_task1_FaultLogger.h"
#include<fstream>

// Log sensor
void FaultLogger::log(Sensor& s){
    std::ofstream OutFile("log.txt",std::ios::app);
    OutFile<<"ID: "<<s.getId()<<" Value: "<<s.getValue()<<" Threshold: "<<s.getThreshold()<<" Status: "<<s.getStatus()<<std::endl;
    OutFile.close();
}