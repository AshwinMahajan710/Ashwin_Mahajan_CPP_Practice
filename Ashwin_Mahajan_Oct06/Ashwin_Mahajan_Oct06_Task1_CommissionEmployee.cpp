#include<iostream>
#include<string>
#include"Ashwin_Mahajan_Oct06_Task1_CommissionEmployee.h"

// constructor
CommissionEmployee::CommissionEmployee(const std::string &fname, const std::string &lName, const std::string &s_no,double sales, double rate){
    this->firstName = fname;
    this->lastName = lName;
    this->socialSecurityNumber = s_no;
    this->grossSales = sales;
    this->commissionRate = rate;
}

// earning from commision
double CommissionEmployee:: earnings() const{
    return (commissionRate * grossSales);
}


void CommissionEmployee:: print() const{
    std::cout<<"Commission Employeee: "<<firstName <<" "<<lastName<<std::endl;
    std::cout<<"Security No: "<<socialSecurityNumber<<std::endl;
    std::cout<<"Gross sales: "<<grossSales<<std::endl;
    std::cout<<"Commission Rate: "<<commissionRate<<std::endl;
}