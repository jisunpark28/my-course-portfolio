/******************************************
 Introduce a third function called divide and pass fVal and any 

integer (like 5). Perform the division of fVal by integer sent.

Call display within divide. no data needs returned. 

Note! 함수 안에서 불러들일 함수는 항상 먼저 정의되야 함.
******************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void display(double val) {
	
	printf("result is : %.2lf\n", val);

}

void divide(double fVal, int sVal) {

	//double res = fVal / sVal;
	display(fVal/sVal);
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

	//printf("Sum is : %.2lf\n", retVal);

	printf("Summation ");
	display(retVal);

	printf("Division by 5 ");
	divide(fVal, 5);

	return 0;


}