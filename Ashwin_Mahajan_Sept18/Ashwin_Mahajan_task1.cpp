#include<iostream>

class VehicleStatus{
    private:
        int num_wheels;
        float* wheel_speed ;
        int num_temps;
        float* engine_temp;

    public:
        // Constructor -> Default
        VehicleStatus(){
            this->num_wheels = 0;
            this->num_temps = 0;
            this->engine_temp = nullptr;
            this->wheel_speed = nullptr;
        }
    
        // Constructor -> parameterized
        VehicleStatus(int num_wheels, float* wheel_speed ,int num_temps,float* engine_temp){
            this->num_temps = num_temps;
            this->num_wheels = num_wheels;

            // Allocating dynamic memory for storing values
            this->wheel_speed = new float[num_wheels];
            this->engine_temp = new float[num_temps];

            // assigning values
            for(int i=0;i<num_wheels;i++){ this->wheel_speed[i] = wheel_speed[i]; }
            for(int i=0;i<num_wheels;i++){ this->engine_temp[i] = engine_temp[i]; }
        }       

        // Getters
        int getNumWheels() const{return num_wheels;}
        float* getWheelSpeed() const{return wheel_speed;} 
        int getNumTemps() const{return num_temps;}
        float* getEngineTemp() const{return engine_temp;}

        // Function to return average wheel speed
        float averageWheelSpeed() const{
            float totalWheelSpeed = 0.0;
            for(int i=0; i<num_wheels;i++){
                totalWheelSpeed += wheel_speed[i];
            }
            return totalWheelSpeed/num_wheels;
        }

        // Function to return maximum engine temperature
        float maxEngineTemp() const{
            float MaxTemp = 0.0;
            for(int i=0; i<num_temps;i++){
                MaxTemp = MaxTemp > engine_temp[i] ? MaxTemp : engine_temp[i];
            }
            return MaxTemp;
        }

        // Return max wheel speed
        float maxWheelSpeed() const{
            float MaxSpeed = 0.0;
            for(int i=0; i<num_wheels;i++){
                MaxSpeed = MaxSpeed > wheel_speed[i] ? MaxSpeed : wheel_speed[i];
            }
            return MaxSpeed;
        }

        // This method returns true if max wheel speed of this object greater than other object 
        bool isWheelSpeedHigher(const VehicleStatus& other) const{
            return (this->maxWheelSpeed() > other.maxWheelSpeed());
        }

        // Destructor to free up dynamic allocated memory 
        ~VehicleStatus(){
            delete[] wheel_speed;
            delete[] engine_temp;
        }
};

// Global Function: Printing vehicle status
void printVehicleStatus(const VehicleStatus& vs){

    // getting the parameters for object 
    int num_wheels = vs.getNumWheels();
    int num_temps = vs.getNumTemps();
    float* vehicle_speeds = vs.getWheelSpeed();
    float* engine_temps = vs.getEngineTemp();

    // Printing vehicle status
    std::cout<<"Speed of wheel:"; 
    for (int i = 0; i < num_wheels; i++) { std::cout<<" "<<vehicle_speeds[i]; }
    std::cout<<"\nEngine Temperature:";
    for (int i = 0; i < num_temps; i++) { std::cout<<" "<<engine_temps[i]; }
    std::cout<<std::endl;
}

// Global Function: Compare two objects max wheel speed
bool compareWheelSpeedGlobal(const VehicleStatus& vs1, const VehicleStatus& vs2){
    return vs1.isWheelSpeedHigher(vs2);
}

int main(){
 
    // Initializing first object and its params
    int num_wheels_1 = 4;
    float wheel_speeds_1[num_wheels_1]{55.5f, 56.6f, 57.2f, 55.9f};
    int num_temp_1 = 2;
    float engine_temps_1[num_temp_1]{90.5f, 88.9f};
    VehicleStatus v1(num_wheels_1,wheel_speeds_1, num_temp_1, engine_temps_1); // creating first object

    // Initializing second object and its params
    int num_wheels_2 = 4;
    float wheel_speeds_2[num_wheels_1]{50.0f, 51.2f, 49.8f, 50.4f};
    int num_temp_2 = 2;
    float engine_temps_2[num_temp_1]{92.0f, 89.5f};
    VehicleStatus v2(num_wheels_2,wheel_speeds_2, num_temp_2, engine_temps_2); // creating second object

    // Printing the status of both object using global function
    std::cout<<"\nStatus of object v1: "<<std::endl;
    printVehicleStatus(v1);
    std::cout<<"\n Status of object v2: "<<std::endl;
    printVehicleStatus(v2);

    // Comparing max speeds --> object's method
    std::cout<<"\nWheel Speed Comparison(object call): ";
    v1.isWheelSpeedHigher(v2) ? std::cout<<"Max wheel speed of object v1("<<v1.maxWheelSpeed()<<") is greater than max wheel speed of object v2("<<v2.maxWheelSpeed()<<")..."<<std::endl : std::cout<<"Wheel speed of object v2("<<v2.maxWheelSpeed()<<") is greater than v1("<<v1.maxWheelSpeed()<<")...";

    // Comparing max speeds --> global method
    std::cout<<"\nWheel Speed Comparison(global call): ";
    v1.isWheelSpeedHigher(v2) ? std::cout<<"Wheel speed of object v1("<<v1.maxWheelSpeed()<<") is greater than v2("<<v2.maxWheelSpeed()<<")..."<<std::endl : std::cout<<"\nWheel speed of object v2("<<v2.maxWheelSpeed()<<") is greater than v1("<<v1.maxWheelSpeed()<<")...";

    // Dynamic memory will be freed as destructor of class do it automatically
    return 0;
}