/***************************************************************** 

    File: lab2.c

    Author: [Your Name]
    Seneca email: [Your Seneca email address]

    To compile program in codespaces, in terminal pane type:
        gcc -Wall lab2_Demo1.c lab2_Demo1_Main.c
    To run program in codespaces, in terminal pane type:
        ./a.out
        
***************************************************************/

#include <stdio.h>
#include "Lab2_Demo1.h"

int lastDigit(int number){

    return number % 10;
}

int wholeMinutes(int seconds){

    return seconds / 60;
}