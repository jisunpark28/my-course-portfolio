/*
Function returns a 1 if letter is a lower case alphabetic character, 
				   0 otherwise.
				   
isLower('5') returns 0
isLower('T') returns 0
isLower('a') returns any number that isn't 0
*/

#include <stdio.h>
#include "Lab3_Demo.h"

int isLower(char);

int main(void){

	char letter;
	int result;

	letter = 'I';
	result = isLower(letter);
	printf("isLower(%c) = %d\n",letter, result);

	return 0;
}