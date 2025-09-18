#include<iostream>

class EgoVehicleData{
    private:
        int num_lanes;
        float* lane_positions;
        float* sensor_confidence;
    
    public:
        //Constructor -> Default
        EgoVehicleData(){
            this->num_lanes = 0;
            this->lane_positions = nullptr;
            this->sensor_confidence = nullptr;
        }

        // Constructor -> parameterized
        EgoVehicleData(int num_lanes,float* lane_positions,float* sensor_confidence){
            this->num_lanes = num_lanes;
            this->lane_positions = new float[num_lanes];
            this->sensor_confidence = new float[num_lanes];

            // assigning values
            for(int i=0;i<num_lanes;i++){ this->lane_positions[i] = lane_positions[i]; }
            for(int i=0;i<num_lanes;i++){ this->sensor_confidence[i] = sensor_confidence[i]; }
        }

        //Constructor -> Copy constructor
        EgoVehicleData(const EgoVehicleData& other){
            this->num_lanes = other.num_lanes;
            this->lane_positions = new float[num_lanes];
            this->sensor_confidence = new float[num_lanes];

            // assigning values
            for(int i=0;i<num_lanes;i++){ this->lane_positions[i] = other.lane_positions[i]; }
            for(int i=0;i<num_lanes;i++){ this->sensor_confidence[i] = other.sensor_confidence[i]; }
        }

        //Getters
        int getNumLanes() const{return num_lanes;}
        float* getLanePositions() const{return lane_positions;} 
        float* getSensorConfidence() const{return sensor_confidence;}

        // Getting averege lane position value
        float getAverageLanePosition() const{
            if (num_lanes == 0) return 0.0f;
            float sumOfLanePosition = 0.0;
            for(int i=0; i<num_lanes;i++){
                sumOfLanePosition += lane_positions[i];
            }
            return sumOfLanePosition/num_lanes;
        }
        
        // This function will return maximum confidence throghout sensor array
        float totalSensorConfidence() const{
            float TotalConfidence = 0.0;
            for(int i=0; i<num_lanes;i++){
                TotalConfidence += sensor_confidence[i];
            }
            return TotalConfidence;
        }

        // updating sensor confidence by multiplying with the particular factor
        void updateSensorConfidence(float factor){
            for (int i = 0; i < num_lanes; i++) {sensor_confidence[i] *= factor; }
        }

        // Destructor
        ~EgoVehicleData(){
        delete[] lane_positions;
        delete[] sensor_confidence;
        }
};  

// Pointing reference of highest to sensor with highest sum of sensor scores
void findHighestConfidenceVehicle(EgoVehicleData* array, int size, const EgoVehicleData*& highest){
    if(array == nullptr){
        std::cout<<"Array is already empty.."<<std::endl;
        return ; // handle if array is empty
    }
        
    highest = &array[0];
    for(int i=0;i<size;i++){
        if(array[i].totalSensorConfidence() > highest->totalSensorConfidence()) 
            highest = &array[i];
    }
}

// printing the information of vehicle with highest confidence score
void printHighestConfidenceVehicle(const EgoVehicleData* vehicle){

    float* lane_positions = vehicle->getLanePositions();
    float* sensor_confidence = vehicle->getSensorConfidence();
    std::cout<<"\nHighest Confidence Vehicle data: "<<std::endl;
    std::cout<<"Num of lanes: "<<vehicle->getNumLanes()<<std::endl;
    std::cout<<"Lanes Positions:";
    for (int i = 0; i < vehicle->getNumLanes(); i++){std::cout<<" "<<lane_positions[i];}
    std::cout<<"\nSensor Confidence scores:";
    for (int i = 0; i < vehicle->getNumLanes(); i++){std::cout<<" "<<sensor_confidence[i];}
    std::cout<<"\nTotal Confidence Score: "<<vehicle->totalSensorConfidence()<<std::endl;
    std::cout<<std::endl;
}

// Printing the information of ego vehicle
void printEgoVehicleData(const EgoVehicleData& data){
    std::cout<<"\n Ego Vehicle data: "<<std::endl;
    std::cout<<"Num of lanes: "<<data.getNumLanes()<<std::endl;
    std::cout<<"Lanes Positions:";
    for (int i = 0; i < data.getNumLanes(); i++){std::cout<<" "<<data.getLanePositions()[i];}
    std::cout<<"\nSensor Confidence scores:";
    for (int i = 0; i < data.getNumLanes(); i++){std::cout<<" "<<data.getSensorConfidence()[i];}
}

int main(){ 

    // intialize variables and create objects
    int totalEgoVehicles = 3; 

    int num_lanes_1 = 3;
    float lane_positions_1[num_lanes_1]{3.2f, 3.0f, 3.4f};
    float sensor_confidence_1[num_lanes_1]{0.95f, 0.97f, 0.93f};

    int num_lanes_2= 3;
    float lane_positions_2[num_lanes_2]{2.9f, 2.8f, 3.1f};
    float sensor_confidence_2[num_lanes_2]{0.92f, 0.90f, 0.88f};

    int num_lanes_3 = 3;
    float lane_positions_3[num_lanes_3]{3.4f, 3.5f, 3.6f};
    float sensor_confidence_3[num_lanes_3]{0.99f, 0.98f, 0.97f};

    EgoVehicleData* array = new EgoVehicleData[totalEgoVehicles]{
        EgoVehicleData(num_lanes_1,lane_positions_1,sensor_confidence_1),
        EgoVehicleData(num_lanes_2,lane_positions_2,sensor_confidence_2),
        EgoVehicleData(num_lanes_3,lane_positions_3,sensor_confidence_3)
    };

    // Adjusting confidence score of each object by using different factors
    array[0].updateSensorConfidence(0.5);
    array[1].updateSensorConfidence(0.6);
    array[2].updateSensorConfidence(0.7);

    // Finding highest confidence vehicle
    const EgoVehicleData* highest = nullptr;
    findHighestConfidenceVehicle(array,totalEgoVehicles,highest);

    // Printing highest confidence vehicle
    printHighestConfidenceVehicle(highest);

    // To free dynamically allocated memory
    delete[] array;
}