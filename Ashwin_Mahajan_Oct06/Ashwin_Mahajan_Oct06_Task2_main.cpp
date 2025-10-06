#include<iostream>
#include"Ashwin_Mahajan_Oct06_Task2_Student.h"
#include"Ashwin_Mahajan_Oct06_Task2_UndergraduateStudent.h"
#include"Ashwin_Mahajan_Oct06_Task2_Freshman.h"
#include"Ashwin_Mahajan_Oct06_Task2_Sophomore.h"
#include"Ashwin_Mahajan_Oct06_Task2_Junior.h"
#include"Ashwin_Mahajan_Oct06_Task2_Senior.h"
#include"Ashwin_Mahajan_Oct06_Task2_HonorsSenior.h"
#include"Ashwin_Mahajan_Oct06_Task2_ExchangeSenior.h"
#include"Ashwin_Mahajan_Oct06_Task2_GraduateStudent.h"
#include"Ashwin_Mahajan_Oct06_Task2_MastersStudent.h"
#include"Ashwin_Mahajan_Oct06_Task2_ThesisMastersStudent.h"
#include"Ashwin_Mahajan_Oct06_Task2_NonThesisMastersStudent.h"
#include"Ashwin_Mahajan_Oct06_Task2_DoctoralStudent.h"
#include"Ashwin_Mahajan_Oct06_Task2_PhDCandidate.h"
#include"Ashwin_Mahajan_Oct06_Task2_PostDocFellow.h"

int main(){

    // Creating object of each class
    Freshman f("Amit", "UG101", "Computer Science", 1, 15);
    HonorsSenior hs("Neha", "UG401", "Physics", 4, 120, "Quantum Entanglement Thesis");
    ExchangeSenior es("Luca", "UG402", "Mechanical", 4, 110, "Politecnico di Milano");
    ThesisMastersStudent tm("Priya", "GR201", "Electrical", "Dr. Rao", "Smart Grid Optimization");
    NonThesisMastersStudent ntm("Raj", "GR202", "Civil", "Dr. Mehta", "Bridge Load Simulation");
    PhDCandidate phd("Sneha", "GR301", "Biotech", "Dr. Kapoor", "Gene Editing Ethics", 3);
    PostDocFellow pdf("Dr. Tanmay", "GR401", "AI Research", "Dr. Bose", "DARPA Grant",6,"Granted by Amazon");

    // Store it in student array and run each function
    Student* arr[7];
    arr[0] = &f;
    arr[1] = & hs;
    arr[2] = & es;
    arr[3] = & tm;
    arr[4] = & ntm;
    arr[5] = & phd;
    arr[6] = & pdf;

    for(int i=0;i<7;i++){
        std::cout<<"\nElement "<<i<<std::endl;
        arr[i]->displayInfo();
        std::cout<<"Level: "<<arr[i]->getLevel()<<std::endl;
    }

}