// Print details

#include <iostream>
#include "Ashwin_Mahajan_task4_AirTrafficController.h"

int main() {
    std::cout << "* * * * * * * * * * * * * * * * * * * Air Traffic Control Simulator * * * * * * * * * * * * * * * * * * * * " << std::endl;

    // Flight at the gate
    Flight flight1("IndiGo", "6E203", "Airbus A320", "08:30", "10:15", "DEL", "BOM", "PARKED_AT_GATE");

    // Flight preparing for takeoff
    Flight flight2("Air India", "AI101", "Boeing 787", "09:00", "13:45", "DEL", "LHR", "TAKEOFF");

    // Flight descending for landing
    Flight flight3("SpiceJet", "SG305", "Boeing 737", "07:15", "09:30", "BLR", "MAA", "DESCENDING");

    // Print details of all flights
    std::cout << "\n--- Flight 1 Details ---" << std::endl;
    flight1.PrintFlightDetails();

    std::cout << "\n--- Flight 2 Details ---" << std::endl;
    flight2.PrintFlightDetails();

    std::cout << "\n--- Flight 3 Details ---" << std::endl;
    flight3.PrintFlightDetails();

    return 0;
}
