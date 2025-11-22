#include <stdio.h>

double findPopCornPrice(char size, int hasButter, int hasSeaoning){

    double price = 5.00;

    if (size == 'm') price += 1;
    else if (size == 'l') price += 3;
    if (hasButter != 0) price += 1;
    if (hasSeaoning != 0) price += 0.5;
    return price; 
}