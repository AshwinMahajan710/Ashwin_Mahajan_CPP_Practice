#include"Ashwin_Mahajan_task4_AirTrafficController.h"
#include<iostream>

// constructor
Flight::Flight(std::string airline,std::string flightNumber,std::string planeModel,std::string departureTime,std::string estimatedArrivalTime, std::string start_destination, std::string end_destination,std::string status){
    this->airline = airline;
    this->flightNumber = flightNumber;
    this->planeModel = planeModel;
    this->departureTime = departureTime;
    this->estimatedArrivalTime = estimatedArrivalTime;
    this->start_destination = start_destination;
    this->end_destination = end_destination;
    this->status = getStatusAttr(status);
    if (status == "PARKED_AT_GATE" || status == "ARRIVED_AT_GATE")
    {
        this->currentSpeed = 0;
        this->currentAltitude = 0;
        this->targetAltitude = 0;
    }
    else if (status == "LANDED_TAXIING" || status == "TAXIING" || status == "TAKEOFF")
    {
        this->currentSpeed = 100;
        this->currentAltitude = 0;
        this->targetAltitude = 0;
    }
    else if(status == "CLIMBING")
        {
        this->currentSpeed = 300;
        this->currentAltitude = 1000;
        this->targetAltitude = 2000;
    }
    else if(status == "DESCENDING")
        {
        this->currentSpeed = 300;
        this->currentAltitude = 2000;
        this->targetAltitude = 1000;
    }
    else {
        this->currentSpeed = 100;
        this->currentAltitude = 500;
        this->targetAltitude = 500;
    }
};

// get status based on string val
FlightStatus Flight::getStatusAttr(const std::string status) const{
    if(status == "PARKED_AT_GATE"){return FlightStatus::PARKED_AT_GATE;}
    else if(status == "ARRIVED_AT_GATE"){return FlightStatus::ARRIVED_AT_GATE;}
    else if(status == "CLIMBING"){return FlightStatus::CLIMBING;}
    else if(status == "DESCENDING"){return FlightStatus::DESCENDING;}
    else if(status == "LANDED_TAXIING"){return FlightStatus::LANDED_TAXIING;}
    else if(status == "TAXIING"){return FlightStatus::TAXIING;}
    else if(status == "LANDING"){return FlightStatus::LANDING;}
    else if(status == "TAKEOFF"){return FlightStatus::TAKEOFF;}
    else{return FlightStatus::OTHER;}
};

// Get names of the status
std::string Flight::getStatusName(FlightStatus status) const {
    switch (status) {
        case FlightStatus::PARKED_AT_GATE:
            return "PARKED_AT_GATE";
        case FlightStatus::ARRIVED_AT_GATE:
            return "ARRIVED_AT_GATE";
        case FlightStatus::CLIMBING:
            return "CLIMBING";
        case FlightStatus::DESCENDING:
            return "DESCENDING";
        case FlightStatus::LANDED_TAXIING:
            return "LANDED_TAXIING";
        case FlightStatus::TAXIING:
            return "TAXIING";
        case FlightStatus::LANDING:
            return "LANDING";
        case FlightStatus::TAKEOFF:
            return "TAKEOFF";
        case FlightStatus::OTHER:
        default:
            return "OTHER";
    }
}

// function to print flight details
void Flight::PrintFlightDetails() const{
    std::cout << "Airline: " << this->airline << std::endl;
    std::cout << "Plane Model: " << this->planeModel << std::endl;
    std::cout << "Flight Number: " << this->flightNumber << std::endl;
    std::cout << "Departure Time: " << this->departureTime << std::endl;
    std::cout << "Estimated Arrival Time: " << this->estimatedArrivalTime << std::endl;
    std::cout << "Current Altitude: " << this->currentAltitude << std::endl;
    std::cout << "Target Altitude: " << this->targetAltitude << std::endl;
    std::cout << "Current Speed: " << this->currentSpeed << std::endl;
    std::cout << "Origin: " << this->start_destination << std::endl;
    std::cout << "Destination: " << this->end_destination << std::endl;
    std::cout << "Status: " << this->getStatusName(this->status) << std::endl;
}

// changing altitude
void Flight::changeAltitude(double altitude) {
    this->currentAltitude = altitude;
    std::cout<<"Current Altitude changed to: "<<altitude<<std::endl;
}

// changing speed
void Flight::changeSpeed(double speed) {
    this->currentSpeed = speed;
    std::cout<<"Current Speed changed to: "<<speed<<std::endl;
}

// changing status
void Flight::beginLandingApproach() {
    std::cout << airline << " " << flightNumber << " beginning landing approach..."<<std::endl;
    status = FlightStatus::LANDING;
}