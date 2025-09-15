// # CPP_Practice ---> Your_first_name_Sept15 ---> Ashwin_Mahajan_Sept15_task1.cpp 

/*
Repository Name : CPP_Practice
Visibility : Public
 
Create a day wise folder with name as YourFirstName_Sept15
YourFirstName_Sept15_task1.cpp
YourFirstName_Sept15_task2.cpp
*/

#include<iostream>
#include<string>
#include<iomanip>
#include<limits>

enum ComponentType
{
    COMPONENT_TYPE_ENGINE,
    COMPONENT_TYPE_AVIONICS,
    COMPONENT_TYPE_LANDING_GEAR,
    COMPONENT_TYPE_FUEL_SYSTEM
};

enum ComponentStatus
{
    COMPONENT_STATUS_OPERATIONAL,
    COMPONENT_STATUS_MAINTENANCE_REQUIRED,
    COMPONENT_STATUS_FAILED
};

// function to return string of component type
std::string comp_type_name(ComponentType ct){
    if (ct == COMPONENT_TYPE_ENGINE){ return "Engine.";}
    else if(ct == COMPONENT_TYPE_AVIONICS) {return "Avionics.";}
    else if(ct == COMPONENT_TYPE_LANDING_GEAR) {return "Landing Gear.";}
    else if(ct == COMPONENT_TYPE_FUEL_SYSTEM) {return "Fuel System.";}
    else return "Unable to fetch.";
}


// function to return string of component status
std::string comp_status_name(ComponentStatus cs){
    if (cs == COMPONENT_STATUS_OPERATIONAL){ return "Operational.";}
    else if(cs == COMPONENT_STATUS_MAINTENANCE_REQUIRED) {return "Maintainance required.";}
    else if(cs == COMPONENT_STATUS_FAILED) {return "Failed.";}
    else return "Unable to fetch.";
}

class AerospaceComponent{

    private:
        int componentIdentifier;
        double componentEfficiency;
        std::string componentManufacturer;
        ComponentType componentType;
        ComponentStatus componentStatus;

    public:
        // Default constructor
        AerospaceComponent(){
            componentIdentifier = 0;
            componentEfficiency = 100.0;
            componentManufacturer = "Unknown";
            componentType = COMPONENT_TYPE_ENGINE;
            componentStatus = COMPONENT_STATUS_OPERATIONAL;
        }

        // Parameterized constructor
        AerospaceComponent(int comp_id, double comp_eff, std::string comp_mft, ComponentType ct, ComponentStatus cs):componentIdentifier(comp_id), componentEfficiency(comp_eff), componentManufacturer(comp_mft), componentType(ct), componentStatus(cs){}

        // Getter ---> to get access to private values
        int getComponentIdentifier() const {return componentIdentifier;}
        double getComponentEfficiency() const {return componentEfficiency;}
        std::string getComponentManufacturer() const {return componentManufacturer;}
        ComponentType getComponentType() const {return componentType;}
        ComponentStatus getComponentStatus() const {return componentStatus;}

        // Setter ----> to set the private
        void setComponentIdentifier(int cid) {this->componentIdentifier = cid;}
        void setComponentEfficiency(double ce) { this->componentEfficiency = ce;}
        void setComponentManufacturer(std::string cm) {this->componentManufacturer = cm;}
        void setComponentType(ComponentType ct) {this->componentType = ct;}
        void setComponentStatus(ComponentStatus cs) {this->componentStatus = cs;}

        // Status Update Member function
        void UpdateStatus(){
            if (componentEfficiency < 50.0) componentStatus = COMPONENT_STATUS_FAILED;
            else if( componentEfficiency < 80.0) componentStatus = COMPONENT_STATUS_MAINTENANCE_REQUIRED;
            else componentStatus = COMPONENT_STATUS_OPERATIONAL ;
        }

