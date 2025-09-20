// Remainder 1 :--> Parameterized constructor car (dynamic arrays not intialized)

#include<iostream>
#include<vector>
#include<utility> // for std::swap
#include<algorithm> // for std::sort

// Service Record class --> Maintain Service Records
class ServiceRecord{
    private:
        std::string date_; // Format YYYY-MM-DD: 
        int mileage_; 
        std::string description_;
    
    public:

        // Constructor --> Default (Creates an empty record)
        ServiceRecord(){
            date_= "";
            mileage_ = 0;
            description_="";
        }

        // Constructor --> parameterized
        ServiceRecord(const std::string& date, int mileage, const std::string& description){
            this->date_ = date;
            this->mileage_ = (mileage>=0) ? mileage : 0; // Validate mileage
            this->description_ = description;
        }

        // Constructor --> Copy
        ServiceRecord(const ServiceRecord& other){
            this->date_ = other.date_;
            this->description_ = other.description_;
            this->mileage_ = other.mileage_;
        }

        // Overloaded Operator --> "=" (Changes values of the current "this" object using other object)
        ServiceRecord& operator=(const ServiceRecord& other){
            if(&other != this){
                this->date_ = other.date_;
                this->description_ = other.description_;
                this->mileage_ = other.mileage_;
            }
            return *this;
        }

        // Getters
        const std::string& getDate() const{return date_;}
        int getMileage() const {return mileage_;}
        const std::string& getDescription() const{return description_;}

        // Utility function --> Printing the details of particular service record
        void print() const{
            std::cout<<"\nService Date: "<<date_;
            std::cout<<"  Mileage of Car: "<<mileage_;
            std::cout<<"  Description of Service: "<<description_<<std::endl;
        }
};

// Class Car --> Maintain Car Details
class Car{
    private:
        std::string vin_; // Vehicle Identification Number --> Unique
        std::string make_; // Manufacturer name
        std::string model_; // Model name
        double price_; // Current Market Price --> Non-Negative (>=0)
        ServiceRecord* serviceHistory_; // Dynamic array to store service records
        size_t serviceCount_; // No of valid service records stored
        size_t serviceCap_; // Allocated capacity of service history array 
        int* damageCodes_; // Dynamic array that stores “damage codes”
        size_t damageCount_; // Number of valid damage-code entries
        size_t damageCap_; // Allocated capacity of damageCodes_.
        static size_t totalCars_; // Counter of live car objects

        // method to increase service history size
        void reserveService(size_t newCap){
            ServiceRecord* newService = new ServiceRecord[newCap];
            for(size_t i=0;i<serviceCount_;i++){
                newService[i] = serviceHistory_[i];
            }
            delete[] serviceHistory_;
            serviceHistory_ = newService;
            serviceCap_ = newCap;
        }

        // Method to increase damagecode capacity size
        void reserveDamage(size_t newCap){
            int* newDamageCodes = new int[newCap];
            for (size_t i=0;i<damageCount_;i++){
                newDamageCodes[i] = damageCodes_[i];
            } 
            delete[] damageCodes_;
            damageCodes_ = newDamageCodes;
            damageCap_ = newCap;
        }
    
    public:

        // Constructor --> Default 
        Car(){
            vin_ = "";
            make_ = "";
            model_ = "";
            price_ = 0;
            serviceHistory_ = nullptr;
            serviceCount_ = 0;
            serviceCap_ = 0;
            damageCodes_ = nullptr;
            damageCap_ = 0;
            damageCount_ = 0;
            totalCars_++; // Increment total cars
        }

        // Constructor --> Parameterized
        Car(const std::string& vin, const std::string& make, const std::string& model, double price){
            this->vin_ = vin;
            this->make_ = make;
            this->model_ = model;
            this->price_ = (price>=0) ? price : 0; // Validate price
            serviceHistory_ = nullptr;
            serviceCount_ = 0;
            serviceCap_ = 0;
            damageCodes_ = nullptr;
            damageCap_ = 0;
            damageCount_ = 0;
            totalCars_++; // Increment total cars
        }
 
