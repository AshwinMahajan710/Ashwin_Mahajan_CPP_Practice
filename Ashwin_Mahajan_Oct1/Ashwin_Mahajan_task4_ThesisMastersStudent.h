
// ThesisMastersStudent header file

#include"Ashwin_Mahajan_task4_MastersStudent.h"
#ifndef THESIS_MASTER_STUDENT_H
#define THESIS_MASTER_STUDENT_H

class ThesisMastersStudent : public MastersStudent{
    public:
        std::string thesisTitle;
        ThesisMastersStudent(std::string name,std::string studentID,std::string department,std::string advisor,std::string thesisTitle);
        virtual void displayInfo() const;
        virtual std::string getLevel() const;
};

#endif