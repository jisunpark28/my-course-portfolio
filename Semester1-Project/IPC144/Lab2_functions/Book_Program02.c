#include <stdio.h>
#include "Book_Program02.h"

int sum3Digits(int threeDigitNumber){
    int rc;
    
    rc = threeDigitNumber/100;
    rc += (threeDigitNumber % 100)/10;
    rc += threeDigitNumber % 10;

    return rc;
}