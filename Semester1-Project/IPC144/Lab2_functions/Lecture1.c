/******************************************
Introduce another function called getInput
to obtain one double input at a time and returns that.

Main function sould be modified to obtain values for 
fVal and sVal using getInput.

******************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

double getInput() {
	// Obtaining input from user and returning the values at a time

	double val;
	printf("Enter input: ");
	scanf("%lf", &val);

	return val;
}



double add(double val1, double val2) {
	// Adding two values and returning the sum

	double sum = val1 + val2;

	return sum;
}




int main() {

	double fVal = getInput();
	double sVal = getInput();
	double retVal = add(fVal, sVal);

	printf("SUm is : %.2lf\n", retVal);

	return 0;


}