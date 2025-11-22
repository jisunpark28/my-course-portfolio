/******************************************
Palleral Array + String

Declare a character array to store your address
Obtain the address
Display it

[^\n] before enter
[^H] befor H
******************************************/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>


int main() {

    char address[41];

    printf("Enter your address: \n");
    scanf("%40[^\n]%*c", address); 

    printf("You entered %s\n", address); 


	return 0;

}