        // Constructor --> Copy Constructor
        Car(const Car& other){
            this->vin_ = other.vin_;
            this->make_ = other.make_;
            this->model_ = other.model_;
            this->price_ = other.price_; // Validate price
            this->damageCount_ = other.damageCount_;
            this->damageCap_ = other.damageCap_;
            this->damageCodes_ = new int[damageCap_];
            for (size_t i = 0; i < damageCount_; i++) { this->damageCodes_[i] = other.damageCodes_[i]; } // Assign damagecode of other object to this
            this->serviceCount_ = other.serviceCount_;
            this->serviceCap_ = other.serviceCap_;
            this->serviceHistory_ = new ServiceRecord[serviceCap_];
            for (size_t i = 0; i < serviceCount_; i++) { this->serviceHistory_[i] = other.serviceHistory_[i]; } // Assign damagecode of other object to this
            totalCars_++; // Increment total cars
        }

        //copy-and-swap implementation (strong exception safety) --> takes parameter by value
        // More understanding --> "IMP Concepts/ 1_Copy_and_Swap_idom.txt"
        Car& operator=(Car other){
            swap(*this,other);
            return *this;
        }

    
        friend void swap(Car& lhs, Car& rhs) noexcept{
            using std::swap;
            swap(lhs.vin_ , rhs.vin_);
            swap(lhs.make_ , rhs.make_);
            swap(lhs.model_ , rhs.model_);
            swap(lhs.price_ , rhs.price_);
            swap(lhs.damageCount_ , rhs.damageCount_);
            swap(lhs.damageCap_ , rhs.damageCap_);
            swap(lhs.damageCodes_ , rhs.damageCodes_);
            swap(lhs.serviceCount_ , rhs.serviceCount_);
            swap(lhs.serviceCap_ , rhs.serviceCap_);
            swap(lhs.serviceHistory_ , rhs.serviceHistory_);
        }

        // Destructor
        ~Car(){
            delete[] serviceHistory_; // free space for dynamically allocated memory
            delete[] damageCodes_; // Free space of dynamically allocated memory
            totalCars_--; // decrement totalcars 
        }   

        // Static accessor
        static size_t getTotalCars() {return totalCars_;}
        
        // Setters
        void setVIN(const std::string& vin){this->vin_ = vin;}
        void setMake(const std::string& make){this->make_ = make;}
        void setModel(const std::string& model){this->model_ = model;}
        void setPrice(double price) {price>=0 ? this->price_ = price : throw std::invalid_argument("Price can never be -ve");}

        // Getters
        const std::string& getVIN() const{return vin_;}
        const std::string& getMake() const{return make_;}
        const std::string& getModel() const{return model_;}
        double getPrice() const{return price_;}
        size_t getServiceCount() const{return serviceCount_;}
        size_t getDamageCount() const{return damageCount_;}
        const ServiceRecord* getServiceHistory() const{return serviceHistory_;}
        const int* getDamageCodes() const{return damageCodes_;}

        // Adding service
        void addService(const ServiceRecord& rec){
            if(serviceCap_ == serviceCount_){
                size_t newCap = (serviceCap_ == 0) ? 1 : serviceCap_ * 2; // assign space more larger
                reserveService(newCap);
            }
            serviceHistory_[serviceCount_++] = rec; // Increment the service count as well as assign the object
        }

        // Same with adding damage
        void addDamageCode(int code){
            if(damageCount_ == damageCap_){
                int newCap = (damageCount_==0) ? 1 : (damageCap_*2);
                reserveDamage(newCap);
            }
            damageCodes_[damageCount_++] = code;
        }

        // Print the information in readable format
        void printInfo() const{
            std::cout<<"Vehicle VIN: "<<vin_<<std::endl;
            std::cout<<"Vehcle Manufacturer: "<<make_<<std::endl;
            std::cout<<"Vehcle Model: "<<model_<<std::endl;
            std::cout<<"Vehcle Price: "<<price_<<std::endl;
            std::cout<<"No of Service Records: "<<serviceCount_<<std::endl;
            if(serviceCount_>0) {
                for (size_t i=0;i<serviceCount_;i++)
                {   
                    std::cout<<"Service Records "<<i+1<<": ";
                    serviceHistory_[i].print();
                }
            }
            std::cout<<"No of Damage Codes: "<<damageCount_<<std::endl;
            if(damageCount_>0) {
                std::cout<<"Damage Codes: ";
                for (size_t i=0;i<damageCount_;i++)
                {
                    std::cout<<" "<<damageCodes_[i];
                }
                std::cout<<std::endl;
            }
        }
};

