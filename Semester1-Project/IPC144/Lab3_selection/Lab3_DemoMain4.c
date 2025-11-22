/*
Note!comma 중요성! printf("" variable) --> printf("", variable)  

This function is passed three(3) values and 
returns the biggest number of the three.

| Age Group | Pricing on Monday(no coupons)| Pricing on Tuesday to Thursdays | Pricing on Weekends Friday-Sun | 
|---|---|---|---|
| Children (12 and Under) | $5.00 | $7.00 | $8.00 |
| Seniors (65 and Over) | $5.00 | $9.00 | $10.00|
| General Admission | $5.00 | $12.00 | $15.00 |
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "Lab3_Demo.h"

double ticketPrice(int, int, int);

int main(void){

	int age, hasCoupon, dayOfWeek;
	double result;

    age = 12;
    hasCoupon = 0;
    dayOfWeek = 2;
    result = ticketPrice(age, hasCoupon, dayOfWeek);
    printf("The price is %.2lf\n", result);
	return 0;
}