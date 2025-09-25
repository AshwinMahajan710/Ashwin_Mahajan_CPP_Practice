
// In this exercise, you’ll create a Flight class that could be used in a simple air-traffic-control
// simulator. The application’s main function will act as air traffic control. Visit sites such as
// www.howstuffworks.com/air-traffic-control.htm
// to research how the air-traffic-control system works. Then identify some key attributes of a Flight
// in an air-traffic-control system. Think about the different states a plane could be in from the time
// it’s parked at an airport gate until it arrives at its destination—parked, taxiing, waiting to take off,
// taking off, climbing, and so on. Use a FlightStatus enumeration to represent these states. The
// attributes might include the plane’s make and model, current air speed, current altitude, direction,
// carrier, departure time, estimated arrival time, origin and destination. The origin and destination
// should be specified using standard three-letter airport codes, such as BOS for Boston and LAX for Los
// Angeles (these codes are available at world-airport-codes.com). Provide set and get functions to
// manipulate these and any other attributes you identify. Next, identify the class’s behaviors and
// implement them as functions of the class. Include behaviors such as changeAltitude, reduceSpeed
// and beginLandingApproach. The Flight constructor should initialize a Flight’s attributes. You
// should also provide a toString function that returns a string representation of a Flight’s current
// status (e.g., parked at the gate, taxiing, taking off, changing altitude). This string should include
// all of the object’s instance-variable values.
// When the application executes, main will display the message, "Air Traffic Control Simula-
// tor", then will create and interact with three Flight objects representing planes that are currently
// flying or preparing to fly. For simplicity, the Flight’s confirmation of each action will be a message
// displayed on the screen when the appropriate function is called on the object. For example, if you
// call a flight’s changeAltitude function, the method should:
// a) Display a message containing the airline, flight number, "changing altitude", the cur-
// rent altitude and the new altitude.
// b) Change the state of the status data member to CHANGING_ALTITUDE.
// c) Change the value of the newAltitude data member.
// In main, create and initialize three Flight objects that are in different states—for example, one
// could be at the gate, one could be preparing for takeoff and one could be preparing for landing.
// The main function should send messages to (invoke functions on) the Flight objects. As a Flight
// object receives each message, it should display a confirmation message from the function being
// called—such as “[Airline name] [Flight number] changing altitude from 20000 to 25000 feet.”
// The function should also update the appropriate state information in the Flight object. For exam-
// ple, if Air Traffic Control sends a message like “[Airline] [flight number] descend to 12000 feet,”
// the program should execute a function call like flight1.changeAltitude(12000), which would
// display a confirmation message and would set data member newAltitude to 12000. [Note: Assume
// the Flight’s currentAltitude data member is being set automatically by the plane’s altimeter.]
#ifndef FLIGHT_H
#define FLIGHT_H

#include <string>

enum class FlightStatus {
    PARKED_AT_GATE, // parked
    ARRIVED_AT_GATE, // finally arrived
    TAXIING, // moving on ground  
    LANDED_TAXIING, // moving on ground when landing
    TAKEOFF,
    CLIMBING, // getting altitude after takeof
    DESCENDING, // descending
    LANDING, // Landing 
    OTHER
};

class Flight{
    
    private:
        // All the attributes of plane 
        std::string airline;
        std::string flightNumber;
        std::string planeModel;
        double currentSpeed;    
        double currentAltitude; 
        double targetAltitude;  
        std::string departureTime;
        std::string estimatedArrivalTime;
        std::string start_destination; 
        std::string end_destination;
        FlightStatus status;
    
    public:
        Flight(std::string airline,std::string flightNumber,std::string planeModel,std::string departureTime,std::string estimatedArrivalTime, std::string start_destination, std::string end_destination,std::string status);

        std::string getStatusName(FlightStatus ) const; // will return name based on flight status
        FlightStatus getStatusAttr(std::string ) const; // will return Flightstatus based on name

        // Change altitude
        void changeAltitude(double newAltitude);  

        // Reduce or increase speed
        void changeSpeed(double newSpeed);  

        // Begin landing approach
        void beginLandingApproach();  

        // Display flight info
        void PrintFlightDetails() const;

};

#endif