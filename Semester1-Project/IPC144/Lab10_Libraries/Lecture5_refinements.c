#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(){

/*  //Only use in menu
    //conditional operator

    //switch case
    int choice;
    printf("1. Pizza\n2. Pasta\n3. burger\n0. Exit\n");
    printf("Make your selection: ");
    scanf("%d", &choice);

    switch(choice) {
    
        case 1:
            printf("\nYou ordered Pizza\n");
            printf("Enjoy\n");
            break;
        case 2 :
            printf("\nYou ordered Pasta\n");
            printf("Enjoy\n");
            break; //if there is no break, it's going to go next case
        case 3 :
            printf("\nYou ordered burger\n");
            printf("Enjoy\n");
            break;
        case 0 :
            printf("\nExiting Now\n");
            break;
        default :
            printf("Invalid Choice\n");
    }
*/

    //conditional operator

    //switch case
    char choice;
    printf("A. Pizza\nB. Pasta\nC. burger\nD. Exit\n");
    printf("Make your selection: ");
    scanf("%c", &choice);
/*
    switch(choice) {
        
        case 'a': 
        case 'A':
            printf("\nYou ordered Pizza\n");
            printf("Enjoy\n\n");
            break;
        case 'b': 
        case 'B' :
            printf("\nYou ordered Pasta\n");
            printf("Enjoy\n\n");
            break; //if there is no break, it's going to go next case
        case 'c': 
        case 'C' :
            printf("\nYou ordered burger\n");
            printf("Enjoy\n\n");
            break;
        case 'd': 
        case 'D' :
            printf("\nExiting Now\n");
            break;
        default :
            printf("Invalid Choice\n");
    }
*/

    //conditional operator 
    int x = 7;
    double res;

    if (x > 9) {
        res = x * 56.7;
    }
    else {
        res = x - 78;
    }
    printf("%.lf\n", res);

    //conditional operator 
    res = x >9? x*56.7 : x-78;
    printf("%.lf\n", res);

    //conditional operator 
    printf("%.lf\n", x >9? x*56.7 : x-78);



    //Q. Using a conditional operator do the following
    /*
        print "Invalid" When marks > 100 and < 0
        Print "A Grade" when marks >= 80
        Print "B Grade" when marks >= 70 and <80
        Print "C Grade" when marks >= 50 and <70
        Print "F Grade" Otherwise
    */
    double mk;
    char grade[21];

    printf("Enter Mark: ");
    scanf("%lf", &mk);

    strcpy(grade, mk<0 || mk>100? "Invalid": x>=80? "A Grade" : x>=70? "B Grade" : x>=50? "C Grade" : "F Grade");
    puts(grade);

    return 0;
}