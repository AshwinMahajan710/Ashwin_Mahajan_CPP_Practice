#include<iostream>
#include<iomanip>

class CameraConfig{
    private:
        int num_modes;
        int* resolution_width;
        int* resolution_height;

    public:

        // Parameterized Constructor
        CameraConfig(int num_modes, int* resolution_width, int* resolution_height){
            this->num_modes = num_modes;
            this->resolution_height = new int[num_modes];
            this->resolution_width = new int[num_modes];
            for(int i=0;i<num_modes;i++){
                this->resolution_height[i] = resolution_height[i];
                this->resolution_width[i] = resolution_width[i];
            }
        }

        // Copy constructor --> Deep copy
        CameraConfig(const CameraConfig& other){
            this->num_modes = other.num_modes;
            this->resolution_height = new int[other.num_modes];
            this->resolution_width = new int[other.num_modes];
            for(int i=0;i<num_modes;i++){
                this->resolution_height[i] = other.resolution_height[i];
                this->resolution_width[i] = other.resolution_width[i];
            }
        }

        // getters
        int getNumModes() const{
            return num_modes;
        }
        int* getResolutionWidth() const{
            return resolution_width;
        }
        int* getResolutionHeight() const{
            return resolution_height;
        }
    
        // Print config function to display mode resoltions
        void printConfig() const{
            std::cout<<std::setw(10)<<"Mode"<<std::setw(10)<<"Width"<<std::setw(10)<<"Height"<<std::endl;
            for(int i=0;i<num_modes;i++){
                std::cout<<std::setw(10)<<i<<std::setw(10)<<resolution_width[i]<<std::setw(10)<<resolution_height[i]<<std::endl;
            }
        }

        // Additional function which will return resolution of particular mode
        long return_resolution(int mode) const{
            return (resolution_height[mode] * resolution_width[mode]); 
        }

        // comparing resolution of two modes
        bool isHigherResolution(int mode1, int mode2) const{
            long mode1_res = return_resolution(mode1);
            long mode2_res = return_resolution(mode2);
            return (mode1_res > mode2_res);
        }

        ~CameraConfig(){
            delete[] resolution_height;
            resolution_height = nullptr;
            delete[] resolution_width;
            resolution_width = nullptr;
        }
};

// global function for printing configurations
void printCameraConfig(const CameraConfig& config){
    int num_modes = config.getNumModes();
    int* resolution_width = config.getResolutionWidth();
    int* resolution_height = config.getResolutionHeight();
    
    std::cout<<std::setw(10)<<"Mode"<<std::setw(10)<<"Width"<<std::setw(10)<<"Height"<<std::endl;
    for(int i=0;i<num_modes;i++){
        std::cout<<std::setw(10)<<i<<std::setw(10)<<resolution_width[i]<<std::setw(10)<<resolution_height[i]<<std::endl;
    }
}

// global function for comparing resolution of different modes
bool globalCompareResolution(const CameraConfig& config, int m1,
int m2){
    int* resolution_width = config.getResolutionWidth();
    int* resolution_height = config.getResolutionHeight();
    long mode1_res = resolution_height[m1] * resolution_width[m1];
    long mode2_res = resolution_height[m2] * resolution_width[m2];
    return (mode1_res > mode2_res);
}

int main(){ 

    // Initialization and object creation
    int num_modes = 3;
    int* resolution_width = new int[3]{1920, 1280, 3840};
    int* resolution_hight = new int[3]{1080, 2160, 720};

    CameraConfig config(num_modes, resolution_width, resolution_hight);

    // Printing the details of the resolutions in the CameraConfig object
    std::cout<<"* * * * * * * * * * * * * * * * * * Camera info * * * * * * * * * * * * * * * * * * "<<std::endl;
    config.printConfig();
    std::cout<<"* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * "<<std::endl;
    
    // Comparing resolution of mode 0 and 2 using member function of class
    if(config.isHigherResolution(0,2)){
        std::cout<<"Resolution of mode 0: "<<config.return_resolution(0)<<"  is greater than Resolution of mode 2: "<<config.return_resolution(2)<<std::endl;
    }
    else{
        std::cout<<"Resolution of mode 2: "<<config.return_resolution(2)<<"  is greater than Resolution of mode 0: "<<config.return_resolution(0)<<std::endl;
    }

    // Comparing resolution of mode 0 and 2 using global function of class
    if(globalCompareResolution(config,0,2)){
        std::cout<<"Resolution of mode 0: "<<config.return_resolution(0)<<"  is greater than Resolution of mode 2: "<<config.return_resolution(2)<<std::endl;
    }
    else{
        std::cout<<"Resolution of mode 2: "<<config.return_resolution(2)<<"  is greater than Resolution of mode 0: "<<config.return_resolution(0)<<std::endl;
    }

    return 0;
}