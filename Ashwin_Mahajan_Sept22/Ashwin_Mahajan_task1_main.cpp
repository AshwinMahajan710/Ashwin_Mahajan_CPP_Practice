//  Main file: usage of the class

#include<iostream>
#include "Ashwin_Mahajan_task1_Gradebook.h" 

int main(){
    
    // Calling the gradebooks constructor
    GradeBook gradeBook1( "CS101 Introduction to Programming in C++","Ashwin Mahajan" );
    GradeBook gradeBook2( "CS102 C++ Data Structures", "Saurach Sarode");
    
    // display each GradeBook's courseName
    std::cout << "gradeBook1's initial course name is: "<< gradeBook1.getCourseName()<<" And its instructor name is: "<<gradeBook1.getCourseInstructorName()<< "\ngradeBook2's initial course name is: "<< gradeBook2.getCourseName()<<" And its instructor name is: "<<gradeBook2.getCourseInstructorName() << std::endl;
    
    // modify myGradeBook's courseName (with a valid-length string)
    gradeBook1.setCourseName( "CS101 C++ Programming" );
    
    // display each GradeBook's courseName
    std::cout << "\ngradeBook1's course name is: "<< gradeBook1.getCourseName()<< "\ngradeBook2's course name is: "<< gradeBook2.getCourseName() << std::endl;
}