/******************************************
Function

[Function Structure]
data-type(A) fn_name(data-type varName, dat-type varName, ...){
    //Instructions

    return value; (value should be of the tata type(A))

Term of parameter & argument
	parameter : variable
	argument : values, declaring the variable (called input argument)
}
******************************************/

#include <stdio.h>

double add(double val1, double val2) {

	double sum = val1 + val2;

	return sum;
}

int main() {

	double fVal = 67.56, sVal = 78.89;
	double retVal = add(fVal, sVal);

	printf("Sum is : %.2lf\n", retVal);

	return 0;
}