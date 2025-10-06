// PhDCandidate header file

#include"Ashwin_Mahajan_Oct06_Task2_DoctoralStudent.h"
#ifndef PHD_CANDIDATE_H
#define PHD_CANDIDATE_H

class PhDCandidate : public DoctoralStudent{
    public:

        PhDCandidate(std::string name,std::string studentID,std::string department,std::string advisor, std::string dissertationTitle, int yearsInProgram);
        virtual void displayInfo() const;
        virtual std::string getLevel() const;
};

#endif