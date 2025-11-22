/*
Selection
    if - else
Alternatives
    default - if
*/
#define _CRT_CECURE_NO_WARNINGS
#include <stdio.h>

int main(void){
    int muffinNum;
    double muffinUnitPrice, tax, total;
    printf("Please enter the number of muffins purchased: ");
    scanf("%d", &muffinNum);
    printf("Please enter the price of each muffin: ");
    scanf("%lf", &muffinUnitPrice);

    if (muffinNum < 6) tax = muffinNum * 1.13;
    else tax = 0;
    
    total = muffinNum*muffinUnitPrice + tax;
    printf("Cost of %d muffins at %.2lf each: $%.2lf\n", muffinNum, muffinUnitPrice, muffinUnitPrice*muffinNum);
    printf("Taxes: %.2lf\n", tax);
    printf("Total: %.2lf\n", total);
    
    return 0;
}