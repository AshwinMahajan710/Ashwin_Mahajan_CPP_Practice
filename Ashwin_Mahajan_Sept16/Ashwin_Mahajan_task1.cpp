#include<iostream>

// Class LaneBoundary
class LaneBoundary{
    private:
        float curvature;
        int lane_id;
    public:
        LaneBoundary(float curvature, int lane_id):curvature(curvature), lane_id(lane_id){} // constructor

        // getters
        float getCurvature() const {return curvature;}
        int getLaneId() const {return lane_id;}

        // Compare curvature function
        bool compareCurvature(const LaneBoundary& other) const{
            return this->curvature > other.curvature;
        }

        // display details
        void displayDetails() const {
            std::cout<<"Curvature: "<<curvature<<std::endl;
            std::cout<<"Lane ID: "<<lane_id<<std::endl;
        }

};  

// Comparing first one curvature is greater or not
bool isCurvatureGreater(const LaneBoundary& lane1, const LaneBoundary& lane2){
    return lane1.compareCurvature(lane2);
}

// Printing lane comaparison results
void printLaneComparison(const LaneBoundary& lane1, const LaneBoundary& lane2){
    if(isCurvatureGreater(lane1, lane2)){
        std::cout<<"Curvature of lane 1: "<<lane1.getCurvature()<<" is greater than curvature of lane 2: "<<lane2.getCurvature()<<std::endl;
    }else{
        std::cout<<"Curvature of lane 2: "<<lane2.getCurvature()<<" is greater than curvature of lane 1: "<<lane1.getCurvature()<<std::endl;
    }
}

int main(){
    // Creating two laneboundary objects
    LaneBoundary l1(0.015,1);
    LaneBoundary l2(0.023,2);

    // Comparing by class methods
    if(l1.compareCurvature(l2)){
        std::cout<<"Curvature of lane 1: "<<l1.getCurvature()<<" is greater than curvature of lane 2: "<<l2.getCurvature()<<std::endl;
    }
    else{
        std::cout<<"Curvature of lane 2: "<<l2.getCurvature()<<" is greater than curvature of lane 1: "<<l1.getCurvature()<<std::endl;
    }

    // Comparing by global functions
    printLaneComparison(l1,l2);

    return 0;
}