        // Functionn for simulating usage hours
        void SimulateUsage(int usageHours){
            double oldEfficieny = componentEfficiency;
            for(int i=0;i<usageHours;i++){
                if(componentEfficiency<=0){
                    componentEfficiency = 0;
                    break;
                }
                componentEfficiency -= 0.5; // reduce by 0.5 every hour
            }
            std::cout<<"Old Efficiency: "<<oldEfficieny<<std::endl;
            std::cout<<"New Efficiency: "<<componentEfficiency<<std::endl;
            std::cout<<"Simulation done successfully..."<<std::endl;
        }

        void PerformMaintenanceCheck(){
            switch(componentStatus){
                case COMPONENT_STATUS_OPERATIONAL:
                    std::cout<<"Component is in operation.."<<std::endl;
                    break;
                case COMPONENT_STATUS_MAINTENANCE_REQUIRED:
                    std::cout<<"Component requires maintainance..."<<std::endl;
                    break;
                case COMPONENT_STATUS_FAILED:
                    std::cout<<"Component Failed..."<<std::endl;
                    break;
                default:
                    std::cout<<"Unable to fetch component status.."<<std::endl;
            }
        }

        // function for boosting efficieny
        void BoostEfficiency(){
            while(componentEfficiency<100){
                if(componentEfficiency>100){
                    componentEfficiency = 100.0;
                    return;
                } 
                componentEfficiency += 1.0;
            }
            std::cout<<"Efficiency Boosted Successfully.."<<std::endl;
        }

        // Display function for displaying information
        void DisplayDetails() const{
            std::cout<<" * * * * * * * * * * * * * * * Aerospace Component Details * * * * * * * * * * * * * * * "<<std::endl;
            std::cout<<"Component ID: "<<componentIdentifier<<std::endl;
            std::cout<<"Component Efficiency: "<<componentEfficiency<<std::endl;
            std::cout<<"Component Manufacturer: "<<componentManufacturer<<std::endl;
            std::cout<<"Component Type: "<<comp_type_name(componentType)<<std::endl;
            std::cout<<"Component Status: "<<comp_status_name(componentStatus)<<std::endl;
            std::cout<<" * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * "<<std::endl;
        }

        ~AerospaceComponent(){
            std::cout<<"Component "<<componentIdentifier<< "destroyed."<<std::endl;
        }

};

// Assign manufacture name
void AssignManufacturer(AerospaceComponent &component, const std::string &manufacturerName){
    std::string oldManufacturer = component.getComponentManufacturer(); 
    component.setComponentManufacturer(manufacturerName);
    std::cout<<"Old manufacturer: "<<oldManufacturer<<std::endl;
    std::cout<<"New manufacturer: "<<component.getComponentManufacturer()<<std::endl;
    std::cout<<"Manufacture name changed successfully..."<<std::endl;
}

bool IsEfficient(const AerospaceComponent &component){
    if(component.getComponentEfficiency()>85.0) return 1; // efficient component if efficiency > 85.0
    return 0;
}

// checks if types of both same or not
bool IsSameType(const AerospaceComponent &componentA, const AerospaceComponent &componentB){
    return(componentA.getComponentType()==componentB.getComponentType());
}

// checks if status of both same or not
bool IsSameStatus(const AerospaceComponent &componentA, const AerospaceComponent &componentB){
    return(componentA.getComponentStatus()==componentB.getComponentStatus());
}

// printing all components in formatted table
void PrintFormattedComponentList(const AerospaceComponent componentList[], const int listSize){
    
        std::cout << std::left << std::setw(10) << "ID"
                << std::setw(15) << "Efficiency"
                << std::setw(20) << "Manufacturer"
                << std::setw(20) << "Status"
                << std::setw(20) << "Type"
                << std::endl;

        std::cout << std::string(85, '-') << std::endl;

        // Print each component
        for (int i = 0; i < listSize; i++) {
            std::cout << std::left << std::setw(10) << componentList[i].getComponentIdentifier()
                    << std::setw(15) << componentList[i].getComponentEfficiency()
                    << std::setw(20) << componentList[i].getComponentManufacturer()
                    << std::setw(20) << comp_status_name(componentList[i].getComponentStatus())
                    << std::setw(20) << comp_type_name(componentList[i].getComponentType())
                    << std::endl;
        }
}

