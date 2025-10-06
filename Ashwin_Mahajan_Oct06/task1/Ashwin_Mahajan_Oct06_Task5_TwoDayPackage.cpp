#include<iostream>
#include"Ashwin_Mahajan_Oct06_Task5_TwoDayPackage.h"
#include"Ashwin_Mahajan_Oct06_Task5_Package.h"

// constructor
TwoDayPackage::TwoDayPackage(std::string sName, std::string sAddress, std::string sState, std::string sZip,std::string rName, std::string rAddress, std::string rState, std::string rZip, double weight, double price, double fee): Package(sName,sAddress,sState,sZip,rName,rAddress,rState,rZip,weight,price){
    this->flatFee = (fee < 0) ? 0.0 : fee;
}

//calculate cost function
double TwoDayPackage::calculateCost() const{
    return (weight*pricePerOunce) + flatFee;
}

// Display function
void TwoDayPackage::display() const{
    Package::display();
    std::cout<<"Flat fee: "<<flatFee<<std::endl;
    std::cout<<"Total Cost: "<<calculateCost()<<std::endl;
}