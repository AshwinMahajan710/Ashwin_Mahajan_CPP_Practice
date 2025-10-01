// Main file for battery monitor

#include<iostream>
#include<string>
#include"Ashwin_Mahajan_task2_BatteryMonitor.h"

int main(){

    // Creating 2 object of battery monitor
    BatteryMonitor s1("SCT101", 300, 4.0, 5.0, true, 3); // 80% health
    BatteryMonitor s2("SCT202", 150, 3.5, 5.0, true, 2); // 70% health

    // Populating the trips using [] as per the no of trips count in objects
    s1[0] = 12; s1[1] = 18; s1[2] = 25;
    s2[0] = 10; s2[1] = 15;

    // Displaying both objects using string
    std::cout<<"\nScooter s1 status: "<<std::endl;
    std::cout<<s1;
    std::cout<<"\nScooter s2 status: "<<std::endl;
    std::cout<<s2;

    // compare healths
    if(s1>s2) {std::cout<<"\nHealth of s1 is greater than health of s2.."<<std::endl;}
    else if(s1<s2) {std::cout<<"\nHealth of s1 is smaller than health of s2.."<<std::endl;}

    // Simulate the charge cycles on s1 and check on the reduced capacity
    s1 += 50;
    std::cout<<"\nScooter s1 new status: "<<std::endl;
    std::cout<<s1;

    // check the actiavtion status of scooter
    if(!s1) {std::cout<<"\nScooter is not active..."<<std::endl;}
    else {std::cout<<"\nScooter is active..."<<std::endl;}

    // Create new object v3 and then verify that it is deep copy or not
    BatteryMonitor s3("SCT303", 500, 8.0, 10.0, false, 3);
    s3[0] = 123; s3[1] = 101; s3[2] = 456;

    std::cout<<"\nScooter s3 status: "<<std::endl;
    std::cout<<s3;

    s3 = s1; // deep copy
    std::cout<<"\nScooter s3 new status: "<<std::endl;
    std::cout<<s3;

    s3[0] = 500;

    std::cout<<"\nScooter s1 new status after modification in s3: "<<std::endl;
    std::cout<<s1;

    std::cout<<"\nScooter s3 new status after modification in s3: "<<std::endl;
    std::cout<<s3;


    // memory cleaned via destructor as delete function was called in the dynamic array

    return  0;
}