// SUccessful execution in main file

#include"Ashwin_Mahajan_task4_Simpletron.h"
#include<iostream>

int main(){

    // Lets make 2 objects
    Simpletron pc1;
    Simpletron pc2;

    // Load programs in both objects
    pc1.loadPrograms();
    // pc2.loadPrograms();

    // Execute and check execution
    pc1.executeOp();
    // pc2.executeOp();

    std::cout<<"The sum of no is: "<<pc1.getSum()<<std::endl;
    std::cout<<"The average calculation:- "<<pc1.getAverage()<<std::endl;
    std::cout<<"The largest no: "<<pc1.getLargest()<<std::endl;

}
