// Main learning: 
// 1. Use of the unsigned variables ---> if still try to store -ve value ex. -5 then 2^32 - 5 = 4294967291 this is the value that variable stores
// 2. Type Qualifiers like 'const' only allowed to member functions 
// 3. const Pedestrian* &closest --> value of object to which pointer pointing to cannot change ,Pedestrian* const & closest can chaneg the values of object pointer points to but cannot change pointer itslef


#include<iostream>
#include<limits>

class Pedestrian{

    private:
        uint32_t pedestrian_id;
        float distance_from_vehicle; 

    public:
        // Constructor -- Parameterized
        Pedestrian(uint32_t id, float distance){
            this->pedestrian_id = id;
            this->distance_from_vehicle = distance;
        }

        //Constructor -- Default
        Pedestrian(){
            this->pedestrian_id = 0;
            this->distance_from_vehicle = std::numeric_limits<float>::max();
        }

        // getter for distance and pedestrian_id
        float getDistanceFromVehicle() const{return this->distance_from_vehicle;}
        uint32_t getPedestrianId() const{return this->pedestrian_id;}

        // Update distance wrt new disance
        void updateDistance(float newDistance){
            this->distance_from_vehicle = newDistance;
        }

        // Update Id wrt new ID
        void updatePedestrianID(uint32_t id){
            this->pedestrian_id = id;
        }
};

 // Finding the closest pedestrian
void findClosestPedestrian(Pedestrian* array, uint32_t size, const Pedestrian*& closest){        
    closest = &array[0];
    for (int i=0;i<size;i++){
        if(array[i].getDistanceFromVehicle() < closest->getDistanceFromVehicle()){
            closest = &array[i];
        }
    }
}

void printPedestrianInfo(const Pedestrian& ped){
    std::cout<<"Pedestrian Info: "<<"Pedestrian ID: "<<ped.getPedestrianId()<<"   Pedestrian Distance: "<<ped.getDistanceFromVehicle()<<std::endl;
}

void printClosestPedestrian(const Pedestrian* closest){
    std::cout<<"Closest Pedestrian Info: "<<"Pedestrian ID: "<<closest->getPedestrianId()<<"   Pedestrian Distance: "<<closest->getDistanceFromVehicle()<<std::endl;
}

int main(){

    // Creating the array of dynamically allocated objects
    uint32_t size = 3;
    Pedestrian* array = new Pedestrian[3]{
            Pedestrian(101,12.4),
            Pedestrian(102,8.7),
            Pedestrian(103,15.1)
        };

    //Finding the closest Pedestrian using detection function;
    const Pedestrian* closest_Pedestrian = nullptr;
    findClosestPedestrian(array,size,closest_Pedestrian);

    // Printing the details of all Pedestrian
    std::cout<<"All Pedestrians: "<<std::endl;
    for (int i=0;i<size;i++){
        printPedestrianInfo(array[i]);
    }

    // Print closest pedestrian
    std::cout<<"Closest Pedestrians: "<<std::endl;
    printClosestPedestrian(closest_Pedestrian);
    
    // delete allocated memory
    delete[] array;
    array = nullptr;
    return 0;
}
