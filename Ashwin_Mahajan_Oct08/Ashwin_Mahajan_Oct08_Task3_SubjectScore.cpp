#include<iostream>
#include"Ashwin_Mahajan_Oct08_Task3_GradeLevel.h"
#include"Ashwin_Mahajan_Oct08_Task3_SubjectScore.h"

// constructor
SubjectScore::SubjectScore(std::string subjectName, int score,std::string grade){
    this->subjectName = subjectName;
    this->score = score;
    this->grade = getGradeUsingString(grade);
}

// Display Subject score
void SubjectScore::displaySubjectScore() const{
    std::cout<<"Subject Name: "<<this->subjectName<<std::endl;
    std::cout<<"Subject Score: "<<this->score<<std::endl;
    std::cout<<"Subject Grade: "<<this->getGradeStringName()<<std::endl;
}

// get grade using string grade
GradeLevel SubjectScore:: getGradeUsingString(std::string gradeName) const{
    if(gradeName == "Distinction") {return GradeLevel::DISTINCTION;}
    else if(gradeName == "Fail") {return GradeLevel::FAIL;}
    else if(gradeName == "Merit") {return GradeLevel::MERIT;}
    else {return GradeLevel::PASS;}
}

// getter for grade
std::string SubjectScore::getGradeStringName() const{
    switch (this->grade)
    {
        case GradeLevel::DISTINCTION :{
            return "Distinction";
            break;
        }

        case GradeLevel::MERIT :{
            return "Merit";
            break;
        }
        case GradeLevel::PASS :{
            return "Pass";
            break;
        }
        case GradeLevel::FAIL :{
            return "Fail";
            break;
        }
        
        default:{
            return "";
            break;
        }
    }
}

// get name
std::string SubjectScore::getSubjectName() const{
    return this->subjectName;
}

int SubjectScore::getScore() const{
    return this->score;
}

GradeLevel SubjectScore:: getGrade() const{
    return grade;
}