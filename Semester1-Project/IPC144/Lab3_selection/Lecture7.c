/******************************************
    Combine above statements to show error for invalid age
	when its between 20 and 30 --> 50$
	when its less than 50 but greater than 35 --> 25$
	otherwise 10$
******************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {



	int age;
	printf("Enter Age: ");
	scanf("%d", &age);

		if (age < 0 || age > 120) {
		printf("Invalid age....\n");
	}
		else if (age >= 20 && age <= 30) {
		printf("Fare is 50$\n");
	}
		else if (age < 50 && age > 35) {
			printf("Fare is 25$\n");
		}
		else {
			printf("Fare is 10$\n");
		}


	return 0;
}