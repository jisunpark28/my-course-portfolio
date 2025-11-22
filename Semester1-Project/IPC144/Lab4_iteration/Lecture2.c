/******************************************
Iteration

3. for loop: initialize(최초한번), condition, count(카운트먼저하고 조건확인)

Note! 몇번 진행할지 정해졌을때만 for loop


Q1. Print 5 - 1

******************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {

	int count;

	//for loop
    for (count=0;count<5;count++) {
        printf("Val: %d\n", count+1);
    }


	return 0;
}