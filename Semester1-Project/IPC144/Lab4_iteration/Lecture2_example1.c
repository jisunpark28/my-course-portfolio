/******************************************
Iteration

3. for loop: initialize(최초한번), condition, count(카운트먼저하고 조건확인)

Note! 몇번 진행할지 정해졌을때만 for loop


Q1. Obtain marks of 5 students and find the average

******************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {

	int count;
    double mark, total = 0;

	//for loop
    for (count=0;count<5;count++) {
        printf("Enter Mark for Student %d: \n", count+1);
        scanf("%lf", &mark);
        total = total + mark;
        }
    printf("Average is: %.2lf\n", total / count);

	return 0;
}