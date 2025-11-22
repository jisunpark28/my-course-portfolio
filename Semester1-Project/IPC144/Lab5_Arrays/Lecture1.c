/******************************************
Array Bagic

Address
: get one address for many variables
******************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(){

    double mark[5];

    mark[0] = 55.6;
    mark[1] = 45.6;
    mark[2] = 35.6;
    mark[3] = 25.6;
    mark[4] = 15.6;


    printf("First Mark is %.2lf\n", mark[0]);
    printf("First Mark is %.2lf\n", mark[1]);    
    printf("First Mark is %.2lf\n", mark[2]);    
    printf("First Mark is %.2lf\n", mark[3]);    
    printf("First Mark is %.2lf\n", mark[4]);    

    return 0;
}