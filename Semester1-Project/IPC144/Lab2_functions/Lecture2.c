/******************************************
Introduce another function called display, which is
receiving a single double value. display the received value.
no data is returned.

Modify the main to call display to display the result of the 
summation (instead of printf in main)
******************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>



void display(double val) {
	
	printf("Result is : %.2lf\n", val);

}


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

	//printf("SUm is : %.2lf\n", retVal);
	display(retVal);

	return 0;


}