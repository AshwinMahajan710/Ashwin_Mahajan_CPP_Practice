#include<iostream>
#include<string>
#include"Ashwin_Mahajan_task2_BatteryMonitor.h"

// Parameterized constructor
BatteryMonitor::BatteryMonitor(std::string scooterID, int chargeCycles, float currentCapacity, float originalCapacity, bool isActive, int tripCount){
    this->scooterID = scooterID;
    this->chargeCycles = chargeCycles;
    this->batteryCapacity = currentCapacity;
    this->originalCapacity = originalCapacity;
    this->isActive = isActive;
    this->tripCount = tripCount;
    this->tripDistances = new int[tripCount];
    for(int i=0;i<tripCount;i++){tripDistances[i] = 0;}
}

// Copy contructor
BatteryMonitor::BatteryMonitor(const BatteryMonitor& other){
    delete[] tripDistances;
    this->scooterID = other.scooterID;
    this->chargeCycles = other.chargeCycles;
    this->batteryCapacity = other.batteryCapacity;
    this->originalCapacity = other.originalCapacity;
    this->isActive = other.isActive;
    this->tripCount = other.tripCount;
    this->tripDistances = new int[tripCount];
    for(int i=0;i<tripCount;i++){tripDistances[i] = other.tripDistances[i];}
}

//destructor
BatteryMonitor::~BatteryMonitor(){
    delete[] tripDistances;
}

// Firnd function to print details
std::ostream& operator<<(std::ostream& out, const BatteryMonitor& other){
    out<<"Scooter ID: "<<other.scooterID<<std::endl;
    out<<"Total Charging Cycles: "<<other.chargeCycles<<std::endl;
    out<<"Current Battery Capacity: "<<other.batteryCapacity<<std::endl;
    out<<"Original Battery Capacity: "<<other.originalCapacity<<std::endl;
    out<<"Is Scooter Active: "<< (other.isActive ? "Yes" : "No")<<std::endl;
    out<<"Total Trip count: "<<other.tripCount<<std::endl;
    if(other.tripCount > 0) {out<<"Distance Covered in each trip: ";}
    for(int i=0;i<other.tripCount;i++){
        out<<other.tripDistances[i]<<" ";
    }
    out<<std::endl;
    return out;
}

// deep copy
void BatteryMonitor::operator =(const BatteryMonitor& other){
    delete[] tripDistances;
    this->scooterID = other.scooterID;
    this->chargeCycles = other.chargeCycles;
    this->batteryCapacity = other.batteryCapacity;
    this->originalCapacity = other.originalCapacity;
    this->isActive = other.isActive;
    this->tripCount = other.tripCount;
    this->tripDistances = new int[tripCount];
    for(int i=0;i<tripCount;i++){tripDistances[i] = other.tripDistances[i];}
}

 // return true if this battery health is less that other
bool BatteryMonitor::operator<(const BatteryMonitor& other) const{
    float thisBatteryHealth = (this->batteryCapacity / this->originalCapacity);
    float otherBatteryHealth = (other.batteryCapacity / other.originalCapacity);
    return (thisBatteryHealth<otherBatteryHealth);
}

// return false if this battery health is less that other
bool BatteryMonitor::operator>(const BatteryMonitor& other) const{
    float thisBatteryHealth = (this->batteryCapacity / this->originalCapacity);
    float otherBatteryHealth = (other.batteryCapacity / other.originalCapacity);
    return (thisBatteryHealth>otherBatteryHealth);
}

// increase charge cycles and simulate degradation
void BatteryMonitor::operator +=(int newCycles){
    float degradationRate = (originalCapacity - batteryCapacity) / chargeCycles;
    chargeCycles +=  newCycles;
    batteryCapacity -= degradationRate * newCycles;
}

// return -1 if invalid index passed
const int& BatteryMonitor:: operator[](int index) const {
    if(index < tripCount){return tripDistances[index];}
    else throw std::out_of_range("\nThe index passed is out of range...");
}

// using reference to change the trip distance if want to
int& BatteryMonitor:: operator[](int index){
    if(index < tripCount){return tripDistances[index];}
    else throw std::out_of_range("\nThe index passed is out of range...");
}

// return true if scooter is active
bool BatteryMonitor :: operator!() const{
    if(!isActive) {return true;}
    else {return false;}
}


