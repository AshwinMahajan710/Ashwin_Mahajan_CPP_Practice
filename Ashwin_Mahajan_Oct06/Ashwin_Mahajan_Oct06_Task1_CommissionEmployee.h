#ifndef COMMISSION_H
#define COMMISSION_H

#include <string>
class CommissionEmployee{
    private:
        std::string firstName;
        std::string lastName;
        std::string socialSecurityNumber;
        double grossSales; // gross weekly sales
        double commissionRate; // commission percentage
    
    public:
        // constructor
        CommissionEmployee(const std::string &, const std::string &, const std::string &,double = 0.0, double = 0.0 );
        
        // member functions
        double earnings() const; // calculate earnings
        void print() const; // print CommissionEmployee object
};

#endif