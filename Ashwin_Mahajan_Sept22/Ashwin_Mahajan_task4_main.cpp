#include<iostream>
#include"Ashwin_Mahajan_task4_HeartRates.h"
int main(){
    HeartRates patient("Ashwin","Mahajan",7,10,2003);
    
    // Check
    std::cout<<"Patients Name: "<<patient.getFirstName()<<" "<<patient.getLastName()<<std::endl;
    std::cout<<"Patients birth date is: "<<patient.getBirthDay()<<"/"<<patient.getBirthMonth()<<"/"<<patient.getBirthYear()<<std::endl;
    std::cout<<"Patients age is: "<<patient.getPersonAge()<<" His Max heart rate should be: "<<patient.getMaxiumumHeartRate()<<" And his targeted heart rate should be (80%): "<<patient.getTargetHeartRate()<<std::endl;
}