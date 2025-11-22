/***************************************************************** 

    File: project.h

    Author: Jisun Park
    Seneca email: jpark295@myseneca.ca

    To compile program in codespaces, in terminal pane type:
        gcc -Wall project.c projectmain.c
    To run program in codespaces, in terminal pane type:
        ./a.out
        
***************************************************************/
//function prototypes go into this file as does any constants

int fNumCars(void); //Prototypes for the funtion, defining number of cars 
char fDirection(void); //Prototypes for the funtion, defining direction of train
int fDrawPoint(int, char); //Prototypes for the funtion, defining draw point when drawing the final train
void defineWindow(char, char[], char[]); //Prototypes for the funtion, Randomly define the window
void drawTrainRight(int, int, char[],char[],char[],char[],char[],char[]); //Prototypes for the funtion, drawing right direction train
void drawTrainLeft(int, int, char[],char[],char[],char[],char[],char[]); //Prototypes for the funtion, drawing left direction train
