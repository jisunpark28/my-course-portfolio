#include <stdio.h>
#include "Lecture6.h"

void display(double val);



int main(void) {

	float fVal = 8.99;
	int sVal = 7;
	double result = multiply(fVal, sVal);
	display(result);


	return 0;
}