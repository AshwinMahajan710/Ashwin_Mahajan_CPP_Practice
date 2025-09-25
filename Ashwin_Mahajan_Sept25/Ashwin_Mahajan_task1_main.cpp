// Main File


#include<iostream>
#include"Ashwin_Mahajan_task1_SavingAccount.h"

int main(){

    // Create two objects
    SavingsAccount saver1(2000);
    SavingsAccount saver2(3000);

    // Set annual Intrest to 3%
    SavingsAccount::modifyInterestRate(3);

    // Print the monthly intrest and then modified balance for both
    std::cout<<"\n This month intrest of saver1: "<<saver1.calculateMonthlyInterest()<<"\nNew Balance: "<<saver1.getCurrentBalance()<<std::endl;
    std::cout<<"\n This month intrest of saver2: "<<saver2.calculateMonthlyInterest()<<"\nNew Balance: "<<saver2.getCurrentBalance()<<std::endl;

    // Set annual Intrest to 4%
    SavingsAccount::modifyInterestRate(4);
    std::cout<<"\n This month intrest of saver1: "<<saver1.calculateMonthlyInterest()<<"\nNew Balance: "<<saver1.getCurrentBalance()<<std::endl;
    std::cout<<"\n This month intrest of saver2: "<<saver2.calculateMonthlyInterest()<<"\nNew Balance: "<<saver2.getCurrentBalance()<<std::endl;

    return 0;
}