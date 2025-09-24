#include<iostream>
#include"Ashwin_Mahajan_task1_Time.h" // Using the existing class from task1

int main(){

    Time time; // Creating object

    std::cout<<" * * * * * * * * * * * * * * * * * *  Time * * * * * * * * * * * * * * * * * * * * * * "<<std::endl;

    while(true){
        int ch; //for choice

        // Print menu of option
        std::cout<<"1. Add Hour Time.."<<std::endl;
        std::cout<<"2. Add Minute Time.."<<std::endl;
        std::cout<<"3. Add Second Time.."<<std::endl;
        std::cout<<"4. Increment time per sec.."<<std::endl;
        std::cout<<"5. Show Standard Time.."<<std::endl;
        std::cout<<"6. Show Universal Time.."<<std::endl;
        std::cout<<"7. Exit.."<<std::endl;

        // entering choice
        std::cout<<"Enter your choice: "<<std::endl;
        std::cin>>ch;

        switch (ch)
        {

        case 1:
            {int hour;
            std::cout<<"Enter Hour time: ";
            std::cin>>hour;
            try{ time.setHour(hour); }
            catch(const std::invalid_argument &e ){
                std::cerr<<"Invalid Argument: "<<e.what()<<std::endl;
                time.setHour(0); // If failed then set hour again to 0
            }
            break;}

        case 2:
            {int minute;
            std::cout<<"Enter Minute time: ";
            std::cin>>minute;
            try{ time.setMinute(minute); }
            catch(const std::invalid_argument &e ){
                std::cerr<<"Invalid Argument: "<<e.what()<<std::endl;
                time.setMinute(0); // If failed then set hour again to 0
            }
            break;}

        case 3:
            {int second;
            std::cout<<"Enter Second time: ";
            std::cin>>second;
            try{ time.setSecond(second); }
            catch(const std::invalid_argument &e ){
                std::cerr<<"Invalid Argument: "<<e.what()<<std::endl;
                time.setSecond(0); // If failed then set hour again to 0
            }
            break;}
            
        case 4:
            {time.tick();
            break;}
        
        case 5:
            {time.printUniversal();
            break;}

        case 6:
            {time.printStandard();
            break;}

        case 7:
            {std::cout<<"\n Exit from program..."<<std::endl;
            return 0;}
            
        default:
            {std::cout<<"Invalid choice..."<<std::endl;
            break;}
        }
    }
    
    return 0;
}
