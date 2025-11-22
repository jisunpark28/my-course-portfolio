/******************************************

The size of data types like long int is determined by the system's architecture and compiler, 
which is why its size can be 4 bytes on a 32-bit system and 8 bytes on a 64-bit system.

[Variables]
Initialization - the variable has default value.
char - 1 byte of storage meant to hold the encoding of a character
int - 4 bytes of storage meant to hold a whole number.
float - 4 bytes of storage meant to hold a floating point number. This is a number that has decimal places.
double - 8 bytes of storage meant to hold a floating point number. The difference between a double and a float is that doubles can store floating points more accurately.

[Modifiers]
unsigned - It will cause all bits to be used for positive numbers only
short - It reduces the amount of storaged used.
long - It increases the amount of storaged used for a variable.

[Type Conversions]
Narrowing - a larger or more general type to a smaller or more specific type, it can cause data lose and have unintended consequences
Promoting - a smaller or less general type to a larger more general type, 
Casting - explicit casting & implicit casting, the conversion from one data type to another, To perform an explicit cast, put (data type) before the expression being converted.

[Styling Conventions] - Camelcase

******************************************/



#include <stdio.h>
int main(void)
{
    printf("size (number of bytes) of a char : %lu\n", sizeof(char));   
    printf("size (number of bytes) of a int : %lu\n", sizeof(int));
    printf("size (number of bytes) of a float : %lu\n", sizeof(float)); 
    printf("size (number of bytes) of a double : %lu\n", sizeof(double)); 
    printf("size (number of bytes) of a long : %lu\n", sizeof(long)); 
    printf("size (number of bytes) of a short : %lu\n", sizeof(short)); 
    printf("size (number of bytes) of a long long : %lu\n", sizeof(long long));    

    return 0;
}