/*
Note!comma 중요성! printf("" variable) --> printf("", variable)  

This function is passed three(3) values and 
returns the biggest number of the three.

biggest(2, 5, 15) returns 15
biggest(25, 3, 18) returns 25
*/

#include <stdio.h>
#include "Lab3_Demo.h"

int biggest(int, int, int);

int main(void){

	int first, second, third;
	int result;

	first = 2;
	second = 5;
	third = 4;
	result = biggest(first, second, third);
	printf("biggest(%d, %d, %d) returns %d\n", first, second, third, result);

	return 0;
}