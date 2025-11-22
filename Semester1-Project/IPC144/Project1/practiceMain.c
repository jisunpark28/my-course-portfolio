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


#include <stdio.h>
#include "project.h"

//This main function defines the number of cars and direction of the train, calls other functions, and prints the final train drawing defined by the user.
int main(void)
{
    int numCars = fNumCars();
    char direction = fDirection(); 
    printTrain(numCars, direction);
    return 0;
}