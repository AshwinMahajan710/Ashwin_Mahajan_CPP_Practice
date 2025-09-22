//In this exercise, you’ll design a “starter” HealthProfile class for a person. The class attri-
// butes should include the person’s first name, last name, gender, date of birth (consisting of separate
// attributes for the month, day and year of birth), height (in inches) and weight (in pounds). Your class
// should have a constructor that receives this data. For each attribute, provide set and get functions.
// The class also should include functions that calculate and return the user’s age in years, maximum
// heart rate and target-heart-rate range (see Exercise 3.16), and body mass index (BMI; see
// Exercise 2.30). Write an application that prompts for the person’s information, instantiates an ob-
// ject of class HealthProfile for that person and prints the information from that object—including
// the person’s first name, last name, gender, date of birth, height and weight—then calculates and
// prints the person’s age in years, BMI, maximum heart rate and target-heart-rate range. It should also
// display the “BMI values” chart from Exercise 2.30. Use the same technique as Exercise 3.16 to cal-
// culate the person’s age.

#ifndef HEALTH_PROFILE_H
#define HEALTH_PROFILE_H

#include<string>

// Enum class for gender
enum class Gender{
    MALE,
    FEMALE,
    OTHER
};

class HealthProfile{
    private:
        std::string f_name; // First name of patient
        std::string l_name; // Last name of patient
        Gender gender; // Enum class for Gender
        int birth_day;
        int birth_month;
        int birth_year;
        float height;
        float weight;

    public:

        // Constructor
        HealthProfile(std::string,std::string,std::string,int,int,int,float,float);

        // Getters
        std::string getFirstName() const; // First name of patient
        std::string getLastName() const; // Last name of patient
        std::string getGender() const; // Enum class for Gender
        int getBirthDay() const;
        int getBirthMonth() const;
        int getBirthYear() const;
        float getHeight() const;
        float getWeight() const;

        // Setters
        void setFirstName(std::string);
        void setLastName(std::string);
        void setGender(std::string);
        void setBirthDay(int);
        void setBirthMonth(int);
        void setBirthYear(int );
        void setHeight(int);
        void setWeight(int );

        // Function to return users age in years
        int getPersonAge() const;

        // return max_heart_rate
        int getMaxiumumHeartRate() const ;

        // return target_heart_rate
        int getTargetHeartRate() const;

        // Return BMI
        float getBMI() const;

        // Additional Functions 
        // Convert Gender to string
        std::string getGenderName(Gender) const;

        // Convert string to gender
        Gender setGenderUsingNames(std::string);

};  

#endif