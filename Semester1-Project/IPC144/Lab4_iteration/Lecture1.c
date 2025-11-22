/******************************************
Iteration

2. while loop: pre-check loop
while(condition) : condition = true --> instrructions keep working

Note! count = 0 (atarting 0 is best option!)

Q1. Print 5 - 1

******************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {

	int count = 0;

	//whilel loop
    while (count < 5){

        //instructions
        count++;
        printf("Value: %d\n", count);

    }


	return 0;
}