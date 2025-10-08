#ifndef STUDENT_H
#define STUDENT_H

#include<string>
#include"Ashwin_Mahajan_Oct08_Task3_SubjectScore.h"
#include"Ashwin_Mahajan_Oct08_Task3_GradeLevel.h"

class Student{
    private:
        SubjectScore* arr[10];
        int scoreCount;

    public:    
        Student();
        void addScores(SubjectScore&);
        double getAverageScore() const;
        int getSubjectCountWithDistinction() const;
        void printMeritAndDistinctionScores() const;
        void displayAll() const;
        SubjectScore* const* getSubjectScores() const;
        int getSubjectScoreCounts() const;
};
#endif