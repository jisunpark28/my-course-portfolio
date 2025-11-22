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
//#define _CRT_SECURE_NO_WARNINGS

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "project.h"


//This function prompts the user to input a number between 0 and 5, and it validates the value to return the number of train cars in the return parameter.
int fNumCars(void) 
{
    int numCars;

    do{
        printf("Please enter a number of cars(0-5): ");
        scanf(" %d", &numCars);
        if (numCars<0 || numCars>5){
          printf("Error: You have to enter 0 to 5\n");
        }
    } while(numCars<0 || numCars>5);

    return numCars;
}


//This function prompts the user to input a letter L or R(case-insensitive), and it validates the value to return the letter of train direction in the return parameter.
char fDirection(void) 
{
    char direction;

    do{
        printf("Please enter a direction(L or R): ");
        scanf(" %c", &direction);
        if (direction =='L' || direction =='l'){
            direction='L';
        }else if(direction =='R' || direction == 'r'){
            direction='R';
        }else{
            printf("Error: You have to enter L or R(case-insensitive)\n");
        }

    } while(!(direction =='L' || direction =='R'));

    return direction;
}



//This function prints a train drawing based on the input arguments 'numCars' and 'direction,' and it can randomly change the number of windows for the cars.
void printTrain(int numCars, char direction)
{   

    int pointX = 48-(numCars-1)*12; //Defining the start point to draw the right derection train, which is decided on the number of cars
    int pointY = (numCars+1)*12-1; //Defining the end point to draw the left direction train, which is decided on the number of cars
    int i, j; 

    //Defining the basic train structure in an array for each line
    char trainRightLine1[73] = "                                                                &&&    "; 
    char trainRightLine2[73] = "                                                                  &&   ";
    char trainRightLine3[73] = "___________ ___________ ___________ ___________ ___________ _____  &   ";
    char trainRightLine4[73] = "| I I I I | | I I I I | | I I I I | | I I I I | | I I I I | | []|__II  ";
    char trainRightLine5[73] = "|_________|_|_________|_|_________|_|_________|_|_________|_|        | ";
    char trainRightLine6[73] = "  OO---OO     OO---OO     OO---OO     OO---OO     OO---OO   OOO----OO >";

    char trainLeftLine1[73] = "     &&&                                                               ";
    char trainLeftLine2[73] = "    &&                                                                 ";
    char trainLeftLine3[73] = "   &  _____ ___________ ___________ ___________ ___________ ___________";
    char trainLeftLine4[73] = "  II__|[] | | I I I I | | I I I I | | I I I I | | I I I I | | I I I I |";   
    char trainLeftLine5[73] = " |        |_|_________|_|_________|_|_________|_|_________|_|_________|";
    char trainLeftLine6[73] = "< OO----OOO   OO---OO     OO---OO     OO---OO     OO---OO     OO---OO  ";


    //Deleting the tranin's windows depends on the (0 or 1) generating from random number(ran())
    if(direction=='R'){
        for (i=2; i<=58; i+=12){
            for (j=i; j<i+8; j++){
                if(rand()%2==0){            
                    trainRightLine4[j] = ' ';
                }
            }
        }
    }else{
        for (i=14; i<=70; i+=12){
            for (j=i; j<i+8; j++){
                if(rand()%2==0){
                    trainLeftLine4[j] = ' ';
                }
            }
        }
    }

    //if: Drawing 'a right direction train' line by line from the starting point of each array
    //else: Drawing 'a left direction train' line by line until the end point of each array
    if(direction=='R'){       
        for (i = pointX; i < 71; i++) {
            printf("%c", trainRightLine1[i]); 
        } 
        printf("\n");
        for (i = pointX; i < 71; i++) {
            printf("%c", trainRightLine2[i]);
        } 
        printf("\n");
        for (i = pointX; i < 71; i++) {
            printf("%c", trainRightLine3[i]);
        } 
        printf("\n");
        for (i = pointX; i < 71; i++) {
            printf("%c", trainRightLine4[i]);
        } 
        printf("\n");
        for (i = pointX; i < 71; i++) {
            printf("%c", trainRightLine5[i]);
        } 
        printf("\n");
        for (i = pointX; i < 71; i++) {
            printf("%c", trainRightLine6[i]);
        }
        printf("\n");               
    }else{                                      
        for (i = 0; i < pointY; i++) {
            printf("%c", trainLeftLine1[i]);
        } 
        printf("\n"); 
        for (i = 0; i < pointY; i++) {
            printf("%c", trainLeftLine2[i]);
        } 
        printf("\n");   
        for (i = 0; i < pointY; i++) {
            printf("%c", trainLeftLine3[i]);
        } 
        printf("\n");    
        for (i = 0; i < pointY; i++) {
            printf("%c", trainLeftLine4[i]);
        } 
        printf("\n");    
        for (i = 0; i < pointY; i++) {
            printf("%c", trainLeftLine5[i]);
        } 
        printf("\n");    
        for (i = 0; i < pointY; i++) {
            printf("%c", trainLeftLine6[i]);
        } 
        printf("\n");    
    }
}
