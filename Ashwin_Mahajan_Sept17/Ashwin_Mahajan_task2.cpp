// Main Learnings :
// 1. Before proceeding forward make sure to initialize static variables
// 2. A default constructor is required when dynamically allocating an array of objects if the entire array is not fully initialized.

#include<iostream>
#include<limits>

class TrackedVehicle{
    private:
        uint32_t vehicle_id;
        float speed, distance;
        static float min_recorded_distance;
        static int vehicle_count;
    
    public:
        TrackedVehicle(uint32_t vehicle_id,float speed, float distance){
            this->vehicle_id = vehicle_id;
            this->speed = speed;
            this->distance = distance;

            if(min_recorded_distance > distance){min_recorded_distance = distance;}// update static min_recorded_distance
            vehicle_count++;  // increment vehicle_count
        }

        TrackedVehicle(){
            this->vehicle_id = 0;
            this->speed = 0;
            this->distance = std::numeric_limits<float> ::max();

            // as default constructor is dummy initialization no static variable updatation required
            // if(min_recorded_distance > distance){min_recorded_distance = distance;}// update static min_recorded_distance
            // vehicle_count++;  // increment vehicle_count
        }

        // getters
        float getDistance()const{return distance;}
        uint32_t getVehicleID()const{return vehicle_id;}
        float getSpeed()const{return speed;}

        void display() const{
            std::cout<<"\nVehicle ID: "<<vehicle_id<<"\nVehicle Speed: "<<speed<<"\nVehicle distance: "<<distance<<std::endl;
        }

        const TrackedVehicle* compareDistance(const TrackedVehicle&other){
            if(this->distance <= other.distance) return this;
            else return &other;
        }

        static int getVehicleCount(){
            return vehicle_count;
        }

        static float getMinRecordedDistance(){
            return min_recorded_distance;
        }

        ~TrackedVehicle(){
            std::cout<<"Vehicle with ID: "<<vehicle_id<<" Has been deleted..."<<std::endl;
        }
};

// Function to get vehicle with smallest distance
void findLeadVehicle(TrackedVehicle* arr,uint32_t size, const TrackedVehicle*& lead){
    lead = &arr[0];
    for(int i=0;i<size;i++){
        if(arr[i].getDistance() < lead->getDistance()){
            lead = &arr[i];
        }
    }
}

// Global Function: Printing vehicle details
void printTrackedVehicle(const TrackedVehicle& vehicle){
    vehicle.display();
}

// Global Function: Printing lead vehicle details
void printLeadVehicle(const TrackedVehicle* lead){
    lead->display();
}

// Intializing static variables
float TrackedVehicle::min_recorded_distance = std::numeric_limits<float>::max();
int TrackedVehicle::vehicle_count = 0;

int main(){

    // Allocate 4 objects on heap
    uint32_t size = 4;

    TrackedVehicle* tracked_vehicles = new TrackedVehicle[size]{
        TrackedVehicle(501,80.0,60.0),
        TrackedVehicle(502,78.0,45.0),
        TrackedVehicle(503,85.0,100.0),
        TrackedVehicle(504,76.0,40.0)
    };

    // Find the lead vehicle
    const TrackedVehicle* lead_vehicle = nullptr; 
    findLeadVehicle(tracked_vehicles,size, lead_vehicle);

    //Printing all vehicles
    std::cout<<"\nFollowing are the details of all vehicles: "<<std::endl;
    for(int i=0;i<size;i++){
        printTrackedVehicle(tracked_vehicles[i]);
    }

    // Printing details of lead vehicle 
    std::cout<<"\nFollowing are the details of lead vehicles: "<<std::endl;
    printLeadVehicle(lead_vehicle);

    // Printing minimum recorded distance
    std::cout<<"\nMinimum Recorded Distance: "<<tracked_vehicles[0].getMinRecordedDistance()<<std::endl;

    // Printing total vehicle count
    std::cout<<"\nTotal vehicle Count: "<<tracked_vehicles[0].getVehicleCount()<<std::endl;

    // Deallocating the heap memory .
    delete[] tracked_vehicles;
    tracked_vehicles = nullptr;
    lead_vehicle = nullptr;

    return 0;
}