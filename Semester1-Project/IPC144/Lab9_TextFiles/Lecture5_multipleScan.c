#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(){
    int id, age;
    double mark;
    char name[21];

    printf("Enter Id, Age, Name and Mark(id,age,name;mark): ");
    int retVal = scanf("%d,%d,%20[^;];%lf%*c",&id,&age,name,&mark); //\n이 있으면 작동 안함. why? \n대신 %*c써줄 수 있음. why?
    // it returns how many adresses successfully filed
    printf("RetVal = %d\n", retVal);


    return 0;
}