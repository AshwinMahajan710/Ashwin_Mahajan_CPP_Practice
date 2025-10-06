// DoctoralStudent header file

#include"Ashwin_Mahajan_Oct06_Task2_GraduateStudent.h"
#ifndef DOCTORAL_STUDENT_H
#define DOCTORAL_STUDENT_H

class DoctoralStudent : public GraduateStudent{
    public:
        std::string dissertationTitle;
        int yearsInProgram;
        DoctoralStudent(std::string name,std::string studentID,std::string department,std::string advisor, std::string dissertationTitle, int yearsInProgram);
        virtual void displayInfo() const;
        virtual std::string getLevel() const;
};

#endif