// Main file --> Usage of the class

#include<iostream>
#include"Ashwin_Mahajan_task3_Invoice.h"

int main(){ 

    // Create the object
    Invoice invoice1(1011220,"Vehicle Part",12,1234);

    // Validate using test cases
    std::cout<<"For the respective invoive: "<<"\nInvoiced Part No: "<<invoice1.getPartNumber()<<"\nPart Description: "<<invoice1.getPartDescription()<<"\nParts Quantity: "<<invoice1.getQuantity()<<"\nPrice Per Item: "<<invoice1.getPricePerItem()<<std::endl;

    // validate total invoice cost
    std::cout<<"\n Total Invoice amount: "<<invoice1.getInvoiceAmount()<<std::endl;
    return 0;
}