/*************************************************************************
Please enter the first number: 15
Please enter the second number: 18
Please enter the third number: 20
The average of 15, 18, and 20 is 17.67
**************************************************************************/

#define CRT_CECURE_NO_WARNING
#include <stdio.h>
int main(void)
{
    int numFirst;
    int numSecond;
    int numThird;
    double average;

    printf("Please enter the first number: ");
    scanf("%d", &numFirst);
    printf("Please enter the second number: ");
    scanf("%d", &numSecond);
    printf("Please enter the third number: ");
    scanf("%d", &numThird);

    average = (numFirst + numSecond + numThird) / 3.00;

    printf("The average of %d, %d, and %d is %.2lf", numFirst, numSecond, numThird, average);


    return 0;
}