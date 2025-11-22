/*************************************************************************
Write a program that will calculate a weighted-grade for a course where 
the marks come from 3 tests. Each test has a different weight towards 
the final grade as listed below:

Test-1: 20%
Test-2: 30%
Test-3: 50%
Write a program that will ask the user to enter their percentage grade for each test then use the entered values to calculate their final grade

Please enter the percentage grade of the first test: 90.3
Please enter the percentage grade of the second test: 22.7
Please enter the percentage grade of the third test: 60.3
The final grade is: 55.02 %
**************************************************************************/

#define CRT_CECURE_NO_WARNING
#include <stdio.h>
int main(void)
{
    double test1Pct;
    double test2Pct;
    double test3Pct;
    double gradeFinal;

    printf("Please enter the percentage grade of the first test: ");
    scanf("%lf", &test1Pct);
    printf("Please enter the percentage grade of the second test: ");
    scanf("%lf", &test2Pct);
    printf("Please enter the percentage grade of the third test: ");
    scanf("%lf", &test3Pct);

    gradeFinal = (test1Pct * 0.2) + (test2Pct * 0.3) + (test3Pct * 0.5);

    printf("The final grade is: %.2lf %%", gradeFinal);

    return 0;
}