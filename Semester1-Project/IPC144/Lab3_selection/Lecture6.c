/******************************************
	Obtain age, if you age is inbetween 20 and 30
	(inclusive of 20 and 30) your fare is 50$
	Otherwise 25

	If age is less than 0 or greater than 120, show an error " Invalid age"
	otherwise print valid age
******************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {



	int age;
	printf("Enter Age: ");
	scanf("%d", &age);
	if (age >= 20 && age <= 30){
		printf("You pay 50$\n");
	}
	else {
		printf("You pay 25$\n");
	}


	if (age < 0 || age > 120) {
		printf("Invalid age....\n");
	}
	else {
		printf("Valid age");
	}

	return 0;
}