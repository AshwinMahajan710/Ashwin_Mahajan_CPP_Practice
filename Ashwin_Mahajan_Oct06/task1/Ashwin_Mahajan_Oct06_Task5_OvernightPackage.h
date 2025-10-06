#ifndef OVERNIGHT_PACKAGE_H
#define OVERNIGHT_PACKAGE_H
#include<string>
#include"Ashwin_Mahajan_Oct06_Task5_Package.h"

class OvernightPackage: public Package{
    private:
        double additional_fee_per_ounce;
    
    public:
        OvernightPackage(std::string sName, std::string sAddress, std::string sState, std::string sZip,std::string rName, std::string rAddress, std::string rState, std::string rZip, double weight, double price, double extraFee);
        
        // to calculate cost
        double calculateCost() const;

        // display function
        void display() const;
};

#endif
