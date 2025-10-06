#include<iostream>
#include"Ashwin_Mahajan_Oct06_Task5_OvernightPackage.h"
#include"Ashwin_Mahajan_Oct06_Task5_TwoDayPackage.h"
#include"Ashwin_Mahajan_Oct06_Task5_Package.h"
#include<string>
#include<vector>

int main(){
    std::vector<Package*> packages;

    // pushing two packages
    packages.push_back(new OvernightPackage("Ashwin Mahajan","Savata Nagar, Nashik","Maharashtra","422009","Sudam Sonawane","Pavan nagar, Pune","Maharashtra","422004", 4, 12,10));
    
    packages.push_back(new TwoDayPackage("Digvijay Dada","Indian church, Bombay","Maharashtra","422012","Dipak sonawane","Phule vasti, Bikaner","Gujrat","434004", 8, 10,50));

    for(int i=0;i<2;i++){
        std::cout<<std::endl;
        packages[i]->display();
    }
}