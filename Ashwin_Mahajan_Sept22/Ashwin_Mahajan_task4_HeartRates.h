// (Target-Heart-Rate Calculator) While exercising, you can use a heart-rate monitor to see
// that your heart rate stays within a safe range suggested by your trainers and doctors. According to the
// American Heart Association (AHA) (www.americanheart.org/presenter.jhtml?identifier=4736),
// the formula for calculating your maximum heart rate in beats per minute is 220 minus your age in
// years. Your target heart rate is a range that is 50–85% of your maximum heart rate. [Note: These for-
// mulas are estimates provided by the AHA. Maximum and target heart rates may vary based on the health,
// fitness and gender of the individual. Always consult a physician or qualified health care professional before
// beginning or modifying an exercise program.] Create a class called HeartRates. The class attributes
// should include the person’s first name, last name and date of birth (consisting of separate attributes
// for the month, day and year of birth). Your class should have a constructor that receives this data as
// parameters. For each attribute provide set and get functions. !!!!!!!The class also should include a function
// getAge that calculates and returns the person’s age (in years), a function getMaxiumumHeartRate that
// calculates and returns the person’s maximum heart rate and a function getTargetHeartRate that cal-
// culates and returns the person’s target heart rate. Since you do not yet know how to obtain the current
// date from the computer, function getAge should prompt the user to enter the current month, day
// and year before calculating the person’s age. Write an application that prompts for the person’s in-
// formation, instantiates an object of class HeartRates and prints the information from that object—
// including the person’s first name, last name and date of birth—then calculates and prints the person’s
// age in (years), maximum heart rate and target-heart-rate range.

// Header File --> Declaration of class

#include<string>

class HeartRates{
    private:
        std::string f_name;
        std::string l_name;
        int birth_day;
        int birth_month;
        int birth_year;

    public:

        // Constructor
        HeartRates(std::string,std::string, int , int, int);

        // Getters
        std::string getFirstName() const;
        std::string getLastName() const;
        int getBirthDay() const;
        int getBirthMonth() const;
        int getBirthYear() const;

        // Setters
        void setFirstName(std::string);
        void setLastName(std::string);
        void setBirthDay(int);
        void setBirthMonth(int);
        void setBirthYear(int );

        // Return persons age in years
        int getPersonAge(); // No need to prompt the day , month and year as we can get it from system
        int getMaxiumumHeartRate();
        int getTargetHeartRate();

};
