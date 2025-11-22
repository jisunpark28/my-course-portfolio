/*
Logical Operators

boolean data type:
    A boolean type is a data type where the result is either true or false.
    C does not have boolean types built into the language. 
    Instead a 0 value is false, every non-zero value is true.
*/
#include <stdio.h>
#include "book_code.h"

int main(void)
{
	char size = getSize();
	char addTapioca = getTapioca();
	char addJelly = getJelly();
	double price = calculateTea(size, addTapioca, addJelly);
	printResult2(price);
}

