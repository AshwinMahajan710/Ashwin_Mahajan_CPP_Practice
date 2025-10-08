#include"Ashwin_Mahajan_Oct08_Task3_GradeLevel.h"
#include"Ashwin_Mahajan_Oct08_Task3_Student.h"
#include"Ashwin_Mahajan_Oct08_Task3_SubjectScore.h"

void summarizeGrades(Student* students[], int studentCount);
const SubjectScore* findTopScorer(Student* students[], int studentCount, const std::string& subject);
void exportAllDistinctions(Student* students[], int studentCount);