#include <stdio.h>
#include "Book_Program03.h"

double buy3GetOneFree(double unitPrice, int numUnits){
    double totalPrice;

    totalPrice = unitPrice * numUnits  - (numUnits / 4) * unitPrice;

    return totalPrice;
}