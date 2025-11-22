/***************************************************************** 

    File: lab8.c

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
#include <string.h>
#include "lab8.h"


int readNumericDataFile(const char* name, struct DateTime rec[], int maxCapacity) {
    FILE* fp = NULL;
    fp = fopen(name, "r");
    int count=0;
    if (fp != NULL){

        while (count < maxCapacity && fscanf(fp,"%d,%d,%d,%d,%d", &rec[count].day, &rec[count].month, &rec[count].year, &rec[count].hour, &rec[count].minute) == 5){
            printf("%d,%d,%d,%d,%d\n", rec[count].day, rec[count].month, rec[count].year, rec[count].hour, rec[count].minute);
            count++;
        }
        fclose(fp);
        return count;
    }
    else{
        return 0;
    }
}


int readStringDataFile(const char* name, struct DateTime rec[], int maxCapacity){
    FILE* fp = NULL;
    fp = fopen(name, "r");
    int i = 0;
    char ampm[4];

    if (fp != NULL){


       while(i < maxCapacity && fscanf(fp,"%d/%d/%d;%d:%d %s%*c", &rec[i].day, &rec[i].month, &rec[i].year, &rec[i].hour, &rec[i].minute, ampm) == 6){
            printf("%02d/%02d/%d;%d:%d %s\n", rec[i].day, rec[i].month, rec[i].year, rec[i].hour, rec[i].minute, ampm);
            if(ampm[0]=='p' && rec[i].hour !=12){
                rec[i].hour += 12;
            }else if(ampm[0]=='a' && rec[i].hour ==12){
                rec[i].hour = 0;
            }           
            i++;
        }
        fclose(fp);    
    }
    else{
        printf("File Open Error !!!\n");
    }
    return i;
}

void printToFile(const char* filename, struct DateTime data[], int size){
    FILE* fp = NULL;
    fp = fopen(filename,"w");
    int i;
    const char monthNames[13][10] = {" ", "January", "February", "March", "April", "May", "June", 
        "July", "August", "September", "October", "November", "December"};
    const char* ampm;

    if (fp != NULL){
        for(i=0; i<size; i++){
            if(data[i].hour > 12){
                data[i].hour -= 12;
                ampm="pm";
            }else if(data[i].hour==0){
                data[i].hour = 12;
                ampm="am";
            }else if(data[i].hour==12){
                ampm="pm";
            }else{
                ampm="am";                
            }
            fprintf(fp,"%s %d, %d %d:%02d %s\n",monthNames[data[i].month], data[i].day, data[i].year, data[i].hour, data[i].minute, ampm);
        }
        fclose(fp);
    }else{
        printf("File Open Error !!!\n");     
    }
}