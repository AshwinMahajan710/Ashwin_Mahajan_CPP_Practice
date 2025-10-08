#include<iostream>
#include"Ashwin_Mahajan_Oct08_Task1_SensorReading.h"
#include"Ashwin_Mahajan_Oct08_Task1_SeverityLevel.h"
#include"Ashwin_Mahajan_Oct08_Task1_DiagnosticReport.h"
#include<algorithm> // for std::sort
#include<string>

// constructor
void DiagnosticReport::addSensorReading(const SensorReading& newReading){
    this->collection.push_back(newReading);
    std::cout<<"Successfully added sensor reading with sensor name: "<<newReading.getSensorName()<<std::endl;
}

// display readings
void DiagnosticReport::displayAllReadings() const{
    for(int i=0;i<this->collection.size();i++){
        std::cout<<std::endl;
        collection[i].display();
    }
}

// get count of sensor readings with particular severity level
int DiagnosticReport::getReadingsCountBySeverity(SeverityLevel level) const{
    int count = 0;
    for(int i=0;i<this->collection.size();i++){
        if (collection[i].getSeverity() == level) { count++; }
    }
    return count;
}

// will return pointer to arr with severity object
SensorReading* DiagnosticReport::filterBySeverity(SeverityLevel level, int& count)const{
    for(int i=0; i<this->collection.size();i++){
        if(collection[i].getSeverity()== level){
            count++;
        }
    }
    SensorReading* arr = new SensorReading[count];
    int tempCount = 0;
    for(int i=0; i<this->collection.size();i++){
        if(collection[i].getSeverity()== level){
            arr[tempCount++] = collection[i];
        }
    }
    return arr;
}


// Sorting objects by severity
void DiagnosticReport::sortBySeverityDescending(){
    std::sort(collection.begin(), collection.end(), compareSeverity);
}

// sorting function
bool DiagnosticReport::compareSeverity(const SensorReading& a, const SensorReading& b) {
    return a.getSeverity() > b.getSeverity();
}

// function which will give count of each severity level
void DiagnosticReport::severityMap() const{
    int lowCount = 0;
    int mediumCount = 0;
    int highCount = 0;
    int criticalCount = 0;

    for(int i=0;i<collection.size();i++){
        if(collection[i].getSeverity() == SeverityLevel::LOW) {lowCount++;}
        else if(collection[i].getSeverity() == SeverityLevel::MEDIUM) {mediumCount++;}
        else if(collection[i].getSeverity() == SeverityLevel::HIGH) {highCount++;}
        else {criticalCount++;}
    }
    std::cout<<"\nLow Severity Level: "<<lowCount<<"\nMedium Severity Level: "<<mediumCount<<"\nHigh Severity Level: "<<highCount<<"\nCritical Severity Level: "<<criticalCount<<std::endl;
}

// Find sensor reading by name
SensorReading* DiagnosticReport::findReadingByName(const std::string& name){
    for(int i=0;i<collection.size();i++){
        if(collection[i].getSensorName() == name) {return &collection[i];}
    }
    return nullptr;
}

