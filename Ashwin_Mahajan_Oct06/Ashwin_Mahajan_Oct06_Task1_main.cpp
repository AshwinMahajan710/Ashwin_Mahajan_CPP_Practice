#include"Ashwin_Mahajan_Oct06_Task1_CommissionEmployee.h"
#include"Ashwin_Mahajan_Oct06_Task1_BasePlusCommissionEmployee.h"
#include<iostream>

// testing the base plus commision employeee
int main(){
    BasePlusCommissionEmployee employee(50000,*(new CommissionEmployee("Ashwin","Mahajan","1234567",13,4)));
    employee.print();
}   