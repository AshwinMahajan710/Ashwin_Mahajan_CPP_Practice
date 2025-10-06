// PostDocFellow header file

#include"Ashwin_Mahajan_Oct06_Task2_DoctoralStudent.h"
#ifndef POST_DOC_H
#define POST_DOC_H

class PostDocFellow : public DoctoralStudent{
    public:
        std::string researchGrant;
        PostDocFellow(std::string name,std::string studentID,std::string department,std::string advisor, std::string dissertationTitle, int yearsInProgram, std::string researchGrant);
        virtual void displayInfo() const;
        virtual std::string getLevel() const;
};

#endif