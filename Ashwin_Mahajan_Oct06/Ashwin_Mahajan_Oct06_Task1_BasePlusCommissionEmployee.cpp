#include"Ashwin_Mahajan_Oct06_Task1_BasePlusCommissionEmployee.h"
#include"Ashwin_Mahajan_Oct06_Task1_CommissionEmployee.h"
#include<iostream>
#include<string>

// constructor
BasePlusCommissionEmployee::BasePlusCommissionEmployee(double baseSal, CommissionEmployee ce){
    this->baseSalary = baseSal;
    commisionEmployee = &ce;
}

// member function to print
void BasePlusCommissionEmployee::print() const{
    commisionEmployee->print();
    std::cout<<"Base salary: "<<baseSalary<<std::endl;
    std::cout<<"Net Salary: "<<baseSalary + earnings()<<std::endl;
}

// earning function
double BasePlusCommissionEmployee::earnings() const{
    return (commisionEmployee->earnings()*baseSalary/100);
}