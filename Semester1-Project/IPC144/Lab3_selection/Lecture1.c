/******************************************
Selection: Alternative path

******************************************/


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {

	int age;

	printf("Enter Age:  ");
	scanf("%d", &age);

	//Alternative path
	if (age >= 18) {
		printf("Fare is $10\n");
	}
	else {
		printf("Fare is $5\n");
	}

    return 0;
}