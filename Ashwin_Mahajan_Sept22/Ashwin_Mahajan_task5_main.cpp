#include<iostream>
#include"Ashwin_Mahajan_task5_HealthProfile.h"
#include<string>
#include<limits>

int main(){

    // Get user input
    std::string fname, lname, gender;
    int day, month, year;
    int height, weight;
    std::cout<<"Enter patients information: "<<std::endl;
    std::cout<<"\nEnter patient first name: ";
    getline(std::cin,fname);
    std::cout<<"\nEnter patient last name: ";
    getline(std::cin,lname);
    std::cout<<"\nEnter patient Gender(MALE,FEMALE,OTHER): ";
    getline(std::cin,gender);
    std::cout<<"\n Enter day, month and year of birth one by one: ";
    std::cin>>day>>month>>year;
    std::cout<<"Enter height (in meter) and Weight (in kg): ";
    std::cin>>height>>weight;

    // Create object
    HealthProfile patient(fname,lname,gender, day, month, year, height, weight);

    // Print information of patient
    std::cout<<"\n* * * * * * * * * * * * * * * * * * * * Patient Information * * * * * * * * * * * * * * * * * * * * "<<std::endl;
    std::cout<<"Patients Name: "<<patient.getFirstName()<<" "<<patient.getLastName()<<std::endl;
    std::cout<<"Patients birth date is: "<<patient.getBirthDay()<<"/"<<patient.getBirthMonth()<<"/"<<patient.getBirthYear()<<std::endl;
    std::cout<<"Patients gender: "<<patient.getGender()<<std::endl;
    std::cout<<"Patients age is: "<<patient.getPersonAge()<<" His Max heart rate should be: "<<patient.getMaxiumumHeartRate()<<" And his targeted heart rate should be (80%): "<<patient.getTargetHeartRate()<<std::endl;
    std::cout<<"Patients BMI: "<<patient.getBMI()<<std::endl;
    return 0;
}