/******************************************
Selection: Multiple Alternative paths (+ more paths)

METHOD 1
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
	else if (age < 35) {
		printf("Adult Pays applied 10%% discount %.2lf\n", 15*0.9 );
	}
	else if (age <= 55) {
		printf("Adult Pays $15\n");
	}
	else {
		printf("Senior Pays $12\n");
	}

    return 0;
}