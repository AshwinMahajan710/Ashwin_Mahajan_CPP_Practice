#include<iostream>

// sensortypes using enum
enum class SensorType{
    LIDAR,
    RADAR,
    CAMERA
};

// function for getting string of type of sensor
const char* sensorTypeToString(SensorType t){
    if(t == SensorType::CAMERA) return "CAMERA";
    else if(t == SensorType::RADAR) return "RADAR";
    else return "LIDAR";
}

// SensorArray class to store sensor information
class SensorArray{
    private:
        int sensor_id;
        SensorType type;
        double* temperature_readings;
        int num_readings;
        static double global_max_temperature;
    
        public:

            // Parameterized constructor
            SensorArray(int sensor_id, SensorType type,double* temperature_readings,int num_readings){
                this->sensor_id = sensor_id;
                this->num_readings = num_readings;
                this->type = type;
                this->temperature_readings = new double[num_readings];
                for(int i=0;i<num_readings;i++){
                    this->temperature_readings[i] = temperature_readings[i];
                    if(temperature_readings[i]>global_max_temperature) global_max_temperature = temperature_readings[i];
                }
            }

            // Default constructor
            SensorArray(){
                sensor_id = 0;
                type = SensorType::LIDAR;
                temperature_readings = nullptr;
                num_readings = 0;
            }

            // returning the max temperature
            double getMaxTemperature() const{
                // we cannot use static variable as it stores max temperature ever recorded but we only want recent highest temeperature
                double maxTemp = temperature_readings[0];
                for(int i=1;i<num_readings;i++){
                    if(maxTemp<temperature_readings[i]){
                        maxTemp = temperature_readings[i];
                    }
                }
                return maxTemp;
            }

            // Printing sensor information
            void printSensorInfo() const{
                std::cout<<"Sensor ID: "<<sensor_id<<"\nType: "<<sensorTypeToString(type)<<"\nMaximum Temperature: "<<getMaxTemperature()<<std::endl<<std::endl;
            }

            // return highest temperature ever recorded
            static double getGlobalMaxTemperature(){
                return global_max_temperature;
            }

            // Destructor
            ~ SensorArray(){
                delete[] temperature_readings;
            }
    
};

// Global Fuction to print snesor info
void printSensor(const SensorArray& s){
    s.printSensorInfo();
}

// Printing all sensor information
void printAllSensors(const SensorArray* arr, int size){
    for(int i=0;i<size;i++){
        arr[i].printSensorInfo();
    }
}

// initialize static variable globalMaxTemperature
double SensorArray::global_max_temperature = 0.0;

int main(){

    // Initialization
    int size = 3;
    double lidar_readings[3] = {35.5, 36.1, 34.9};
    double radar_readings[3] = {39.0, 38.7, 39.3};
    double camera_readings[3] = {30.2, 31.0, 30.5};
    int num_sensors = 3;
    SensorArray* sensor_array = new SensorArray[num_sensors]{
        SensorArray(801, SensorType::LIDAR, lidar_readings, 3),  // lidar_reading = shortform to &lidar_reading[0]
        SensorArray(802, SensorType::RADAR, radar_readings, 3),
        SensorArray(803, SensorType::CAMERA, camera_readings, 3)
    };

    // Printing all sensors information
    std::cout<<"\n Below is information of all sensors: \n"<<std::endl;
    printAllSensors(sensor_array, size);

    // printing global max temperature
    std::cout<<"The global max temeperature of all sensors is: "<<SensorArray::getGlobalMaxTemperature()<<std::endl;

    // Free all allocated memory
    delete[] sensor_array;

    return 0;
}