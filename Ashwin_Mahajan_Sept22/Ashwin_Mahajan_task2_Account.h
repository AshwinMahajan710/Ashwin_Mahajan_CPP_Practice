// Header File --> Declaration of class

#ifndef ACCOUNT_H
#define ACCOUNT_H

class Account{
    private:
        int accountBalance;
    
    public:
        Account(int); // Constructor 
        void credit(int val);
        void debit(int val);
        int getBalance();
};

#endif