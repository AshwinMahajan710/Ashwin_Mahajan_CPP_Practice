
#include<iostream>

int main(){
    bool seats[10] = {false}; // Assign each element of array with false
    int choice;
    int business_track=0; // Keeps track of business class ticket
    int economy_track=5; // Keeps track of economy class ticktes 
    std::cout<<"* * * * * * * * * * * * * * * * * * * * Train Reservation System * * * * * * * * * * * * * * * * * * * * "<<std::endl;
    while (true)
    {
        std::cout<<"1. Book for first class..."<<std::endl;
        std::cout<<"2. Book for second class..."<<std::endl;
        std::cout<<"3. Exit..."<<std::endl;

        std::cout<<"\nEnter your choice: ";
        std::cin>>choice;

        switch (choice)
        {
        case 1:
            if(business_track <= 4){
                seats[business_track++] = true;
                std::cout<<"Tickets booked successfully for business section... \nSeat no: "<<100+business_track<<std::endl;
            }
            else{
                if(economy_track<=9){
                    int ch;
                    std::cout<<"Business class is full...would you like to book seat in economy class? 1 for 'yes' : 2 for 'no'"<<std::endl;
                    do
                    {
                        std::cin>>ch;
                        switch (ch)
                        {
                        case 1:
                            seats[economy_track++] = true;
                            std::cout<<"Tickets booked in economy class successfully....\n Seat no: "<<100 + economy_track<<std::endl;
                            
                            break;
                        
                        case 2:
                            std::cout<<"Ticket booking cancled..."<<std::endl;

                        default:
                            std::cout<<"Wrong choice enter agin...."<<std::endl;
                            break;
                        }
                    }while(ch!=1 && ch!=2);
                }
                else{
                    std::cout<<"Bookings fulled...Next flight leaves in 3 hours."<<std::endl;
                }
            }
            break;
        
        case 2:
            if(economy_track <= 9){
                seats[economy_track++] = true;
                std::cout<<"Tickets booked successfully for economic section... \nSeat no: "<<100+economy_track<<std::endl;
            }
            else{
                if(business_track<=4){
                    int ch;
                    std::cout<<"Economic class is full...would you like to book seat in Business class? 1 for 'yes' : 2 for 'no'"<<std::endl;
                    do
                    {
                        std::cin>>ch;
                        switch (ch)
                        {
                        case 1:
                            seats[business_track++] = true;
                            std::cout<<"Tickets booked in business class successfully....\n Seat no: "<<100 + business_track<<std::endl;
                            break;
                        
                        case 2:
                            std::cout<<"Ticket booking cancled..."<<std::endl;

                        default:
                            std::cout<<"Wrong choice enter agin...."<<std::endl;
                            break;
                        }
                    }while(ch!=1 && ch!=2);
                }
                else{
                    std::cout<<"Bookings fulled...Next flight leaves in 3 hours."<<std::endl;
                }
            }
            break;
        
        case 3:
            std::cout<<"Thank you for using reservation system..."<<std::endl;
            std::cout<<"The seats available are:";
            for(int i=0;i<10;i++){
                if(seats[i]==false) {std::cout<<" "<<100+i+1;}
            }
            return 0;

        default:
            std::cout<<"Wrong choice entered ... Enter again..."<<std::endl;
            break;
        }
    }
    
    return 0;
}
