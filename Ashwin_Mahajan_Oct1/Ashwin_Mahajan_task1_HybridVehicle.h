
#include<string>

#ifndef HYBRID_VEHICLE_H
#define HYBRID_VEHICLE_H

// class hybridvehicle
class HybridVehicle{
    private:
        std::string modelName;
        float electricKm;
        float gasolineKm;
        float gasolineUsed;
        int tripsCount; // total trips
        int trips[10]; // array to store trip distance
    
    public:
        HybridVehicle(std::string, float, float, float); // constructor
        friend std::ostream& operator<<(std::ostream& out,const HybridVehicle& ); // printing the vehicles details
        HybridVehicle operator+(const HybridVehicle& other) const; // return new obj with added values of both obj
        operator float() const; // return efficiency
        bool operator == (const HybridVehicle& other) const; // equality check
        void operator = (const HybridVehicle& other); // deep copy
        void operator ++(int); // increment trips count
        const int& operator[](int) const;  // to read
        int& operator[](int); // to change
        long operator()(); // to get total distance
};      

#endif