#include <stdio.h>
#include "Book_Program03.h"

int main(void){

    double unitPrice = 5;
    double numUnits = 8;

    printf("The Total Price is $%.2lf", buy3GetOneFree(unitPrice, numUnits));
    return 0;
}