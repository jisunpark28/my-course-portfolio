#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(){
    int mark;
    char grade;

    printf("Enter your test score (0-100): ");
    scanf("%d", &mark);
    if (mark < 60){
        grade = 'F';
    } else if (mark <70){
        grade = 'D';
    } else if (mark <80){
        grade = 'C';
    } else if (mark <90){
        grade = 'B';
    } else if (mark <= 100){
        grade = 'A';
    }

    printf("Your grade is: '%c", grade);
    return 0;
}