
// GraduateStudent header file

#include"Ashwin_Mahajan_task4_Student.h"
#ifndef GRADUATE_STUDENT_H
#define GRADUATE_STUDENT_H

class GraduateStudent : public Student{
    public:
        std::string advisor;

        GraduateStudent(std::string name,std::string studentID,std::string department,std::string advisor);
        virtual void displayInfo() const;
        virtual std::string getLevel() const;
};

#endif