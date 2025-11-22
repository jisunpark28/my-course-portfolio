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
#include "reProject.h"
#define SIZE 73 

//This main function defines the number of cars and direction of the train, calls other functions, and prints the final train drawing defined by the user.
int main(void)
{   
    //Define each row of the right direction train as a character array.
    char trainRightLine1[SIZE] = "                                                                &&&    "; 
    char trainRightLine2[SIZE] = "                                                                  &&   ";
    char trainRightLine3[SIZE] = "___________ ___________ ___________ ___________ ___________ _____  &   ";
    char trainRightLine4[SIZE] = "| I I I I | | I I I I | | I I I I | | I I I I | | I I I I | | []|__II  ";
    char trainRightLine5[SIZE] = "|_________|_|_________|_|_________|_|_________|_|_________|_|        | ";
    char trainRightLine6[SIZE] = "  OO---OO     OO---OO     OO---OO     OO---OO     OO---OO   OOO----OO >";

    //Define each row of the left direction train as a character array.
    char trainLeftLine1[SIZE] = "     &&&                                                               ";
    char trainLeftLine2[SIZE] = "    &&                                                                 ";
    char trainLeftLine3[SIZE] = "   &  _____ ___________ ___________ ___________ ___________ ___________";
    char trainLeftLine4[SIZE] = "  II__|[] | | I I I I | | I I I I | | I I I I | | I I I I | | I I I I |";   
    char trainLeftLine5[SIZE] = " |        |_|_________|_|_________|_|_________|_|_________|_|_________|";
    char trainLeftLine6[SIZE] = "< OO----OOO   OO---OO     OO---OO     OO---OO     OO---OO     OO---OO  ";

    int numCars = fNumCars(); //The numCars defined by fNumCars is used to determine the start and end points for drawing the train.
    char direction = fDirection();  //The direction, which is defined by fDirection, is used to determine the direction for drawing the train.
    int drawPoint = fDrawPoint(numCars,direction); //The drawPoint defined by fDrawPoint, is determined by the train's direction and the number of cars. It's used to establish the critical start and end points for drawing the train.

    defineWindow(direction,trainRightLine4,trainLeftLine4); //Using the defineWindow function, train windows are randomly deleted to draw a varying number of windows.
    
    //Depending on the direction value, the function to draw the train is called.
    if(direction=='R'){
        drawTrainRight(numCars,drawPoint,trainRightLine1,trainRightLine2,trainRightLine3,trainRightLine4,trainRightLine5,trainRightLine6);
    }else{
        drawTrainLeft(numCars,drawPoint,trainLeftLine1,trainLeftLine2,trainLeftLine3,trainLeftLine4,trainLeftLine5,trainLeftLine6);
    }

    return 0;
}