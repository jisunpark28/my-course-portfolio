/***************************************************************** 

    File: projectmain.c

    Author: Jisun Park
    Seneca email: jpark295@myseneca.ca

    To compile program in codespaces, in terminal pane type:
        gcc -Wall project.c projectmain.c
    To run program in codespaces, in terminal pane type:
        ./a.out
        
***************************************************************/
//your main for the project goes into this file
//Uncomment the next line if you are using Visual Studio
#define _CRT_SECURE_NO_WARNING
#include <stdio.h>
#include <string.h>
#include "project.h"

int main(void)
{
    static struct BabyName femaleData[SIZE] = { {0} };
    static struct BabyName maleData[SIZE] = { {0} };
    //static struct BabyName temp[SIZE] = { {0} };
    int femaleDataCount = 0;
    int maleDataCount = 0;
    int userChoice;

    loadData("femalebabynames.csv", "malebabynames.csv", femaleData, maleData, &femaleDataCount, &maleDataCount);
    userChoice = displayMenu();

    while (userChoice != 4) {
        if (userChoice == 1) {
            findNameCount(femaleData, maleData, femaleDataCount, maleDataCount);
            userChoice = displayMenu();
        }
        else if (userChoice == 2) {
            getTopNames(femaleData,maleData, femaleDataCount, maleDataCount);
            userChoice = displayMenu();
        }
        else if (userChoice == 3) {
            nameHistogram(femaleData,maleData, femaleDataCount, maleDataCount);
            userChoice = displayMenu();
        }
    }

    saveCombinedData(femaleData,maleData, femaleDataCount, maleDataCount);

    switch (userChoice) {


        
    }
    return 0;
}