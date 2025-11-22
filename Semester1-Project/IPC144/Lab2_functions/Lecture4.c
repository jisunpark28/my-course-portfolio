/******************************************
Function prototypes (=stoll front???쇼핑몰에서 보여주듯)
: 


******************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//void display(double val)
//void divide(double fVal, int sVal)
//double getInput()
//double add(double val1, double val2)

//function prototypes (변수이름은 안 적어도 됨)
void display(double);
void divide(double, int);
double getInput();
double add(double, double);

void display(double val) {
	
	printf("Result is : %.2lf\n", val);

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

	printf("Sum is :");
	display(retVal);

	printf("Division by 5 result in: ");
	divide(fVal, 5);

	return 0;


}