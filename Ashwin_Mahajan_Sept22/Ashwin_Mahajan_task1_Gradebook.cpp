//  Source file --> Implementation of class


#include <iostream>
#include "Ashwin_Mahajan_task1_Gradebook.h" 

// Constructor --> definition
GradeBook::GradeBook(std::string name, std::string instructorName){
    this->courseName = name;
    this->courseInstructorName = instructorName;
}

// Setter
void GradeBook::setCourseName(std::string name){
    if ( name.length() <= 25 ){
        courseName = name;
    } 
    else{
        courseName = name.substr( 0, 25 );
        std::cout << "Name \"" << name << "\" exceeds maximum length (25).\n"<< "Limiting courseName to first 25 characters.\n" << std::endl;
    }
}

// Setter for course instructor name
void GradeBook::setCourseInstructorName(const std::string instructorName){
    this->courseInstructorName = instructorName;
}

// Getter 
std::string GradeBook::getCourseName() const{
    return courseName;
}

std::string GradeBook::getCourseInstructorName() const{
    return courseInstructorName;
}

// Display message function
void GradeBook::displayMessage() const{
    std::cout << "Welcome to the grade book for\n" << getCourseName()<< "!" << std::endl;
    std::cout<<"The Instructor name for this course is: "<<getCourseInstructorName()<<" !"<<std::endl;
}