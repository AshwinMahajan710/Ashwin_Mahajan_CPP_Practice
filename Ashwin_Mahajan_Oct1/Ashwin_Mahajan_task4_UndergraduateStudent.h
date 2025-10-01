
// UndergraduateStudent header file

#include"Ashwin_Mahajan_task4_Student.h"
#ifndef UNDERGRADUATE_STUDENT_H
#define UNDERGRADUATE_STUDENT_H

class UndergraduateStudent : public Student{
    public:
        int year;
        int creditsEarned;

        UndergraduateStudent(std::string name,std::string studentID,std::string department, int year, int creditsEarned);
        virtual void displayInfo() const;
        virtual std::string getLevel() const;
};

#endif