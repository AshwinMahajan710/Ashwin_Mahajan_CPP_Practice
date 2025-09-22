//  Source file --> Implementation of class

#include<iostream>
#include "Ashwin_Mahajan_task2_Account.h"

// Constructor of account class called
Account::Account(int amount){
    if(amount>=0){
        this->accountBalance = amount;
    }
    else{
        this->accountBalance = 0;
        std::cout<<"Invalid amount eneterd.. Account balance setted to 0..."<<std::endl;
    }
}

// Debit function
void Account::debit(int amt){
    if(amt<=0){
        std::cout<<"Debit amount invalid !!! Transaction failed..."<<std::endl;
    }
    else if(amt>accountBalance ) {
        std::cout<<"Debit amount greater than balance !!! Transaction Failed..."<<std::endl;
    }
    else{
        accountBalance -= amt;
        std::cout<<"Amount debited successfully !!! New balance: "<<Account::getBalance()<<std::endl;
    }
}

// Credit function
void Account::credit(int amt){
    if(amt<=0) {
        std::cout<<"Credit amount Invalid !!! Transaction Failed..."<<std::endl;
    }
    else{
        accountBalance += amt;
        std::cout<<"Amount credited successfully !!! New balance: "<<Account::getBalance()<<std::endl;
    }
}

// getBalance function
int Account::getBalance(){
    return accountBalance;
}
