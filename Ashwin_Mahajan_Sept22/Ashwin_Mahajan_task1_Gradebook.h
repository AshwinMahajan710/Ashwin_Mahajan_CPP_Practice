// Header File --> Declaration of class

#ifndef GRADEBOOK_H
#define GRADEBOOK_H

#include <string>
#include<iostream>

class GradeBook
{
    private:
        std::string courseName;
        std::string courseInstructorName;

    public:
        GradeBook( std::string , std::string); // constructor that initializes a GradeBook object
        void setCourseName( std::string ); // function that sets the course name
        std::string getCourseName() const; // function that gets the course name
        void setCourseInstructorName( std::string ); // function that sets the course name
        std::string getCourseInstructorName() const; // function that gets the course name
        void displayMessage() const; // function that displays a welcome message
};

# endif