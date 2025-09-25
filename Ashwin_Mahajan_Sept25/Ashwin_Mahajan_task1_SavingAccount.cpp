// Source file ---> class definition

#include<iostream>
#include"Ashwin_Mahajan_task1_SavingAccount.h"

// Initializing the static member
float SavingsAccount::annualInterestRate = 3.0; //By default intrest rate will be 3%

// current balance
SavingsAccount::SavingsAccount(float currentBalance){
    this->savingsBalance = currentBalance;
}

// Will return the mothly intrest and will also add it in the savingBalance
float SavingsAccount::calculateMonthlyInterest() {
    float intrestOfThisMonth = (this->savingsBalance*annualInterestRate) / 100; // Formulae to calculate intrest rate on svaing amount
    this->savingsBalance += intrestOfThisMonth;
    return intrestOfThisMonth;
}

// will return the current balance --> reference to save memory but constant so that no one can modify
const float& SavingsAccount::getCurrentBalance() const{
    return this->savingsBalance;
}

// Will set the new savings balance
void SavingsAccount::setBalance(const float& val){
    this->savingsBalance = val;
}

// Set new intrest rate
void SavingsAccount::modifyInterestRate(const float& rate){
    SavingsAccount::annualInterestRate = rate;
}

// get intrest rate
float SavingsAccount::getAnnualIntrestRate(){
    return SavingsAccount::annualInterestRate;
}
