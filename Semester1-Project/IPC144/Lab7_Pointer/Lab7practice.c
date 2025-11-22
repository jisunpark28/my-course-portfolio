#include <stdio.h>

//a struct to store all the information you need regarding 
struct Assessment
{
	float mark;	//number of marks received for assessment
	float max;	//total number of marks for the assessment (max score)
	int weight; //weight of the assessment
};

struct Grades{
	int Labs
	int Projfects
	int quizzes
	int midterm
	int final 
};


//This function is passed the address of a Grades struct and a character array.  
//It will then apply the course rules for a course to determine the final letter 
//grade and store that into letterGrade as a null terminated string.  
//You are welcome to add additional functions if you wish to help break down the problem

void calculateGrades(struct Grades* graderecord, char letterGrade[]);

int main(void)
{
	char finalGrade[5];
	struct Grades myMarks = {};  //initialize this struct to store your grades

	//Note this is your calculation of your marks... it may not be correct (bug in code)
	calculateGrades(&myMarks, finalGrade);
	printf("The function calculated my mark to be: %s\n", finalGrade);

	return 0;
}

void calculateGrades(struct Grades* graderecord, char letterGrade[])
{

}
