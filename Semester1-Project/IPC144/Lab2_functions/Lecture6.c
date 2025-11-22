/******************************************
Create a new project

1.Create a header file called utility.h

Add the function prototype for a function called multiply that 

receives a float and a int and returns a double 

2. Create a c file called utility.c. Implement the above function

to multiply the two values and return a double.

3. Create another file called testData.c that contains a main 

function and display function.


main fn

=======

Hardcode(assign in program) a float and int to some values.

Call multiply with the values and receives a result. The result 

has to be displayed with a function called display.



Display fn

==========

Receives a double value and display it
******************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "Lecture6.h"

double multiply(float fVal, int sVal) {

	return (double)(fVal * sVal);
}

void display(double val) {

	printf("Result: %.2lf\n", val);
}

