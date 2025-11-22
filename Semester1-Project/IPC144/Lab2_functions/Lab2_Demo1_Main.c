/***************************************************************** 

    File: lab2main.c

    Author: [Your Name]
    Seneca email: [Your Seneca email address]

    To compile program in codespaces, in terminal pane type:
        gcc -Wall lab2.c lab2main.c
    To run program in codespaces, in terminal pane type:
        ./a.out
        
***************************************************************/
//Uncomment the next line if you are using Visual Studio
//#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "Lab2_Demo1.h"

int main(void)
{
    int num = 1521; //Hardcode(assign in program);
    int seconds = 121;

    //call function with that testvalue and assign to result
    printf("Last Digit of %d is = %d\n", num, lastDigit(num));
    printf("%d seconds converted to minutes is %d\n", seconds, wholeMinutes(seconds));

    return 0;
}


//[Interactive tester]
// int main(void)
// {
//     int number;
//     int result;

//     //read in a the test value
//     printf("enter a number: ");
//     scanf("%d", &number);

//     //call function with that testvalue and assign to result
//     result = lastDigit(number);

//     //print the result
//     printf("\nLast Digit(%d) = %d\n", number, result);

//     return 0;
// }