// validation of efficiency value
double getValidatedEfficieny(const std::string& str, double minVal, double maxVal){
    double res = -1.0;
    while(res<minVal || res>maxVal){
        std::cout<<str<<std::endl;
        std::cin>>res;

        if(res<minVal && res>maxVal){
            std::cout<<"Criteria not satisfied .. Enter no between "<<minVal<<" and "<<maxVal<<std::endl;
        }
    }
    return res;
}

// validation for component Type
int getValidatedCompType(const std::string& str, int minVal, int maxVal){
    int res = -1;
    while(res<minVal || res>maxVal){
        std::cout<<str<<std::endl;
        std::cin>>res;

        if(res<minVal && res>maxVal){
            std::cout<<"Criteria not satisfied .. Enter no between "<<minVal<<" and "<<maxVal<<std::endl;
        }
    }
    return res;
}

// validation for component Status
int getValidatedCompStatus(const std::string& str, double minVal, double maxVal){
    int res = -1.0;
    while(res<minVal || res>maxVal){
        std::cout<<str<<std::endl;
        std::cin>>res;

        if(res<minVal && res>maxVal){
            std::cout<<"Criteria not satisfied .. Enter no between "<<minVal<<" and "<<maxVal<<std::endl;
        }
    }
    return res;
}

std::string getValidatedManufacturerName(const std::string& str){
    std::string res;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clear leftover newline
    while (true) {
        std::cout << str << std::endl;
        std::getline(std::cin, res);   // actually read the input
        if (!res.empty()) {
            break;
        }
        std::cout << "Criteria not satisfied .. Enter non-empty string" << std::endl;
    }
    return res;
}


