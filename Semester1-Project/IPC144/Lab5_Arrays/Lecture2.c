/******************************************
Array in Loop

#define SIZE 5 
Has the same effect as const int SIZE = 5. 
Called Macro directive or a preprocessor directive
******************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SIZE 5 //const int SIZE = 5, it works like variable.

int main(){

    double mark[SIZE];
    int i;

    for (i=0; i<SIZE; i++){
        printf("Enter Mark %d: ", i+1);
        scanf("%lf", &mark[i]);
    }

    for (i=0; i<SIZE; i++){
        printf("Student %d Got %.2lf\n", i+1, mark[i]);
    }


    return 0;
}