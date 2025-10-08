#include<iostream>
#include"Ashwin_Mahajan_Oct08_Task1_SensorReading.h"
#include"Ashwin_Mahajan_Oct08_Task1_DiagnosticReport.h"
#include"Ashwin_Mahajan_Oct08_Task1_SeverityLevel.h"
#include<string>

int main(){
    
    // creating the object of class diagnostic report
    DiagnosticReport report;

    // Adding sensor readings
    report.addSensorReading(SensorReading("EngineTemp",105, SeverityLevel::HIGH));
    report.addSensorReading(SensorReading("OilPressure",20, SeverityLevel::MEDIUM));
    report.addSensorReading(SensorReading("BrakeFluidLevel",5, SeverityLevel::CRITICAL)); 
    report.addSensorReading(SensorReading("BatteryVoltage",12.5, SeverityLevel::LOW));
    report.addSensorReading(SensorReading("WheelTemp",30,SeverityLevel::MEDIUM));

    // Displaying sensor readings
    std::cout<<"\nAll readings in the report are: "<<std::endl;
    report.displayAllReadings();

    // Counting the objects of same severity level
    std::cout<<"\nCount of readings with Medium soverity levels is: "<<report.getReadingsCountBySeverity(SeverityLevel::MEDIUM)<<std::endl;

    // check for severity distribution map
    std::cout<<"\nFollowing is the severity map: "<<std::endl;
    report.severityMap();

    // Sorting and then display all readings
    std::cout<<"\nReadings after sorting: "<<std::endl;
    report.sortBySeverityDescending();
    report.displayAllReadings();

    // filter and display only critical readings
    int count = 0;
    SensorReading* arr =  report.filterBySeverity(SeverityLevel::CRITICAL, count);
    if(arr == nullptr) {std::cout<<"\nNo sensor reading with given severity level....";}
    else {
        std::cout<<"\nFollowing are the sensors with given sensor reading...."<<std::endl;
        for(int i=0;i<count;i++){
            std::cout<<std::endl;
            arr->display();
        }
    }

    // Searching for a sensor
    SensorReading* readingByName = report.findReadingByName("BatteryVoltage");
    if(readingByName == nullptr) {std::cout<<"\nNo sensor reading with given name....";}
    else {
        std::cout<<"\nFollowing is the sensor with given name...."<<std::endl;
        std::cout<<std::endl;
        readingByName->display();
    }

    return 0;
}   