/***************************************************************** 

    File: lab7.c

    Author: Jisun Park
    Seneca email: jpark295@myseneca.ca

    To compile program in codespaces, in terminal pane type:
        gcc -Wall lab7.c lab7main.c
    To run program in codespaces, in terminal pane type:
        ./a.out
        
***************************************************************/
//Uncomment the next line if you are using Visual Studio
//#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "Lab7.h"

int findDate(int day, int month, int year, struct Date dates[],int size){
    int i, index=0, flag=0;
    for(i=0;i<size && flag==0;i++){
        if (day == dates[i].day && month == dates[i].month && year==dates[i].year){
            index=i;
            flag=1;
        }
        else{
            index=-1;
        }
    }
    return index;
}

int numInYear(int year, struct Date dates[], int size){
    int i, numMatch=0;
    for(i=0; i<size; i++){
        if (year == dates[i].year){
            numMatch++;
        }
    }
    return numMatch;
}

int cmpDates(int dayIndex1, int dayIndex2, struct Date dates[]){
    int compare;
    int dates1 = dates[dayIndex1].year*10000 + dates[dayIndex1].month*100 + dates[dayIndex1].day;
    int dates2 = dates[dayIndex2].year*10000 + dates[dayIndex2].month*100 + dates[dayIndex2].day;

    if(dates1 == dates2){
        compare = 0;
    }else if (dates1 < dates2){
        compare = 1;
    }else{
        compare = -1;
    }
    return compare;
}

void printDates(struct Date dates[], int size){
    int i;
    const char monthNames[13][10] = {" ", "January", "February", "March", "April", "May", "June", 
        "July", "August", "September", "October", "November", "December"};
    for(i=0;i<size;i++){
        printf("%s %d, %d\n",monthNames[dates[i].month], dates[i].day, dates[i].year);
    }
}