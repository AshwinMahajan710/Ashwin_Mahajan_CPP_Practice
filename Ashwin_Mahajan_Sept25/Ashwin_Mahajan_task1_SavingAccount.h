// Header file --> contain class declaration

#ifndef SAVINGS_ACCOUNT_H
#define SAVINGS_ACCOUNT_H

class SavingsAccount{
    private:
        static float annualInterestRate; // Will store the annual Interest rate ----> same for each user
        float savingsBalance; // Will store balance
    public:

        // constructor
        SavingsAccount(float currentBalance); 

        // Getters
        static float getAnnualIntrestRate(); // will give the annual Intrest rate common for every user
        const float& getCurrentBalance() const; // will be used to print the intrest

        // Setters
        void setBalance(const float& val);
        static void modifyInterestRate(const float& newRate); // will modify the intrest rate

        // MemberFunctions
        float calculateMonthlyInterest(); // will return the intrest rate and also add it in balance
        
};

#endif