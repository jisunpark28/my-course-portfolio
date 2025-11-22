/***************************************************************** 

    File: lab2practice.c

    Author: [Your Name]
    Seneca email: [Your Seneca email address]

    To compile program in codespaces, in terminal pane type:
        gcc -Wall lab2practice.c lab2main.c
    To run program in codespaces, in terminal pane type:
        ./a.out
        
***************************************************************/
#include <stdio.h>
#include "Lab2_Practice.h"

int numSeconds(int hours, int minutes, int seconds)
{
    int total = hours * 60 * 60 + minutes *60 + seconds;

    return total;
}
