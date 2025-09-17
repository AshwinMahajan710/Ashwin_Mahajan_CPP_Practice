#include<iostream>
#include<limits>

class DetectedObject{
    private:
        uint32_t object_id;
        float rel_speed;
        float distance;

    public:

        // Valuers intialization
        DetectedObject(uint32_t object_id=0,float rel_speed=0.0,float distance=0.0){
            this->object_id = object_id;
            this->distance = distance;
            this->rel_speed = rel_speed;
        }
        
        // Getters
        uint32_t getId() const { return object_id; }
        float getRelSpeed() const { return rel_speed; }
        float getDistance() const { return distance; }

        // Display detail of object
        void display() const{
            std::cout<<"Object ID: "<<object_id<<"\n Relative Speed: "<<rel_speed<<"\n Distance: "<<distance<<std::endl;
        }

        // Finding the object is risky or not
        bool isHigherRisk(const DetectedObject& other){
            if( (this->distance < other.distance) && (this->rel_speed > other.rel_speed)) return true;
            else return false;
        }

        // Values update on copied object
        void updateValuesByValue(DetectedObject obj){
            obj.rel_speed += 2;
            obj.distance -= 5; 
            std::cout<<"\n Copy has been Updated... following are the object params"<<std::endl;
            // here destructor gets activated and deletes copy 
        }

        // Values update by reference on original object
        void updateValuesByReference(DetectedObject &obj){
            obj.rel_speed += 2;
            obj.distance -= 5; 
            std::cout<<"\n Original object has been updated.. following are the object params"<<std::endl;
        }

        ~DetectedObject(){
            std::cout<<"\n Object with Object ID: "<<object_id<<" has been deleted..."<<std::endl;
        }
};

// Finding risky object global function  
void findHighestRiskObject(DetectedObject* arr, uint32_t size, const DetectedObject*& riskObj){
    riskObj = &arr[0]; 
    bool isFound = false; // for checking high risk object found or not
    for(int i=1;i<size;i++){ // compare risky object wrt first object
        if(arr[i].isHigherRisk(*riskObj)){
            isFound = true;
            riskObj = &arr[i];
            return;
        }   
    }
    if(!isFound){
        riskObj = nullptr;
        std::cout<<"\n No risky object found..."<<std::endl;
    }
}

// Printing details of detected object
void printDetectedObject(const DetectedObject& obj){
    obj.display();
}

// printing Highest Risk object if found
void printHighestRiskObject(const DetectedObject* obj){
    if(obj == nullptr) std::cout<<"No risky object found...."<<std::endl;
    else obj->display();
}

// Update values by object
void updateObjectValuesByValueGlobal(DetectedObject obj){
    obj.updateValuesByValue(obj);
}

// Update values by reference
void updateObjectValuesByReferenceGlobal(DetectedObject &obj){
    obj.updateValuesByReference(obj);
}

int main(){
    // Initialize values
    uint32_t size = 3;
    DetectedObject * detectetd_object = new DetectedObject[3]{
        DetectedObject(701,15,55),
        DetectedObject(702,20,35),
        DetectedObject(703,10,30)
    };

    // Calling the update by VALUE global function and print the results
    updateObjectValuesByValueGlobal(detectetd_object[0]);
    printDetectedObject(detectetd_object[0]);

    // Calling the update by REFERENCE global function and print the results
    updateObjectValuesByReferenceGlobal(detectetd_object[0]);
    printDetectedObject(detectetd_object[0]);

    // Finding and printing highest risk object
    const DetectedObject* risky_object = nullptr;

    std::cout<<"\n The risky object is: "<<std::endl;
    findHighestRiskObject(detectetd_object,size,risky_object);
    printHighestRiskObject(risky_object);

    // delete heap allocated namic memeory
    delete[] detectetd_object;

}