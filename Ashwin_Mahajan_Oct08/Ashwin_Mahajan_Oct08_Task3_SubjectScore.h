
// Subject Score header file

#ifndef SUBJECT_SCORE_H
#define SUBJECT_SCORE_H

#include<string>
#include"Ashwin_Mahajan_Oct08_Task3_GradeLevel.h"

class SubjectScore{
    private:
        std::string subjectName;
        int score;
        GradeLevel grade;

    public:
        SubjectScore(std::string subjectName, int score,std::string grade);
        void displaySubjectScore() const;
        
        // get grade using string grade
        GradeLevel getGradeUsingString(std::string) const;

        // getters
        std::string getGradeStringName()const;
        std::string getSubjectName() const;
        int getScore() const;
        GradeLevel getGrade() const;
};

#endif