// Global Function --> get average price of all cars
double averagePrice(const Car* arr, size_t n){
    if(n==0) return 0.0;
    double sum = 0.0;
    for(size_t i=0;i<n;i++){
        sum += arr[i].getPrice();
    }
    return sum/n;
}

// Global function - compare by price ----> used with std::sort for ascending sorting
bool compareByPriceAsc(const Car& a, const Car& b){
    return a.getPrice() < b.getPrice();
}

// Global function - compare by price ----> used with std::sort for descending sorting
bool compareByPriceDesc(const Car& a, const Car& b){
    return a.getPrice() > b.getPrice();
}

// Global Function - Compare the VIN --> return true if same
bool areCarsEqual(const Car& a, const Car& b){
    return (a.getVIN() == b.getVIN());
}

// Global Function - get the pointer which points to the car with greatest price
const Car* maxPriceCar(const Car* arr, size_t n){
    if(n==0) return nullptr;
    const Car* maxPriceCar = &arr[0];
    for(size_t i=1;i<n;i++){
        if(maxPriceCar->getPrice() < arr[i].getPrice()){
            maxPriceCar = &arr[i];
        }
    }
    return maxPriceCar;
}

// Global function - get the pointer which points to matching vin
const Car* findCarByVIN(const Car* arr, size_t n, const std::string& vin){
    for(size_t i=0;i<n;i++){
        if(arr[i].getVIN() == vin){ return &arr[i];}
    }
    return nullptr; // No car with similar vin found
}

// Global Function: Count cars containing a specific damage code
size_t countCarsWithDamage(const Car* arr, size_t n, int code){
    size_t count = 0;
    for(size_t i=0;i<n;i++){
        size_t dmgCount = arr[i].getDamageCount();
        const int* dmgCodes = arr[i].getDamageCodes(); 
        for(size_t j=0;j<dmgCount;j++){
            if(dmgCodes[j] == code){
                count++;
                break;
            }
        }
    }
    return count;
}

// Global Function: Swpping two objects 
void swapCars(Car& a, Car&b){
    swap(a,b);
}

// Additional function to print damagecodes
void printDamageCodes(const Car& car, const std::string& name){
    std::cout << "\nDamage codes of " << name << ": ";
    for(size_t i=0; i<car.getDamageCount(); i++){
        std::cout << " " << car.getDamageCodes()[i];
    }
}

//Helper function to assign damagecodes and servicerecord array to car object
void bindDetails(Car& car, const int* dmgCodes, size_t damageCount, const ServiceRecord* records, size_t recordCount){
    for(size_t i=0;i<damageCount;i++){
        car.addDamageCode(dmgCodes[i]);
    }
    for(size_t i=0;i<recordCount;i++){
        car.addService(records[i]);
    }
}

// Initialize the static variable
size_t Car::totalCars_ = 0;

