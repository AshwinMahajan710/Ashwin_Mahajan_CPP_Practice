#include<string>
#include<iostream>

#ifndef BATTERY_MONITOR_H
#define BATTERY_MONITOR_H

// Battery monitor class
class BatteryMonitor{
    private:
        std::string scooterID;
        int chargeCycles;
        float batteryCapacity; // current capacity in kWh
        float originalCapacity; // original capacity in kWh
        bool isActive; // 
        int tripCount; //number of trips;
        int* tripDistances; //dynamically allocated array of trip distances
    
    public:
        BatteryMonitor(std::string, int, float, float, bool, int); // parameterized constructor
        BatteryMonitor(const BatteryMonitor&); // copy constructor
        ~BatteryMonitor(); // destructor 
        void operator =(const BatteryMonitor& ); // deep copy
        bool operator<(const BatteryMonitor&) const; // return true if this battery health is less that other
        bool operator>(const BatteryMonitor&) const; // return false if this battery health is less that other
        void operator +=(int); // increase charge cycles and simulate degradation
        const int& operator[](int) const ;// accessing trip by subscript
        int& operator[](int); // will give reference of the trip distance if want to change it
        bool operator!() const; // return true if scooter is active else return false
        friend std::ostream& operator<<(std::ostream& out, const BatteryMonitor&); // print  details of the scooter
};

#endif