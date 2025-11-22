/******************************************
Selection: Optional Path

******************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {

	int age;

	printf("Enter Age:  ");
	scanf("%d", &age);

	//optional Path
	if (age >= 18) {
		printf("Fare is $10\n");
	}

    return 0;
}