int main(){

    // STEP 1:
    // Current total cars
    std::cout<<"Total cars in record count: "<<Car::getTotalCars()<<std::endl;

    // STEP 2:
    // Adding a car using default constructor and check car increment and also Car info
    Car c1;
    std::cout<<"\nTotal cars in record count: "<<Car::getTotalCars()<<std::endl;
    std::cout<<"\nCar Info of object assigned via default constructor: "<<std::endl;
    c1.printInfo();

    // STEP 3:
    // Adding a car via parameterized constructor and verify correct operation
    Car c2("HGCM","Honda","Accord",999.99);
    std::cout<<"\nTotal cars in record count: "<<Car::getTotalCars()<<std::endl;
    std::cout<<"\nCar Info of object assigned via Parameterized constructor: "<<std::endl;
    c2.printInfo();

    // STEP 4:
    // Adding the damagecodes and then see them
    c2.addDamageCode(101);
    c2.addDamageCode(102);
    c2.addDamageCode(103);
    std::cout<<"\nCar information for Car object c2: "<<std::endl;
    c2.printInfo();

    // STEP 5:
    //Doing same thing with service records
    const ServiceRecord sr1("2025-09-01",10,"Highly Maintained");
    const ServiceRecord sr2("2024-02-06",30,"Red Colour");
    c2.addService(sr1);
    c2.addService(sr2);
    std::cout<<"\nCar information for Car object c2: "<<std::endl;
    c2.printInfo();

    // STEP 6:
    // Creating the object using the copy constructor
    Car c3(c2);
    std::cout<<"\nTotal cars in record count after creating c3 using c2: "<<Car::getTotalCars()<<std::endl;

    // STEP 6a:
    // Displaying damage code of array and then alter c2 and then again display them 
    printDamageCodes(c2,"c2");
    printDamageCodes(c3,"c3");
    c3.addDamageCode(404); // Add additional damage code in c3 object
    printDamageCodes(c2,"c2");
    printDamageCodes(c3,"c3");
    std::cout<<std::endl;

    // STEP 6b:
    // Getting service count on both original and copy
    std::cout<<"\nThe service count for object c2: "<<c2.getServiceCount()<<std::endl;
    std::cout<<"The service count for object c3: "<<c3.getServiceCount()<<std::endl;

    // STEP 7:
    // Creating object using default constructor and then and then assign c3 to c4
    Car cAssign;
    cAssign = c3;
    std::cout<<"\n New object c4: "<<std::endl;
    cAssign.printInfo();
    
    // STEP 7a:
    // Add a damage code so that we can verify that it is deep copy
    cAssign.addDamageCode(405);
    std::cout<<"\nObject c3: "<<std::endl;
    c3.printInfo();
    std::cout<<"\nObject cAssign: "<<std::endl;
    cAssign.printInfo();

    // STEP 8:
    // Allocating a dynamic array for 3 car objects
    Car* arr = new Car[3];
    std::cout<<"\nNow Total car count: "<<Car::getTotalCars()<<std::endl;

    // Step 8a:
    // Assigning each element of heap with different variables
    arr[0] = Car("JHAKA","cAcura","Acura TLX",27999.49);
    arr[1] = Car("5YJ3E","Tesla","Model 3",39999.00);
    arr[2] = Car("WBA4","BMW","3 Series",34999.99);

    // Step 8b:
    // Assign each object in list with damagecodes and servicerecords
    size_t codeCount1 = 2;
    size_t codeCount2 = 3;
    size_t codeCount3 = 1;
    const int codes1[] = {101,102};
    const int codes2[] = {101,104, 103};
    const int codes3[] = {101};
    size_t serviceCount1 = 3;
    size_t serviceCount2 = 1;
    size_t serviceCount3 = 2;
    const ServiceRecord services1[] = {
        ServiceRecord("2023-01-01", 10000, "Oil change"),
        ServiceRecord("2024-01-01", 20000, "Tire replacement"),
        ServiceRecord("2025-03-04", 1200, "Bonet Issue")
    };
    const ServiceRecord services2[] = {
        ServiceRecord("2023-01-01", 10000, "Engine Servicing"),
    };
    const ServiceRecord services3[] = {
        ServiceRecord("2023-01-01", 10000, "Engine Servicing"),
        ServiceRecord("2022-01-01", 1000, "Brake oiling"),
    };
    bindDetails(arr[0],codes1,codeCount1,services1,serviceCount1);
    bindDetails(arr[1],codes2,codeCount2,services2,serviceCount2);
    bindDetails(arr[2],codes3,codeCount3,services3,serviceCount3);

    // STEP 8c:
    // Loop over each object in loop and see that it is correct or not
    std::cout<<"Looping over Car array: "<<std::endl;
    for(size_t i=0;i<3;i++){
        std::cout<<"\nShowing Car "<<i+1<<std::endl;
        arr[i].printInfo();
    }

    // STEP 9:
    // Get the average price of cars in array
    std::cout<<"\n Average price of all cars in array: "<<averagePrice(arr, 3)<<std::endl;
    
    // STEP 10:
    // trying other utility functions
    std::cout<<"\n Car with maximum price of all cars in array: "<<maxPriceCar(arr, 3)->getPrice()<<std::endl;
    
    const Car* findOrNot = findCarByVIN(arr,3,"WBA4");
    if(findOrNot !=nullptr){
        std::cout<<"\nCar Found: "<<std::endl;
        findOrNot->printInfo();
    }else{
        std::cout<<"\nCar not Found: "<<std::endl;
    }

    int code = 101;
    std::cout<<"\nTotal cars with code "<<code<<": "<<countCarsWithDamage(arr,3,code)<<std::endl;

    areCarsEqual(arr[0],arr[1]) ? std::cout<<"Cars are equal.."<<std::endl : std::cout<<"Cars are not equal.."<<std::endl;

    // STEP 11:
    // Delete allocated dynamic array
    delete[] arr;

    // STEP 13:
    std::cout<<"\nNow Total car count: "<<Car::getTotalCars()<<std::endl;
    return 0;
}
