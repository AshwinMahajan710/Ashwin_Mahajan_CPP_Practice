
#ifndef BASE_PLUS_COMMISSION_EMPLOYEE
#define BASE_PLUS_COMMISSION_EMPLOYEE

#include"Ashwin_Mahajan_Oct06_Task1_CommissionEmployee.h"

class BasePlusCommissionEmployee{
    private:
        double baseSalary;
        CommissionEmployee* commisionEmployee;    // commison employee object instead of overloaidng it for problem statement

    public:
        BasePlusCommissionEmployee(double ,CommissionEmployee );
        double earnings() const; // calculate earnings
        void print() const;
};

#endif