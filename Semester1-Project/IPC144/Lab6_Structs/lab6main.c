#include <stdio.h>
#include "lab6.h"

int main(void)
{
    //Function1 - Call by Reference - Passing the Address
    int quarters, dimes, nickels;
    makeChange(54, &quarters, &dimes, &nickels);
    printf("Quarters: %d\tDimes: %d\tNickels: %d\n", quarters, dimes, nickels);

    //Function2
    struct DateTime dt;
    char dateString[] = "23/11/2025";
    setDate(dateString, &dt);

    //Function3
    dt.hour = 23;
    dt.minute = 33;     
    printDateTime(&dt);

    //Practice1
    const char timeString[] = "23:45";
    setTime(timeString, &dt);

    //Practice2 - Call by Reference 
    const char str[] = "December 6, 2025(Thursday)";
    int numAlpha;
    int numDigits;
    countCharacters(str, &numAlpha, &numDigits);
    printf("The number of Alphabet: %d\nThe number of Digits:%d\n",numAlpha, numDigits);

    //Practice3
    int array[] = {34, 245, 454, 41, 34, 245, 951};
    int size=7;
    int minIdx;
    int maxIdx;
    double average;
    minMaxAverage(array, size, &minIdx, &maxIdx, &average);
    printf("Index of the smallest value: %d\nIndex of the largest value:%d\nAverage of the values:%.2lf\n", minIdx, maxIdx, average);

    return 0;
}