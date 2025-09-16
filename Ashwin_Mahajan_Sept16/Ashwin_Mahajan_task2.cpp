#include<iostream>

// class ObjectDistance 
class ObjectDistance{
    private:
        float radar_distance;
        float camera_distance; 
        ObjectDistance* obj;

    public:
        
        // Constructor
        ObjectDistance(float radar_distance,float camera_distance){
            this->radar_distance = radar_distance;
            this->camera_distance = camera_distance;
        }

        // Getter
        float getRadarDistance() const{return radar_distance;}
        float getCameraDistance() const{return camera_distance;}

        // Setters
        void setRadarDistance(float val){
            radar_distance += val;
        }
        void setCameraDistance(float val){
            camera_distance += val;
        }

        // Just adjusting distances by values
        void adjustDistancesByValue(ObjectDistance obj){
            obj.camera_distance = obj.camera_distance + 5.0;
            obj.radar_distance = obj.radar_distance + 5.0;
            std::cout<<"Local copy of the objects... Values:--> Camera Distance: "<<obj.camera_distance<<" Radar Distance: "<<obj.radar_distance<<std::endl;
        }

        // Adjusting distance by values
        void adjustDistancesByReference(ObjectDistance& obj){
            obj.camera_distance = obj.camera_distance + 5.0;
            obj.radar_distance = obj.radar_distance + 5.0;
        }

        // Verifying deletion of dynamically allocated object
        ~ObjectDistance(){
            std::cout<<"Object has been successfully deleted..."<<std::endl;
        }
};         

// Global function to print the details
void printObjectDistance(const ObjectDistance& obj){
    std::cout<<"Camera Distance: "<<obj.getCameraDistance()<<std::endl;
    std::cout<<"Radar Distance: "<<obj.getRadarDistance()<<std::endl;
}

// Global function to dynamically create object on heap
ObjectDistance* createObjectDistanceOnHeap(float radar, float camera){
    return (new ObjectDistance(radar,camera));
}

int main(){ 

    float radar = 35.5, camera = 34.8; // initialize values for radar and camera
    ObjectDistance* newObj =createObjectDistanceOnHeap(radar, camera); // dynamically allocating objects on heap

    newObj->adjustDistancesByValue(*newObj);// changing object values by passing object by reference
    printObjectDistance(*newObj);// checking the changed values
    newObj->adjustDistancesByReference(*newObj); // changing object values by passing object by value
    printObjectDistance(*newObj);// checking the changed values

    // deleting the dynamically allocated object
    delete newObj;
    newObj = nullptr;

    return 0;
}