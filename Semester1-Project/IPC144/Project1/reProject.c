/***************************************************************** 

    File: project.c

    Author: Jisun Park
    Seneca email: jpark295@myseneca.ca

    To compile program in codespaces, in terminal pane type:
        gcc -Wall reProject.c reProjectmain.c
    To run program in codespaces, in terminal pane type:
        ./a.out
        
***************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "reProject.h"


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


//This function defining the draw point based on the number of cars and direction.
int fDrawPoint(int numCars, char direction)
{   
    int drawPoint;
    if (direction=='R'){
        drawPoint = 48-(numCars-1)*12; //Defining the start point to draw the right derection train
    }else{
        drawPoint = (numCars+1)*12-1; //Defining the end point to draw the left direction train
    }
    return drawPoint;
}


//This fuction deletes the tranin's windows depends on the (0 or 1) generating from random number(ran())
void defineWindow(char direction, char trainRightLine4[], char trainLeftLine4[])
{
    int i,j;

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
}


//This function draws a train moving to the right by printing characters from the drawPoint index to the end of each of the six character arrays.
void drawTrainRight(int numCars, int drawPoint, char trainRightLine1[],char trainRightLine2[],char trainRightLine3[],char trainRightLine4[],char trainRightLine5[],char trainRightLine6[])
{   
    int i;   

    for (i = drawPoint; i < 71; i++) {
        printf("%c", trainRightLine1[i]); 
    } 
    printf("\n");
    for (i = drawPoint; i < 71; i++) {
        printf("%c", trainRightLine2[i]);
    } 
    printf("\n");
    for (i = drawPoint; i < 71; i++) {
        printf("%c", trainRightLine3[i]);
    } 
    printf("\n");
    for (i = drawPoint; i < 71; i++) {
        printf("%c", trainRightLine4[i]);
    } 
    printf("\n");
    for (i = drawPoint; i < 71; i++) {
        printf("%c", trainRightLine5[i]);
    } 
    printf("\n");
    for (i = drawPoint; i < 71; i++) {
        printf("%c", trainRightLine6[i]);
    }
    printf("\n");               
}
    

//This function draws a train moving to the left by printing characters from index 0 up to, but not including, the drawPoint index for each of the six character arrays.
void drawTrainLeft(int numCars, int drawPoint, char trainLeftLine1[],char trainLeftLine2[],char trainLeftLine3[],char trainLeftLine4[],char trainLeftLine5[],char trainLeftLine6[])
{       
    int i; 

    for (i = 0; i < drawPoint; i++) {
        printf("%c", trainLeftLine1[i]);
    } 
    printf("\n"); 
    for (i = 0; i < drawPoint; i++) {
        printf("%c", trainLeftLine2[i]);
    } 
    printf("\n");   
    for (i = 0; i < drawPoint; i++) {
        printf("%c", trainLeftLine3[i]);
    } 
    printf("\n");    
    for (i = 0; i < drawPoint; i++) {
        printf("%c", trainLeftLine4[i]);
    } 
    printf("\n");    
    for (i = 0; i < drawPoint; i++) {
        printf("%c", trainLeftLine5[i]);
    } 
    printf("\n");    
    for (i = 0; i < drawPoint; i++) {
        printf("%c", trainLeftLine6[i]);
    } 
    printf("\n");    
}
