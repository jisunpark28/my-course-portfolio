/******************************************
Selection: Multiple Alternative paths (+ more paths)

METHOD 2
******************************************/


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {

	int age;

	printf("Enter Age:  ");
	scanf("%d", &age);

		// Alternative path(s) - METHOD 2
	if (age <= 18) {
		printf("Teenager Pays $5\n");
	} 
	else if (age <= 55) {
		double fare = 15;
		if (age < 35) {
			fare *= .9;
		}
		printf("Adult Pays %.2lf\n", fare);
	}
	else {
		printf("Senior Pays $12\n");
	}

    return 0;
}