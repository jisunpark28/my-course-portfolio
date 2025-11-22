/*
these 4 functions are loosely coupled.

Selection - Alternative
    1. Explicit Branching
        if-else (참이면 A, 거짓이면 B)
    2. Default & Override
        if (일단 Default value 세팅, 만약 조건이 참이면 값을 덮어 씀 )
*/

#include <stdio.h>
#include "book_code.h"

double getUnitPrice()
{
    double unitPrice;
    printf("Please enter the number of muffins purchased: ");
    scanf("%lf",&unitPrice);
    return unitPrice;
}

int getNumMuffins()
{
	int numMuffins;
	printf("Please enter the price of each muffin: ");
	scanf("%d", &numMuffins);
	return numMuffins;
}


void outputResult(int numMuffins, double unitPrice, double taxes)
{
	double subtotal = numMuffins*unitPrice;
	printf("Cost of %d muffins at $%.2lf each: $%.2lf\n",numMuffins,							unitPrice, subtotal);
	printf("Taxes: $%.2lf\n",taxes);
	printf("Total: $%.2lf\n",subtotal + taxes);
}


double calculateTaxes(int numMuffins, double unitPrice)
{
	double taxes;
	//check if number of muffins is less than 6.

//Explicit Branching
	// if(numMuffins < 6){
	// 	taxes = numMuffins*unitPrice*0.13;
	// }
	// else{
	// 	taxes = 0;
	// }
	// return taxes;

//Default & Override
    taxes = numMuffins*unitPrice*0.13;
    if (numMuffins >= 6) taxes=0;
    return taxes;
}
