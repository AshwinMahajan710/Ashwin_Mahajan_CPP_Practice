//     (Enhancing Class Time) Modify the Time class of Figs. 9.8–9.9 to include a tick member
// function that increments the time stored in a Time object by one second. The Time object should
// always remain in a consistent state. Write a program that tests the tick member function in a loop
// that prints the time in standard format during each iteration of the loop to illustrate that the tick
// member function works correctly. Be sure to test the following cases:
// a) Incrementing into the next minute.
// b) Incrementing into the next hour.
// c) Incrementing into the next day (i.e., 11:59:59 PM to 12:00:00 AM).

#ifndef TIME_H
#define TIME_H

// Class Time 
class Time{
    private:
        int hour;
        int minute;
        int second;
    
    public:

        // Constructor --> with parameters already initialized
        Time(int hour=0, int min = 0, int second = 0);

        // Setters
        void setTime( int, int, int ); // set hour, minute, second
        void setHour( int ); // set hour (after validation)
        void setMinute( int ); // set minute (after validation)
        void setSecond( int ); // set second (after validation)

        // Getters
        int getHour() const; // Rteurn time in hours
        int getMinute() const; // Return time in minutes
        int getSecond() const; // Return time in seconds

        // Printing complete time 
        void printUniversal() const; // output time in universal-time format
        void printStandard() const; // output time in standard-time format'

        // Tick function which will increase time by seconds
        void tick(); // funtion which will increment time in second
};

#endif