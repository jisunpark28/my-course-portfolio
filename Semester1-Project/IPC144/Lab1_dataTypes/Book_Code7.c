/******************************************
Write a program that will ask the user to enter a decimal number. 
It will then print out the part of the number before the decimal point 
and after the decimal point separately.
You may assume there will be no more than 9 digits before or after the decimal point.
******************************************/

#define CRT_CECURE_NO_WARNING
#include <stdio.h>

int main(void)
{
    int beforeDecimal;
    int afterDecimal;
    
    printf("Please enter a decimal number: ");
    scanf("%d.%d", &beforeDecimal, &afterDecimal);

    printf("The part of the number before the decimal is %d\n", beforeDecimal);
    printf("The part of the number after the decimal is %d\n", afterDecimal);

    return 0;
}