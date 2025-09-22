//  Source file --> Implementation of class

#include<iostream>
#include "Ashwin_Mahajan_task3_Invoice.h"

// Define the constructor
Invoice::Invoice(int partNumber, std::string partDesc, int qty, int pricePerItem){
    this->part_number = partNumber;
    this->part_description = partDesc;
    this->quantity = (qty >= 0) ? qty : 0 ; // Validate price: If less than 0 , make it 0;
    this->price_per_item = (pricePerItem >= 0) ? pricePerItem : 0 ; // Validate price: If less than 0 , make it 0;
}

// Memeber function ---> return invoice amount
int Invoice::getInvoiceAmount() {return (quantity * price_per_item);}

// Getters
int Invoice::getPartNumber() const {return part_number;}
std::string Invoice::getPartDescription() const {return part_description;}
int Invoice::getQuantity() const {return quantity;}
int Invoice::getPricePerItem() const {return price_per_item;}

// Setters
void Invoice::setPartNumber(int partNo){this->part_number = part_number;}
void Invoice::setPartDescription(std::string partDesc){this->part_description = partDesc;}
void Invoice::setQuantity(int qty){this->quantity = (qty>=0) ? qty:0;} 
void Invoice::setPricePerItem(int price_per_item){this->price_per_item = (price_per_item>=0) ? price_per_item : 0;}