
// Student header file

#include<string>
#include<iostream>

#ifndef STUEDENT_H
#define STUEDENT_H

// class student
class Student{
    public:
        std::string name;
        std::string studentID;
        std::string department;

        Student(std::string name,std::string studentID,std::string department);
        virtual void displayInfo() const;
        virtual std::string getLevel() const;
};

#endif