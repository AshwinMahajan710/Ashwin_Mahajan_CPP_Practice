
// Student cpp file

#include<iostream>
#include<string>
#include"Ashwin_Mahajan_Oct08_Task3_Student.h"
#include"Ashwin_Mahajan_Oct08_Task3_GradeLevel.h"
#include"Ashwin_Mahajan_Oct08_Task3_SubjectScore.h"

// constructor
Student::Student(){
    for(int i=0;i<10;i++){ this->arr[i] = nullptr; }
    this->scoreCount = 0;
}

// Add score function
void Student::addScores(SubjectScore& score){
    if(scoreCount<10){
        this->arr[scoreCount++] = &score;
        std::cout<<"Score of "<<score.getSubjectName()<<" subject addedd successfully"<<std::endl;
    }
    else{
        std::cout<<"Cannot add score..."<<std::endl;
    }
}

// function to get average score
double Student::getAverageScore()const{
    if(scoreCount==0) {return 0.0;}
    else{
        double sum = 0.0;
        for(int i=0;i<scoreCount;i++){
            sum += arr[i]->getScore();
        }
        return (sum/scoreCount);
    }
}

// function to get count of subjects with distinction
int Student::getSubjectCountWithDistinction() const{
    int count = 0;
    for(int i=0;i<scoreCount;i++){
        if(arr[i]-> getGrade() == GradeLevel::DISTINCTION){
            count++;
        }
    }
    return count;
}

// function to print scores with distinction and merit
void Student::printMeritAndDistinctionScores()const{
    for (int i = 0; i < scoreCount; i++)
    {
        if(arr[i]->getGrade() == GradeLevel::DISTINCTION || arr[i]->getGrade() == GradeLevel::MERIT){
            std::cout<<std::endl;
            arr[i]->displaySubjectScore();
        }
    }
}

// display all 
void Student::displayAll() const{
    for(int i=0;i<scoreCount;i++){
        std::cout<<std::endl;
        arr[i]->displaySubjectScore();
    }
}

// will return the constant pointer to the subject scores 
SubjectScore* const* Student::getSubjectScores() const {
    return arr;
}

// get total score counts
int Student:: getSubjectScoreCounts() const{
    return this->scoreCount;
}