int main(){
    int choice;// for switch case

    AerospaceComponent componentOne(101, 92.5, "GE Aviation",COMPONENT_TYPE_ENGINE, COMPONENT_STATUS_OPERATIONAL); AerospaceComponent componentTwo(102, 45.0, "Honeywell",COMPONENT_TYPE_AVIONICS, COMPONENT_STATUS_FAILED);
    AerospaceComponent componentThree;

    AerospaceComponent components [10];
    components[0] = componentOne;
    components[1] = componentTwo;
    components[2] = componentThree;
    int totalComponents = 3; // total no of components

    std::cout<<" * * * * * * * * * * * * * * Aerospace Component Monitoring System * * * * * * * * * * * * * * * "<<std::endl;
    while (true)
    {
        std::cout<<"1. Add component details."<<std::endl;
        std::cout<<"2. Assign manufacturer."<<std::endl;
        std::cout<<"3. Simulate usage."<<std::endl;
        std::cout<<"4. Boost efficiency."<<std::endl;
        std::cout<<"5. Check maintenance status."<<std::endl;
        std::cout<<"6. Compare components."<<std::endl;
        std::cout<<"7. Search by component ID."<<std::endl;
        std::cout<<"8. Display all components."<<std::endl;
        std::cout<<"9. Exit."<<std::endl;
        
        std::cout<<"Enter your choice: "<<std::endl;
        std::cin>>choice;

        switch (choice)
        {
        
            case 1:{
            if(totalComponents>=10){
                std::cout<<"Total entries fulll..."<<std::endl;
            }
            int id = 0;
            int tempVal; // for assigning type of the enum object
            double efficiency = 0.0;
            std::string manufacturer_name = "";
            ComponentType type;
            ComponentStatus status;

            std::cout<<"Enter the ID: "<<std::endl;
            std::cin>>id;
            efficiency = getValidatedEfficieny("Enter the efficiency: ", 0.0, 100.0);
            tempVal = getValidatedCompStatus("Enter the Status of Component: (0: Operational, 1: Need Maintainance, 2:Falied)", 0,2);
            status = static_cast<ComponentStatus>(type);
            tempVal = getValidatedCompType("Enter the Type of Component: (0: Engine, 1: Avionics, 2:Landing gear, 3:Fuel System) ", 0,3);
            type = static_cast<ComponentType>(type);
            manufacturer_name = getValidatedManufacturerName("Enter the manufacturer name: ");
            AerospaceComponent newComponent(id, efficiency, manufacturer_name, type, status);
            components[++totalComponents] = newComponent;
            std::cout<<"Values assigned successfully...."<<std::endl;
            break;
        }

        case 2:{
            int id;
            int found = false;
            std::string newManufacturerName;
            std::cout<<"Enter the id of component to change maufacturer: "<<std::endl;
            std::cin>>id;
            newManufacturerName = getValidatedManufacturerName("Enter the new manufacturer name: ");
            for(int i=0;i<totalComponents;i++){
                if(components[i].getComponentIdentifier()==id){
                    AssignManufacturer(components[i],newManufacturerName);
                    found = true;
                }
            }
            if(!found){
                std::cout<<"Respective ID not found.."<<std::endl;
            }
            break;
        }

        case 3:{
            int id;
            int found = false;
            int usageHours;
            std::cout<<"Enter the id of component to change maufacturer: "<<std::endl;
            std::cin>>id;
            std::cout<<"Enter the usage hours: "<<std::endl;
            std::cin>>usageHours;
            for(int i=0;i<totalComponents;i++){
                if(components[i].getComponentIdentifier()==id){
                    components[i].SimulateUsage(usageHours);
                    found = true;
                }
            }
            if(!found){
                std::cout<<"Respective ID not found.."<<std::endl;
            }
            break;
        }

        case 4:{
            int id;
            int found = false;
            std::cout<<"Enter the id of component to change maufacturer: "<<std::endl;
            std::cin>>id;
            for(int i=0;i<totalComponents;i++){
                if(components[i].getComponentIdentifier()==id){
                    components[i].BoostEfficiency();
                    found = true;
                }
            }
            if(!found){
                std::cout<<"Respective ID not found.."<<std::endl;
            }
            break;
        }

        case 5:{
            int id;
            int found = false;
            std::cout<<"Enter the id of component to change maufacturer: "<<std::endl;
            std::cin>>id;
            for(int i=0;i<totalComponents;i++){
                if(components[i].getComponentIdentifier()==id){
                    components[i].PerformMaintenanceCheck();
                    found = true;
                }
            }
            if(!found){
                std::cout<<"Respective ID not found.."<<std::endl;
            }
            break;
        }

        case 6:{
            int id1, id2;
            int found1 = false, found2 = false;
            std::cout<<"Enter the two ids: "<<std::endl;
            std::cin>>id1>>id2;
            AerospaceComponent a1,a2;
            for (int i = 0; i < totalComponents; i++)
            {
                if (components[i].getComponentIdentifier()==id1)
                {
                    a1 = components[i];
                    found1 = true;
                }
                if (components[i].getComponentIdentifier()==id2)
                {
                    a2 = components[i];
                    found2 = true;
                }
            }
            if(!found1 || !found2){
                std::cout<<"Ids not found.."<<std::endl;
            }
            else{
                IsSameType(a1,a2) ? std::cout<<"Both components are same"<<std::endl : std::cout<<"Both components are not same"<<std::endl;
            }
            break;
        }

        case 7:{
            int id;
            int found = false;
            std::cout<<"Enter the id of component to change maufacturer: "<<std::endl;
            std::cin>>id;
            for(int i=0;i<totalComponents;i++){
                if(components[i].getComponentIdentifier()==id){
                    std::cout<<"The component found with respective id.."<<std::endl;
                    components[i].DisplayDetails();
                    found = true;
                }
            }
            if(!found){
                std::cout<<"Respective ID not found.."<<std::endl;
            }
            break;
        }

        case 8:{
            PrintFormattedComponentList(components,totalComponents);
            break;
        }
        
        case 9:
            std::cout<<"Thank you for using application ..."<<std::endl;
            return 0;
        
        default:
            std::cout<<"Invalid input"<<std::endl;
            break;
        }
    }
    return 0;
}