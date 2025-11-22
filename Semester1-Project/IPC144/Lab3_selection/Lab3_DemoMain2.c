/*
Function returns the upper case version of letter if letter is a lower case alphabetic character. 
Otherwise, function returns letter.

toUpper('5') returns '5'
toUpper('a') returns 'A'
toUpper('B') returns 'B'
*/
#include <stdio.h>
#include "Lab3_Demo.h"

char toUpper(char);

int main(void){

	char letter;
	char result;

	letter = 'a';
	result = toUpper(letter);
	printf("toUpper('%c') returns '%c'\n",letter, result);

	return 0;
}