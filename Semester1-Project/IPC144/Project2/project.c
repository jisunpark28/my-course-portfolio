/***************************************************************** 

    File: project.c

    Author: Jisun Park
    Seneca email: jpark295@myseneca.ca

    To compile program in codespaces, in terminal pane type:
        gcc -Wall project.c projectmain.c
    To run program in codespaces, in terminal pane type:
        ./a.out
        
***************************************************************/
//Uncomment the next line if you are using Visual Studio
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "project.h"

int loadData(const char* femaleFile, const char* maleFile, struct BabyName femaleData[], struct BabyName maleData[], int* femaleDataCount, int* maleDataCount) 
{
    int i = 0;
    int j = 0;
    FILE* fpFemale = NULL;
    FILE* fpMale = NULL;

    fpFemale = fopen(femaleFile, "r");
    fpMale = fopen(maleFile, "r");

    if (fpFemale != NULL && fpMale != NULL) {
        fscanf(fpFemale, "%*[^\n]");
        fscanf(fpMale, "%*[^\n]");
        while (i < SIZE && fscanf(fpFemale, "%d,%30[^,],%d%*[^\n]", &femaleData[i].year, femaleData[i].name, &femaleData[i].frequency) == 3) {
            i++;
        }
        *femaleDataCount = i;
        while (j < SIZE && fscanf(fpMale, "%d,%30[^,],%d%*[^\n]", &maleData[j].year, maleData[j].name, &maleData[j].frequency) == 3) {
            j++;
        }
        *maleDataCount = j;
        fclose(fpFemale);
        fclose(fpMale);

        return 1;
    }
    else {
        return 0;
    }
}

int displayMenu()
{
    int mode;

    do {
        printf("\n-----------------------------------------------------\n");
        printf("Baby Name Data Viewer\n\n1. number of babies\n2. top 5 names\n3. histogram\n4. exit\n");
        printf("Enter your choice: ");
        scanf("%d", &mode);
        if (mode > 4 || mode < 1) {
            printf("Number entered was invalid. Please select the option again.\n\n");
        }
    } while (mode > 4 || mode < 1);

    return mode;
}

void findNameCount(struct BabyName femaleData[], struct BabyName maleData[], int szFemale, int szMale)
{
    char getName[31] = { 0 };
    int i;
    int countFemale = 0;
    int countMale = 0;

    //Get name to find the matching name
    printf("Enter the Name:");
    scanf(" %30[^\n]", getName);
    printf("%s\n", getName);
    nameOrganize(getName);

    //Finding
    printf("\nResults for %s\n", getName);
    printf("Female babies:\n");
    for (i = 0; i < szFemale; i++) {
        if (strcmp(getName, femaleData[i].name) == 0) {
            countFemale += femaleData[i].frequency;
            printf("%d: %d\n",femaleData[i].year, femaleData[i].frequency);
        }
    }
    printf("Male babies:\n");
    for (i = 0; i < szMale; i++) {
        if (strcmp(getName, maleData[i].name) == 0) {
            countMale += maleData[i].frequency;
            printf("%d: %d\n",maleData[i].year, maleData[i].frequency);
        }
    }
    //totalCount = countFemale+countMale;
    printf("\nTotal female babies: %d\n", countFemale);
    printf("Total male babies: %d\n", countMale);
    printf("Total babies: %d\n\n", countFemale+countMale);
}


void nameOrganize(char name[])
{
    int read = 0;
    int write = 0;
    char buffer;
    while (name[read] != '\0') {
        buffer = name[read];
        if (buffer >= 'a' && buffer <= 'z') {
            name[write] = buffer - 32;
            write++;
        }
        else if (buffer >= 'A' && buffer <= 'Z') {
            name[write] = buffer;
            write++;
        }
        read++;
    }
    name[write] = '\0';
}


void insertionSort(struct BabyName top5[], struct BabyName data)
{
    int i;
    int j;
    int flag=0;
    for(i=0; i<5 && flag==0; i++){
        if (data.frequency > top5[i].frequency){
            for(j=4; j>i; j--){
                top5[j] = top5[j-1];
            }
            top5[i] = data;
            flag=1;
        }
    }
}

