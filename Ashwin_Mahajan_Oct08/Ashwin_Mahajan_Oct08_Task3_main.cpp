// Main file

#include"Ashwin_Mahajan_Oct08_Task3_GradeLevel.h"
#include"Ashwin_Mahajan_Oct08_Task3_Student.h"
#include"Ashwin_Mahajan_Oct08_Task3_Student.h"
#include"Ashwin_Mahajan_Oct08_Task3_Global.h"

#include<iostream>
#include<string>

int main(){
    
    // Create first student object
    Student s;

    // Add Subject scores
    SubjectScore* sub1 = new SubjectScore("Math",92,"Distinction");
    SubjectScore* sub2 = new SubjectScore("Physics",78,"Merit");
    SubjectScore* sub3 = new SubjectScore("Chemistry",65,"Pass");
    SubjectScore* sub4 = new SubjectScore("History",45,"Fail");
    SubjectScore* sub5 = new SubjectScore("English",88,"Distinction");

    // Adding all subjects
    s.addScores(*sub1);
    s.addScores(*sub2);
    s.addScores(*sub3);
    s.addScores(*sub4);
    s.addScores(*sub5);

    // display all 
    std::cout<<"\nDisplaying all scores: "<<std::endl;
    s.displayAll();

    // get average score
    std::cout<<"\nAverage score of the student: "<<s.getAverageScore()<<std::endl;

    // displaying count of students with disticntion
    std::cout<<"\nCount of students with distinction: "<<s.getSubjectCountWithDistinction()<<std::endl;

    // top scorers
    std::cout<<"\nTop scorers are : "<<std::endl;
    s.printMeritAndDistinctionScores();
    
    // Now creating second object
    Student s2;

    // adding scores to seconcd obect
    SubjectScore* sub6 = new SubjectScore("Math",38,"Fail");
    SubjectScore* sub7 = new SubjectScore("English",92,"Distinction");
    SubjectScore* sub8 = new SubjectScore("Marathi",98,"Distinction");
    s2.addScores(*sub6);
    s2.addScores(*sub7);
    s2.addScores(*sub8);

    // lets create array of pointers to the students
    Student* arr[2];
    arr[0] = &s; 
    arr[1] = &s2; 

    // now print the report
    std::cout<<"\nThis is the report for all students: "<<std::endl;
    summarizeGrades(arr, 2);
    
    // function to find top scorer for english subject 
    const SubjectScore* top_scorer = findTopScorer(arr,2,"Math");
    if(top_scorer != nullptr) {
        std::cout<<"\nFollowing are the details for top scorer: "<<std::endl;
        top_scorer->displaySubjectScore();
    }
    else{
        std::cout<<"\nStudent with that subject not found.."<<std::endl;
    }

    // now print each students distinction subject
    std::cout<<"\nStudent subject details with disticntion: "<<std::endl;
    exportAllDistinctions(arr,2);

    return 0;
}