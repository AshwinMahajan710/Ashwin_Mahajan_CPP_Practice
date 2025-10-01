#include<iostream>
#include<string>
#include"Ashwin_Mahajan_task1_HybridVehicle.h"

// Parameterized constructor
HybridVehicle::HybridVehicle(std::string modelName, float electricKm, float gasolineKm, float gasolineUsed){
    this->modelName = modelName;
    this->electricKm = electricKm;
    this->gasolineKm = gasolineKm;
    this->gasolineUsed = gasolineUsed;
    this->tripsCount = 0;
    for(int i=0; i<10;i++){
        trips[i] = 0;
    }
}

// Friend function for printing object details
std::ostream& operator<<(std::ostream& out,const HybridVehicle& other){
    out<<"Vehicle Model Name: "<< other.modelName<<std::endl;
    out<<"Traveled Electric KM: "<< other.electricKm<<std::endl;
    out<<"Traveled Gasoline KM: "<< other.gasolineKm<<std::endl;
    out<<"Total Gasoline used: "<< other.gasolineUsed<<std::endl;
    if(other.tripsCount > 0) {out<<"Trips: ";} // only show trips if they are greater than zero
    for (int i = 0; i < other.tripsCount; i++){ out<<other.trips[i]<<" " ;}
    out<<std::endl;
    return out;
}

// +operator
HybridVehicle HybridVehicle:: operator+(const HybridVehicle& other) const{
    float newElectricKM = this->electricKm + other.electricKm;
    float newGasolineKM = this->gasolineKm + other.gasolineKm;
    float newGasolineUsed = this->gasolineUsed + other.gasolineUsed; 
    HybridVehicle newVehicle("New Vehicle", newElectricKM, newGasolineKM, newGasolineUsed); // create new vehicle object
    for(int i=0;i<10;i++){ // assign each trip value by adding them
        newVehicle.trips[i] = this->trips[i] + other.trips[i]; 
    }
    newVehicle.tripsCount = (this->tripsCount>other.tripsCount) ? this->tripsCount : other.tripsCount; // update trips count of new vehicle as max of both vehicle
    return newVehicle;
}

// float operator overloading to get the efficiency
HybridVehicle:: operator float() const{
    return (gasolineUsed != 0) ? (electricKm + gasolineKm) / gasolineUsed : 0.0f;
}

// using the overloaded float operator return the wquality results
bool HybridVehicle::operator == (const HybridVehicle& other) const{
    return (float(*this) == float(other));
}

// Deep copy 
void HybridVehicle:: operator = (const HybridVehicle& other){
    if(this == &other) {return ;} // both objects are same as stored in same location in memory
    this->electricKm = other.electricKm;
    this->modelName = other.modelName;
    this->gasolineUsed = other.gasolineUsed;
    this->tripsCount = other.tripsCount;
    for(int i=0;i<tripsCount;i++){this->trips[i] = other.trips[i];}
}

// increment the ++ operator to increase trip count and add dummy trip
void HybridVehicle:: operator ++(int){
    if(tripsCount<9) {this->trips[tripsCount++] = -1;} // adding dummy trip only is there is place 
}

// Return the accessed trip distance
const int& HybridVehicle:: operator[](int val) const{
    return trips[val];
}

// Return non-constant reference to change the value
int& HybridVehicle:: operator[](int val){
    if(trips[val]==0) {tripsCount++;}
    return trips[val];
}

// will return total travelled speed 
long HybridVehicle:: operator()(){
    long totalDistanceTravelled = 0;
    for(int i=0;i<tripsCount;i++){
        if(trips[i] != -1){ totalDistanceTravelled += trips[i];}
    }
    return totalDistanceTravelled;
}