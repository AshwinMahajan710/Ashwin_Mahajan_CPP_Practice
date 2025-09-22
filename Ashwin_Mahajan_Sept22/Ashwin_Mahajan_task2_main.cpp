// Main file --> Usage of the class

#include<iostream>
#include "Ashwin_Mahajan_task2_Account.h"

int main(){

    // Defining object
    Account ac1(100);
    Account ac2(200);

    // Performing actions
    ac1.credit(-12);
    ac1.credit(100);

    ac2.debit(-2);
    ac2.debit(12);

    return 0;
}