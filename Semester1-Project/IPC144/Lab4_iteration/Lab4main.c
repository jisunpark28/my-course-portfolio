#include <stdio.h>
#include "Lab4.h"

int power(int, int);
int readIntInRange(int, int);
int fibonacci(int);


int main(void){
    int base=2;
    int exponent=3;
    printf("power(%d,%d) = %d\n", base, exponent, power(base, exponent));


    int min=10;
    int max=25;
    readIntInRange(min,max);


    int n=5;
    printf("fibonacci(%d) returns %d\n", n, fibonacci(n));


    int start=8;
    int stop=8;
    printf("sum(%d,%d) returns %d\n", start, stop, sum(start,stop));

    int endPoint=22;
    printf("fizzBuzzScore(%d) returns %d\n", endPoint, fizzBuzzScore(endPoint));

    int number=6172;
    printf("sumDigits(%d) returns %d\n", number, sumDigits(number));

    int letter = 'T'; 
    printf("isLower(%c) returns %d\n", letter, isLower(letter));

    printf("toUpper(%c) returns %c\n", letter, toUpper(letter));
    int first=2;
    int second=5;
    int third=15;
    printf("biggest(%d,%d,%d) returns %d\n", first, second, third, biggest(first,second,third));

    int age=12;
    int hasCoupon=1; 
    int dayOfWeek=1;
    printf("ticket price = %.2lf\n", ticketPrice(age,hasCoupon,dayOfWeek));

    return 0;
}