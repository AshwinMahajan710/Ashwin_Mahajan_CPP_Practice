
#ifndef PACKAGE_H
#define PACKAGE_H

#include<string>

class Package{
    // so that they can be inherited without any issue
    protected:
        std::string senderName, senderAddress,  senderState, senderZip;
        std::string receiverName, receiverAddress,  receiverState, receiverZip;
        double weight ;// in ounce
        double pricePerOunce; // in Dollars

    public:
        Package(std::string sName, std::string sAddress, std::string sState, std::string sZip,std::string rName, std::string rAddress, std::string rState, std::string rZip, double weight, double price);

        // to calculate cost
        virtual double calculateCost() const;

        // display function
        virtual void display() const;

};

#endif