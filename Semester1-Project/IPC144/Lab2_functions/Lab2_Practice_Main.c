/***************************************************************** 

    File: lab2practicemain.c

    Author: [Your Name]
    Seneca email: [Your Seneca email address]

    To compile program in codespaces, in terminal pane type:
        gcc -Wall lab2practice.c lab2practicemain.c
    To run program in codespaces, in terminal pane type:
        ./a.out

	Write your test main in this file to test your functions
        
***************************************************************/
//Uncomment the next line if you are using Visual Studio
//#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "Lab2_Practice.h"

int main(void)
{
    int hours = 2, minutes = 3, seconds = 4;

    printf("Thus the total number of seconds = %d + %d + %d = %d", hours*3600, minutes*60, seconds, numSeconds(hours, minutes, seconds));
    return 0;
}