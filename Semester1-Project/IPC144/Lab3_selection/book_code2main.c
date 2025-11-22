/*
Alternatives


*/

#include <stdio.h>
#include "book_code.h"


int main(){
	int numSold = getNumMuffins();
	double unitPrice = getUnitPrice();
	double tax = calculateTaxes(numSold, unitPrice);
	outputResult(numSold, unitPrice, tax);

    return 0;
}