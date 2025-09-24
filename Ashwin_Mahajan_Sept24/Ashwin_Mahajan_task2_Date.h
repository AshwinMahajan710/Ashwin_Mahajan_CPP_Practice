
#ifndef DATE_H
#define DATE_H

// Class date
class Date
{
    private:
        int month;
        int day;
        int year;
        static int days[13];
        
    public:
        Date( int = 1, int = 1, int = 2000 ); // default constructor
        void print() const; // To print the date
        void nextDay(); // To increent the date
        bool isLeap(int) const; // Additional function to check if year is leap or not
        bool Validate_day(int,int,int);

        // Setters
        void setDate(int,int,int);
        void setYear(int);
        void setMonth(int);
        void setDay(int);

        // Getters
        int getDay() const;
        int getMonth() const;
        int getYear() const;

};

#endif
