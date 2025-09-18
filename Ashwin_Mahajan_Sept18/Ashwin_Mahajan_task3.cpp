#include<iostream>

enum class SatelliteStatus{
    OPERATIONAL, 
    MAINTENANCE, 
    DECOMMISSIONED
};

class SatelliteData{
    private:
        int satellite_id;
        int num_antennas;
        float* signal_strength;
        float orbital_altitude;
        SatelliteStatus status;
        static int active_satellites;

    public:
        // Constructor -> Default
        SatelliteData(){
            this->satellite_id = 0;
            this->num_antennas = 0;
            this->signal_strength = nullptr;
            this->orbital_altitude = 0;
            this->status = SatelliteStatus::DECOMMISSIONED;
        }

        // Constructor -> Parametrized
        SatelliteData(int satellite_id,int num_antennas,float* signal_strength,float orbital_altitude,SatelliteStatus status){
            this->satellite_id = satellite_id;
            this->num_antennas = num_antennas;
            this->signal_strength = new float[num_antennas];
            for(int i=0;i<num_antennas;i++){ this->signal_strength[i] = signal_strength[i]; }
            this->orbital_altitude = orbital_altitude;
            this->status = status;
            active_satellites++;
        }

        // Constructor -> copy
        SatelliteData(const SatelliteData& other){
            this->satellite_id = other.satellite_id;
            this->num_antennas = other.num_antennas;
            this->signal_strength = new float[num_antennas];
            for(int i=0;i<num_antennas;i++){ this->signal_strength[i] = other.signal_strength[i]; }
            this->orbital_altitude = other.orbital_altitude;
            this->status = other.status;
            active_satellites++;
        }   

        // Getters
        int getSatelliteId() const{return satellite_id;}
        float* getSignalStrength() const{return signal_strength;} 
        int getNumAntennas() const{return num_antennas;}
        float getOrbitalAltitude() const{return orbital_altitude;}

        // Getting average signal strength
        float getAverageSignalStrength() const{
            float sumOfSignalStrengths = 0.0;
            for(int i=0;i<num_antennas;i++){
                sumOfSignalStrengths += signal_strength[i];
            }
            return sumOfSignalStrengths/num_antennas;
        }

        // boosting signal function by multiplying signal strength with factor
        void boostSignal(float factor){
            for(int i=0;i<num_antennas;i++){
                signal_strength[i] *= factor;
            }
        }

        // Overloaded boost signal function
        void boostSignal(float factor, float threshold){
            for(int i=0;i<num_antennas;i++){
                signal_strength[i] *= factor;
                if(signal_strength[i]>threshold) signal_strength[i] = threshold;
            }
        }

        // function to get total satellite counts
        static int getActiveSatelliteCount(){
            return active_satellites;
        }

        // Set satellite Status 
        void setStatus(SatelliteStatus new_status){
            status = new_status;
        }

        // Get status in string format
        const char* getStatusString() const{
            switch (status)
            {
            case SatelliteStatus::OPERATIONAL:
                return "Operational";
                break;
            
            case SatelliteStatus::MAINTENANCE:
                return "Maintainance";
                break;
            
            case SatelliteStatus::DECOMMISSIONED:
                return "Decommissioned";
                break;
            
            default:
                return "Other";
                break;
            }
        }

        // Destructor to delete dynamically allocated memory
        ~SatelliteData(){
            active_satellites--; // if partcular object deletes it is not active satellite anymore
            delete[] signal_strength;
        }
};

// Printing the satellite data
void printSatelliteData(const SatelliteData& sd){
    std::cout<<"Satellite ID: "<<sd.getSatelliteId()<<std::endl;
    std::cout<<"Number of antennas: "<<sd.getNumAntennas()<<std::endl;
    std::cout<<"Signal Strength:";
    for (int i = 0; i < sd.getNumAntennas(); i++){std::cout<<" "<<sd.getSignalStrength()[i];}
    std::cout<<"\nOrbital Altitude: "<<sd.getOrbitalAltitude()<<std::endl;
    std::cout<<"Satellite Status: "<<sd.getStatusString()<<std::endl;
}

// camparing two Satellite objects based on altitude
bool compareAltitude(const SatelliteData& s1, const SatelliteData& s2){
    return (s1.getOrbitalAltitude() > s2.getOrbitalAltitude());
}

// cloning data of one object to another using copy constructor
void cloneSatellite(const SatelliteData& source, SatelliteData*& target){
    target = new SatelliteData(source);
}

// Printing current active satellites 
void printActiveSatelliteCount(){
    std::cout<<"\nCurrently active satellite no: "<<SatelliteData::getActiveSatelliteCount()<<std::endl;
}

// update signal status if getting signal less than average signal
void updateStatusIfWeak(SatelliteData& sd, float confidence_threshold){
    if(sd.getAverageSignalStrength() < confidence_threshold) sd.setStatus(SatelliteStatus::MAINTENANCE);
}

int SatelliteData::active_satellites = 0;

int main(){

    // Initializing the params and creating objects
    int satellite_id_1 = 101;
    int num_antennas_1 = 3;
    float signal_strength_1[num_antennas_1]{78.5f, 80.2f, 79.0f};
    float orbital_altitude_1 = 550.0f;
    SatelliteStatus status_1 = SatelliteStatus::OPERATIONAL;

    int satellite_id_2 = 102;
    int num_antennas_2 = 2;
    float signal_strength_2[num_antennas_2]{75.0f, 76.5f};
    float orbital_altitude_2 = 600.0f;
    SatelliteStatus status_2 = SatelliteStatus::MAINTENANCE;

    SatelliteData data1(satellite_id_1,num_antennas_1,signal_strength_1,orbital_altitude_1,status_1);
    SatelliteData data2(satellite_id_2,num_antennas_2,signal_strength_2,orbital_altitude_2,status_2);

    // Bossting satellite strength of object data1 using both functions
    data1.boostSignal(1.1); // without threshold
    data1.boostSignal(1.3,110); // with threshold

    //Comparing altitudes
    compareAltitude(data1,data2) ? std::cout<<"\nAltitude of Satelite 1 ("<<data1.getOrbitalAltitude()<<") is greater than altitude of satelite 2 ("<<data2.getOrbitalAltitude()<<")..."<<std::endl : std::cout<<"\nAltitude of Satelite 2 ("<<data2.getOrbitalAltitude()<<") is greater than altitude of satelite 1 ("<<data1.getOrbitalAltitude()<<")..."<<std::endl;

    // cloning data2 in data3
    SatelliteData* data3 = nullptr;
    cloneSatellite(data2,data3);

    // Printing the data of all satellites
    std::cout<<"\nFollowing is the data of satellite 1: "<<std::endl;
    printSatelliteData(data1);
    std::cout<<"\nFollowing is the data of satellite 2: "<<std::endl;
    printSatelliteData(data2);
    std::cout<<"\nFollowing is the data of satellite 3: "<<std::endl;
    printSatelliteData(*data3);

    // Updating the strength of all satellites using updateStatus function
    updateStatusIfWeak(data1,100);
    std::cout<<"\nCurrent status of Satellite 1 is: "<<data1.getStatusString()<<std::endl;
    updateStatusIfWeak(data2,100);
    std::cout<<"\nCurrent status of Satellite 2 is: "<<data2.getStatusString()<<std::endl;
    updateStatusIfWeak(*data3,100);
    std::cout<<"\nCurrent status of Satellite 3 is: "<<data3->getStatusString()<<std::endl;

    // Printing active satellite count
    printActiveSatelliteCount();

    // all dynamic allocated memory will automatically get freed
    delete data3;

    return 0;
}