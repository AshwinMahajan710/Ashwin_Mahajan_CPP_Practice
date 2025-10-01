
// NonThesisMastersStudent header file

#include"Ashwin_Mahajan_task4_MastersStudent.h"
#ifndef NON_THESIS_MASTER_STUDENT_H
#define NON_THESIS_MASTER_STUDENT_H

class NonThesisMastersStudent : public MastersStudent{
    public:
        std::string projectTitle;
        NonThesisMastersStudent(std::string name,std::string studentID,std::string department,std::string advisor,std::string projectTitle);
        virtual void displayInfo() const;
        virtual std::string getLevel() const;
};

#endif