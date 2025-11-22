/******************************************
Selection: Multiple Alternative paths(inner conditions)

******************************************/


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {

	int age;

	printf("Enter Age:  ");
	scanf("%d", &age);

	// Alternative path(s) - METHOD 1 
	if (age <= 18) {
		printf("Teenager Pays $5\n");
	}
	else {                      
		if (age <= 55) {        //inner conditions

		printf("Adult Pays $15\n");
		}
		else {
			printf("Senior Pays $12\n");
		}
	}

    return 0;
}