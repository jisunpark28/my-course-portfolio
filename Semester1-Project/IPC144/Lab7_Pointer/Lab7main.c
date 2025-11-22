/***************************************************************** 

    File: lab7main.c

    Author: Jisun Park
    Seneca email: jpark295@myseneca.ca

    To compile program in codespaces, in terminal pane type:
        gcc -Wall Lab7.c Lab7main.c
    To run program in codespaces, in terminal pane type:
        ./a.out
        
***************************************************************/
//Uncomment the next line if you are using Visual Studio
//#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "Lab7.h"

int main(void)
{
    //Function1
    struct Date dates[3]={{1,1,2024},{2,9,2023},{24,11,2024}};
    int day = 14;
    int month = 9;
    int year = 2020;
    int index = findDate(day, month, year, dates, 3);
    printf("%d\n", index);

    //Function2 
    int numMatch = numInYear(year, dates, 3);
    printf("%d\n", numMatch);

    //Function3
    int dayIndex1 = 0;
    int dayIndex2 = 1;
    int compare = cmpDates(dayIndex1, dayIndex2, dates);
    printf("%d\n", compare);

    //Function4
    printDates(dates, 3);
}

