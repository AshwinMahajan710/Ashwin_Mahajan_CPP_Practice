
// Header file ---> Declaration of class
#include<string>

#ifndef INVOICE_H
#define INVOICE_H

// Declaration of invoice class
class Invoice{
    private:
        int part_number;
        std::string part_description;
        int quantity; // Quantity of item purchased
        int price_per_item; 

    public:

        // COnstructor
        Invoice(int,std::string,int,int);

        // Getters
        int getPartNumber() const;
        std::string getPartDescription() const;
        int getQuantity() const;
        int getPricePerItem() const;

        //Setters
        void setPartNumber(int);
        void setPartDescription(std::string);
        void setQuantity(int);
        void setPricePerItem(int);

        // Member function :- Get invoice amount
        int getInvoiceAmount();

};

#endif