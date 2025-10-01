
// MastersStudent header file

#include"Ashwin_Mahajan_task4_GraduateStudent.h"
#ifndef MASTER_STUDENT_H
#define MASTER_STUDENT_H

class MastersStudent : public GraduateStudent{
    public:
    
        MastersStudent(std::string name,std::string studentID,std::string department,std::string advisor);
        virtual void displayInfo() const;
        virtual std::string getLevel() const;
};

#endif