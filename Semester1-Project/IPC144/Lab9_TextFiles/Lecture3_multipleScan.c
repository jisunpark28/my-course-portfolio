#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(){
    int id, age;
    double mark;
    char name[21];
    
//Case1. scan only numbers
    //printf("Enter Id and Age and marks: ");
    //scanf("%d%d%lf%s", &id, &age, &mark);
    //printf("ID=%d\t Age=%d\tMark=%.2lf\n", id, age, mark);

//Case2. scan characters
    //Input Format: id,age,name;mark\n
    printf("Enter Id, Age, Name and Mark(id,age,name;mark): ");
    //scanf("%d,%d,%20[^;]%lf\n",&id,&age,name,&mark); //Don't Use %20[^\n] because \n is in the behind of the mark value
    //scanf("%d,%d,%20[^;]%lf\n",&id,&age,name,&mark); //\n이 있으면 작동 안함. why?
    //scanf("%d,%d,%20[^;]%lf",&id,&age,name,&mark); //\n이 있으면 작동 안함. why?
    scanf("%d,%d,%20[^;]%lf%*c",&id,&age,name,&mark); //\n이 있으면 작동 안함. why? \n대신 %*c써줄 수 있음. why?
    printf("ID=%d\tAge=%d\tName=%s\tMark=%.2lf\n", id,age,name,mark);

    return 0;
}