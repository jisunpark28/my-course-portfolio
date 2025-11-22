#define _CRT_SECURE_NO_WARNINGS	
#include <stdio.h>
#include "Lecture9.h"

double getMark() {
	double mk;
	printf("Enter Mark: ");
	scanf("%lf", &mk);

	return mk;

}

char obtainLetter(double mks) {
	char ret;

	if (mks >= 80) {
		ret = 'A';
	}
	else if (mks >= 70) {
		ret = 'B';
	}
	else if (mks >= 60) {
		ret = 'C';
	}
	else if (mks >= 50) {
		ret = 'D';
	}
	else {
		ret = 'F';
	}
	return ret;
}

void display(char let) {
	printf("Student Grade is %c\n", let);
}