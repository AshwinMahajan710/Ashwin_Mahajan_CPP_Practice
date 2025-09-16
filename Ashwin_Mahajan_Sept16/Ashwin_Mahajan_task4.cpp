// Main thing Learned ----> while passing the object by value, it always invokes copy constructor
// ----> If program in doing dynamic allocation of memory, There are chances of shallow copy if copy constructor is not defined explicitly 

#include<iostream>
#include<iomanip>

class RadarSignal{
    private:
        int num_channels;
        float* signal_strength;

    public:

        // Constructor
        RadarSignal(int num_channels,float* signal_strength){
            this->num_channels = num_channels;
            this->signal_strength = new float[num_channels];
            for(int i=0;i<num_channels;i++){
                this->signal_strength[i] = signal_strength[i];
            }    
        }

        // Copy constructor 
        RadarSignal(const RadarSignal& obj) {
            num_channels = obj.num_channels;
            signal_strength = new float[num_channels];
            for (int i = 0; i < num_channels; i++) {
                signal_strength[i] = obj.signal_strength[i];
            }
        }

        // Getters
        int getNumChannels() const{
            return num_channels;
        }

        float* getSignalStrength() const{
            return signal_strength;
        }

        // Calculating average singnal strength
        float averageSignal() const{
            float sum = 0;
            for(int i=0;i<num_channels;i++){
                sum += signal_strength[i];
            }
            return sum/float(num_channels);
        }

        // Boostsignal by value
        void boostSignalByValue(RadarSignal obj){
            std::cout<<"Object passed by value: (No change in actual copy)"<<std::endl;
            
            for(int i=0;i<obj.num_channels;i++){
                obj.signal_strength[i] += 5.0;
            }
        }
        
        // Boostsignal by Reference
        void boostSignalByReference(RadarSignal& obj){
            std::cout<<"Object passed by Reference: (Change in actual obj values)"<<std::endl;
            for(int i=0;i<obj.num_channels;i++){
                obj.signal_strength[i] += 5.0;
            }
        }

        // Destructor
        ~RadarSignal(){
            delete[] signal_strength;
            signal_strength = nullptr;
        }
};

// Printing the details of the radarsignal
void printRadarSignal(const RadarSignal& radar){
    int num_channel = radar.getNumChannels();
    float* signal_strength = radar.getSignalStrength();
    std::cout<<std::setw(15)<<"Channel No."<<std::setw(15)<<"Signal Strength"<<std::endl;
    for (int i = 0; i < num_channel; i++)
    {
        std::cout<<std::setw(15)<<i<<std::setw(15)<<signal_strength[i]<<std::endl;
    }
}

// Creting dynamic radarsignal object
RadarSignal* createRadarSignalHeap(int num, float* signals){
    return new RadarSignal(num,signals);
}

int main(){

    // testing
    int num_channels = 4;
    float* signal_strength = new float[4]{55.5,48.2,60.1,52.6};

    // Allocate dyanamic memory
    RadarSignal* radarSignal = createRadarSignalHeap(num_channels,signal_strength);

    // Performing operation
    radarSignal->boostSignalByValue(*radarSignal);
    printRadarSignal(*radarSignal);
    radarSignal->boostSignalByReference(*radarSignal);
    printRadarSignal(*radarSignal);

    // to free dynamically allocated memory
    delete [] signal_strength;
    delete radarSignal;
    radarSignal = nullptr;

    return 0;
}