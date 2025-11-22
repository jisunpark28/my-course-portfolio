#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "Book_Program01.h"

double metricHeight(int feet, int inches){
    double centi;
    
    centi = feet * 12 * 2.54 + inches * 2.54;
    
    return centi;

}