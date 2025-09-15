#include<iostream>
#include<string>
#include<vector>
#include<limits>
using namespace std;

// Actual FleetVehicle class 
class FleetVehicle{
    private:
        int vehicleID;
        float fuelLevel;
        double distanceTravelled;
        char status; // 'A' for active 'I' for Inactive 
        bool isAvailable;
        string driverName;

    public:

        // Default constructor
        FleetVehicle(){
            vehicleID = 0;
            fuelLevel = 50.0;
            distanceTravelled = 0.0;
            status = 'A';
            isAvailable = true;
            driverName = "Unassigned";
        }

        // Parameterized constructor
        FleetVehicle(int vehicleID,float fuelLevel, double distanceTravelled,char status,bool isAvailable,string driverName){
            this->vehicleID = vehicleID;
            this->fuelLevel = fuelLevel;
            this->distanceTravelled = distanceTravelled;
            this->status = status;
            this->isAvailable = isAvailable;
            this->driverName = driverName;

            updateStatus(); // In case of inconsistency in status value
        }

        // Destructor
        ~FleetVehicle(){
            cout<<"Destructor called for vehicle ID: "<<vehicleID<<endl;
        }

        // Getters 
        int getVehicleID() const { return vehicleID; }
        float getFuelLevel() const { return fuelLevel; }
        double getDistanceTravelled()const { return distanceTravelled; }
        char getStatus()const { return status; }
        bool getIsAvailable()const { return isAvailable; }
        string getDriverName()const { return driverName; }

        // setters
        void setVehicleID(int vehicleID) { this->vehicleID = vehicleID; }
        void setFuelLevel(float fuelLevel){ this->fuelLevel = fuelLevel; }
        void setDistanceTravelled(double distanceTravelled){ this->distanceTravelled = distanceTravelled;}
        void setStatus(char status){ this->status = status; }
        void setIsAvailable(bool isAvailable){ this->isAvailable = isAvailable;}
        void setDriverName(string driverName){ this->driverName = driverName; }

        // updatestatus function
        void updateStatus(){
            if (fuelLevel < 10.0 || !isAvailable){
                status = 'I';
            }
            else{
                status = 'A';
            }
        }

        // Display Details
        void displayInfo(){

            string is_vehicle_available = (isAvailable) ? "Yes" : "No";
            string current_status = (status == 'A') ? "Active" : "Inactive";

            cout<<"\n * * * * * * * * * * * * * * * * * * * * * * "<<endl;
            cout<<"Vehicle ID: "<<vehicleID<<endl;
            cout<<"Fuel Level: "<<fuelLevel<<endl;
            cout<<"Distance Travelled: "<<distanceTravelled<<endl;
            cout<<"Status: "<<current_status<<endl;
            cout<<"Vehicle Availability: "<<is_vehicle_available<<endl;
            cout<<"Driver Name: "<<driverName<<endl;
            cout<<" * * * * * * * * * * * * * * * * * * * * * * "<<endl;
        }
};

// Global function to change driver
void assignDriver(FleetVehicle &vehicle, string name){
    string oldDriverName = vehicle.getDriverName(); // old driver name
    vehicle.setDriverName(name);
    cout<<"Previous Driver Name: "<<oldDriverName<<endl;
    cout<<"New Driver Name: "<<vehicle.getDriverName()<<endl;
    cout<<"Driver name chnaged successfully...."<<endl;
}

// Function for refuling fuel
void refuelVehicle(FleetVehicle &vehicle, float fuelAmount){
    if (fuelAmount<=0)
    {   
        throw invalid_argument("ERROR: Fuel Amount must be greater than 0...\n");
    }
    float remainingFuel = vehicle.getFuelLevel();
    vehicle.setFuelLevel(remainingFuel + fuelAmount);
    cout<<"Old fuel level : "<<to_string(remainingFuel)<<endl;
    cout<<"New fuel level after refuling: "<<to_string(vehicle.getFuelLevel())<<endl;
}


int main(){
    
    int choice; // for choices in switch case loop
    // Dynamic allocation for 3 fleets of vehicle
    vector<FleetVehicle*> vehicles(3);
    vehicles[0] = new FleetVehicle(101, 45.5, 120.0, 'A', true, "Raj");
    vehicles[1] = new FleetVehicle(102, 8.0, 300.0, 'A', true, "Priya");
    vehicles[2] = new FleetVehicle();

    // Switch Case
    cout<<" ---------------Welcome to Fleet Management System --------------- "<<endl;
    while (true)
    {
        cout<<"\n 1. Add vehicle details using parameterized constructor."<<endl;
        cout<<"2. Assign a driver."<<endl;
        cout<<"3. Refuel a vehicle."<<endl;
        cout<<"4. Update status."<<endl;
        cout<<"5. Display vehicle info."<<endl;
        cout<<"6. Exit"<<endl;

        cout<<"Enter Your choice: "<<endl;
        cin>>choice;

        switch (choice)
        {
        case 1: {
            int vehicleID;
            float fuelLevel;
            double distanceTravelled;
            char status;
            bool availability;
            std::string driverName;

            cout<<"Enter all the details (Id, Fuel Level, Distance Travel, Status, Availability, Driver Name): ";
            cin>>vehicleID>>fuelLevel>>distanceTravelled>>status>>availability;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin,driverName);
            FleetVehicle* newVehicle = new FleetVehicle(vehicleID,fuelLevel,distanceTravelled,status, availability, driverName);
            vehicles.push_back(newVehicle);
            cout<<"Operation completed successfully..."<<endl;
            break;
        }

        case 2:{
            string new_driver_name;
            int id;
            bool found = false;
            cout<<"Enter the id of the vehicle to change or assign driver: "<<endl;
            cin>>id;
            cout<<"Enter the new name of driver: "<<endl;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin,new_driver_name);
            for(FleetVehicle* item: vehicles){
                if (item->getVehicleID()==id)
                {
                    assignDriver(*item,new_driver_name);
                    cout<<"Driver changed successfully..."<<endl;
                    found = true;
                    break;
                }
            }
            if(!found){
                cout<<"Respective vehicle with given id not available..."<<endl;
                break;
            }
        }

        case 3:{
            try{
                float refuel_val;
                int id;
                bool found = false;
                cout<<"Enter the id of the vehicle to change or assign driver: "<<endl;
                cin>>id;
                cout<<"Enter the refule value: "<<endl;
                cin>>refuel_val;

                for(FleetVehicle* item: vehicles){
                    if (item->getVehicleID()==id)
                    { 
                        refuelVehicle(*item,refuel_val);
                        cout<<"Fuel Capacity changed successfully..."<<endl;
                        found = true;
                        break;
                    }
                }
                if(!found){
                    cout<<"Respective vehicle with given id not available..."<<endl;
                    break;
                }
            } catch(const exception& e){
                cout<<e.what()<<endl;
            }
            break;
        }

        case 4:{
            for (FleetVehicle* item: vehicles)
            {
                item->updateStatus();
            }
            cout<<"Status of entire vehicles updated successfully...";
            break;
        }

        case 5:{
            cout<<"Following is the entire Information: "<<endl;
            for(FleetVehicle* item: vehicles){
                item->displayInfo();
            }
            break;
        }

        case 6: {
            for (FleetVehicle*& item : vehicles) {   
                delete item;
                item = nullptr;  
            }
            cout << "Thank you for using application..." << endl;
            return 0;
        }

        default:
            cout<<"Wrong choice ... enter again..."<<endl;
            break;
        }
    }

    return 0;
}