void getTopNames(struct BabyName femaleData[], struct BabyName maleData[], int szFemale, int szMale)
{
    int getYear;
    int i;
    struct BabyName topFemale[5]={{0}};
    struct BabyName topMale[5]={{0}};

    do {
        printf("\nEnter the Year:");
        scanf("%d%*c", &getYear);
        if (getYear > 2023 || getYear < 1914) {
            printf("Number entered was invalid. Number must be between 1914 to 2023 inclusive\n");
        }
    } while (getYear > 2023 || getYear < 1914);

    printf("\nResults for %d\n", getYear);
    printf("\nTop 5 names for female\n");
    for (i=0; i < szFemale; i++){
        if (femaleData[i].year == getYear) {
            insertionSort(topFemale, femaleData[i]);
        }
    }
    for (i=0; i < 5; i++){
        printf("%d. %s: %d\n", i+1, topFemale[i].name, topFemale[i].frequency);
    }

    printf("\nTop 5 names for male\n");
    for (i=0; i < szMale; i++){
        if (maleData[i].year == getYear){
            insertionSort(topMale, maleData[i]);
        }
    }
    for (i=0; i < 5; i++){
        printf("%d. %s: %d\n", i+1, topMale[i].name, topMale[i].frequency);
    }
}

void nameHistogram(struct BabyName femaleData[], struct BabyName maleData[], int szFemale, int szMale){
    char getName[31] = {0};
    int year=2023;
    int i;
    int j;
    int star;
    //int countMale = 0;

    //Get name to find the matching name
    printf("Enter the Name:");
    scanf(" %30[^\n]", getName);
    printf("%s\n", getName);
    nameOrganize(getName);
    printf("The following histogram is totally made up");    
    for(i=0; i<22; i++){
        printf("\n%d-%d |",(year-5*i)-4, (year-5*i));
        star = countPerYear(getName, (year-5*i), femaleData, maleData, szFemale, szMale);
        for(j=0;j<star;j++){
            printf("*");
        }
    }
}

int countPerYear(char getName[], int endYear, struct BabyName femaleData[], struct BabyName maleData[], int szFemale, int szMale){
    int startYear =  endYear-4;
    int i;
    //int countTotal = 0;
    int countName = 0;
    int star;
    for (i=0; i<szFemale; i++){
        if (femaleData[i].year >= startYear && femaleData[i].year<= endYear) {
            //countTotal += femaleData[i].frequency;
            if (strcmp(getName, femaleData[i].name) == 0) {
                countName += femaleData[i].frequency;
            }
        }
    }
    for (i=0; i<szMale; i++){
        if (maleData[i].year >= startYear && maleData[i].year<= endYear) {
            //countTotal += maleData[i].frequency;
            if (strcmp(getName, maleData[i].name) == 0) {
                countName += maleData[i].frequency;
            }
        }
    }
    star = countName;
    return star;
}

void saveCombinedData(struct BabyName femaleData[], struct BabyName maleData[], int szFemale, int szMale){
    FILE* fp = NULL;
    fp = fopen("combined.txt", "w");
    int i;
    int j;

    if (fp != NULL) {
        for (i=0; i<szFemale; i++){
            for (j=0; j<szMale; j++){
                if ((femaleData[i].year == maleData[j].year) && (femaleData[i].name == maleData[j].name)){
                    femaleData[i].frequency += maleData[j].frequency;
                    maleData[j].year = 0;
                }
            }
            fprintf(fp,"%d,%s,%d\n", femaleData[i].year,femaleData[i].name,femaleData[i].frequency);
        }
        for (i=0; i<szMale; i++){
            if (maleData[i].year != 0){
                fprintf(fp,"%d,%s,%d\n", maleData[i].year,maleData[i].name,maleData[i].frequency);    
            }
        }
        fclose(fp);
        printf("Finished, writing data to combined.txt\n");
    }else {
        printf("File Save Error !!!\n");
    }
}