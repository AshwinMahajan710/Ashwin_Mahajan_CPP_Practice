#include"Ashwin_Mahajan_Oct08_Task3_GradeLevel.h"
#include"Ashwin_Mahajan_Oct08_Task3_Student.h"
#include"Ashwin_Mahajan_Oct08_Task3_SubjectScore.h"
#include"Ashwin_Mahajan_Oct08_Task3_Global.h"
#include<iostream>
#include<string>

// function to summarize grades
void summarizeGrades(Student* students[], int studentCount){
    int passCount = 0;
    int meritCount = 0;
    int distinctionCount = 0;
    int failCount = 0;

    for(int i=0;i<studentCount;i++){
        SubjectScore* const* subject = students[i]->getSubjectScores();
        int scoreCounts = students[i]->getSubjectScoreCounts();
        for(int j=0;j<scoreCounts;j++){
            if(subject[j]->getGrade() == GradeLevel::PASS) {passCount++;}
            else if(subject[j]->getGrade() == GradeLevel::DISTINCTION) {distinctionCount++;}
            else if(subject[j]->getGrade() == GradeLevel::MERIT) {meritCount++;}
            else {failCount++;}
        }
    }
    std::cout<<"\nPass: "<<passCount<<"\nFail: "<<failCount<<"\nMerit: "<<meritCount<<"\nDistinction: "<<distinctionCount<<std::endl;
}

// Finding the top score wrt subject
const SubjectScore* findTopScorer(Student* students[], int studentCount, const std::string& subject){
    const SubjectScore* highestScore = nullptr;
    for(int i=0;i<studentCount;i++){
        SubjectScore* const* subjects = students[i]->getSubjectScores();
        int scoreCount = students[i]->getSubjectScoreCounts();
        for(int j=0;j<scoreCount;j++){
            if(subjects[i]->getSubjectName() == subject){
                if(highestScore == nullptr) {highestScore = subjects[i];}
                else{ highestScore = (highestScore->getScore() > subjects[i]->getScore()) ? highestScore : subjects[i];}
            }
        } 
    }
    return highestScore;
}

// details of subject with distinction
void exportAllDistinctions(Student* students[], int studentCount){
    for(int i=0;i<studentCount;i++){
        SubjectScore* const* subjects = students[i]->getSubjectScores();
        int scoreCount = students[i]->getSubjectScoreCounts();
        for(int j=0;j<scoreCount;j++){
            if(subjects[j]->getGrade() == GradeLevel::DISTINCTION){
                std::cout<<"Student "<<i<<": "<<std::endl;
                subjects[j]->displaySubjectScore();
            }
        } 
    }
}