#ifndef TWO_DAY_PACKAGE_H
#define TWO_DAY_PACKAGE_H

#include"Ashwin_Mahajan_Oct06_Task5_Package.h"

class TwoDayPackage : public Package{
    private: 
        double flatFee;
    
    public:
        TwoDayPackage(std::string sName, std::string sAddress, std::string sState, std::string sZip,std::string rName, std::string rAddress, std::string rState, std::string rZip, double weight, double price, double fee);
        
        // to calculate cost
        double calculateCost() const;

        // display function
        void display() const;
};
#endif