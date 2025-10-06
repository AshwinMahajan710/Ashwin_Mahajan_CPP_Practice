#include<iostream>
#include"Ashwin_Mahajan_Oct06_Task5_OvernightPackage.h"
#include"Ashwin_Mahajan_Oct06_Task5_Package.h"

// constructor
OvernightPackage::OvernightPackage(std::string sName, std::string sAddress, std::string sState, std::string sZip,std::string rName, std::string rAddress, std::string rState, std::string rZip, double weight, double price, double extraFee): Package(sName,sAddress,sState,sZip,rName,rAddress,rState,rZip,weight,price){
    this->additional_fee_per_ounce = (extraFee < 0) ? 0.0 : extraFee;
}

//calculate cost function
double OvernightPackage::calculateCost() const{
    return (weight*pricePerOunce) + (weight*additional_fee_per_ounce);
}

// Display function
void OvernightPackage::display() const{
    Package::display();
    std::cout<<"Additional overnight fee per ounce: "<<additional_fee_per_ounce<<std::endl;
    std::cout<<"Total Cost: "<<calculateCost()<<std::endl;
}