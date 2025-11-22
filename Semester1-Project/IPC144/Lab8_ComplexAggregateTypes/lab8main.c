/***************************************************************** 

    File: lab8main.c

    Author: [Your Name]
    Seneca email: [Your Seneca email address]

    To compile program in codespaces, in terminal pane type:
        gcc -Wall lab8.c lab8main.c
    To run program in codespaces, in terminal pane type:
        ./a.out
        
***************************************************************/
//Uncomment the next line if you are using Visual Studio
//#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>
#include "lab8.h"
#define SIZE 20

int main(void)
{
    struct DateTime recordsInt[SIZE] = {{0}};
    struct DateTime recordsChar[SIZE] = {{0}};
    readNumericDataFile("lab8format1.txt", recordsInt, SIZE);
    readStringDataFile("lab8format2.txt", recordsChar, SIZE);
    printToFile("printToFile.txt", recordsInt, SIZE);
    }