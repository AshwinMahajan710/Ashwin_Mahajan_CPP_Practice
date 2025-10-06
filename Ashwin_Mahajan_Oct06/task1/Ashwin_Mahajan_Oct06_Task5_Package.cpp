
#include"Ashwin_Mahajan_Oct06_Task5_Package.h"
#include<iostream>
#include<string>

// constructor
Package::Package(std::string sName, std::string sAddress, std::string sState, std::string sZip,std::string rName, std::string rAddress, std::string rState, std::string rZip, double weight, double price){
    this->senderName = sName;
    this->senderAddress = sAddress;
    this->senderState = sState;
    this->senderZip = sZip;
    this->receiverName = rName;
    this->receiverAddress = rAddress;
    this->receiverState = rState;
    this->receiverZip = rZip;  
    this->weight = (weight < 0) ? 0.0 : weight;
    this->pricePerOunce = (price < 0) ? 0.0 : price;
}

// to calculate cost
double Package:: calculateCost() const{
    return (this->weight * this->pricePerOunce);
}

// display function
void Package::display() const{
    std::cout<<"Sender Name: "<<senderName<<std::endl;
    std::cout<<"Sender Address: "<<senderAddress<<std::endl;
    std::cout<<"Sender State: "<<senderState<<std::endl;
    std::cout<<"Sender Zip: "<<senderZip<<std::endl;
    std::cout<<"Receiver Name: "<<receiverName<<std::endl;
    std::cout<<"Receiver Address: "<<receiverAddress<<std::endl;
    std::cout<<"Receiver State: "<<receiverState<<std::endl;
    std::cout<<"Receiver Zip: "<<receiverZip<<std::endl;
    std::cout<<"Weight of parcle(ounce): "<<weight<<std::endl;
    std::cout<<"Charges per ounce: "<<pricePerOunce<<std::endl;
}