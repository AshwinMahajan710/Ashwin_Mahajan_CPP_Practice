#include<iostream>

void printClassification(const std::string& label){
    std::cout<<" The parcel you passed is: "<<label<<std::endl;
}

class ParcelAnalyzer{
    public:
        std::string classifyWeight(int grams){// Accepts weight in grams
            if(grams<500){return "Light";}
            else if(grams>=500 && grams<=2000){return "Medium";}
            else {return "Heavy";}
        } 
        std::string classifyWeight(float kilograms){// Accepts weight in kilograms
            if(kilograms<0.5){return "Light";}
            else if(kilograms>=0.5 && kilograms<=2.0){return "Medium";}
            else {return "Heavy";}
        } 
        std::string classifyWeight(double pounds){// Accepts weight in pounds
            if(pounds<1.1){return "Light";}
            else if(pounds>=1.1 && pounds<=4.4){return "Medium";}
            else {return "Heavy";}
        } 
};

int main(){
    ParcelAnalyzer parcel_analyzer;

    // Calling object with grams
    printClassification(parcel_analyzer.classifyWeight(650));
    
    // calling object with kilograms
    printClassification(parcel_analyzer.classifyWeight(float(2.2)));

    // calling weight with pounds
    printClassification(parcel_analyzer.classifyWeight(double(4.4)));


    return 0;
}