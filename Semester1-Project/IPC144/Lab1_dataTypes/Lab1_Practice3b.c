/*************************************************************************
Expanding on problem 3a, suppose each test was graded out of 50 (raw marks). 
All scores are whole numbers out of 50 however each test is worth it's 
respective percentage of the course grade. 
Rewrite the previous problem so that it takes in the raw scores out of 50 
and calculate their final grade

Please enter the grade of the first test out of 50: 36
Please enter the grade of the second test out of 50: 44
Please enter the grade of the third test out of 50: 33
The final grade is: 73.80 %
**************************************************************************/
#define CRT_CECURE_NO_WARNING
#include <stdio.h>
int main(void)
{
    int gradeFirst, gradeSecond, gradeThird;
    double finalGrade;

    printf("Please enter the grade of the first test out of 50: ");
    scanf("%d", &gradeFirst);
    printf("Please enter the grade of the second test out of 50: ");
    scanf("%d", &gradeSecond);
    printf("Please enter the grade of the third test out of 50: ");
    scanf("%d", &gradeThird);    

    finalGrade = (2 * gradeFirst) * 0.2 + (2 * gradeSecond) * 0.3 + (2 * gradeThird) * 0.5;

    printf("The final grade is: %.2lf", finalGrade);  

    return 0;
}